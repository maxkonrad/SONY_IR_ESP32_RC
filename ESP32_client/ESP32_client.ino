#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#define IR_SEND_PIN 4
#include <IRremote.h>

const char* ssid = "TurkTelekom_ZT45P2_2.4GHz";
const char* password = "*******";
const int port = 8080;

IPAddress ip(192, 168, 1, 186);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

AsyncWebServer server(port);
  
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("WiFi bağlantısı bekleniyor...");
  }
  WiFi.config(ip, gateway, subnet);
  server.on("/operate", HTTP_POST, handleOperate);
  server.on("/volup", HTTP_POST, handleVolUp);
  server.on("/voldown", HTTP_POST, handleVolDown);
  server.on("/play", HTTP_POST, handlePlay);
  server.on("/pause", HTTP_POST, handlePause);
  server.on("/stop", HTTP_POST, handleStop);
  server.begin();
}

void handleOperate(AsyncWebServerRequest *request){
  if(request->method() == HTTP_POST){
    IrSender.sendSony(0x44, 0x15, 2, 15);
    Serial.println("Açılıyor");
    request->send(200);
  }
}

void handleVolUp(AsyncWebServerRequest *request){
  if(request->method() == HTTP_POST){
    IrSender.sendSony(0x44, 0x12, 2, 15);
    Serial.println("Ses Artırılıyor");
    request->send(200);
  }
}

void handleVolDown(AsyncWebServerRequest *request){
  if(request->method() == HTTP_POST){
    IrSender.sendSony(0x44, 0x13, 2, 15);
    Serial.println("Ses Azaltılıyor");
    request->send(200);
  }
}

void handlePlay(AsyncWebServerRequest *request){
  if(request->method() == HTTP_POST){
    IrSender.sendSony(0x64, 0x32, 2, 15);
    Serial.println("Müzik Oynatılıyor");
    request->send(200);
  }
}

void handlePause(AsyncWebServerRequest *request){
  if(request->method() == HTTP_POST){
    IrSender.sendSony(0x64, 0x39, 2, 15);
    Serial.println("Müzik Duraklatılıyor");
    request->send(200);
  }
}

void handleStop(AsyncWebServerRequest *request){
  if(request->method() == HTTP_POST){
    IrSender.sendSony(0x64, 0x38, 2, 15);
    Serial.println("Müzik Durduruluyor");
    request->send(200);
  }
}

void loop() {}
