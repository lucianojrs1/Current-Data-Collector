#include <Arduino.h>

const int adcPin = A1;
const float vRef = 5.0;     // Tensão da alimentação (meça com multímetro se puder)
const float shuntR = 0.33;  // Resistor de teste
const float ganhoAop = 100.0; // Ganho que você definiu

void setup() {
  Serial.begin(9600);
  Serial.println("--- Iniciando Leitura ---");
}

void loop() {
  // 1. Ler o valor bruto (0 a 1023)
  int valorAnalog = analogRead(adcPin);
  
  // 2. Converter para Tensão na Saída do Op-Amp
  float saidaAop = valorAnalog * (vRef / 1023.0);
  
  // 3. Descobrir tensão original no Shunt (remover o ganho)
  float tensaoShunt = saidaAop / ganhoAop;
  
  // 4. Calcular Corrente (Lei de Ohm)
  float corrente = tensaoShunt / shuntR;

  // --- MOSTRAR NO MONITOR SERIAL ---
  Serial.print("ADC: ");
  Serial.print(valorAnalog);
  
  Serial.print(" | V_Saida: ");
  Serial.print(saidaAop, 3); // 3 casas decimais
  Serial.print("V");
  
  Serial.print(" | Corrente: ");
  Serial.print(corrente * 1000, 1); // Mostra em mA para facilitar leitura
  Serial.println(" mA");

  delay(500);
}