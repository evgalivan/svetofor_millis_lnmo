/*
 * 
 * Это зеленый сигнал светофора
 * 
 */
void svet_grn(unsigned int cur_time, unsigned int n_time)
{
  if(cur_time >= n_time) // пришло время что-то делать
  {
    digitalWrite(pin_Green, LOW); // меняем состояние светодиода
    svet_state = 4; // to blink
    // digitalWrite(pin_Yellow, HIGH);
    next_time  = cur_time + period_GreenBl;
    blink_time = cur_time + period_Blink;
  }
}
