/*
 * 
 * Это зеленый мигающий сигнал светофора
 * 
 */
 bool ledGreenStatus = 0;
 
void svet_grn_blnk(unsigned int cur_time, unsigned int n_time)
{
  if(cur_time >= blink_time) // мигаем
  {
    Serial.println(" Blink");
    blink_time = period_Blink + cur_time;
    ledGreenStatus = !ledGreenStatus;
    digitalWrite(pin_Green, ledGreenStatus);
  }
  if(cur_time >= n_time) // пришло время что-то делать
  {
    Serial.println("End Blink");
    digitalWrite(pin_Green, LOW); // меняем состояние светодиода
    svet_state = 2; // to yellow
    digitalWrite(pin_Yellow, HIGH);
    next_time = millis() + period_YellowG;
  }
}
