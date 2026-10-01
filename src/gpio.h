#ifndef GPIO_H
#define GPIO_H

// ECS714P/ECS642U Lab 1 definitions

// Create a bit mask (32 bits) with only bit x set
#define MASK(x) (1UL << (x))

// Freedom KL28Z LEDs pin numbers
#define RED_LED_POS (29)        // on port E
#define GREEN_LED_POS (4)       // on port C
#define BLUE_LED_POS (31)       // on port E

// Symbols for constants
#define OFF 0
#define ON 1

// Time periods in 10ms units
#define ONPERIOD 200            // 200 x 10ms = 2 seconds
#define OFFPERIOD 400           // 400 x 10ms = 4 seconds

// States
#define REDOFF 0
#define REDON 1
#define GREENOFF 2
#define GREENON 3
#define BLUEOFF 4
#define BLUEON 5

#endif