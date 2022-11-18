#include <LiquidCrystal.h>
int in_a =15;
int inpr_a = 16;
int out_a = 14;
int outpr_a = 17;
int in_b =10;
int inpr_b = 13;
int out_b = 19;
int outpr_b = 18;
int in_c =9;
int inpr_c = 8;
int out_c = 7;
int outpr_c = 6;
int ppl_a = 0;
int ppl_b=0;
int ppl_c=0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
bool pi_a = 0;
bool po_a = 0;
bool pi_b = 0;
bool po_b = 0;
bool pi_c = 0;
bool po_c = 0;
void setup() {
  pinMode(15, INPUT);
  pinMode(14, INPUT);
  pinMode(10, INPUT);
  pinMode(19, INPUT);
  pinMode(9, INPUT);
  pinMode(7, INPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  lcd.clear();
  digitalWrite(outpr_a, HIGH);
  digitalWrite(inpr_a, HIGH);
  digitalWrite(outpr_b, HIGH);
  digitalWrite(inpr_b, HIGH);
  digitalWrite(outpr_c, HIGH);
  digitalWrite(inpr_c, HIGH);
  pi_a = digitalRead(in_a);
  po_a = digitalRead(out_a);
  pi_b = digitalRead(in_b);
  po_b = digitalRead(out_b);
  pi_c = digitalRead(in_c);
  po_c = digitalRead(out_c);
  if (pi_a == 1){
    ppl_a--;
    Serial.print("Current count for terminal A: ");
    Serial.println(ppl_a);
    delay(500);

    if(ppl_a>=10)
    {
      Serial.println("please wait, terminal A is full");
    }
    else
    {
      Serial.println("please enter terminal A");
    }
    delay(1000);
  }
  else if (po_a == 1){
    ppl_a++ ;
    Serial.print("Current count for terminal A: ");
    Serial.println(ppl_a);
    delay(500);
    if(ppl_a>=10)
    {
      Serial.println("please wait terminal A is full");
      
    }
    else
    {
      Serial.println("please enter terminal A");
    }
    delay(1000);
  }

  // counter for terminal b
  if (pi_b == 1){
    ppl_b--;
    Serial.print("Current count for terminal B: ");
    Serial.println(ppl_b);
    delay(500);

    if(ppl_b>=10)
    {
      Serial.println("please wait, terminal B is full");
    }
    else
    {
      Serial.println("please enter terminal B");
    }
    delay(1000);
  }
  else if (po_b == 1){
    ppl_b++ ;
    Serial.print("Current count for terminal B: ");
    Serial.println(ppl_b);
    delay(500);
    if(ppl_b>=10)
    {
      Serial.println("please wait terminal B is full");
      
    }
    else
    {
      Serial.println("please enter terminal B");
    }
    delay(1000);
  }
  // counter for terminal c
  if (pi_c == 1){
    ppl_c--;
    Serial.print("Current count for terminal C: ");
    Serial.println(ppl_c);
    delay(500);

    if(ppl_c>=10)
    {
      Serial.println("please wait, terminal C is full");
    }
    else
    {
      Serial.println("please enter terminal C");
    }
    delay(1000);
  }
  else if (po_c == 1){
    ppl_c++ ;
    Serial.print("Current count for terminal C: ");
    Serial.println(ppl_c);
    delay(500);
    if(ppl_c>=10)
    {
      Serial.println("please wait terminal C is full");
      
    }
    else
    {
      Serial.println("please enter terminal C");
    }
    delay(1000);
  }

  
  ppl_a = constrain(ppl_a, 0, 50);
  lcd.setCursor(0, 0);
  // lcd.print("PEOPLE IN:");
  lcd.setCursor(11, 0);
  // lcd.print(ppl_a);
  // if (ppl_a >= 20){
  //    lcd.setCursor(0, 1);
  //    lcd.print("PLEASE WAIT");
  //    Serial.println("please wait");
  //    delay(1000);
  // }
  // if (ppl_a <= 19){
  //    lcd.setCursor(0, 1);
  //    lcd.print("PLEASE VISIT");
  //    Serial.println("terminal is free");
  //    delay(1000);
  // }
}

 