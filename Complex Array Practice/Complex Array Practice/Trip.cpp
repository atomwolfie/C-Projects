//This file contains the Trip class implementation
#include "Trip.h"

//This is the default constructor. It creates a Trip object
//with the followig default values:
//	miles - 100
//	fuelPrice - 4.50
//	mpg - 22
//receives nothing
//returns nothing
Trip::Trip(){
    setMiles(100);
    setFuelPrice(4.50);
    setMpg(22);
}

//This is a constructor. It creates a Trip object
//with the values sent
//receives:
//	miles
//	fuelPrice
//	mpg
//returns nothing
Trip::Trip(int theMiles, double theFuelPrice, double theMpg){
    setMiles(theMiles);
    setFuelPrice(theFuelPrice);
    setMpg(theMpg);
}

//sets the number of miles to value sent. If value sent
//is zero or less it will set the number of miles to 1
//Receives:
//		number of miles in the trip
//Returns nothing
void Trip::setMiles(int numberOfMiles){
    if (numberOfMiles>0){
        miles = numberOfMiles;
    }
    else{
        miles = 1;
    }
}

//sets the estimated cost of a gallon of fuel to value
//sent. If value sent is zero or less it will set the
//estimated cost of  a gallon of fuel to 4.00
//Receives:
//		estimated cost of a gallon of fuel
//Returns nothing
void Trip::setFuelPrice(double gallonPrice){
    if (gallonPrice>0){
        fuelPrice = gallonPrice;
    }
    else{
        fuelPrice = 4;
    }
}

//sets the estimated mpg for vehicle making the trip to
// value sent. If value sent is zero or less it will
//set the estimated mpg to 20
//Receives:
//		estimated mpg
//Returns nothing
void Trip::setMpg(double carMpg){
    if (carMpg>0){
        mpg = carMpg;
    }
    else{
        mpg = 20;
    }
}

//computes and returns the estimated fuel cost for the
//trip
//Receives nothing
//Returns:
//		total fuel cost for trip
double Trip::getCost(){
    return miles / mpg*fuelPrice;
}

//adds miles to the trip to include a detour. If miles
// sent are less than zero, no change is made to miles.
//Receives:
//		number of miles in detour
//Returns nothing
void Trip::addDetour(int detourMiles){
    if (detourMiles >= 0){
        miles += detourMiles;
    }
}
