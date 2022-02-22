#include <LiquidCrystal.h> // include the LCD library
#define s0 PB12 
#define s1 PB13 
#define s2 PB14 
#define s3 PB15
#define out PB11
#define rs  PB1
#define en  PB10
#define d4  PA4
#define d5  PA3
#define d6  PA2
#define d7  PA1 
//const int rs = PB11, en = PB10, d4 = PA4, d5 = PA3, d6 = PA2, d7 = PA1; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup() {
lcd.begin(16, 2);//Defining 16*2 LCD



 
delay(4000); //wait for four secounds
lcd.clear(); //Clear the screen
  Serial.begin(9600); 

  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);
  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, LOW);  
}  
    
void loop() { 
  color(); 
  //char lcd_txt[16]=red+" "+blue+" "+green+"\0";
  
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  lcd.setCursor(0, 0);
  lcd.print("R = ");//LCD Row 0 and Column 0
  lcd.setCursor(4, 0);
  lcd.print(red); //Print this Line
  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);
  lcd.setCursor(8, 0);
  lcd.print("G = ");  
  lcd.setCursor(12, 0); //LCD Row 0 and Column 0
  lcd.print(green); //Print this Line
  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC); 
  lcd.setCursor(0, 1);
  lcd.print("B = ");
  lcd.setCursor(4, 1); //LCD Row 0 and Column 0
  lcd.print(blue); //Print this Line

  lcd.setCursor(8, 1);
  //lcd.print("C = ");  
  //lcd.setCursor(12, 1); //LCD Row 0 and Column 0
  
  
  if (red < blue && red < green) {  
    Serial.println(" - (Red Color)");
    lcd.print("RED     ");
    delay(500);
  }  
  else if (blue < red && blue < green) {  
    Serial.println(" - (Blue Color)"); 
    lcd.print("BLUE    ");
    delay(500);
  } 
  else if (green < red && green < blue) {  
    Serial.println(" - (Green Color)"); 
    lcd.print("GREEN   ");
    delay(500);
  }  
  else {
    Serial.println();
    delay (500); 
  } 
}  
    
void color() {    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}