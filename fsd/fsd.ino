#include <ESP8266WiFi.h>
#define RL 10.0 // the value of RL is 10K
#define m -0.36848 // using formula y = mx+c and the graph in the datasheet
#define c 1.105 // btained by before calculation
#define R0 1.9
#define b 1.0
#define LED D0 // pin for fan
double gas;
#define Gas_Pin A0
void setup() 
{
Serial.begin(9600);
pinMode(LED,OUTPUT);
delay(10);
pinMode(Gas_Pin,INPUT);
}
//int ppm1() 
//{  
 // float sensor_volt; //Define variable for sensor voltage 
 // float RS_gas; //Define variable for sensor resistance  
 // float ratio; //Define variable for ratio
 // float sensorValue = analogRead(Gas_Pin); //Read analog values of sensor  
  //sensor_volt = sensorValue*(5.0/1023.0); //Convert analog values to voltage 
  //RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
 // ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
 // double ppm_log = (log10(ratio)-c)/m; //Get ppm value in linear scale according to the the ratio value  
 // float ppm = pow(10, ppm_log); //Convert ppm value to log scale 
  //Serial.println(ppm);
  // delay(200);
  //return(ppm);  
//}
void loop() 
{
  //gas = ppm1();
  //Serial.println(ppm1());
   float sensor_volt; //Define variable for sensor voltage 
  float RS_gas; //Define variable for sensor resistance  
  float ratio; //Define variable for ratio
  float sensorValue = analogRead(Gas_Pin); //Read analog values of sensor  
  sensor_volt = sensorValue*(5.0/1023.0); //Convert analog values to voltage 
  RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
  ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
  double ppm_log = (log10(ratio)-c)/m; //Get ppm value in linear scale according to the the ratio value  
  float ppm = pow(10, ppm_log); //Convert ppm value to log scale 
  Serial.println(ppm);
   
delay(100);
if (ppm>b)
{
  digitalWrite(  LED,  HIGH );
  Serial.println(" light ON ");
}
else{
  digitalWrite(LED,LOW);
  Serial.print(" LIGHT OFF ");
}
}
