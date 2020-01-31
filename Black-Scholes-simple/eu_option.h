#ifndef _EU_OPTION_H_
#define _EU_OPTION_H_

#include <string>

class eu_option{

    private:
        void init();   //Initialize default values
        void copy(const eu_option &o2);
        double call_price() const;
        double put_price() const;
        double call_delta() const;
        double put_delta() const;

    public:
        double r;     //risk-free rate
        double sig;   //volatility
        double k;     //strike price
        double t;     //expiry
        double s_0;   //current price
        double b;     //cost of carry

        std::string o_type; //option type (C/P)

        //Constructors
        eu_option();  //default constructor
        eu_option(const eu_option &o2);  //copy constructor
        eu_option(const std::string &option_type);  //create option type

        ~eu_option(); //destructor

        //Assignment operator
        eu_option &operator=(const eu_option &opt2); 

        double price() const;
        double delta() const;

        //Modifier function
        void toggle(); //Change option type (C/P)


};

#endif