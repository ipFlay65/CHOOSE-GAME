#include <math.h>
#include <ctime>
#include <iostream>

//This function calculate the circumference of circle:
double circumferenceOfCircle(double radius){
    return 2*M_PI*radius;
}

//This function calculate the area of circle.
double areaOfCircle(double radius){
    return M_PI*radius*radius;
}

//This function give me a random number.
int random(){
    // Seed is initialized only once.
    static bool initialized;
    if(!initialized){
        std::srand(std::time(NULL));
        initialized = true;
    }

   int randNumber = std::rand();
   return randNumber;
}
