#include <OneWire.h>
#include <DallasTemperature.h>
#include <LCD-I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Initialize LCD object with I2C address 0x27, 16 columns, and 2 rows

#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS); // Define the OneWire bus on pin 8
DallasTemperature sensors(&oneWire); // Initialize DallasTemperature sensor object

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  sensors.begin(); // Start DallasTemperature sensor
  lcd.begin(false); // Initialize the LCD without auto-scrolling
  lcd.display(); // Turn on the LCD display
  lcd.backlight(); // Turn on the LCD backlight
}

void loop() {
  sensors.requestTemperatures(); // Request temperature readings
  float tempC = sensors.getTempCByIndex(0); // Read temperature in Celsius
  
  // Print temperature to Serial Monitor for debugging
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  // Clear the second line of the LCD before displaying new temperature
  lcd.setCursor(0, 1);
  lcd.print("                ");  // Clear previous data

  // Set cursor and display the new temperature on LCD
  lcd.setCursor(0, 1);
  lcd.print("Temp: " + String(tempC) + " C");

  delay(1000);  // Wait for a second before next reading
}
