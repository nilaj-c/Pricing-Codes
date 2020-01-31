#include "eu_option.h"
#include <math.h>

double normalCDF(double x);

void eu_option::init(){
    //initialize all default values

    //default values

    r = 0.08;
    sig = 0.30;
    k = 65.0;
    t = 0.25;
    s_0 = 60.0; 
    b = r;
    o_type = "C";

}

double eu_option::call_price() const {
    double tmp {}, d1 {}, d2 {}, tmp_price {};
    
    tmp = sig*sqrt(t);
    d1 = (log(s_0/k) + (b + (sig*sig)*0.5)*t)/tmp;
    d2 = d1 - tmp;

    tmp_price = s_0*exp((b-r)*t)*normalCDF(d1) - (k*exp(-r*t)*normalCDF(d2));

    return tmp_price;

}

double eu_option::put_price() const {
    double tmp {}, d1 {}, d2 {}, tmp_price {};

    tmp = sig*sqrt(t);

    d1 = ( log(s_0/k) + (b + (sig*sig)*0.5)*t)/tmp;
    d2 = d1 - tmp;

    tmp_price = (k*exp(-r*t)*normalCDF(-d2)) - (s_0*exp((b-r)*t)*normalCDF(-d1));

    return tmp_price;

}

double eu_option::call_delta() const {
    double tmp {}, d1 {}, tmp_delta {};

    tmp = sig*sqrt(t);

    d1 = (log(s_0/k) + (b + (sig*sig)*0.5)*t)/tmp;

    tmp_delta = exp((b-r)*t)*normalCDF(d1);

    return tmp_delta;

}

double eu_option::put_delta() const {
    double tmp {}, d1 {}, tmp_delta {};

    tmp = sig*sqrt(t);

    d1 = (log(s_0/k) + (b + (sig*sig)*0.5)*t)/tmp;

    tmp_delta = exp((b-r)*t)*(normalCDF(d1) - 1.0);

    return tmp_delta;

}

void eu_option::copy(const eu_option &o2){

    r = o2.r;
    sig = o2.sig;
    k = o2.k;
    t = o2.t;
    s_0 = o2.s_0;
    b = o2.b;
    o_type = o2.o_type;

}

//Constructor

eu_option::eu_option(){
    
    init();  //call option with default parameter values

}

//copy constructor

eu_option::eu_option(const eu_option &o2){

    copy(o2);

}

eu_option::eu_option(const std::string &option_type){

    init();
    o_type = option_type;

    if (o_type == "c"){
        o_type = "C";
    }

}

//Destructor

eu_option::~eu_option(){

}

//Assignment operator deep copy
eu_option &eu_option::operator=(const eu_option &opt2){

    if (this == &opt2){
        return *this;
    }

    copy(opt2);

    return *this;

}

double eu_option::price() const {

    if (o_type == "C"){
        return call_price();
    }
    else {
        return put_price();
    }

}

double eu_option::delta() const {

    if (o_type == "C"){
        return call_delta();
    }
    else {
        return put_delta();
    }

}

void eu_option::toggle() {

    if (o_type == "C"){
        o_type = "P";
    }
    else {
        o_type = "C";
    }

}

double normalCDF(double x) // Phi(-∞, x) aka N(x)
{
    return erfc(-x/sqrt(2.0))/2.0;
}
