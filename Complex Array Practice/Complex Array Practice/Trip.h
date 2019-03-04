
//This header file contains the Trip class declaration
#ifndef TRIP_H
#define TRIP_H


class Trip
{
private:
    int miles;
    double fuelPrice;
    double mpg;
public:
    //This is the default constructor. It creates a Trip object
    //with the followig default values:
    //	miles - 100
    //	fuelPrice - 4.50
    //	mpg - 22
    Trip();
    
    //This is a constructor. It creates a Trip object
    //with the values sent.
    Trip(int, double, double);
    
    //Returns the current number of miles in the trip
    //receives nothing
    //returns:
    //		number of miles in the trip
    int getMiles(){ return miles; }
    
    //Returns the current estimated price per gallon
    //receives nothing
    //returns:
    //		estimated price per gallon
    double getFuelPrice(){ return fuelPrice; }
    
    //Returns the current value of estimated
    //miles-per-gallon (mpg)
    //receives nothing
    //returns:
    //		miles-per-gallon (mpg)
    double getMpg(){ return mpg; }
    
    //sets the number of miles
    void setMiles(int);
    
    //sets the estimated cost of a gallon of fuel
    void setFuelPrice(double);
    
    //sets the estimated mpg for vehicle making the trip
    void setMpg(double);
    
    //computes and returns the estimated fuel cost for
    //the trip
    double getCost();
    
    //adds miles to the trip to include a detour
    void addDetour(int);
};


#endif // !TRIP_H