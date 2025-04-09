#include <Wire.h> // Importando a biblioteca do sensor de água

const int sensorChuva = 34; // Pino conectado ao A0 do módulo

void setup() {
  Serial.begin(115200); // Velocidade da comunicação serial para o esp32
  pinMode(sensorChuva, INPUT); // GPIO 34, ler informações
}

void loop() {
  // Inicializando a leitura do sensor de chuva
  int valor = analogRead(sensorChuva); // Lê valor entre 0 e 4095

  // Apresentando o valor
  Serial.print("Leitura do sensor de chuva: ");
  Serial.println(valor);

  // Condição para dizer que tem chuva
  if (valor>0) {
    Serial.println("💧 Chuva detectada!");
  } else {
    Serial.println("☀️ Seco!");
  }
  delay(2000); // delay de 2 segundos para apresentar os dados lidos do sensor
}
