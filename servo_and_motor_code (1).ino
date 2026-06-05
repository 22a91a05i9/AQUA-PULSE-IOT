#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BT(2, 3);

Servo esc;
Servo steering;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  // Servo setup
  steering.attach(10);
  steering.write(90);

  // ESC setup
  esc.attach(9, 1000, 2000);
  esc.writeMicroseconds(1500);
  delay(3000);

  Serial.println("BOAT READY");
  BT.println("BOAT READY");
}

void loop() {
  if (BT.available()) {
    char c = BT.read();
    Serial.print("GOT: ");
    Serial.println(c);
    doCommand(c);
  }
  if (Serial.available()) {
    char c = Serial.read();
    doCommand(c);
  }
}

void doCommand(char c) {
  switch(c) {

    // ── DC MOTOR FORWARD ──
    case 'F':
      esc.writeMicroseconds(1900);
      BT.println("FORWARD FULL");
      Serial.println("FORWARD FULL");
      break;

    case 'f':
      esc.writeMicroseconds(1600);
      BT.println("FORWARD SLOW");
      Serial.println("FORWARD SLOW");
      break;

    // ── DC MOTOR REVERSE ──
    case 'B':
      esc.writeMicroseconds(1100);
      BT.println("REVERSE FULL");
      Serial.println("REVERSE FULL");
      break;

    case 'b':
      esc.writeMicroseconds(1400);
      BT.println("REVERSE SLOW");
      Serial.println("REVERSE SLOW");
      break;

    // ── DC MOTOR STOP ──
    case 'S':
      esc.writeMicroseconds(1480);
      delay(100);
      esc.writeMicroseconds(1500);
      BT.println("STOP");
      Serial.println("STOP");
      break;

    case '0':
      esc.writeMicroseconds(1480);
      delay(100);
      esc.writeMicroseconds(1500);
      BT.println("STOP");
      Serial.println("STOP");
      break;

    // ── SERVO STEERING ──
    case 'L':
      steering.write(55);
      BT.println("LEFT");
      Serial.println("LEFT");
      break;

    case 'R':
      steering.write(125);
      BT.println("RIGHT");
      Serial.println("RIGHT");
      break;

    case 'C':
      steering.write(90);
      BT.println("CENTER");
      Serial.println("CENTER");
      break;

    // ── SPEED LEVELS ──
    case '1':
      esc.writeMicroseconds(1600);
      BT.println("SPEED 1");
      Serial.println("SPEED 1");
      break;

    case '2':
      esc.writeMicroseconds(1650);
      BT.println("SPEED 2");
      Serial.println("SPEED 2");
      break;

    case '3':
      esc.writeMicroseconds(1700);
      BT.println("SPEED 3");
      Serial.println("SPEED 3");
      break;

    case '4':
      esc.writeMicroseconds(1750);
      BT.println("SPEED 4");
      Serial.println("SPEED 4");
      break;

    case '5':
      esc.writeMicroseconds(1800);
      BT.println("SPEED 5");
      Serial.println("SPEED 5");
      break;

    case '9':
      esc.writeMicroseconds(1900);
      BT.println("SPEED MAX");
      Serial.println("SPEED MAX");
      break;
  }
}
