#include <LiquidCrystal.h>
#include "DS3231.h"
#include <Keypad.h>

DS3231 rtc(SDA, SCL);
LiquidCrystal lcd(14, 9, 10, 11, 12, 13);

//LED
int LED1 = 23;
int LED2 = 22;
int LED3 = 25;
int LED4 = 24;
int LED5 = 27;
int LED6 = 26;
int LED7 = 29;
int LED8 = 28;
int LED9 = 31;
int LED10 = 30;
int LED11 = 33;
int LED12 = 32;
int LED13 = 35;
int LED14 = 34;
int LED15 = 37;
int LED16 = 36;
int LED17 = 39;
int LED18 = 38;
int LED19 = 41;
int LED20 = 40;
int LED21 = 43;

//BUZZERS
int buzzer1 = 45;
int buzzer2 = 44;

const byte rows = 4, cols = 3;
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

String ppd[] = {
  "      00      ",
  "      01      ", 
  "      02      ", 
  "      03      ", 
  "      04      ", 
  "      05      ", 
  "      06      ", 
  "      07      ", 
  "      08      ", 
  "      09      ", 
  "      10      ", 
  "      11      ", 
  "      12      ", 
  "      13      ", 
  "      14      ", 
  "      15      ", 
  "      16      ", 
  "      17      ", 
  "      18      ", 
  "      19      ", 
  "      20      ", 
  "      21      ", 
  "      22      ", 
  "      23      ", 
};
String rep[] = {
  "      05      ",
  "      06      ",
  "      08      ",
  "      12      ",
  "      24      ",
  "     STOP     ",
};

byte rowPINS[rows] = {7, 6, 5, 4}, colPINS[cols] = {3, 2, 1};
byte menu = 0;
byte i = 0,//ppd listac 
 j = 0, //rep listac
 k = 0, //sta je selektovano
 m = 0; //meni

Keypad kp = Keypad(makeKeymap(keys), rowPINS, colPINS, rows, cols);

void setup() {
  // put your setup code here, to run once:
  rtc.begin();
  lcd.begin(16,2);
  
  // LED
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
  pinMode(LED12, OUTPUT);
  pinMode(LED13, OUTPUT);
  pinMode(LED14, OUTPUT);
  pinMode(LED15, OUTPUT);
  pinMode(LED16, OUTPUT);
  pinMode(LED17, OUTPUT);
  pinMode(LED18, OUTPUT);
  pinMode(LED19, OUTPUT);
  pinMode(LED20, OUTPUT);
  pinMode(LED21, OUTPUT);

  //BUZZERS
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);


    
  // The following lines can be uncommented to set the date and time
  //rtc.setTime(20, 40, 40);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(4, 1, 2017);   // Set the date to January 1st, 2014
  //lcd.print(rtc.getTimeStr());
  
}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(m == 0)lcd.print(rtc.getTimeStr());
  
  lcd.setCursor(0,0);  
  char key = kp.getKey();
  
  if(key){
    if(m == 0 || m == 1)
    {
      switch(key)
      {
        case '5':
          m = 1;
          lcd.setCursor(0,0);
          lcd.clear();
          lcd.print(">ALARM");
          k = 1;
          lcd.setCursor(0,1);
          lcd.print("BROJ TELEFONA");
        break;
        
        case '2':
          if(m == 1){
            k = 1;
            lcd.setCursor(0,0);
            lcd.clear();
            lcd.print(">ALARM");
            lcd.setCursor(0,1);
            lcd.print("BROJ TELEFONA");
          }
          break;
          
        case '8':
          if(m == 1){
            k = 2;
            lcd.setCursor(0,0);
            lcd.clear();
            lcd.print("ALARM");
            lcd.setCursor(0,1);
            lcd.print(">BROJ TELEFONA");
          }
          break;
          
          case '#':
           if(m == 1){
            m = 2;
            lcd.setCursor(0,0);
            lcd.clear();
            lcd.print("PRVA TERAPIJA");
            lcd.setCursor(0,1);
            lcd.print(ppd[i]);
            break;
           }

            case '*':
              if(m == 1){
                m = 0;
                lcd.clear();
                delay(100);
              }
              break;
          
        //default:
        //  lcd.print(key);
      }      
    } 
    
     else if(m == 2 && k == 1){
          lcd.setCursor(0,0);
          lcd.clear();
          lcd.print("PRVA TERAPIJA");
          lcd.setCursor(0,1);
          lcd.print(ppd[i]);
          
          switch(key){
            
            case '*':
              m = 1;
              lcd.setCursor(0,0);
              lcd.clear();
              lcd.print(">ALARM");
              k = 1;
              lcd.setCursor(0,1);
              lcd.print("BROJ TELEFONA");
              break;
              
            case '2':
            if(i > 0) i--;
              lcd.setCursor(0,0);
              lcd.clear();
              lcd.print("PRVA TERAPIJA");
              lcd.setCursor(0,1);
              lcd.print(ppd[i]);
              break;
              
            case '8':
              if(i < 23) i++;
              lcd.setCursor(0,0);
              lcd.clear();
              lcd.print("PRVA TERAPIJA");
              lcd.setCursor(0,1);
              lcd.print(ppd[i]);
              break;
              
            case '#':
              m = 3;
              lcd.setCursor(0,0);
              lcd.clear();
              lcd.print("PONAVLJANJE");
              lcd.setCursor(0,1);
              lcd.print(rep[j]);
              break;
          }
      } 
      
       else if(m == 3 && k == 1){
          lcd.setCursor(0,0);
          lcd.clear();
          lcd.print("PONAVLJANJE");
          lcd.setCursor(0,1);
          lcd.print(rep[j]);
          
          switch(key){
            
            case '*':
              m = 2;
              lcd.setCursor(0,0);
              lcd.clear();
              lcd.print("PRVA TERAPIJA");
              lcd.setCursor(0,1);
              lcd.print(ppd[i]);
              break;
              
            case '2':
              if(j > 0) j--;
              break;
              
            case '8':
              if(j < 5) j++;
              break;
              
            case '#':
              if (m == 3){              
              lcd.setCursor(0,0);
              lcd.clear();
              lcd.print("PODESENO");
              delay(3000);
              m=0;
              lcd.clear();
              break;
              }
          }
      }
  }
}
