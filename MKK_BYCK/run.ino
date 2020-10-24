int zz = 0;
int ss = 0;
void controlCompII() {
  vprevious = rpm + rpm1;

  //  if ((int)vprevious == 0 && zz > 0) {
  //    lcd.setCursor(13, 0);
  //    lcd.print("[-]");
  //    Keyboard.press('-');
  //    Keyboard.releaseAll();
  //    delay(500);
  //    zz--;
  //  }

  if (vprevious > mph )  //Speed Up Video speed
  {
    lcd.setCursor(13, 0);
    lcd.print("[-]");
    Keyboard.press('-');
    Keyboard.releaseAll();
    delay(200); //ปั่นเร็วขึ้นให้ลด
    ss = 1;
  }

  if ((int)vprevious < (int)mph )  //Slow Down Video Speed
  {
    lcd.setCursor(13, 0);
    lcd.print("[+]");
    Keyboard.press('+');
    Keyboard.releaseAll();
    delay(600);   //ปั่นเร็วขึ้นให้ลด
    ss = 1;
  }

  if (ss == 0) {  
    lcd.setCursor(13, 0);
    lcd.print("[.]");
    Keyboard.press('-');
    Keyboard.releaseAll();
    delay(200); //ค่อยๆ หยุดให้เพิ่ม
  }

  if ((int)vprevious == (int)mph) //do nothing
  {
    lcd.setCursor(13, 0);
    lcd.print("[#]");
    ss = 0;
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
  Serial.print(mph);
  Serial.print(" - ");
  Serial.println(zz);
}
