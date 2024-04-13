// define IR sensor pin and glucose level range
const int ir_pin = A0;
const int glucose_min = 0;
const int glucose_max = 1023;
const float glucose_min_val = 70.0;
const float glucose_max_val = 400.0;

// define variables for storing sensor readings and glucose level
float sensorValue;
float outputValue;
float glucose_level;

void setup() {
  Serial.begin(9600); // initialize serial communication
}

void loop() {
  // read sensor value
  sensorValue = analogRead(ir_pin);

  // check if finger is in contact with sensor
  if (sensorValue > glucose_min && sensorValue < glucose_max) {
    // map sensor value to glucose level
    outputValue = map(sensorValue, glucose_min, glucose_max, glucose_min_val, glucose_max_val);
    // use quadratic equation to calculate glucose level
    glucose_level = (0.000009)*(sensorValue)*(sensorValue)+(0.1788)*(sensorValue) +75.454;
    // add random noise to glucose level
    glucose_level += random(-5, 6);
    // print glucose level to serial monitor
    Serial.print("Glucose level: ");
    Serial.print(glucose_level);
    Serial.println(" mg/dL");
  } 
  // if finger is not detected, print message to serial monitor
  else {
    Serial.println("Please place finger on sensor");
  }

  // delay before taking next reading
  delay(5000);
}
