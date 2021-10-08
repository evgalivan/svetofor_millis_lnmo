/*
 * 
 * Это желтый фонарь светофора
 * 
 */
void svet_yel(unsigned int cur_time, unsigned int n_time)
{
  Serial.println("if=yes Yellow On");
  if(cur_time >=  n_time) // пришло время что-то делать
  {
    digitalWrite(pin_Yellow, LOW); // меняем состояние светодиода
    svet_state = 1; // to Red
    digitalWrite(pin_Red, HIGH);
    next_time = (millis() + period_Red);
  }
}
