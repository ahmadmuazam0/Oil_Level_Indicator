#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // Set the LCD adress as you find out from Scaning I2C.
int mean=0;
unsigned int sensor_value=0;
void setup()
{
  
  lcd.init();                      // initialize the lcd 
  pinMode(A0,INPUT); // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello Ahmed");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The fluid level");
  lcd.setCursor(0,1);
  lcd.print("is :");
 delay(500);
   lcd.setCursor(6,1);
   lcd.print("--");
  lcd.setCursor(9,1);                       //To set the position of the % sign next to the sensor value
  lcd.print("%");
  delay(500);
}

void loop()
{
  
  for(int i=0;i<=2;i++){
    
    mean=(analogRead(A0));                // Reading value of sensor from analog Input
    
    sensor_value=sensor_value+mean;           // Summing Up the value to one Variable
  
    delay(500);
  }
 
  //Value Mapping
  sensor_value=sensor_value/3;                // Divide on 3 to get the average value
  
  sensor_value=sensor_value-999;
  
  sensor_value=sensor_value*4.8;         // Displaying the %ge of fluid inside
  
  lcd.setCursor(6,1);
  lcd.print("   ");
  lcd.setCursor(6,1);
  lcd.print(sensor_value);                    // Print the value on LCD Display
  sensor_value=0;                             // Reset the Sensor Value variable
  mean=0;                                     // Reset the mean variable
  
}
