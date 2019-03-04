//Aaron Adams
//Created in Xcode
//Raptor Math

#include <iostream>
#include <string>

using namespace std;


int main() {
    
    double time;
    
    const int human = 6;
    
    const int raptor = 25;
    
    double distance;
    
    
    
    cout << "Raptor Math!" << endl;
    
    cout << "A raptor can move 25 m/s " << endl;
    
    cout << "You can move 6 m/s\n";
    
    cout << "He wants to eat your juicy bits!\n" << "How long can you survive? \n";
    
    cout << "Enter your distance from raptor (in meters):";

    
    cin >> distance;
    
    time = distance / (raptor - human);

    
    
    

    cout << "You survived " << time << " seconds!" << endl;
    
    
    
    return 0;
}
