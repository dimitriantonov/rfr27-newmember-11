
// PINS
const int Multi = A0; // multiplexer
const int LED = 9; // led pin

// CONSTANTS
const int num_sensors = 16;
const float temp_threshold = 60; // max of 60 degrees

// VARIABLES
float temperatures[num_sensors]; // float array of all the sensor values
float maxTemperature = 0; // will be set to the highest sensed temperature

void setup() {

  Serial.begin(9600);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  // TEMP VALUES FOR TESTING
  for (int i = 0; i < num_sensors - 1; i++) {
    temperatures[i] = 25.0;
  }
  temperatures[num_sensors - 1] = 65.0;


}

void loop() {

  maxTemperature = findMaxTemp();

  Serial.println(maxTemperature);

  if (maxTemperature > temp_threshold) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}

float findMaxTemp() {

  float max = temperatures[0];
  for (int i = 1; i < num_sensors; i++) {
    if (temperatures[i] > max) {
      max = temperatures[i];
    }
  }

  return max;
}
