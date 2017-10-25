#include <ESP8266WiFi.h>

String  i;
int code=0;
WiFiServer server(80);

void setup()
{
  i = "";

  Serial.begin(9600);
Serial.println("START");
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(16, OUTPUT);
    WiFi.disconnect();
    delay(2000);
    Serial.println("Start Client");
   WiFi.begin("Pytron","pytron123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(1000);
    Serial.println(">>");

  }
  Serial.println("Connected");
  Serial.println((WiFi.localIP()));
  server.begin();
   WiFi.begin("Pytron","pytron123");
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
      digitalWrite(5,HIGH);
      delay(500);
      digitalWrite(16,HIGH);
      delay(500);
      digitalWrite(4,HIGH);
      delay(500);
      break;

      case 910:
      digitalWrite(4,LOW);
      delay(500);
      digitalWrite(16,LOW);
      delay(500);
      digitalWrite(5,LOW);
      delay(500);
      break;
    }
}
