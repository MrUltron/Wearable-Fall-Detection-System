#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;
const int buzzerPin = 3;
const float FREEFALL_THRESHOLD = 0.5; // g
const float IMPACT_THRESHOLD = 2.5;   // g

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("❌ MPU6050 connection failed!");
    while(1);
  }
  Serial.println("✅ MPU6050 ready");
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
  float xg = ax / 16384.0;
  float yg = ay / 16384.0;
  float zg = az / 16384.0;
  float totalG = sqrt(xg*xg + yg*yg + zg*zg);

  // Free-fall detection
  if (totalG < FREEFALL_THRESHOLD) {
    Serial.println("🕳️ Freefall detected");
    delay(300);
    mpu.getAcceleration(&ax, &ay, &az);
    totalG = sqrt(pow(ax/16384.0,2) + pow(ay/16384.0,2) + pow(az/16384.0,2));
    if (totalG > IMPACT_THRESHOLD) {
      Serial.println("💥 Impact detected! Alert!");
      tone(buzzerPin, 1000);  // 1 kHz buzzer
      delay(2000);
      noTone(buzzerPin);
    }
  }
  delay(100);
}
