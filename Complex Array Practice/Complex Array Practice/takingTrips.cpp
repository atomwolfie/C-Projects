#include<iostream>
#include<iomanip>
#include "Trip.h"
using namespace std;

const int SIZE = 3;

int main(){
    //set precision
    cout << fixed << setprecision(2);
    
    
    //1. Define an array of three Trip objects
    
    Trip trips[3];
    
    
    //2. Loop through this array and display the trip cost
    //   for each element in the array.
    
    for (int i = 0; i < SIZE; i++){
        
        
        cout << "The cost of trip " << i + 1 << " is $" << trips[i].getCost() << endl;
        
        
    }
    
    //3. Loop through the array to get the actual values for each of John's trips.
    int num;
    double mpg, fuelPrice;
    
    for (int i = 0; i < SIZE; i++){
        
        cout << "How many miles is trip " << i + 1 << " ? ";
        cin >> num;
        
        trips[i].setMiles(num);
        cout << endl;
        
        cout << "How many miles per gallon does his car get for trip " << i + 1 << " ? ";
        cin >> mpg;
        trips[i].setMpg(mpg);
        
        
        cout << "What is the price for fuel for trip " << i + 1 << " ?";
        cin >> fuelPrice;
        trips[i].setFuelPrice(fuelPrice);
        
        
        
    }
    
    
    //4. Now loop through this array again to display the trip cost for each element in the array.
    
    for (int i = 0; i < SIZE; i++){
        
        cout << "The cost for trip " << i + 1 << " is $" << trips[i].getCost() << endl;
        
        
        
    }
    
    //5. Define a second array.This time initialize the array as above using
    //	 the actual values for John's trip.
    
    Trip johnsTrips[SIZE] = { Trip(3328, 2.48, 25), Trip(718, 2.80, 19), Trip(623, 2.72, 17) };
    
    
    //6. Loop through this new array and print out each trip.
    
    for (int i= 0; i < SIZE; i++){cout << "The cost for trip " << i + 1 << " is $" << johnsTrips[i].getCost() <<  endl;
        
        
    }
    
    //7. Add a detour of 210 miles to this trip.
    
    johnsTrips[2].addDetour(210);
    
    cout << "The cost of trip 3 with a detour of 210 miles is $" <<  johnsTrips[2].getCost();
    
    
    return 0;
}
