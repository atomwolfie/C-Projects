//Calculator
//Aaron Adams
//Created in Xcode

#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;


void addition (double, double);
void subtraction (double, double);
void multiplication (double, double);
void division (double, double);
void modulo (int, int);
void power (double, double);
void equals (double, double);
void lessThan (double, double);
void greaterThan (double, double);
void randomNumber (int, int);


int main() {
    
    double num1, num2;
    char operation;
    
    cout << "Welcome to the calculator \n";
    
    cout << "Valid operators include +,-,*,/,%,^,=,<,>,?" << endl;
    
    cout << "Enter 0:0 and return to quit" << endl << endl;
    
    cout << "Enter equation" << endl;
    
    cin >> num1 >> operation >> num2;
    
        
    while (num1 !=0){
    
    
    switch(operation)
    {
        case '+':
            
            addition (num1, num2);
            
            break;
            
        case '-':
            
            subtraction (num1, num2);
            
            break;
            
        case '*':
            
            multiplication (num1, num2);
            
            break;
        
         case '/':
            
            division (num1, num2);
            
            break;
            
          
         case '%':
            
            modulo(num1, num2);
            
            break;
            
         case '^':
            
            power(num1, num2);
            
            break;
            
         case '=':
            
            equals (num1, num2);
            
            break;
            
          case '<':
            
            lessThan (num1, num2);
            
            break;
            
           case '>':
            
            greaterThan (num1, num2);
            
            break;
            
            case '?':
            
            randomNumber (num1, num2);
            
            break;
            
        
        default:
            cout << "Unable to compute" << endl;
            cout << "Valid operators include +,-,*,/,%,^,=,<,>,?" << endl;
            
            cout << "Enter equation (or enter 0:0 and return to quit): " << endl << endl;
            
            cin >> num1 >> operation >> num2;
            
            return -1;
    }
    
        cout << "Enter another equation (or enter 0:0 and return to quit) \n";
        
        
        cin >> num1 >> operation >> num2;
        
    
    
    
    }
    
    
    
    cout << "Goodbye!" << endl;
    
    return 0;
    }
    




void addition (double num1, double num2){
    
    double answer;
    
    answer = num1 + num2;
    
    cout << answer << endl;
}

void subtraction (double num1, double num2){
    double answer;
    
    answer = num1 - num2;
    
    cout << answer << endl;
}

void multiplication (double num1, double num2){
    double answer;
    
    answer = num1 * num2;
    
    cout << answer << endl;
}

void division (double num1, double num2){
    double answer;
    
    if (num2 == 0){
        cout << "cant divide by 0" << endl;
        
    }
    
    else {
    answer = num1 / num2;
    
    cout << answer << endl;
        
    }
}


void modulo (int num1, int num2){
    int answer;
    
    answer = num1 % num2;
    
    if (num2 == 0){
        
        cout << "Can't do modulur division of 0" << endl;
    }
   
    else if (num2 > num1){
        
        cout << "second number cannot be greater than first number" << endl;
    }
    else {
    
    cout << answer << endl;
   
    }
}

void power (double num1, double num2){
    int answer;
    
    answer = pow (num1, num2);
    
    cout << answer << endl;
}

void equals (double num1, double num2){
    
    
    if (num1 == num2){
        
        cout << " 1 ";
    }
    
    else {
        
        cout << " 0 " << endl;
        
    }
}

void lessThan (double num1, double num2){
    
    if (num1 < num2){
        
        cout << " 1 " << endl;
    }
    
    else {
        
        cout << " 0 " << endl;
        
    }
}

void greaterThan (double num1, double num2){
    
    if (num1 > num2){
        
        cout << " 1 " << endl;
    }
    
    else {
        
        cout << " 0 " << endl;
    }
    
}

void randomNumber (int num1, int num2){
    int seed;
    
    num1 = seed;
    
    srand (seed);
    
    if (num2 < 0){
        
        cout << "Operands cannot be negative for the ? operator!" << endl;
    }
    
    else{
    cout << rand () % num2 + 1 << endl;
        
    }
    
    }




   