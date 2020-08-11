#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "DHT.h"

//WIFI
#define wifi_ssid "IoT"
#define wifi_password "653)k40C"

//----------------- COD MQTT -------------------//
#define TOPICO_PUBLISH   "temp"    //tópico MQTT de envio de informações para Broker
#define ID_MQTT  "sensor_teste"     //id mqtt (para identificação de sessão), unico para cada esp
#define MQTT_USER "coxedkdn" //usuario do broker MQTT
#define MQTT_PASSWD "moDbPbDXEY1K" //senha do usuario MQTT do broker

//---------------------------------

// Define pinos do ESP8266 - NodeMCU
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define D9 3
#define D10 1

#define DHTPIN 2          //pin where the dht11 is connected

DHT dht(DHTPIN, DHT11);

WiFiClient espClient_normal; //permite utilizar IP e porta
WiFiClientSecure espClient;

const char* BROKER_MQTT = "m12.cloudmqtt.com"; //URL do broker MQTT que se deseja utilizar
int BROKER_PORT = 10709; // Porta do Broker MQTT


// ------ MQTT ------------------------------------------------------------------------------------------------------
PubSubClient MQTT(espClient_normal); // Instancia o Cliente MQTT passando o objeto espClient

//Função: inicializa parâmetros de conexão MQTT(endereço do 
//        broker, porta e seta função de callback)
//Parâmetros: nenhum
//Retorno: nenhum
void initMQTT() 
{
    MQTT.setServer(BROKER_MQTT, BROKER_PORT);   //informa qual broker e porta deve ser conectado
}

//Função: reconecta-se ao broker MQTT (caso ainda não esteja conectado ou em caso de a conexão cair)
//        em caso de sucesso na conexão ou reconexão, o subscribe dos tópicos é refeito.
//Parâmetros: nenhum
//Retorno: nenhum
void reconnectMQTT() 
{
    while (!MQTT.connected()) 
    {
        Serial.print("* Tentando se conectar ao Broker MQTT: ");
        Serial.println(BROKER_MQTT);
        if (MQTT.connect(ID_MQTT, MQTT_USER, MQTT_PASSWD)) 
        //if (MQTT.connect(ID_MQTT)) 
        {
            Serial.println("Conectado com sucesso ao broker MQTT!");
            //MQTT.subscribe(TOPICO_SUBSCRIBE); 
        } 
        else 
        {
            Serial.println("Falha ao reconectar no broker.");
            Serial.println("Havera nova tentatica de conexao em 2s");
            delay(2000);
        }
    }
}

//Função: verifica o estado das conexões WiFI e ao broker MQTT. 
//        Em caso de desconexão (qualquer uma das duas), a conexão
//        é refeita.
//Parâmetros: nenhum
//Retorno: nenhum
void VerificaConexoesWiFIEMQTT(void)
{
    if (!MQTT.connected()) 
        reconnectMQTT(); //se não há conexão com o Broker, a conexão é refeita
}



//MQTT fim

void reconnect() {
  // Loop eterno até conectar no mqtt broker/wifi
  while (espClient.connected()) {
    Serial.print("Tentando conectar...");
    delay(5000);
    if (!espClient.connected())
      break;
  }
  Serial.println("Conectado");
}


void setup_wifi() {
  delay(10);
  // Conecta na WiFi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectada");
  Serial.println("Endereco IP: ");
  Serial.println(WiFi.localIP());

  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  setup_wifi();
  // ---- MQTT ----
  initMQTT(); 

}

void loop() {
  // put your main code here, to run repeatedly:
  if(espClient.connected()) {
    reconnect();
  }

  //----- MQTT ---------
  VerificaConexoesWiFIEMQTT();
  
   float h = dht.readHumidity();
   float t = dht.readTemperature();

   // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");

  MQTT.publish("dht11/umidade", String(h).c_str());
  MQTT.publish("dht11/temperatura", String(t).c_str());
  
  MQTT.loop();
  delay(1000);

}
