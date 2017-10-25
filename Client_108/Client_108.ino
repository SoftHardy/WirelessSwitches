ron
///////////////////////////////////////////////////////Light L2-pin16/////////////////////////////////////////////
//////////////////////////////////////////////////////   AC-pin5    //////////////////////////////////////////////

#include <ESP8266WiFi.h>
 
String  i;
int code=0;
WiFiServer server(80);

void setup()
{
  i = "";

  Serial.begin(9600);

  pinMode(16, OUTPUT);
  pinMode(5, OUTPUT);
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
  WiFi.hostname("Client_108") ;
  Serial.println("My host name is:");
  Serial.println((WiFi.hostname()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){ 
    delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    code=i.toInt();
    Serial.println(code);

    switch(code){
      case 211:
      digitalWrite(5,HIGH);
      break;
      case 210:
      digitalWrite(5,LOW);
      break;

      case 721:
      digitalWrite(16,HIGH);
      break;
      case 720:
      digitalWrite(16,LOW);
      break;

////////////////////---------------------------------------------------MOODS-------------------------------------------------------//////////////////////////////

/////////////////////////////////////////ALARMED MOOD/////////////////////////////////////////
      case 5011:
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      break;
      case 5010:
      digitalWrite(16,HIGH);
      digitalWrite(5,HIGH);
      break;

/////////////////////////////////////////SUNSET MOOD/////////////////////////////////////////
      case 5021:
      digitalWrite(16,HIGH);
      digitalWrite(5,HIGH);
      break;
      case 5020:
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      break;

/////////////////////////////////////////MOVIE MOOD/////////////////////////////////////////
      case 5031:
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      break;
      case 5030:
      digitalWrite(16,HIGH);
      digitalWrite(5,HIGH);
      break;

/////////////////////////////////////////SLEEPING MOOD/////////////////////////////////////////
      case 5041:
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      break;
      case 5040:
      digitalWrite(16,HIGH);
      digitalWrite(5,HIGH);
      break;

/////////////////////////////////////////WAKEY WAKEY MOOD/////////////////////////////////////////
      case 5051:
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      break;
      case 5050:
      digitalWrite(16,LOW);
      digitalWrite(5,HIGH);
      break;

/////////////////////////////////////////DEFAULT MOOD/////////////////////////////////////////
      case 5000:
      digitalWrite(16,HIGH);
      digitalWrite(5,HIGH);
      break;
    }
}
