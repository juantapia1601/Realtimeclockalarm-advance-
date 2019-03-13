
#include "stm32f4xx.h"



GPIO_InitTypeDef GPIO_LED;
RTC_TimeTypeDef RTC_ALARM;

 void Delay(__IO uint32_t nCount) //RETARDO PARA LOS LEDS

 {	while(nCount--)
	 	{
	 	}
 }

int main(void)
{
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); //ACTIVAR RELOJ LEDS


	 //CONFIGURACION LEDS
	  GPIO_LED.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15  ;
	  GPIO_LED.GPIO_Mode = GPIO_Mode_OUT;
	  GPIO_LED.GPIO_OType = GPIO_OType_PP;
	  GPIO_LED.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_Init(GPIOD,&GPIO_LED); //los registro los manda a las seccion D


	  //CONFIGURACION ALARMA
	 RTC_ALARM.RTC_Hours = 8;
	 RTC_ALARM.RTC_Minutes = 30;
	 RTC_ALARM.RTC_Seconds = 0;
	 RTC_ALARM.RTC_H12 = AM;


  while (1) //AVISO DE ALARMA
  {

	  GPIO_WriteBit(GPIOD, GPIO_Pin_12, Bit_SET); //funcion que hace al pin 13 salida
	  GPIO_WriteBit(GPIOD, GPIO_Pin_15, Bit_RESET);
	  Delay(16800000);
	  GPIO_WriteBit(GPIOD, GPIO_Pin_13, Bit_SET);
	  GPIO_WriteBit(GPIOD, GPIO_Pin_12, Bit_RESET);
	  Delay(16800000);
	  GPIO_WriteBit(GPIOD, GPIO_Pin_14, Bit_SET);
	  GPIO_WriteBit(GPIOD, GPIO_Pin_13, Bit_RESET);
	  Delay(16800000);
	  GPIO_WriteBit(GPIOD, GPIO_Pin_15, Bit_SET);
	  GPIO_WriteBit(GPIOD, GPIO_Pin_14, Bit_RESET);
	  Delay(16800000);
  }
}
