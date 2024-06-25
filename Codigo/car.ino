#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth não está habilitado! Por favor, execute make menuconfig para habilitá-lo
#endif

BluetoothSerial SerialBT; // Objeto para comunicação Bluetooth

#define enA 13
#define in1 12
#define in2 14

#define in3 27
#define in4 26
#define enB 25

int xAxis = 140, yAxis = 140; // Valores padrão do joystick

int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600); // Inicializa comunicação serial com o monitor serial
  SerialBT.begin("jjj"); // Inicializa a comunicação Bluetooth com o nome "jjj"
  Serial.println("O dispositivo está pronto para parear");
}

void loop() {
  // Valor padrão - sem movimento quando o Joystick está no centro
  // xAxis = 140;
  // yAxis = 140;

  // Lê os dados recebidos do aplicativo Android
  while (SerialBT.available() >= 2) {
    xAxis = SerialBT.read();
    delay(10);
    yAxis = SerialBT.read();
    Serial.print(xAxis);
    Serial.print(",");
    Serial.println(yAxis);
  }
  delay(10);

  // Garante que estamos recebendo valores corretos
  if (xAxis > 130 && xAxis < 150 && yAxis > 130 && yAxis < 150) {
    Stop(); // Função para parar os motores
  }

  if (yAxis > 130 && yAxis < 150) {
    if (xAxis < 130) {
      turnRight(); // Função para virar à direita
      motorSpeedA = map(xAxis, 130, 60, 0, 255);
      motorSpeedB = map(xAxis, 130, 60, 0, 255);
    }

    if (xAxis > 150) {
      turnLeft(); // Função para virar à esquerda
      motorSpeedA = map(xAxis, 150, 220, 0, 255);
      motorSpeedB = map(xAxis, 150, 220, 0, 255);
    }
  } else {
    if (xAxis > 130 && xAxis < 150) {
      if (yAxis < 130) {
        forword(); // Função para mover para frente
      }
      if (yAxis > 150) {
        backword(); // Função para mover para trás
      }

      if (yAxis < 130) {
        motorSpeedA = map(yAxis, 130, 60, 0, 255);
        motorSpeedB = map(yAxis, 130, 60, 0, 255);
      }

      if (yAxis > 150) {
        motorSpeedA = map(yAxis, 150, 220, 0, 255);
        motorSpeedB = map(yAxis, 150, 220, 0, 255);
      }
    } else {
      if (yAxis < 130) {
        forword(); // Função para mover para frente
      }
      if (yAxis > 150) {
        backword(); // Função para mover para trás
      }

      if (xAxis < 130) {
        motorSpeedA = map(xAxis, 130, 60, 255, 50);
        motorSpeedB = 255;
      }

      if (xAxis > 150) {
        motorSpeedA = 255;
        motorSpeedB = map(xAxis, 150, 220, 255, 50);
      }
    }
  }

  analogWrite(enA, motorSpeedA); // Envia sinal PWM para o motor A
  analogWrite(enB, motorSpeedB); // Envia sinal PWM para o motor B
}

void forword() {
  Serial.println("Para frente");
  analogWrite(enA,110);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB,120);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backword() {
  Serial.println("Para trás");
  analogWrite(enA,110);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB,120);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  Serial.println("Virar à direita");
  analogWrite(enA,110);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enB,120);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnRight() {
  Serial.println("Virar à esquerda");
  analogWrite(enA,110);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enB,120);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void Stop() {
  analogWrite(enA,110);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enB,120);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("Parar");
}
