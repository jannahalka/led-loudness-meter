#include <Arduino.h>
#include <PDM.h>

short buff[256];
volatile int numSamples;

void onPDMdata();

void setup() {
  Serial.begin(9600);
  while (!Serial)
    ;

  PDM.onReceive(onPDMdata);
  if (!PDM.begin(1, 16000)) {
    Serial.println("Failed to start PDM!");
    while (1)
      ;
  }
}

void loop() {
  if (numSamples) {
    long sum = 0;

    for (int i = 0; i < numSamples; i++) {
      sum += buff[i] * buff[i];
    }

    float meanSquare = (float)sum / numSamples;
    float rms = sqrt(meanSquare);

    if (rms >= 500) {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    if (rms >= 0 && rms < 500) {
      digitalWrite(LED_BUILTIN, LOW);
    }

    numSamples = 0;
  }
}

void onPDMdata() {
  int bytesAvailable = PDM.available();
  PDM.read(&buff, bytesAvailable);
  numSamples = bytesAvailable / 2;
}
