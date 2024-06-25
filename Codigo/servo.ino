#include <Servo.h> // Inclui a biblioteca do Servo

Servo myservo;  // Cria o objeto do servo
const int servoPin = 10;  // Define a porta do servo
int pos = 0; // Posição inicial do servo

void setup() {
  myservo.attach(servoPin);  // Anexa o servo ao pino especificado
}

void loop() {
  delay(1000); 
  // Move o servo de 0 a 90 graus
  for (pos = 0; pos <= 120; pos += 1) {
    myservo.write(pos);
    delay(5); // Reduzido o delay para aumentar a velocidade
  }
  // Move o servo de 90 a 0 graus
  for (pos = 120; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(5); // Reduzido o delay para aumentar a velocidade
  }
}
