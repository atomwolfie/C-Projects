//
//  Rational.cpp
//  Reverse Polish Calculator
//
//  Created by Aaron Adams on 11/4/15.
//  Copyright (c) 2015 Aaron Adams. All rights reserved.
//

#include "Rational.h"

Rational :: Rational (int n, int d) : numerator(n), denominator(d){}


int Rational:: getDenominator() const {
    
    return  denominator;
}

void  Rational :: setDenominator(int d){
    
    denominator = d;
    
    
}

int Rational:: getNumerator() const {
    
    return numerator;
}

void Rational :: setNumerator(int n){
    
    numerator = n;
    
}



bool operator<(Rational const & a, Rational const & b) {
    
    return a.getNumerator() * b.getDenominator() < b.getNumerator() * a.getDenominator();
    
    
}

bool operator==(Rational const & a, Rational const & b){
    
    if(a.getNumerator() != b.getNumerator() || a.getDenominator() != b.getDenominator()){
        
        return false;
    }
    
    else{
        
        return true;
    }
    
    
}

bool operator != (Rational const & a, Rational const & b){
    
    
    
    return!(a == b);
}

bool operator > (Rational const & a, Rational const & b){
    
    
    return a.getNumerator() * b.getDenominator() > b.getNumerator() * a.getDenominator();
    
}

bool operator <= (Rational const & a, Rational const & b){
    
    
    return a.getNumerator() * b.getDenominator() <= b.getNumerator() * a.getDenominator();
}

bool operator >= (Rational const & a, Rational const & b){
    
    
    return a.getNumerator() * b.getDenominator() >= b.getNumerator() * a.getDenominator();
    
}


Rational ::  operator double(){
    
    
    return static_cast<double> (numerator/ denominator);
}



Rational operator + (Rational const & left, Rational const & right){
    
    Rational result;
    
    Rational newLeft = left;
    
    
    newLeft.setNumerator(left.getNumerator() * right.getDenominator());
    newLeft.setDenominator(newLeft.getDenominator() * right.getDenominator());
    
    Rational newRight (right.getNumerator() * left.getDenominator(), right.getDenominator()* left.getDenominator());
    
    
    
    result.setNumerator(newLeft.getNumerator() + newRight.getNumerator());
    
    result.setDenominator(newLeft.getDenominator());  //need to make gcd function and simplify function that uses gcd
    
    result.Simplify();
    
    
    return result;
    
    
    
}

Rational operator - (Rational const& left, Rational const& right){
    
    Rational result;
    
    Rational newLeft = left;
    
    
    newLeft.setNumerator(left.getNumerator() * right.getDenominator());
    newLeft.setDenominator(newLeft.getDenominator() * right.getDenominator());
    
    Rational newRight (right.getNumerator() * left.getDenominator(), right.getDenominator()* left.getDenominator());
    
    
    
    result.setNumerator(newLeft.getNumerator() - newRight.getNumerator());
    result.setDenominator(newRight.getDenominator());
    
    result.Simplify();
    
    return result;
}

Rational operator * (Rational const& left, Rational const& right){
    
    Rational result;
    
    result.setNumerator(left.getNumerator() * right.getNumerator());
    
    result.setDenominator(left.getDenominator() * right.getDenominator());
    
    result.Simplify();
    
    return result;
}

Rational operator / (Rational const& left, Rational const& right){
    
    Rational result;
    
    result.setNumerator(left.getNumerator() * right.getDenominator());
    
    result.setDenominator(left.getDenominator() * right.getNumerator());
    
    result.Simplify();
    
    return result;
}


Rational& Rational :: operator += (const Rational & r){
    
    numerator = r.getNumerator() * denominator + r.getDenominator() * numerator;
    
    denominator = r.getDenominator() * denominator;
    
    Simplify();
    
    return *this;
}


Rational& Rational :: operator -= (const Rational &r){
    
    numerator = numerator * r.denominator - denominator * r.numerator;
    
    denominator = r.denominator * denominator;
    
    Simplify();
    
    return *this;
}


Rational& Rational :: operator *= (const Rational &r){
    
    numerator = r.numerator * numerator;
    
    denominator = r.denominator * denominator;
    
    Simplify();
    
    return *this;
}

Rational& Rational :: operator /= (const Rational &r){
    
    if (r.numerator == 0)
    
    throw "Cannot divide by zero";
    
    numerator = numerator * r.denominator;
    
    denominator = denominator * r.numerator;
    
    Simplify();
    
    return *this;
}


int Rational :: gcd(){
    
    int A = numerator;
    int B = denominator;
    
    int Temp;
    
    while(B){
        
        Temp = B;
        
        B = A%B;
        
        A = Temp;
    }
    
    return A;
}



void Rational::Simplify(){
    
    int GCDNumber = gcd();
    
    if(GCDNumber != 0){
        
        numerator = numerator / GCDNumber;
        
        denominator = denominator  / GCDNumber;
    }
    
    if(denominator < 0){
        
        numerator *= -1;
        denominator *=-1;
        
    }
}


std::istream & operator>>(std::istream & in , Rational & a){
    
    int n, d;
    
    in >> n;
    
    char temp;
    
    in >> temp;
    
    if(temp == '/'){
        
        in >> d;
        
        a = Rational(n,d);
        
    }
    
    else{
        
        a = Rational(n,1);
        
    }
   
    
    return in;
}




std::ostream & operator<<(std::ostream & out , Rational const& a){
    
    out << a.getNumerator() << '/' << a.getDenominator();
    
    return out;
}



