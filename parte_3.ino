/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de 
   computadoras I
   Nombre: Jose Sebastian Bocaletti Aguilar
   Carnet: 2022235
*/
#include <Wire.h>    
#include <LiquidCrystal_I2C.h>  



#define LCDd 0x27
#define Filas 2
#define Columnas 16
#define TRIG A0
#define ECHO A1
#define BUZZ 12
#define D1 2
#define D2 3
#define D3 4
#define D4 5
#define D5 6
#define D6 7
#define D7 8
#define D8 9
#define D9 10
#define D10 11
int Distancia;
int G;


LiquidCrystal_I2C LCD(LCDd, Columnas, Filas);

void Pines_Configuraciones(){
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);
}

void setup()
{
  Pines_Configuraciones();
  
  for(G=2; G<=11;G++){
  }
  pinMode(BUZZ, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  LCD.init();
  LCD.backlight();
}


void loop()
{
  medir();
  alarma();
}
int medir(){
  long E; 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);
  E = pulseIn(ECHO, HIGH);
  Distancia = E/59;
  delay(50);
  return Distancia;
}
int alarma(){
   if( Distancia > 45){
    LCD.setCursor(0,0);
    LCD.print(" NO ALCANCE          ");
    LCD.setCursor(0,1);
    LCD.print(" PRIVADO");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
  }
  if( Distancia < 45 && Distancia > 30){
    LCD.setCursor(0,0);
    LCD.print(" CERCA             ");
    LCD.setCursor(0,1);
    LCD.print(" PRIVADO");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
  }
  if( Distancia < 30 && Distancia > 15){
    LCD.setCursor(0,0);
    LCD.print(" PRECAUCION        ");
    LCD.setCursor(0,1);
    LCD.print(" PRIVADO");
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    tone(BUZZ, 523);
    delay(5000);
    noTone(BUZZ);
  }


  if( Distancia < 15 && Distancia > 0){
    LCD.setCursor(0,0);
    LCD.print("LIMITE           ");
    LCD.setCursor(0,1);
    LCD.print(" PRIVADO");
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    tone(BUZZ, 523);
    delay(10000);
    noTone(BUZZ);
 }
    else {
    noTone(BUZZ);
 }
    return 0;
}
