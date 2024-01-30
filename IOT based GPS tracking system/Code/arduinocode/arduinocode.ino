#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
const char *ssid = "SMART-G";  
const char *password = "10112019"; 
const char *host = "https://myprojectfinal.in";   


void setup() {
  delay(1000);
  Serial.begin(9600);
  WiFi.mode(WIFI_OFF);        
  delay(1000);
  WiFi.mode(WIFI_STA);  
  WiFi.begin(ssid, password);     
  Serial.println(""); 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print("*");
  } 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
  delay(1000);
 
  
}
void loop() 
{

 while(Serial.available())
{  
           
//HTTPClient http;  
  String postData;  
  String key = Serial.readString();
  Serial.print(key);
//  postData = "uname=" + key;  
//   http.begin("http://myprojectfinal.in/healthm1/view.php");            
//  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
//  int httpCode = http.POST(postData);   
//  String payload = http.getString();
//  Serial.println(payload);
//  http.end();    
//  delay(1000);
      
HTTPClient http;  
//String postData;  
postData ="uname= "+String(key);  
http.begin("http://patient.fantasysolution.in/miethome.php");            
http.addHeader("Content-Type", "application/x-www-form-urlencoded");
int httpCode = http.POST(postData);   
String payload = http.getString();
 
  http.end();  
      
  //Serial.println(payload);  
delay(1000);     

  HTTPClient http1;  
  String postData1;  
  //String key1 = Serial.readString();
    postData1 = "username=fantasy&password=596692&to=8124417446&from=FSSMSS&message=Dear user  your msg is "+String(key)+" Sent By FSMSG FSSMSS&PEID=1501563800000030506&templateid=1507162882948811640";
     Serial.print(postData);
   http1.begin("http://smsserver9.creativepoint.in/api.php");        
  http1.addHeader("Content-Type", "application/x-www-form-urlencoded");
  int httpCode1 = http1.POST(postData1);   
  String payload1 = http1.getString();
  //Serial.println(payload);
  http.end();    
  delay(1000);
  
}
}

