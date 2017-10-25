//////////////////////////////////////////////////////   Light L1-pin4    ////////////////////////////////////////////
/////////////////////////////////////////////////////    Light L3-pin5   ////////////////////////////////////////////
////////////////////////////////////////////////////     Light L4-pin16 ////////////////////////////////////////////

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
    while(!client.available()){       
     delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    code=i.toInt();
    Serial.println(code);
    switch(code){
      case 711:
      digitalWrite(4,HIGH);
      break;
      case 710:
      digitalWrite(4,LOW);
      break;

      case 731:
      digitalWrite(5,HIGH);
      break;
      case 730:
      digitalWrite(5,LOW);

      case 741:
      digitalWrite(16,HIGH);
      break;
      case 740:
      digitalWrite(16,LOW);
      break;
////////////////////////////////////---------------------------------------------------MOODS-------------------------------------------------------//////////////////////////////

/////////////////////////////////////////ALARMED MOOD/////////////////////////////////////////
      case 5011:
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      break;
      case 5010:
      digitalWrite(16,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
      break;

/////////////////////////////////////////SUNSET MOOD/////////////////////////////////////////
      case 5021:
      digitalWrite(16,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
      break;
      case 5020:
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      break;

/////////////////////////////////////////MOVIE MOOD/////////////////////////////////////////
      case 5031:
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      break;
      case 5030:
      digitalWrite(16,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
      break;

/////////////////////////////////////////SLEEPING MOOD/////////////////////////////////////////
      case 5041:
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      break;
      case 5040:
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      break;

/////////////////////////////////////////WAKEY WAKEY MOOD/////////////////////////////////////////
      case 5051:
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      break;
      case 5050:
      digitalWrite(16,LOW);
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      break;

/////////////////////////////////////////DEFAULT MOOD/////////////////////////////////////////
      case 5000:
      digitalWrite(16,HIGH);
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
      break;
    }

}
