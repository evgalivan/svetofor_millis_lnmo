/*
  ЛНМО 2021 (С)

  Курс "Микроконтроллеры"
  Тема Таймер
  Пример реализации светофора 
  при помощи функции millis()

  Как это работает:
  в зависимости от текущего состояния svet_state,
  в основном цикле loop() вызывается фукция проверки
  срабатываения соответствующего таймера.  
  Пины управляются "1", общая у LED - GND.
  Работаем через глобальные переменные.
 
*/
#include <SoftwareSerial.h>
#define DEBUG

// Прописываем порты светодиодов
int pin_Red    = 3; // крсаный свет
int pin_Yellow = 4; // желтый цвет
int pin_Green  = 5; // зелёный цвет

// Устанавливаем время работы каждого цвет
unsigned int period_Red     = 5000;
unsigned int period_YellowR = 2000; // время работы желтого совместно с красным
unsigned int period_YellowG = 2000; // время работы желтого после зеленого
unsigned int period_Green   = 3000; // время работы зеленого сплошного
unsigned int period_GreenBl = 3000; // время мигания зеленого светофора
unsigned int period_Blink   = 600;

unsigned int next_time = 0; // время до включения следующего цвета
unsigned int blink_time = 0;// время до мигания
 
int svet_state = 1;         // текущее состояние светофора
bool led_state = 0;
bool led_state_r = 0;       // текущее состояние красного (on/off)
bool led_state_y = 0;       // текущее состояние желтого  (on/off)
bool led_state_g = 0;       // текущее состояние зеленого (on/off)

//
// the setup function runs once when you press reset or power the board
//
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pin_Red,    OUTPUT);
  pinMode(pin_Yellow, OUTPUT);
  pinMode(pin_Green,  OUTPUT);
  
  // Гасим всех
  digitalWrite(pin_Red, HIGH);  // начинаем работу с красного
  digitalWrite(pin_Yellow, LOW);
  digitalWrite(pin_Green, LOW);

  next_time = millis() + period_Red;
  
  // DEBUG - вывод отладочных сообщений
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
}

// 
// the loop function runs over and over again forever
//
void loop() {
  unsigned int current_time = millis(); // узнаем текущее время
  
  // выбираем работу в зависимости от текущего статуса
  if( svet_state == 1){
    Serial.println("RED");
    svet_red(current_time, next_time, period_YellowR);
    
  }
  else if (svet_state == 2){
    Serial.println("YELLOW");
    svet_yel(current_time, next_time);
  }
  else if (svet_state == 3){
    Serial.println("GREEN");
    svet_grn(current_time, next_time);
  }
  else if (svet_state == 4){
    Serial.println("GREEN BLINK");
    svet_grn_blnk(current_time, next_time);
  }
  else
    Serial.println("Error!");

  // в этом месте может быть любая работа:
  delay(300);
                
}
