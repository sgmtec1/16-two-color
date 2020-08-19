// Open Source
#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); //ENDEREÇO DO I2C E DEMAIS INFORMAÇÕES

int redpin = 11; // pin for red signal
int greenpin = 10; // pin for green signal
int val;

void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
  lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
}

void loop() {
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("LED COM 2 CORES");
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("TWO COLOR");
  for(val = 255; val > 0; val--) { 
    analogWrite(redpin, val); //dim red
    analogWrite(greenpin, 255 - val); // brighten green
    delay(15);
  }
  for(val = 0; val < 255; val++) { 
    analogWrite(redpin, val); //brighten red
    analogWrite(greenpin, 255 - val); //dim green
    delay(15);
  }
}
