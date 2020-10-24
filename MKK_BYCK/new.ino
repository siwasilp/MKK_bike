
void control()
{
  sen00();
  sen11();
  Serial.print(" > ");
  Serial.print( rpm );
  Serial.print(" ");
  Serial.println( rpm1 );
  controlCompII();
}

void sen00()
{
  if (analogRead(sen) > 500)
  {
    time_1 = millis();
    delay(30);
  }
  if (analogRead(sen) < 500)
  {
    time_2 = millis();
    diff = (time_2 - time_1);
    vel = wid / diff;
    tnet = (konst * rad) / vel;
    rpm = (60000) / tnet;
  }
}

void sen11()
{
  if (analogRead(sen1) < 500)
  {
    time_11 = millis();
    delay(30);
  }
  if (analogRead(sen1) > 500)
  {
    time_21 = millis();
    diff1 = (time_21 - time_11);
    vel1 = wid1 / diff1;
    tnet1 = (konst1 * rad1) / vel1;
    rpm1 = (30000) / tnet1 * 10;//---------------
  }
}
