
void print_time(unsigned long time_millis){
    Serial.print("Time: ");
    Serial.print(time_millis/1000);
    Serial.print("s - ");
}

int mode = 0;
int m = 0;
float vprevious, mph;

void controlComp() {
  vprevious = level;
  if (vprevious < mph )  //Speed Up Video speed
  {
    lcd.setCursor(13, 0);
    lcd.print("[-]");
    
    Keyboard.press('-');
    Keyboard.releaseAll();
    delay(300);
  }
  if (vprevious > mph )  //Slow Down Video Speed
  {
    lcd.setCursor(13, 0);
    lcd.print("[+]");
    +
    Keyboard.press('+');
    Keyboard.releaseAll();
    delay(300);
  }
  if (vprevious == mph) //do nothing
  {
    lcd.setCursor(13, 0);
    lcd.print("[#]");
  }
  mph = vprevious;

  Serial.print(button);
  Serial.print(" ");
  Serial.print(level);
  Serial.print(" -> ");
  Serial.print(m);
  Serial.print(" - ");
  Serial.print(vprevious);
  Serial.print(" - ");
  Serial.println(mph);
}
