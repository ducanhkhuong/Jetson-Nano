#include <iostream>
#include <string>
#include <unistd.h>
#include "jetsonGPIO.h"

using namespace std;

int main(){
//setup
    jetsonGPIO led2 = gpio78 ; //pin40
    jetsonGPIO led3 = gpio76;  //pin35
    jetsonGPIO led4 = gpio12;  //pin37
    
    gpioExport(led2);
    gpioExport(led3);
    gpioExport(led4);
    gpioSetDirection(led2,OUTPUT);
    gpioSetDirection(led3,OUTPUT);
    gpioSetDirection(led4,OUTPUT);

    gpioSetValue(led2, LOW);
    gpioSetValue(led3, LOW);
    gpioSetValue(led4, LOW);
//loop
    while(1){
        cout << "Status : Red" << endl ;
        gpioSetValue(led2, HIGH);
        gpioSetValue(led3, LOW);
        gpioSetValue(led4, LOW);
        sleep(1);
        cout << "Status : Green" << endl ;
        gpioSetValue(led2, LOW);
        gpioSetValue(led3, HIGH);
        gpioSetValue(led4, LOW);
        sleep(1);
        cout << "Status : Blue" << endl ;
        gpioSetValue(led2, LOW);
        gpioSetValue(led3, LOW);
        gpioSetValue(led4, HIGH);
        sleep(1);
    }
}