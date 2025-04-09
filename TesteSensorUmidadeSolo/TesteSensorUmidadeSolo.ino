// O sensor não precisa de biblioteca (inda bem)

const int sensorSolo = 34; // Pino conectado à saída A0 do sensor

void setup() {
  Serial.begin(115200);
  pinMode(sensorSolo, INPUT); // OPIO 34, marcado como leitura do sensor
}

void loop() {
  int valor = analogRead(sensorSolo); // Leitura analógica (0–4095)
  
  // Apresenta os valores lidos pelo sensor
  Serial.print("Umidade do solo: ");
  Serial.println(valor);

  // Informando o resultado do processamento de dados
  if (valor < 1500) {
    Serial.println("🌱 Solo úmido!");
  } else if (valor < 3000) {
    Serial.println("😐 Solo moderadamente seco.");
  } else {
    Serial.println("💀 Solo seco! Precisa regar.");
  }

  delay(2000); // Ele demora 2 segundos para atualizar
}
