#include "LedControl.h" 
#include <LiquidCrystal.h>
#define V0_PIN 9
LedControl lc = LedControl(12, 11, 10, 1); //DIN, CLK, LOAD, No. DRIVER
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


//  ZONA DE INITIALIZARI!
const int buttonPin = A1;
int trigPin = 13;
int echoPin = 8;
long duration;
int distance;
int newDistance;
unsigned int row = 7, colPrim = 3, colSecund = 4;
int instantaUltrasonic = 0;
bool loopAnimatie = 0;
const int buzzer = A0;
bool inamici[8];
int inamic1, inamic2;
int vitezaJoc = 0;
int buttonState = 0;
int pinPotentiometru = A2;
int potenVal;
int punctaj = 0;
int vieti = 3;
int hightScore = 0;

int miscare ()     // In aceasta functie misc cele 2 leduri de pe matrice in functie de distanta masurata cu +- 5 cm pt fiecare treapta
{
  digitalWrite(trigPin, LOW); //clear trig
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  newDistance = duration*0.034/2; //calcularea distantei în cm
  
  if (newDistance >= distance && newDistance <= distance + 5)
    {
      lc.setLed(0,  colPrim,row, false);
      lc.setLed(0,  colSecund,row, false);
      row = 0;
      lc.setLed(0, colPrim, row, true);
      lc.setLed(0, colSecund, row, true);
    } 
    
  else if ( newDistance >= distance+6 && newDistance <= distance+11 )
    {
    
      lc.setLed(0,  colPrim,row, false);
      lc.setLed(0,  colSecund,row, false);
      row=1;
      lc.setLed(0, colPrim, row, true);
      lc.setLed(0, colSecund, row, true);
    }
    
  else if (newDistance >= distance+12 && newDistance <= distance+17 )
  {
      lc.setLed(0,  colPrim,row, false);
      lc.setLed(0,  colSecund,row, false);
      row=2;
      lc.setLed(0, colPrim, row, true);
      lc.setLed(0, colSecund, row, true);
  }
  
  else if ( newDistance >= distance+18 && newDistance <= distance+23 )
  {
      lc.setLed(0,  colPrim,row, false);
      lc.setLed(0,  colSecund,row, false);
      row=3;
      lc.setLed(0, colPrim, row, true);
      lc.setLed(0, colSecund, row, true);
  }
  
  else if (newDistance >= distance+24 && newDistance <= distance+29 )
  {
      lc.setLed(0,  colPrim,row, false);
      lc.setLed(0,  colSecund,row, false);
      row=4;
      lc.setLed(0, colPrim, row, true);
      lc.setLed(0, colSecund, row, true);
  }
  
  else if (newDistance >= distance+30 && newDistance <= distance+35 )
  {
      lc.setLed(0,  colPrim,row, false);
      lc.setLed(0,  colSecund,row, false);
      row=5;
      lc.setLed(0, colPrim, row, true);
      lc.setLed(0, colSecund, row, true);
  }
  
  else if (newDistance >= distance+36 && newDistance <= distance+41 )
  {
      lc.setLed(0,  colPrim,row, false);
      lc.setLed(0,  colSecund,row, false);
      row=6;
      lc.setLed(0, colPrim, row, true);
      lc.setLed(0, colSecund, row, true);
  }
  
  else if (newDistance >= distance+42 && newDistance <= distance+50)
  {
     lc.setLed(0,  colPrim,row, false);
     lc.setLed(0,  colSecund,row, false);
     row=7;
     lc.setLed(0, colPrim, row, true);
     lc.setLed(0, colSecund, row, true);
  }
 
  return newDistance;
}

void animatie (bool &loopAnimatie)
{
   // ANIMATIE DESCHIDERE JOC
  
  if ( loopAnimatie==0 )
   {
     for ( int i=0; i<8; i++)
       for ( int j=0; j<8; j++) 
        if ( i<=j )
         {
          lc.setLed(0,i,j,true);
          delay(10);
         }
  
     for ( int i=0; i<8; i++)
       for ( int j=0; j<8; j++)
        if ( i>=j )
         {
          lc.setLed(0,i,j,true);
          delay(10);
         }
          
     for (int i=0; i<8; i++)
       for (int j=0; j<8; j++)      
          if ( i==j )
            {
              lc.setLed(0,i,j,false);
              delay(50);
            }
    
      for (int i=0; i<8; i++)
        for (int j=0; j<8; j++)
          {
            lc.setLed(0,i,j,false);
            delay(10);
          }
          
     loopAnimatie = 1; // o sa ma ajute la verificarea daca s-a mai intrat in aceasta functie sau nu
     
     lc.setLed(0, colPrim, row, true);
     lc.setLed(0, colSecund, row, true);
  }
}

void newGame(int scor)
{
 
    lcd.clear();
    lcd.setCursor( 0, 0);   
    lcd.print("Scorul: ");   
    lcd.setCursor( 9, 0);   
    lcd.print( punctaj );
    
    if ( punctaj >= hightScore )  
       hightScore=punctaj;
    
    lcd.setCursor(0,1);
    lcd.print("Hight Score: ");
    lcd.setCursor(13,1);
    lcd.print(hightScore);
    
    int ok2=0;
    int ok1=0;
    int lastButton;
     
      while (1) // acest loop este pus sa faca tot acest cod pana cand se va apasa pe buton si se va iesi. 
       {
        while (ok1 == 0) // Acest ok1 este utilizat pentru a se intra o singura data in acet while
         {
           buttonState = digitalRead(buttonPin);
           lastButton=buttonState;
           if (buttonState == 1)
            {
              punctaj = 0;
              vieti = 3;
              lcd.clear();            
              ok1 = 1;         
              break;
            }
         }
         
      buttonState=digitalRead(buttonPin);
      
      if (lastButton!=buttonState)
        {
          lcd.setCursor(5,0);
          lcd.print("Start");   
          potenVal = analogRead(pinPotentiometru);
          lcd.setCursor(0,1); 
          lcd.print("Viteza joc:");  
          lcd.setCursor(11,1);
     
     if ((( potenVal/10 ) + 10) <99)
       {
         lcd.print((potenVal/10)+10);       
         lcd.setCursor(13,1);      
         lcd.print(" ");      
         vitezaJoc = 150 - ( potenVal/10 );
        }
       
     else
       {
         lcd.setCursor(11,1);  
         lcd.print("100");       
         vitezaJoc = 50;
       }
       
      lcd.setCursor(14,1);    
      lcd.print("%");    
      buttonState = digitalRead(buttonPin);
     
     if ( buttonState == 1 )
       {
         lcd.clear();         
         buttonState = 0;        
         lcd.setCursor(0,0);         
         lcd.print("Vieti: ");         
         lcd.setCursor(8,0);         
         lcd.print(vieti);         
         lcd.setCursor(0,1);        
         lcd.print("Punctaj: ");         
         lcd.setCursor(10,1);         
         lcd.print("0");        
         break;
     } 
   }   
 }
}
    

void setup ()
{
  
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);  
  lcd.clear();  
  lcd.setCursor(1, 0);  
  lcd.print("Bine ati venit! ");  
  lcd.setCursor(0,1); 
  lcd.print("Calibrati senzor"); 
  pinMode(V0_PIN, OUTPUT); 
  analogWrite(V0_PIN, 90);  
  pinMode(buzzer, OUTPUT);  
  for ( int i=0; i<3; i++ )
    {
       tone(buzzer, 1000);       
       delay(500); //Nu incurca jocul cu nimic. Prelingesc sunetul buzzer-ului       
       noTone(buzzer);           
       delay(500);        
   }
   
  tone(buzzer,2000); 
  delay(200); 
  noTone(buzzer);
    
  lc.shutdown(0, false);   
  lc.setIntensity(0, 2);   
  lc.clearDisplay(0); 
  pinMode(trigPin, OUTPUT);   
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance = duration*0.034/2; 
  randomSeed(analogRead(1));
 
  lcd.clear(); 
  lcd.setCursor(5,0);
  lcd.print("Start");
  
  while(1)
  {
    potenVal = analogRead(pinPotentiometru); 
    lcd.setCursor(0,1);   
    lcd.print("Viteza joc:");    
    lcd.setCursor(11,1);
   
    if ((( potenVal/10 ) + 10) < 99)
     {
      lcd.print( ( potenVal/10 ) + 10 );     
      lcd.setCursor(13,1);     
      lcd.print(" ");     
      vitezaJoc = 150 - ( potenVal/10 );   
     }
    
     else
      {
       lcd.setCursor(11,1);       
       lcd.print("100");     
       vitezaJoc = 50;       
       }
       
      lcd.setCursor(14,1);     
      lcd.print("%");      
      buttonState = digitalRead(buttonPin);
      
      if ( buttonState == 1 )
       {
         lcd.clear();       
         buttonState = 0;       
         lcd.setCursor(0,0);         
         lcd.print("Vieti: ");         
         lcd.setCursor(8,0);         
         lcd.print(vieti);         
         lcd.setCursor(0,1);         
         lcd.print("Punctaj: ");        
         lcd.setCursor(10,1);        
         lcd.print("0");        
         break;
       }      
   } 
}

void loop()
{
  animatie( loopAnimatie );
  int predInamic1 = -1;
  inamic1 = random(8);
  while ( predInamic1 == inamic1 )
    {
       predInamic1 = inamic1;      
       inamic1 = random(8);      
       inamici[inamic1]=1;
    }
    
  int predInamic2 = -1;
  inamic2 = random(8);
  while ( predInamic2 == inamic2 )
    {
       predInamic2 = inamic2;     
       inamic2 = random(8);      
       inamici[inamic2] = 1;
    }
  
   for ( int i=0, j=7; i<8, j>=0; i++, j--)
    { 
     newDistance = miscare();    
     Serial.print(newDistance);    
     Serial.print("\n");
     
     if (( i == colPrim || i == colSecund ) && ( inamic1 == row ))
      {
        loopAnimatie = 0;     
        vieti--;       
        lcd.setCursor(8,0);       
        lcd.print(vieti);        
        tone(buzzer,10);       
        delay(300);        
        tone(buzzer,500);
        delay(100);       
        noTone(buzzer);        
        animatie(loopAnimatie);           
        break;       
      }
      
      if (( j == colPrim || j == colSecund ) && ( inamic2 == row ))
      {
        loopAnimatie = 0;        
        vieti--;        
        lcd.setCursor(8,0);        
        lcd.print(vieti);       
        tone(buzzer,10);        
        delay(500);         
        tone(buzzer,500);        
        delay(100);        
        noTone(buzzer);        
        animatie(loopAnimatie);          
        break;
      }
    
     lc.setLed(0,i,inamic1,true);     
     lc.setLed(0,j,inamic2,true);     
     lcd.setCursor(10,1);     
     punctaj++;    
     lcd.print(punctaj);
     delay(vitezaJoc);     
     newDistance = miscare();
     lc.setLed(0,i,inamic1, false);    
     lc.setLed(0,j,inamic2, false);   
     newDistance = miscare();
     
     if (vieti == 0)
        newGame(punctaj);   
  } 
}
 
