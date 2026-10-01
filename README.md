# Lab 1 What I learnt

This code is provided for lab exercise 1. First read it and then run it, before making any changes.

The code flashes two of the on-board LEDs on the KL28Z development board.



Embedded Systems – Semester A – Lab 1

Work Completed



This lab was completed using the FRDM-KL28Z development board and the Keil µVision development environment.

Activity 1 – Build and Run Starter Project



Cloned the GitHub Classroom repository containing the starter code.



Built the project in Keil µVision.



Downloaded the compiled program to the FRDM-KL28Z board.



Ran the starter program and observed the red and green LEDs changing state.



Activity 2 – Debugging and Program Inspection



Used the Keil debugger to run the program in debug mode.



Set a breakpoint and stepped through the program instructions.



Inspected the corresponding ARM assembly instructions for the C code.



Used the debugger to inspect the GPIO registers and identify the memory address associated with the green LED output.



Activity 3 – Modify the LED Program



The starter program was modified to control all three RGB LED colours.



The program was changed so that:



The red LED is displayed for 2 seconds.



The green LED is displayed for 2 seconds.



The blue LED is displayed for 2 seconds.



The colours change directly from one colour to the next without a gap.



The complete sequence repeats every 10 seconds.



The program continues running indefinitely as a cyclic system.



The timing values in gpio.h were modified to use the 10 ms system tick. The state machine in every10ms() was also modified to include the blue LED and the required colour sequence.



Activity 4 – GitHub



Committed the completed changes to the local Git repository.



Pushed the changes to the GitHub repository.



Updated this README to describe the work completed.

