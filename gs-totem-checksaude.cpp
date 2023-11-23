#include <ArduinoJson.h>
#include <EspMQTTClient.h>
#include "DHTesp.h"

EspMQTTClient client{
  "Wokwi-GUEST", // SSID do WiFi
  "",            // Senha do WiFi
  "mqtt.tago.io",  // Endereço do servidor MQTT
  "Default",       // Nome de usuário MQTT
  "e2307269-561d-42c0-820c-47d4c5082394", // Token do dispositivo MQTT
  "Hospital Santa Cecilia 1", // Nome do dispositivo MQTT
  1883             // Porta de comunicação MQTT
};

void onConnectionEstablished() {
  // Ação a ser realizada quando a conexão é estabelecida
}

StaticJsonDocument<300> documentoJson;

const int DHT_PIN = 15;
int poten1 = 34;
int poten2 = 36;
int microfone = 35;
int camera = 32;

int mic = 0;
int cam = 0;
int valorpoten1 = 0;
int valorpoten2 = 0;
DHTesp dhtSensor;

TempAndHumidity data;  // Declaração da variável fora do loop

void setup() {
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
}

void loop() {
  delay(100);
  // Pegando valor Temperatura
  data = dhtSensor.getTempAndHumidity();
  // Pegando valor Pressão
  valorpoten1 = analogRead(poten1);
  valorpoten2 = analogRead(poten2);
  Serial.println(valorpoten1);
  Serial.println(valorpoten2);

  // Pegando dados Microfone
  mic = analogRead(microfone);
  // Pegando dados Camera
  cam = analogRead(camera);

  // Imprimindo informações
  Serial.println("Temperatura: " + String(data.temperature, 2) + "°C");
  Serial.println("Pressão SIS: " + String(valorpoten1) + "mmHg");
  Serial.println("Pressão DIA: " + String(valorpoten2) + "mmHg");
  Serial.print("Microfone: ");
  Serial.println(mic);
  Serial.print("Camera: ");
  Serial.println(cam);
  Serial.println("---");

  sendInfo();

  // Aguarde por um intervalo de tempo
  delay(5000);
}

// Envio dos dados
void sendInfo() {
  documentoJson.clear();
  documentoJson["variable"] = "temperatura";
  documentoJson["value"] = data.temperature;
  enviarDados("topicTemperatura");

  documentoJson.clear();
  documentoJson["variable"] = "pressaoSIS";
  documentoJson["value"] = valorpoten1;
  enviarDados("topicPressaoSIS");

  documentoJson.clear();
  documentoJson["variable"] = "pressaoDIA";
  documentoJson["value"] = valorpoten2;
  enviarDados("topicPressaoDIA");

  documentoJson.clear();
  documentoJson["variable"] = "microfone";
  documentoJson["value"] = mic;
  enviarDados("topicMicrofone");

  documentoJson.clear();
  documentoJson["variable"] = "camera";
  documentoJson["value"] = cam;
  enviarDados("topicCamera");
}

// Função para enviar dados via MQTT
void enviarDados(const char* topico) {
  String dadosJson;
  serializeJson(documentoJson, dadosJson);
  Serial.println(dadosJson);
  client.publish(documentoJson["variable"], dadosJson);
  client.loop();
}