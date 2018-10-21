#include <DHT.h>#include <DHT_U.h>
#include <ESP8266WiFi.h>


#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 22  (AM2302)

const char* server = "weris.link"; // alamat server
const char* ssid = "Pinrolinvic"; // SSID router wifi
const char* password = "qqqqqqqqq"; // password wifi
const char* SensorID = "Helle.lokasisaya.DHT11"; // ID sensor

int segel = 0;

DHT dht(DHTPIN, DHTTYPE);
 
WiFiClient client;
 
void setup() {
  Serial.begin(115200);
  delay(10);
  dht.begin();
    
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, HIGH);
 
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  }
 
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal membaca sensor DHT");
    return;
  }
  // kalu sukses lanjut
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C. Humidity: ");
  Serial.println(h);
  
  // mulai Kirim data sensor
  if (client.connect(server,80)) {
    Serial.print("Posting data...");
    digitalWrite(BUILTIN_LED, LOW);
    Serial.println("Temperature: " + String(t) + ", Humidity: " + String(h));
    
    // dengan GET /path file php penangkap data
    client.println("GET /iot/terima.php?data1=" + String(t) + "&data2=" + String(h) + "&sid=" +SensorID+ " HTTP/1.1");
    client.println("HOST: weris.link");
    client.println("Connection: close");
    client.println();
    client.stop();
    Serial.println();
    digitalWrite(BUILTIN_LED, HIGH);
  } else {
    Serial.println("Koneksi ke server gagal");
  }
  delay(5000); // delay untuk jeda posting.
}
