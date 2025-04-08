#include "DHT.h" // Importando a biblioteca DHT - Adafruit

#define DHTPIN 15    // Pino conectado ao DATA do DHT11
#define DHTTYPE DHT11  // Tipo do sensor

DHT dht(DHTPIN, DHTTYPE); // Criando os objetos DHT

// Verificar se um número é primo
#define MAXN 100
bool erastotenes[MAXN];

void crivo(){
  memset(erastotenes, true, sizeof(erastotenes));
  erastotenes[0] = false, erastotenes[1] = false;
  for(int i = 2; i * i <= MAXN; i++){
    if(erastotenes[i]){
      for(int j = i; j <= MAXN; j += i){
        erastotenes[j] = false;
      }
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Lendo dados do DHT11...");
  crivo();
}

void loop() {
  float temp = dht.readTemperature();     // Temperatura em Celsius
  float umid = dht.readHumidity();        // Percentual de umidade
  // Para ver se deu alguma falha na leitura dos dados
  if (isnan(temp) || isnan(umid)) {
    Serial.println("Falha ao ler do DHT11 😓");
    delay(2000);
    return;
  }
  // Mostrando os dados de temperatura e umidade
  Serial.print("Temperatura: ");
  Serial.print(int(temp));
  Serial.println(" °C");

  Serial.print("Umidade: ");
  Serial.print(int(umid));
  
  Serial.println(" %");
  Serial.println("--------Análise--------");
  // Pequena análise diretamente do sensor
  if(temp <= 25.00){
    Serial.println("Frio vey❄️");
  }else{
    Serial.println("Tá quente fi🥵");
  }

  if(umid > 50.00){
    Serial.println("Que delicia😌");
  }else{
    Serial.println("Ai☠️");
  }

  if(erastotenes[int(temp)]){
    Serial.println("Oloco, a temperatura eh um numero primo!!");
  }else{
    Serial.println("Nah, a temperatura não eh um numero primo:(");
  }
  Serial.println();
  Serial.println("-----------------------");
  Serial.println("                       ");
  delay(3000);
}
