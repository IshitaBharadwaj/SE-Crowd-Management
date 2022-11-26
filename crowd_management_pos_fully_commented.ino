#include <LiquidCrystal.h>

int in_a = 15;    // assigning pin 15 to signal_a_inner
int inpr_a = 16;  // assigning pin 16 to power_a_inner
int out_a = 14;   // assigning pin 14 to signal_a_outer
int outpr_a = 17; // assigning pin 17 to power_a_inner
int in_b =10;     // assigning pin 10 to signal_b_inner
int inpr_b = 13;  // assigning pin 13 to power_b_inner
int out_b = 19;   // assigning pin 19 to sigal_b_outer
int outpr_b = 18; // assigning pin 18 to power_b_outer
int in_c = 9;     // assigning pin 9 to signal_c_inner
int inpr_c = 8;   // assigning pin 8 to power_c_inner
int out_c = 7;    // assigning pin 7 to signal_c_outer
int outpr_c = 6;  // assigning pin 6 to power_c_outer

// inistalising people in each terminal to 0 
int ppl_a = 0;    
int ppl_b=0;      
int ppl_c=0;   

// assigniing ardiono pins to the lcd display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// setting all sensors to 0  initially
bool pi_a = 0; 
bool po_a = 0;
bool pi_b = 0;
bool po_b = 0;
bool pi_c = 0;
bool po_c = 0;


void setup() // function which sets input/output functionalities to the assigned pins on arduino board
{
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

void loop()  // function which keeps running when the program starts
{
//   lcd.clear();  
  lcd.setCursor(0,0);  // settting cursor in the lcd display to (0,0)
  lcd.print("Welcome "); // printing message on lcd display

  // activating all 3 counters (i.e. 6 sensors)
  digitalWrite(outpr_a, HIGH);
  digitalWrite(inpr_a, HIGH);
    digitalWrite(outpr_b, HIGH);
    digitalWrite(inpr_b, HIGH);
    digitalWrite(outpr_c, HIGH);
    digitalWrite(inpr_c, HIGH);

// assigning variables to sensor inputs in real time
  pi_a = digitalRead(in_a);  // exit terminal a
  po_a = digitalRead(out_a); // enter terminal a
  pi_b = digitalRead(in_b);  // exit terminal b
  po_b = digitalRead(out_b);// enter terminal b
  pi_c = digitalRead(in_c);  // exit terminal c
  po_c = digitalRead(out_c); // enter terminal c


  if ((ppl_a != 10 || ppl_b != 10)) // enter the if block if A and B can accomodate more customers
    {

        if ((po_a == 1 || po_b == 1))  // if user tries to enter A or B 
        {
            if (ppl_a < ppl_b)  // send user to terminal A if people in A are less than people in B
            {
                Serial.println("Enter terminal A");
                ppl_a++;

                delay(1000);
            }
            else if (ppl_b < ppl_a)  // send user to terminal B if people in B are less than people in A
            {
                Serial.println("Enter terminal B");
                ppl_b++;
                delay(1000);
            }
            else // if A and B have equal number of people - send the user to the terminal he tries to enter
            {
                if (po_a == 1)
                {
                    Serial.println("Enter terminal A");
                    ppl_a++;

                    delay(1000);
                }
                else if (po_b == 1)
                {
                    Serial.println("Enter terminal B");
                    ppl_b++;
                    delay(1000);
                }
            }

            // Printing counts of terminal A and B
            Serial.print("Current count for terminal A: ");
            Serial.println(ppl_a);
            Serial.print("Current count for terminal B: ");
            Serial.println(ppl_b);

            if (ppl_c) // Prints people in terminal C if Terminal C is open and is being used
            {
                Serial.print("Current count for terminal C: ");
                Serial.println(ppl_c);
            }
            delay(1000);
        }
        if (pi_a == 1 && ppl_a > 0) // Decrement people counter of terminal A when user tries to exit terminal A while there are some people still in A
        {
            ppl_a--;
            delay(500);
            Serial.println("Exiting terminal A");
            Serial.print("Current count for terminal A: ");
            Serial.println(ppl_a);
            Serial.print("Current count for terminal B: ");
            Serial.println(ppl_b);
            if (ppl_c)
            {
                Serial.print("Current count for terminal C: ");
                Serial.println(ppl_c);
            }

            delay(1000);
        }
        else if (pi_a == 1 && ppl_a == 0)  // If sensor A is triggered when nobody is present in terminal A
        {
            Serial.println("No customers in A");
            delay(1000);
        }
        if (pi_b == 1 && ppl_b > 0) // Decrement people counter of terminal B when user tries to exit terminal B while there are some people still in B
        {
            ppl_b--;
            delay(500);
            Serial.println("Exiting terminal B");
            Serial.print("Current count for terminal A: ");
            Serial.println(ppl_a);
            Serial.print("Current count for terminal B: ");
            Serial.println(ppl_b);
            if (ppl_c)
            {
                Serial.print("Current count for terminal C: ");
                Serial.println(ppl_c);
            }
            delay(1000);
        }
        else if (pi_b == 1 && ppl_b == 0)  // If sensor B is triggered when nobody is present in terminal B
        {
            Serial.println("No customers in B");
            delay(1000);
        }
        if (pi_c == 1 && ppl_c > 0) // Decrement people counter of terminal C when user tries to exit terminal C while there are some people still in C
        {
            ppl_c--;
            delay(500);
            Serial.println("Exiting terminal C");
            Serial.print("Current count for terminal A: ");
            Serial.println(ppl_a);
            Serial.print("Current count for terminal B: ");
            Serial.println(ppl_b);
            Serial.print("Current count for terminal C: ");
            Serial.println(ppl_c);
            delay(1000);
        }
        else if (pi_c == 1 && ppl_c == 0) // If sensor C is triggered when nobody is present in terminal C
        {
            Serial.println("No customers in C");
            delay(1000);
        }

        if (po_c == 1)
        {
            Serial.println("Terminal C is closed");
            delay(1000);
        }
    }
    else // if both A and B cannot accomodate more cutomers then we open terminal C and activate the C counter(i.e sensors of terminal C)
    {
        if ((po_a == 1 || po_b == 1) && ppl_c < 10 && ppl_c >= 0)//This condition takes care of the condition where people are trying to enter terminal A and B as there are full we redirect them to terminal C
        {
            if (ppl_c == 0)//opening terminal C when no people are present in terminal C
                Serial.println("opening terminal C ");

            Serial.println("Enter terminal C");
            ppl_c++; //Incrementing counter for terminal C

            //Printing current count for terminals A,B and C
            Serial.print("Current count for terminal A: ");
            Serial.println(ppl_a);
            Serial.print("Current count for terminal B: ");
            Serial.println(ppl_b);
            Serial.print("Current count for terminal C: ");
            Serial.println(ppl_c);
        }
        else if (ppl_c != 0 && ppl_c != 10 && po_c == 1) //Trying to enter C and when terminal C is already open we just increment the counter for C
        {
            Serial.println("Enter terminal C");
            ppl_c++; //Incrementing counter for terminal C

            //Printing current count for terminals A,B and C
            Serial.print("Current count for terminal A: ");
            Serial.println(ppl_a);
            Serial.print("Current count for terminal B: ");
            Serial.println(ppl_b);
            Serial.print("Current count for terminal C: ");
            Serial.println(ppl_c);
        }
        else //This condition is reached when all teminals are full and the user cant be accomodated 
        {
            if (po_a == 1 || po_b == 1 || po_c == 1)
                Serial.println("Please wait, POS are crowded ");
        }
        if (pi_a == 1 && ppl_a > 0) // Decrement people counter of terminal A when user tries to exit terminal A while there are some people still in A
        {
            ppl_a--;
            delay(500);
            Serial.println("Exiting terminal A");
            Serial.print("Current count for terminal A: ");
            Serial.println(ppl_a);
            Serial.print("Current count for terminal B: ");
            Serial.println(ppl_b);
            Serial.print("Current count for terminal C: ");
            Serial.println(ppl_c);
            delay(1000);
        }
        else if (pi_a == 1 && ppl_a == 0) // If sensor A is triggered when nobody is present in terminal A
        {
            Serial.println("No customers in A");
            delay(1000);
        }
        if (pi_b == 1 && ppl_b > 0) // Decrement people counter of terminal B when user tries to exit terminal B while there are some people still in B
        {
            ppl_b--;
            delay(500);
            Serial.println("Exiting terminal B");
            Serial.print("Current count for terminal A: ");
            Serial.println(ppl_a);
            Serial.print("Current count for terminal B: ");
            Serial.println(ppl_b);
            Serial.print("Current count for terminal C: ");
            Serial.println(ppl_c);
            delay(1000);
        }
        else if (pi_b == 1 && ppl_b == 0) // If sensor B is triggered when nobody is present in terminal B
        {
            Serial.println("No customers in B");
            delay(1000);
        }
        if (pi_c == 1 && ppl_c > 0) // Decrement people counter of terminal C when user tries to exit terminal C while there are some people still in C
        {
            ppl_c--;
            delay(500);
            Serial.println("Exiting terminal C");
            Serial.print("Current count for terminal A: ");
            Serial.println(ppl_a);
            Serial.print("Current count for terminal B: ");
            Serial.println(ppl_b);
            Serial.print("Current count for terminal C: ");
            Serial.println(ppl_c);
            delay(1000);
        }
        else if (pi_c == 1 && ppl_c == 0) // If sensor C is triggered when nobody is present in terminal C
        {
            Serial.println("No customers in C");
            delay(1000);
        }
        delay(1000);
    }
}