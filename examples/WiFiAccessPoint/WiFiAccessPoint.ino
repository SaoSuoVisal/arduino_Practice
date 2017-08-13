
/* Create a WiFi access point and provide a web server on it. */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "Nodemuc_EPS8266";
const char *password = "node";

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
 String body ="<!DOCTYPE html> <html> <head> <title>LEDS</title> </head> <body> <button name=\"ledOn\">On</button> <button name=\"ledOff\">Off</button> </body> </html>";

	server.send(200, "text/html", body);
} 

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();
	Serial.print("Configuring access point...");
	/* You can remove the password parameter if you want the AP to be open. */
	WiFi.softAP(ssid, password); // Set up a soft access point to establish a Wi-Fi network.

	IPAddress myIP = WiFi.softAPIP(); // Return IP address of the soft access point’s network interface.
  /* AC: Access Point is a station that transmits and receives data!
    https://images-na.ssl-images-amazon.com/images/I/31juqcXXbiL.jpg */
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/server", handleRoot);
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
  int numSta; 
  if(WiFi.softAPgetStationNum()){
    if(WiFi.softAPgetStationNum() != numSta){
      numSta = WiFi.softAPgetStationNum();
      Serial.println("Number of connector: ");
      Serial.println(numSta);
    }
  }
}
