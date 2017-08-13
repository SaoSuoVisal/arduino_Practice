 #include <ESP8266WiFi.h>

const char* uuid = "Pum Veasna";
const char* password = "012338558";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(D8, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D5, OUTPUT);
  
  Serial.print("Connacting to: ");
  Serial.println(uuid);
  WiFi.begin(uuid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("");
  Serial.print("WiFi Connected to ");
  Serial.println(uuid);

  server.begin();
  Serial.println("The server is ready Sir!");

  Serial.print("Open: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  if (request.indexOf("/LED=ONB") != -1) {
    digitalWrite(D8, HIGH);
  }

  if (request.indexOf("/LED=OFFB") != -1) {
    digitalWrite(D8, LOW);
  }

  if (request.indexOf("/LED=ONR") != -1) {
    digitalWrite(D7, HIGH);
  }

  if (request.indexOf("/LED=OFFR") != -1) {
    digitalWrite(D7, LOW);
  }

  if (request.indexOf("/LED=ONG") != -1) {
    digitalWrite(D6, HIGH);
  }

  if (request.indexOf("/LED=OFFG") != -1) {
    digitalWrite(D6, LOW);
  }

  if (request.indexOf("/LED=ONY") != -1) {
    digitalWrite(D5, HIGH);
  }

  if (request.indexOf("/LED=OFFY") != -1) {
    digitalWrite(D5, LOW);
  }

  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(D8, HIGH);
  }

  if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(D8, LOW);
  }

  //HTML site
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<body>");
  client.println("<center>");
    client.println("<a href =\"/LED=ON\"\"><button>Turn All On</button></a>");
    client.println("<a href =\"/LED=OFF\"\"><button>Turn All Off</button></a>");
    client.println("</br>");
    
    client.println("<a href =\"/LED=ONB\"\"><button>Turn On Blue</button></a>");
    client.println("<a href =\"/LED=OFFB\"\"><button>Turn Off Blue</button></a>");
    client.println("</br>");
    
    client.println("<a href =\"/LED=ONR\"\"><button>Turn On Red</button></a>");
    client.println("<a href =\"/LED=OFFR\"\"><button>Turn Off Red</button></a>");
    client.println("</br>");
    
    client.println("<a href =\"/LED=ONG\"\"><button>Turn On Green</button></a>");
    client.println("<a href =\"/LED=OFFG\"\"><button>Turn Off Green</button></a>");
    client.println("</br>");
    
    client.println("<a href =\"/LED=ONY\"\"><button>Turn On Yellow</button></a>");
    client.println("<a href =\"/LED=OFFY\"\"><button>Turn Off Yellow</button></a>");
  client.println("</center>");
  client.println("</body>");
  client.println("</html>");
  delay(10);
}
