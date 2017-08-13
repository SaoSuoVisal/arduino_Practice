

/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>


/* Set these to your desired credentials. */
const char *ssid = "Visal's";
const char *password = "visal0202";

WiFiServer server(80);
String body ="<!DOCTYPE html> <html> <head> <title>LEDS</title> </head> <body> <button name=\"ledOn\" onClick = \"/#\"value = \"on\">On</button> <button name=\"ledOff\" value = \"off\">Off</button> </body> </html>";

void setup() {
  Serial.begin(115200);
  Serial.println();
  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); 

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  
  Serial.print("Successfuly Connected");
  server.begin();
  Serial.println("Server is at: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();

  if(client.available()){
    Serial.println("Input");
    char d = client.read();
    if(d){
      Serial.println(d);
    }else{
      Serial.println("Nothing in d");
    }
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println(body);
  delay(10);
}
