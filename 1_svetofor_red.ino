/*
 * Это красный фонарь светофора
 * Arguments:
 *  cur_time  - время вызова функции (текущее)
 *  n_timeR   - время работы красного 
 *  n_timeY   - время работы красного с желтым
 * Как это работает:
 *  если текущее время больше, чем общее красное без желтого,
 *  включается желтый. Если текущее превышает время работы красного,
 *  то цвета гасятся, меняется режим и высчитывается время
 *  окончания работы следующего - зеленого цвета.
 */
void svet_red(unsigned int cur_time, unsigned int n_timeR, unsigned int n_timeY)
{
  if(cur_time >= (n_timeR - n_timeY)) // время работы желтого и красного вместе
    digitalWrite(pin_Yellow, HIGH);
  if(cur_time >= n_timeR) // пришло время что-то делать
  {
    //Serial.println("if=yes Red Off");
    digitalWrite(pin_Red, LOW); // меняем состояние светодиода
    digitalWrite(pin_Yellow, LOW);
    svet_state = 3;  // переходим к зеленому свету
    digitalWrite(pin_Green, HIGH);
    next_time = millis() + period_Green;
  }
}
