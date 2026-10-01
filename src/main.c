#include <MKL28Z7.h>
#include "SysTick.h"
#include "gpio.h"


/* ------------------------------------------
       ECS642/ECS714 Lab1

   Demonstration of simple digital output using KL28Z
   Use RGB LED on Freedom board
   Introduction to cyclic systems
  -------------------------------------------- */

/* --------------------------------------
     Documentation
     =============
     WARNING: SOME PARTS OF THIS CODE ARE NOT EXPLAINED IN FULL IN WEEK 1

     The code has three principal functions
     1. main: this is where the program starts
        DO NOT CHANGE THIS FUNCTION
     2. configure: this setup the peripherals so the LEDs can be used
        DO NOT CHANGE THIS FUNCTION
     3. every10ms: this function runs every 10 ms
        *****EDIT THIS FUNCTION******

     There are also functions setRedLED, setGreenLED, setBlueLED
     Call these but do not change them

     FILE gpio.h
     - - - - - -
     This file contains some (macro) constants that are used here
     *****You may need to add or change constants*****
 -------------------------------------- */


/*----------------------------------------------------------------------------
  Turn LEDs on or off
    onOff can be ON or OFF
*----------------------------------------------------------------------------*/

void setRedLED(int onOff) {
  if (onOff == ON) {
    PTE->PCOR = MASK(RED_LED_POS);
  }
  if (onOff == OFF) {
    PTE->PSOR = MASK(RED_LED_POS);
  }
}


void setGreenLED(int onOff) {
  if (onOff == ON) {
    PTC->PCOR = MASK(GREEN_LED_POS);
  }
  if (onOff == OFF) {
    PTC->PSOR = MASK(GREEN_LED_POS);
  }
}


void setBlueLED(int onOff) {
  if (onOff == ON) {
    PTE->PCOR = MASK(BLUE_LED_POS);
  }
  if (onOff == OFF) {
    PTE->PSOR = MASK(BLUE_LED_POS);
  }
}


/*----------------------------------------------------------------------------
  every10ms - this function runs every 10ms

  Red    = 2 seconds
  Green  = 2 seconds
  Blue   = 2 seconds
  All OFF = 4 seconds

  Total cycle = 10 seconds
*----------------------------------------------------------------------------*/

int state = REDOFF;
int count = OFFPERIOD;


void every10ms() {

  if (count > 0) {
    count--;
  }

  switch (state) {

    /*------------------------------------------------
      RED
    ------------------------------------------------*/

    case REDOFF:

      if (count == 0) {
        setRedLED(ON);
        state = REDON;
        count = ONPERIOD;
      }

      break;


    case REDON:

      if (count == 0) {
        setRedLED(OFF);
        setGreenLED(ON);

        state = GREENON;
        count = ONPERIOD;
      }

      break;


    /*------------------------------------------------
      GREEN
    ------------------------------------------------*/

    case GREENON:

      if (count == 0) {
        setGreenLED(OFF);
        setBlueLED(ON);

        state = BLUEON;
        count = ONPERIOD;
      }

      break;


    /*------------------------------------------------
      BLUE
    ------------------------------------------------*/

    case BLUEON:

      if (count == 0) {
        setBlueLED(OFF);

        state = BLUEOFF;
        count = OFFPERIOD;
      }

      break;


    /*------------------------------------------------
      4 second OFF period
    ------------------------------------------------*/

    case BLUEOFF:

      if (count == 0) {
        setRedLED(ON);

        state = REDON;
        count = ONPERIOD;
      }

      break;
  }
}


/*----------------------------------------------------------------------------
  Configuration
  The GPIO ports for the LEDs are configured.
  This is not explained in week 1.
*----------------------------------------------------------------------------*/

void configure() {

  // Configuration steps
  //   1. Enable clock to GPIO ports
  //   2. Enable GPIO ports
  //   3. Set GPIO direction to output
  //   4. Ensure LEDs are off

  // Enable clock to ports C and E
  PCC_PORTC |= PCC_CLKCFG_CGC(1);
  PCC_PORTE |= PCC_CLKCFG_CGC(1);

  // Make 3 pins GPIO

  PORTE->PCR[RED_LED_POS] &= ~PORT_PCR_MUX_MASK;
  PORTE->PCR[RED_LED_POS] |= PORT_PCR_MUX(1);

  PORTC->PCR[GREEN_LED_POS] &= ~PORT_PCR_MUX_MASK;
  PORTC->PCR[GREEN_LED_POS] |= PORT_PCR_MUX(1);

  PORTE->PCR[BLUE_LED_POS] &= ~PORT_PCR_MUX_MASK;
  PORTE->PCR[BLUE_LED_POS] |= PORT_PCR_MUX(1);

  // Set ports to outputs

  PTE->PDDR |= MASK(RED_LED_POS) | MASK(BLUE_LED_POS);
  PTC->PDDR |= MASK(GREEN_LED_POS);

  // Turn off LEDs

  PTE->PSOR = MASK(RED_LED_POS) | MASK(BLUE_LED_POS);
  PTC->PSOR = MASK(GREEN_LED_POS);
}


/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/

int main (void) {

  configure();

  setRedLED(OFF);
  setGreenLED(OFF);
  setBlueLED(OFF);

  Init_SysTick(1000);

  waitSysTickCounter(10);

  while (1) {

    every10ms();

    waitSysTickCounter(10);
  }
}
