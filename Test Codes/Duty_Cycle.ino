const int potPin = A0;    // Pino analógico para conectar o potenciômetro
const int pwmPin = 9;    // Pino PWM de saída

void setup() {
  pinMode(potPin, INPUT);
  pinMode(pwmPin, OUTPUT);

  // Defina a frequência desejada (exemplo: 1000 Hz)
  analogWriteFreq(1000);
}

void loop() {
  // Lê o valor do potenciômetro
  int potValue = analogRead(potPin);
  
  // Converte o valor do potenciômetro para um valor PWM (0 a 255)
  int pwmValue = map(potValue, 0, 1023, 0, 255);
  
  // Define o ciclo de trabalho no pino PWM
  analogWrite(pwmPin, pwmValue);
  
  delay(20); // Pequeno atraso para evitar flutuações rápidas
}

