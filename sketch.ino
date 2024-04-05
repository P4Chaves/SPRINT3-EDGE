#include <WiFi.h>
#include <PubSubClient.h>

const int pinPotenciometro = 34;  // Pino para o potenciômetro
const int pinNTC = 35;            // Pino para o sensor temperatura
const int pinBuzzer = 27;          // Pino para o buzzer

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() { 
  delay(10);
  Serial.println();
  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA); 
  WiFi.begin("Wokwi-GUEST", ""); // SSID e senha da rede WiFi
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address:");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) { 
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) { 
    Serial.print((char)payload[i]);
  }
}

void reconnect() { 
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      client.publish("/ThinkIOT/Publish", "Welcome");
      client.subscribe("/ThinkIOT/Subscribe"); 
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(pinBuzzer, OUTPUT);
  Serial.begin(115200);
  setup_wifi(); 
  client.setServer("test.mosquitto.org", 1883); // MQTT broker
  client.setCallback(callback); 
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Leitura do potenciômetro
  int valorPotenciometro = analogRead(pinPotenciometro);
  // Mapeia o valor do potenciômetro para uma faixa de frequência cardíaca
  int frequenciaCardiaca = map(valorPotenciometro, 0, 4095, 40, 150);

  // Leitura do sensor NTC
  int valorNTC = analogRead(pinNTC);
  // Converte o valor do NTC para temperatura em graus Celsius
  float temperatura = mapeiaTemperatura(valorNTC);

  // Envia os dados para o MQTT
  char message[50];
  snprintf(message, 50, "%d", frequenciaCardiaca);
  client.publish("/Thinkitive/frequenciaCardiaca", message);
  snprintf(message, 50, "%.2f", temperatura);
  client.publish("/Thinkitive/temperatura", message);

  // Verifica se a frequência cardíaca está fora da faixa ideal 
  if (frequenciaCardiaca < 60 || frequenciaCardiaca > 100) {
    // Emite um alerta sonoro usando o buzzer
    digitalWrite(pinBuzzer, HIGH);
    delay(500);  // Mantém o alerta sonoro por 0,5 segundos
    digitalWrite(pinBuzzer, LOW);
  }

  // Verifica se a temperatura está fora da faixa ideal
  if (temperatura < 36 || temperatura > 38) {
    // Emite um alerta sonoro usando o buzzer
    digitalWrite(pinBuzzer, HIGH);
    delay(500);  // Mantém o alerta sonoro por 0,5 segundos
    digitalWrite(pinBuzzer, LOW);
  }

  delay(1000);  // Aguarda 1 segundo antes de ler novamente
}

// Função para converter a leitura do NTC para temperatura em graus Celsius
float mapeiaTemperatura(int leitura) {
  return map(leitura, 0, 4095, 20, 45); 
}