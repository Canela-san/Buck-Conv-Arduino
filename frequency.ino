#include <FreqMeasure.h>

const int potPin = A0;    // Pino analógico para conectar o potenciômetro

void setup() {
  pinMode(potPin, INPUT);

  // Inicializa a biblioteca FreqMeasure
  FreqMeasure.begin();
}

void loop() {
  // Lê o valor do potenciômetro
  int potValue = analogRead(potPin);
  
  // Converte o valor do potenciômetro para um valor de frequência (Hz)
  int frequency = map(potValue, 0, 1023, 100, 5000); // Mapeia o valor para um intervalo de frequência desejado
  
  // Define a frequência de PWM usando a biblioteca FreqMeasure
  FreqMeasure.end();
  FreqMeasure.begin();
  FreqMeasure.setFrequency(frequency);
}

