#include "mbed.h"
#include "max32630fthr.h"
#include "USBSerial.h"

DigitalOut led1(LED1); // internal red LED
DigitalOut pin1(AIN_0); // trying to find a output pin on the board
MAX32630FTHR pegasus;

// main() runs in its own thread in the OS
// (note the calls to Thread::wait below for delays)
int main()
{
    pegasus.init(MAX32630FTHR::VIO_3V3);
    
    while(true) {
        pin1 = !pin1;
        led1 = !led1; // cycles state of the internal LED
        Thread::wait(500);
    }
}
