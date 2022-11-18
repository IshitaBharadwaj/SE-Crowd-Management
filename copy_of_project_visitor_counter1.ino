#include <LiquidCrystal.h>
int in =15;
int inpr = 16;
int out = 14;
int outpr = 17;
int ppl = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
bool pi = 0;
bool po = 0;
void setup() {
  pinMode(15, INPUT);
  pinMode(14, INPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  digitalWrite(outpr, HIGH);
  digitalWrite(inpr, HIGH);
  pi = digitalRead(in);
  po = digitalRead(out);
  if (pi == 1){
    ppl--;
    Serial.print("Current count: ");
    Serial.println(ppl);
    delay(500);

    if(ppl>=10)
    {
      Serial.println("please wait");
    }
    else
    {
      Serial.println("please enter this terminal");
    }
    delay(1000);
  }
  else if (po == 1){
    ppl++ ;
    Serial.print("Current count: ");
    Serial.println(ppl);
    delay(500);
    if(ppl>=10)
    {
      Serial.println("please wait");
      
    }
    else
    {
      Serial.println("please enter this terminal");
    }
    delay(1000);
  }
  ppl = constrain(ppl, 0, 50);
  lcd.setCursor(0, 0);
  // lcd.print("PEOPLE IN:");
  lcd.setCursor(11, 0);
  // lcd.print(ppl);
  // if (ppl >= 20){
  //    lcd.setCursor(0, 1);
  //    lcd.print("PLEASE WAIT");
  //    Serial.println("please wait");
  //    delay(1000);
  // }
  // if (ppl <= 19){
  //    lcd.setCursor(0, 1);
  //    lcd.print("PLEASE VISIT");
  //    Serial.println("terminal is free");
  //    delay(1000);
  // }
}

 