#include <Servo.h>
#include <LiquidCrystal.h>

// LCD Setup (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 8);

// Servo Setup
Servo radarServo;
#define SERVO_PIN 12  // Servo moves normally on Pin 12

// Ultrasonic Sensor & Buzzer
#define TRIG 10
#define ECHO 11
#define BUZZER 9  // Buzzer controlled by sensor on Pin 9

// LED Warning System
#define RED_LED 13    // Red LED (Danger)
#define YELLOW_LED 2  // Yellow LED (Caution)

unsigned long lastSensorUpdate = 0; // Track last update time
const int sensorUpdateInterval = 300; // Read sensor every 300ms

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2); // Initialize LCD
  lcd.setCursor(0, 0);
  lcd.print("Proximity Radar");

  radarServo.attach(SERVO_PIN);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {
  //  Servo moves normally (0° to 180° and back)
  static int angle = 0;
  static bool movingForward = true;
  
  if (movingForward) {
    angle += 5;
    if (angle >= 180) movingForward = false;
  } else {
    angle -= 5;
    if (angle <= 0) movingForward = true;
  }
  
  radarServo.write(angle);
  delay(50);  // Normal speed delay

  //  Update sensor readings every 300ms
  if (millis() - lastSensorUpdate >= sensorUpdateInterval) {
    lastSensorUpdate = millis();

    // Read Distance
    float distance = getDistance();
    if (distance < 0) return;

    //  Update LCD Display
    lcd.setCursor(0, 0);
    lcd.print("Distance:       ");
    lcd.setCursor(10, 0);
    lcd.print(distance);
    lcd.print(" cm ");

    //  Buzzer & LED Alert System
    if (distance < 30) {
      digitalWrite(RED_LED, HIGH);   // Red LED ON (Danger)
      digitalWrite(YELLOW_LED, LOW); // Yellow LED OFF
      for (int i = 0; i < 3; i++) {  // Buzzer beeps
        digitalWrite(BUZZER, HIGH);
        delay(100);
        digitalWrite(BUZZER, LOW);
        delay(100);
      }
    } else if (distance < 90) {
      digitalWrite(RED_LED, LOW);    // Red LED OFF
      digitalWrite(YELLOW_LED, HIGH); // Yellow LED ON (Caution)
      digitalWrite(BUZZER, LOW);
    } else {
      digitalWrite(RED_LED, LOW);
      digitalWrite(YELLOW_LED, LOW);
      digitalWrite(BUZZER, LOW);
    }

    //  Print Distance to Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}

//  Function to Measure Distance
float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH, 30000); // Timeout of 30ms
  if (duration == 0) return -1;  // Return -1 if no echo detected
  return duration * 0.034 / 2; // Convert to cm
}
