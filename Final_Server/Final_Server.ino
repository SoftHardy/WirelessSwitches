#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include<elapsedMillis.h>

String  i;
int code;
WiFiServer server(80);

String  httpurl;
HTTPClient http;

elapsedMillis timer0;
#define interval 1000

void setup()
{
  
  i = "";
  
  Serial.begin(9600);

Serial.println("START");
    WiFi.disconnect();
  delay(2000);
  Serial.println("Start Server");
   WiFi.begin("Pytron","pytron123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(1000);
    Serial.println(">>");

  }
  Serial.println("Connected");
  Serial.println((WiFi.localIP()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) {Serial.println("IF !CLIENT"); return; }
    timer0=0;
    while(!client.available()){ 
      if (timer0 > interval) {
        return;
    }
    
    
    Serial.println("WHILE !CLIENT.AVAILABLE"); delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    code=i.toInt();
    Serial.println(code);  
    switch(code){
      case 111:
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="111";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

      case 110:
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="110";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

      case 112:
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="112";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

      case 211:
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="211";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

      case 210:
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="210";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      
      case 711:
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="711";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      
      case 710:
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="710";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      
      case 721:
      httpurl = "http://";
      httpurl+="192.168.1.108";   
      httpurl+="/";
      httpurl+="721";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      
      case 720:
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="720";
      http.begin(httpurl);
      http.GET();
      http.end(); 
      break;
      
      case 731:
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="731";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      
      case 730:
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="730";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      
      case 741:
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="741";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      
      case 740:
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="740";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

      case 751:
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="751";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

      case 750:
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="750";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

      case 911:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="911";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

      case 910:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

//////////////////---------------------------------------------------------MOODS--------------------------------------------/////////////////////////////////////

////////////////////////////////////////////////ALARMED MOOD ON///////////////////////////////////////////////
      
          //*****************CHANDELIER******************
      case 5011:
      Serial.println("5011/sdjbbsdv");
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5011";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5011";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5011";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5011";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

/////////////////////////////////////ALARMED MOOD OFF//////////////////////////////////
      case 5010:
      Serial.println("5010/dkndcd");
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="911";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5010";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5010";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5010";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5010";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      

///////////////////////////////////SUNSET MOOD ON//////////////////////////////////////
      case 5021:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="911";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5021";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5021";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5021";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5021";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

////////////////////////////////////SUNSET MOOD OFF///////////////////////////////////////
      case 5020:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5020";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5020";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5020";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5020";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

////////////////////////////////////////////MOVIE MOOD ON//////////////////////////////////
      case 5031:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5031";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5031";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5031";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5031";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

////////////////////////////////////////////////////////////MOVIE MOOD OFF///////////////////////////////////////////
      case 5030:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="911";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5030";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5030";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5030";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5030";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

//////////////////////////////////////////////////SLEEPING MOOD ON///////////////////////////////////////////////////////
      case 5041:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5041";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5041";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5041";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5041";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

////////////////////////////////////////////////////////SLEEPING MOOD OFF////////////////////////////////////////////////
      case 5040:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5040";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5040";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5040";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5040";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

/////////////////////////////////////////////////////////WAKEY WAKEY MOOD ON////////////////////////////////////
      case 5051:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5051";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5051";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5051";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5051";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

//////////////////////////////////////////////////////////WAKEY WAKEY MOOD OFF///////////////////////////////////////////////
      case 5050:
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5050";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5050";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5050";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5050";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;

////////////////////////////////////////////////////////////DEFAULT MOOD////////////////////////////////////////
      case 5000:
      Serial.println("5000/c ,vnccnddc");
      httpurl = "http://";
      httpurl+="192.168.1.106";
      httpurl+="/";
      httpurl+="910";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.108";
      httpurl+="/";
      httpurl+="5000";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.109";
      httpurl+="/";
      httpurl+="5000";
      http.begin(httpurl);
      http.GET();
      http.end();
      httpurl = "http://";
      httpurl+="192.168.1.110";
      httpurl+="/";
      httpurl+="5000";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
      httpurl = "http://";
      httpurl+="192.168.1.111";
      httpurl+="/";
      httpurl+="5000";
      http.begin(httpurl);
      http.GET();
      http.end();
      break;
    }

      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
}
