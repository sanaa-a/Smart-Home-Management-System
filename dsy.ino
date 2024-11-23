#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(2,3,4,5,6,7);
SoftwareSerial SIM800A(10,9);

char inchar;

float Voltage1 = A0;
float Current1 = A1;

float I1= 0;
float V1 = 0;

int out1= 8;

int power;
int energy;

int unt = 0;
int prs = 0;

int p1 = 0;
int p2 = 0;

void setup(){
  Serial.begin(9600);
  SIM800.begin(9600);

  pinMode(Voltage1,INPUT);
  pinMode(Current1,INPUT);

  pinMode(out1,OUTPUT);
  
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("WeLCOME");
  lcd.setCrusor(0,1);
  lcd.print("S.E.M.S");

  SIM800.print("AT\r\n");
  delay(1000);
  SIM800.print("AT+CMGF=1\r\n");  // set SMS mode to text
  delay(1000);
  SIM800.print("AT+CNMI=2,2,0,0,0\r\n"); 
  delay(1000);
  sim1(); 
  delay(1000);
  SIM800.print("ON GSM"); // Message contents
  delay(500);
  SIM800.write(byte(26)); // (signals end of message)
  delay(1000);
  SIM800.println("AT+CMGD=1,4\r\n"); // delete all SM
  delay(500);
  lcd.clear();

  unt = EEPROM.read(2);
  p2 = EEPROM.read(0);
  prs = EEPROM.read(1);
  if (unt>0)(digitalWrite(out1,HIGH));

}
 void loop() 
  {
  //If a character comes in from the cellular module...
  if(SIM900.available() >0)
  {
    inchar=SIM900.read(); 
    if (inchar=='R')
    {
 
      delay(10);
    inchar=SIM900.read(); 
      if (inchar=='U')
      {
        delay(10);
        inchar=SIM900.read();
        if (inchar=='1')
        {
       sim1();
       delay(1000);
       SIM900.println("Recharge Card 100"); // Message contents
       delay(500);
       SIM900.write(byte(26)); // (signals end of message)
       delay(500);  
        digitalWrite(contactor,HIGH); 
       prs = prs+100;
       unt = prs/5;
       con1=0;
       con2=0;
        }
        else if (inchar=='2')
        {
       sim1();
       delay(1000);
       SIM900.println("Recharge Card 200"); // Message contents
       delay(500);
       SIM900.write(byte(26)); // (signals end of message)
       delay(500);     
        digitalWrite(contactor,HIGH); 
       prs = prs+200;
       unt = prs/5;
       con1=0;
       con2=0;
        }
        else if (inchar=='3')
        {
       sim1();
       delay(1000);
       SIM900.println("Recharge Card 300"); // Message contents
       delay(500);
       SIM900.write(byte(26)); // (signals end of message)
       delay(500);   
        digitalWrite(contactor,HIGH); 
       prs = prs+300;
       unt = prs/5;
       con1=0;
       con2=0;
        }
         else if (inchar=='4')
        {
        sim1();
       delay(1000);
       SIM900.println("Recharge Card 400"); // Message contents
       delay(500);
       SIM900.write(byte(26)); // (signals end of message)
       delay(500);  
        digitalWrite(contactor,HIGH); 
       prs = prs+400;
       unt = prs/5;
       con1=0;
       con2=0;
        }
           else if (inchar=='4')
        {
       sim1();
       delay(1000);
       SIM900.println("Recharge Card 500"); // Message contents
       delay(500);
       SIM900.write(byte(26)); // (signals end of message)
       delay(500);    
    
       {
       con1=1;

        } 
      
        }
        
    }

