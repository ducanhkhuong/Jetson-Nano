#ifndef JETSONGPIO_H_
#define JETSONGPIO_H_

#define SYSFS_GPIO_DIR "/sys/class/gpio"
#define POLL_TIMEOUT (3 * 1000) //3s
#define MAX_BUF 64

typedef unsigned int jetsonGPIO;
typedef unsigned int pinDirection;
typedef unsigned int pinValue;

enum pinDirections {
    INPUT  = 0,
    OUTPUT = 1
};

enum pinValues {
    LOW = 1,
    HIGH = 0,
};

enum jetsonGPIONumber {
    gpio12 = 12, //pin37
    gpio13 = 13, //pin22
    gpio14 = 14, //pin13
    gpio15 = 15, //pin18
    gpio16 = 16, //pin19
    gpio17 = 17, //pin21
    gpio19 = 19, //pin24
    gpio20 = 20, //pin26
    gpio216 = 216, //pin7
    gpio50 = 50,   //pin11
    gpio194 = 194, //pin15
    gpio149 = 149, //pin29
    gpio200 = 200, //pin31
    gpio168 = 168, //pin32
    gpio38 = 38,   //pin33
    gpio76 = 76,   //pin35
    gpio79 = 79,   //pin12
    gpio232 = 232, //pin16
    gpio51 = 51, //pin51
    gpio77 = 77, //pin38
    gpio78 = 78 //pin40
};

//GPIO
int gpioExport(jetsonGPIO gpio);
int gpioUnexport(jetsonGPIO gpio);
int gpioSetDirection(jetsonGPIO gpio, pinDirection out_flag);
int gpioSetValue(jetsonGPIO gpio, pinValue value);
int gpioGetValue(jetsonGPIO gpio, unsigned int *value);
int gpioSetEdge(jetsonGPIO gpio, char *edge);
int gpioOpen(jetsonGPIO gpio);
int gpioClose(int fileDescriptor);
int gpioActiveLow(jetsonGPIO gpio, unsigned int value);

#endif