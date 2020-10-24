#define INTERVAL_MESSAGE1 1200 //5วินาที
#define INTERVAL_MESSAGE2 800 //7วินาที
#define INTERVAL_MESSAGE3 1000 //11วินาที
#define INTERVAL_MESSAGE4 1500 //13วินาที
 
unsigned long time_x = 0;
unsigned long time_y = 0;
unsigned long time_3 = 0;
unsigned long time_4 = 0;
 
void print_time(unsigned long time_millis);


#include <Wire.h>
#include <Keyboard.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int sen  = A0;
int sen1 = A1;
int pot = A5;
int sw  = A4;
int A, B;
int pin_A = A0;
int pin_B = A1;
int level  = 0;
int button = 0;
//-------------------------------

const float wid = 0.012;   //adjust the width of the fan blade according to your needs.
const float rad = 0.045;   //adjust the radius of the point of detection in the fan blade.
const float konst = 6.2832;  //  2*pi.
float time_1;
float time_2;
float vel;
float diff;
float tnet;
float rpm;

//-----------------------------

const float wid1 = 0.012;   //adjust the width of the fan blade according to your needs.
const float rad1 = 0.045;   //adjust the radius of the point of detection in the fan blade.
const float konst1 = 6.2832;  //  2*pi.
float time_11;
float time_21;
float vel1;
float diff1;
float tnet1;
float rpm1;
//-----------------------------

void setup() {
  Keyboard.begin();
  Serial.begin(9600);
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);

  pinMode(sen, INPUT);
  pinMode(sen1, INPUT);
  lcd.init();
  lcd.backlight();
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nurs"); delay(120);
  lcd.print("ing"); delay(120);
  lcd.print("_"); delay(120);
  lcd.print("Sci"); delay(120);
  lcd.print("ence."); delay(120);
  lcd.setCursor(0, 1);
  lcd.print("K"); delay(120);
  lcd.print("K"); delay(120);
  lcd.print("U"); delay(120);
  lcd.print("_"); delay(120);
  lcd.print("E"); delay(120);
  lcd.print("x"); delay(120);
  lcd.print("e"); delay(120);
  lcd.print("r"); delay(120);
  lcd.print("c"); delay(120);
  lcd.print("i"); delay(120);
  lcd.print("s"); delay(120);
  lcd.print("e"); delay(120);
  lcd.print(" "); delay(120);
  lcd.print("V"); delay(120);
  lcd.print("."); delay(120);
  lcd.print("1"); delay(120);

  lcd.setCursor(0, 0);
  lcd.print("Nursing_Science.");
  lcd.setCursor(0, 1);
  lcd.print("KKU_Exercise V.1"); delay(500);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");  delay(200);
  lcd.setCursor(0, 0);
  lcd.print("Nursing_Science.");;
  lcd.setCursor(0, 1);
  lcd.print("KKU_Exercise V.1"); delay(500);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");  delay(200);
  lcd.setCursor(0, 0);
  lcd.print("Nursing_Science.");;
  lcd.setCursor(0, 1);
  lcd.print("KKU_Exercise V.1"); delay(500);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");  delay(200);
  lcd.setCursor(0, 0);
  lcd.print("Nursing_Science.");;
  lcd.setCursor(0, 1);
  lcd.print("KKU_Exercise V.1"); delay(500);
  delay(3000);
  lcd.clear();
}
int button_old = 0;


void loop() {
  
  read_in();
  if (button != button_old) {
    Keyboard.press('z');
    Keyboard.releaseAll();
    lcd.clear();
  }
  button_old = button;
  if (button == 1) {
    lcd.setCursor(0, 0);
    lcd.print("MODE_TEST !");
    controlComp();
    lcd.setCursor(0, 1);
    lcd.print(button);  lcd.print(" ");
    lcd.setCursor(5, 1);
    lcd.print(level);   lcd.print(" ");
    lcd.setCursor(10, 1);
    lcd.print(A);  lcd.print(" ");
    lcd.setCursor(13, 1);
    lcd.print(B);   lcd.print(" ");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("MODE_RUN!!!");
    control();
    lcd.setCursor(0, 1);
    lcd.print(button);
    lcd.print(A);
    lcd.print(B);
    lcd.setCursor(4, 1);
    lcd.print(rpm);    lcd.print(" ");
    lcd.setCursor(10, 1);
    lcd.print(rpm1);   lcd.print(" ");
  }
}
