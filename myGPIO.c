/*
 * GPIO.c
 *
 *  Created on:03/03/2020
 *      Author: Jay Patel
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"
#define PRESSED 0
#define LPad_Right BIT4        //Launchpad Right Button
#define LPad_Left BIT1         //Launchpad Right Button
#define Booster_1 BIT1         //Boosterpack Top Button
#define Booster_2 BIT5         //Boosterpack Bottom Button
#define LeftLED BIT0           //Left LED of Launchpad
#define RightLED_Red BIT0      //Right LED RED of Launchpad
#define RightLED_Green BIT1    //Right LED GREEN of Launchpad
#define RightLED_Blue BIT2     //Right LED BLUE of Launchpad
#define BoosterLED_Red BIT6    //Boosterpack LED RED
#define BoosterLED_Green BIT4  //Boosterpack LED GREEN
#define BoosterLED_Blue BIT6   //Boosterpack LED BLUE
// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1
    P1DIR &= ~LPad_Left;
    P1REN |= LPad_Left;

    // Launchpad S2
    P1DIR &= ~LPad_Right;
    P1REN |= LPad_Right;

    // Boosterpack S1
    P3DIR &= ~Booster_1;
    P3REN |= Booster_1;

    // Boosterpack S2
    P3DIR &= ~Booster_2;
    P3REN |= Booster_2;

    // Launchpad LED1
    P1DIR |= LeftLED;

    // Launchpad LED2 Red
    P2DIR |= RightLED_Red;

    // Launchpad LED2 Green
    P2DIR |= RightLED_Green;

    // Launchpad LED2 Blue
    P2DIR |= RightLED_Blue;

    // Boosterpack LED Red
    P2DIR |= BoosterLED_Red;

    // Boosterpack LED Green
    P2DIR |= BoosterLED_Green;

    // Boosterpack LED Blue
    P5DIR |= BoosterLED_Blue;

    // Turn off all LEDs at the start.
    P1OUT &= ~LeftLED;
    P2OUT &= ~RightLED_Red;
    P2OUT &= ~RightLED_Green;
    P2OUT &= ~RightLED_Blue;
    P2OUT &= ~BoosterLED_Red;
    P2OUT &= ~BoosterLED_Green;
    P5OUT &= ~BoosterLED_Blue;
}

// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return(GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1));
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return(GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN4));
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return(GPIO_getInputPinValue(GPIO_PORT_P5, GPIO_PIN1));
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return(GPIO_getInputPinValue(GPIO_PORT_P3, GPIO_PIN5));
}

// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0);
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0);
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1);
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1);
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN6);
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN6);
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN4);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN4);
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    GPIO_setOutputHighOnPin(GPIO_PORT_P5, GPIO_PIN6);
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN6);
}
