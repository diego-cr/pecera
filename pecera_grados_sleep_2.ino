#include "LowPower.h"
#include <CheapStepper.h>

CheapStepper stepper (8,9,10,11); 
boolean moveClockwise = true;

long siesta = 17; // horas a dormir
long siesta_seg = siesta * 450; // horas a segundos/8

long siesta2 = (24-siesta); // horas a dormir
long siesta2_seg = siesta * 450; // horas a segundos/8

int grados = 204.8;
int posicion = 0;


void setup() {
  stepper.setRpm(10);
   mueve(); // posicion 0
   mueve(); // posicion 0 + grados

//test!
//siesta_seg=1;
//siesta2_seg=2;

}

void loop() {

  for (int i=0;i<siesta_seg;i++)    // Vamos a la siesta
    LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,SPI_OFF, USART0_OFF, TWI_OFF);
  mueve();
  
  for (int ii=0;ii<siesta2_seg;ii++)    // Vamos a la siesta2
    LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,SPI_OFF, USART0_OFF, TWI_OFF);
  mueve();

}

int mueve(){
  stepper.moveTo (moveClockwise, posicion);
  posicion = posicion + grados;
  stepper.off();
  if (posicion >= 4070)  posicion = 0;

}
