// blink.cpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <unistd.h>
#include "jetsonGPIO.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "NVIDIA Jetson TX2 Blink demo." << endl;
    cout << "Flashing the LED connected to PIN32 (gpio297)" << endl;
    jetsonTX2GPIONumber redLED = gpio297; // Ouput
    // Make the button and led available in user space
    gpioExport(redLED);
    gpioSetDirection(redLED, outputPin);

    // Flash the LED 5 times
    while (true)
    {
        cout << "Setting the LED on" << endl;
        gpioSetValue(redLED, on);
        usleep(1000000); // on for 200ms
        cout << "Setting the LED off" << endl;
        gpioSetValue(redLED, off);
        usleep(1000000); // off for 200ms
    }

    return 0;
}
