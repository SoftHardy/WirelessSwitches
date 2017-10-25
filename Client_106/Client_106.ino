#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
String  i;
int code=0;
String  httpurl;
HTTPClient http;

WiFiServer server(80);

void setup()
{
  i = "";

  Serial.begin(9600);

  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  WiFi.disconnect();
  delay(2000);
  Serial.println("Start Client");
   WiFi.begin("Pytron","pytron123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(1000);
    Serial.println(">>");

  }
  Serial.println("Connected");
  Serial.println("My IP is:");
  Serial.println((WiFi.localIP()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    code=i.toInt();
    Serial.println(code);
    switch(code){
      case 911:
      digitalWrite(16,HIGH);
      delay(1000);
      digitalWrite(4,HIGH);
      delay(500);
      digitalWrite(5,HIGH);
      delay(500); 
       
      httpurl = "http://";
      httpurl+="192.168.1.105";
      httpurl+="/";
      httpurl+="CHANDELIER_ON";
      http.begin(httpurl);
      http.GET();
      http.end();
      
      httpurl = "http://";
      httpurl+="192.168.1.104";
      httpurl+="/";
      httpurl+="911";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

      case 910:
      httpurl = "http://";
      httpurl+="192.168.1.104";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      
      httpurl = "http://";
      httpurl+="192.168.1.105";
      httpurl+="/";
      httpurl+="CHANDELIER_OFF";
      http.begin(httpurl);
      http.GET();
      http.end();
      
      digitalWrite(5,LOW);
      delay(500);
      digitalWrite(4,LOW);
      delay(1000);
      digitalWrite(16,LOW);
      delay(500);
      break;

    }
    
}
