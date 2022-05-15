#include <iostream>
#include <string>
#include <functional>
#include <cmath>


//angle structure with constrained value with range of -pi to pi
struct angle{
    const float value;

    angle(float x): value(angle_conversion(x)){}

    angle operator+ (angle y){
        return angle(this->value + y.value);
    }

    angle operator- (angle y){
        return angle(this->value - y.value);
    }

    private:
        //function to convert angle to be in range of -pi to pi, kept private for secure
        float angle_conversion(float alfa){
        if(alfa>-M_PI && alfa<=M_PI)
            return alfa;
        else if(alfa>0)
            return angle_conversion(alfa-2*M_PI);
        else
            return angle_conversion(alfa+2*M_PI);
        }
};


int main() {

    angle x(0.7);
    std::cout<<"x.value: "<<x.value<<std::endl;
    
    angle y = x + angle(0.1); // y.value should be 0.8
    std::cout<<"y.value: "<<y.value<<std::endl;

    angle z(5); // z.value should be 5 - 2pi
    std::cout<<"z.value: "<<z.value<<std::endl;
    
}