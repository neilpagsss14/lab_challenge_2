#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd(0x3E, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup() {
    pinMode(19,INPUT); // PIR
    pinMode(23, OUTPUT); //LED
    pinMode(21, OUTPUT); // lcd
    pinMode(18, OUTPUT); // buzz

    lcd.begin(); //initialize the lcd
    lcd.backlight(); //open the backlight 

}

void loop() {
  
  // lcd.clear();
  // lcd.setCursor(2, 0); 
  // lcd.print("G D S C 2023");
  // lcd.setCursor(1, 1); 
  // lcd.print("C H A M P I O N");
  // delay(5000) ;
  // lcd.clear();
  // lcd.setCursor(2, 0); 
  // lcd.print("T E A M ");
  // lcd.setCursor(1, 1); 
  // lcd.print("TAMBAYAYONG");
  // delay(2000) ;

  int mySensorState = 0;
  mySensorState = digitalRead(19);
  if (mySensorState == HIGH)
  {
    digitalWrite(18, HIGH);
    // tone(18, 500, 300);
    // delay(100);
    // delay(200);
    digitalWrite(23, LOW);
    lcd.clear();                 // clear display
    lcd.setCursor(2, 0);         // move cursor to   (0, 0)
    lcd.print("M O T I O N");        // print message at (0, 0)
    lcd.setCursor(0, 1);         // move cursor to   (2, 1)
    lcd.print("D E T E C T E D"); // print message at (2, 1)
    delay(2000);                 // display the above for two seconds

    lcd.clear();                  // clear display
    lcd.setCursor(3, 0);          // move cursor to   (3, 0)
    lcd.print("Ruuuuuuun!");        // print message at (3, 0)
    lcd.setCursor(1, 1);          // move cursor to   (0, 1)
    lcd.print("Run bby Ruuun!"); // print message at (0, 1)
    delay(2000);                  // display the above for two seconds
    lcd.clear();

  }
  else
  {
    // lcd.clear();                 // clear display
    lcd.setCursor(6, 0);         // move cursor to   (0, 0)
    lcd.print("N O");        // print message at (0, 0)
    lcd.setCursor(2, 1);         // move cursor to   (0, 0)
    lcd.print("M O T I O N");        // print message at (0, 0)
    delay(500);
    lcd.clear();
    digitalWrite(18, LOW);
    digitalWrite(23, HIGH);
  }
}
