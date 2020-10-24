void read_in() {
  level  = analogRead(pot);
  button = digitalRead(sw);
  A = digitalRead(pin_A);
  B = !digitalRead(pin_B);
}
