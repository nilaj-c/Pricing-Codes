#include "eu_option.h"
#include <iostream>

using namespace std;

int main(){

    eu_option c1;

    cout << "The default call option price: " <<c1.price() << endl;

    c1.toggle();

    cout << "The default put option price: " <<c1.price() << endl;

    eu_option p1;
    p1.o_type = "P";
    p1.s_0 = 100.0;
    p1.k = 95.0;
    p1.t = 0.5;
    p1.r = 0.1;
    p1.sig = 0.2;
    double q = 0.05;
    p1.b = p1.r - q;

    cout << "Put option price: " << p1.price() << endl;

    return 0;
}