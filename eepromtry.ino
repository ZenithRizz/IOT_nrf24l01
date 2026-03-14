#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Wait for Serial Monitor to connect (optional)

  Serial.println("Welcome! Checking for stored value...");

  // Read the stored value from EEPROM
  int storedValue = EEPROM.read(0); // Read from address 0

  // Check if a valid value is stored (e.g., a value between 0 and 255)
  if (storedValue != 255) { // 255 is the default erased state of EEPROM
    Serial.print("Stored value found: ");
    Serial.println(storedValue);
  } else {
    Serial.println("No valid value found. Enter a value to store:");
  }
}

void loop() {
  // Check if user entered a value
  if (Serial.available() > 0) {
    int userInput = Serial.parseInt(); // Read integer input from Serial

    // Validate input
    if (userInput >= 0 && userInput <= 255) {
      Serial.print("Storing value: ");
      Serial.println(userInput);

      // Write the input to EEPROM
      EEPROM.write(0, userInput); // Store at address 0
      delay(2000); // Ensure write completes

      Serial.println("Value stored successfully! Restart the Arduino to check.");
    } else {
      Serial.println("Invalid input. Please enter a value between 0 and 255.");
    }
  }
}
