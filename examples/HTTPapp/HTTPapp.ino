#include <ESP8266WiFi.h>

int led = 8; //D8 

const char* ssid = "Aks"; 
const char* password = "simple1234"; 
WiFiServer server(80); //Define web server port

void setup() {
  Serial.begin(115200);
  Serial.println();
  
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  
  //Connecting to Wifi
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  //Loading to connect
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  //Connected
  Serial.println("");
  Serial.print("WiFi Connected");

  //Initialized the connection
  server.begin();
  Serial.println("Sever is ready Sir!");

  //Display IP address
  Serial.print("Server start at: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  //See if there is someone in the page
  WiFiClient client = server.available();
  if(!client){
    return;
  }
  //Wait fro data
  Serial.println("new Client");
  while(!client.available()){
    delay(1);
  }
  
  //Get input from user
  String request = client.readStringUntil('\r');

  //Conpair of the request 
  if(request.indexOf("/on") != -1){
    digitalWrite(led, HIGH);
  }

  if(request.indexOf("/off") != -1){
    digitalWrite(led, LOW);
  }

  //HTML site
  client.println("HTTP/1.1 200 OK");  //HTML Header
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
    client.println("<center>");
      client.println("<a href = \"/on\"\"><button>Turn On</button></a>");
      client.println("<a href = \"/off\"\"><button>Turn Off</button></a>");
    client.println("</center>");
  client.println("</html>");
  delay(10);
}
//https://www.youtube.com/watch?v=_mIDsAo3DA0 
