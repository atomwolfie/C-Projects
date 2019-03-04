// Aaron Adams
// Created in Xcode
// Age Benefits


#include <iostream>

using namespace std;

int main() {
    
    int age;
    
    cout << "With more age, comes more responsibility... " << endl;
    
    cout << "Let's see what you're allowed to do. Enter your age: " << endl;
    
    cin >> age;
    
    
    if (age >= 25)
    {
     
        cout << "You can do anything you want! Except murder and some other stuff... " << endl;
    
    }
    
    
    else if ( age >= 18)
    {
        cout << "You can vote but not drive." << endl;
    }

        
    if (age == 16 || age == 17)
    {
        cout << "You can drive but not vote. "<< endl;
        
    }
    
    
    
    if ( age < 16)
    {
        cout << "You can't even drive :(" << endl;
    }
    
    
    
    
    
    
    
    return 0;
}
