#define BLYNK_TEMPLATE_ID "your TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "your TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "your AUTH_TOKEN"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#define soilpin 32
BlynkTimer timer;
 char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "your ssid";  // Enter your Wifi Username
char pass[] = "your password";  // Enter your Wifi password
void setup()
{     
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(soilpin,INPUT);
  timer.setInterval(1000L, sendSensor);
}
void loop()
{
  Blynk.run(); 
  timer.run();
}
void sendSensor()
{
  int value = analogRead(soilpin);  // Read from the soil moisture sensor
  int soilmoisturepercentage = map(value,1200,1050,0,100);
  Blynk.virtualWrite(V0, soilmoisturepercentage);
  Serial.print("Soil Moisture : ");
  Serial.print(soilmoisturepercentage);
 
}
