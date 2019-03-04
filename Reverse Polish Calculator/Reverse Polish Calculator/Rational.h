//
//  Rational.h
//  Reverse Polish Calculator
//
//  Created by Aaron Adams on 11/4/15.
//  Copyright (c) 2015 Aaron Adams. All rights reserved.
//

#ifndef Reverse_Polish_Calculator_Rational_h
#define Reverse_Polish_Calculator_Rational_h


#include <iostream>
#include<ostream>
#include<istream>
#include<fstream>

class Rational {
    
    public:
    
    Rational(int n = 0, int d = 1);
    Rational(Rational const&) = default;
    operator float();
    operator double();
    Rational& operator+=(Rational const &);
    Rational& operator-=(Rational const &);
    Rational& operator*=(Rational const &);
    Rational& operator/=(Rational const &);
    Rational& operator=(Rational const&) = default;
    int getNumerator()const;
    int getDenominator()const;
    void setNumerator(int);
    void setDenominator(int);
    void Simplify();
    int gcd();
    
    private:
    
    int numerator; int denominator;
};


bool operator < (Rational const &, Rational const &);
bool operator == (Rational const &, Rational const &);
bool operator != (Rational const &, Rational const &);
bool operator > (Rational const &, Rational const &);
bool operator <= (Rational const &, Rational const &);
bool operator >= (Rational const &, Rational const &);
Rational operator + (Rational const &,Rational const &);
Rational operator - (Rational const &,Rational const &);
Rational operator * (Rational const &,Rational const &);
Rational operator / (Rational const &,Rational const &);
std::ostream & operator<<(std::ostream &, Rational const&);
std::istream & operator>>(std::istream &, Rational &);



#endif
