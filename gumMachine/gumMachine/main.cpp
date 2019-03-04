//AaronAdams
//Created in Xcode



#include <iostream>
#include <iomanip>


using namespace std;

int main() {
    
    cout << setprecision(2)<< fixed;
    
    
    char decision;
    
    int Trident = 1;
    
    int Dentyne = 1;
    
    int Five = 1;
    
    int Orbit = 1;
    
    
    cout << "You are standing a at gum machine, and you want some bad.\nSo many types!" << endl;
    cout << "All packs cost $1.00" << endl << endl << endl;
    
    cout << "Press s to report machine status" << endl;
    
    cout << "Press d to put in a quarter" << endl;
    
    cout << "Press a to pull 1st tab "<< endl;
    
    cout << "Press b to pull 2nd tab" << endl;
    
    cout << "Press c to pull 3rd tab " << endl;
    
    cout << "Press f to pull 4th tab" << endl;
    
    cout << "Press r to restock the machine" << endl;
    
    cout << "Press q to walk away like a boss"<< endl;
    
    cin >> decision;
    
    while (decision != 'Q' && decision != 'q') {
        
        
        switch (decision){
                
                case 's':
                case 'S':
                
                double balance;
                
                cout << "There is $" << balance << " in the machine" << endl;
                cout << "There are " << Trident << " packs of Trident in Tab 1" << endl;
                cout << "There are " << Dentyne << " packs of Dentyne in Tab 2" << endl;
                cout << "There are " << Five << " packs of Five in Tab 3" << endl;
                cout << "There are " << Orbit << " packs of Orbit in Tab 3" << endl << endl << endl;
                
                
                
                cout << "Press s to report machine status" << endl;
                
                cout << "Press d to put in a quarter" << endl;
                
                cout << "Press a to pull 1st tab "<< endl;
                
                cout << "Press b to pull 2nd tab" << endl;
                
                cout << "Press c to pull 3rd tab " << endl;
                
                cout << "Press f to pull 4th tab" << endl;
                
                cout << "Press r to restock the machine" << endl;
                
                cout << "Press q to walk away like a boss"<< endl;
                
                cin >> decision;
                
                break;
                
                case 'd':
                case 'D':
                
                balance = balance + 0.25;
                cout << "Ca-Ching!" << endl << endl << endl;
                
                cout << "Press s to report machine status" << endl;
                
                cout << "Press d to put in a quarter" << endl;
                
                cout << "Press a to pull 1st tab "<< endl;
                
                cout << "Press b to pull 2nd tab" << endl;
                
                cout << "Press c to pull 3rd tab " << endl;
                
                cout << "Press f to pull 4th tab" << endl;
                
                cout << "Press r to restock the machine" << endl;
                
                cout << "Press q to walk away like a boss"<< endl;
                
                cin >> decision;
                
                break;
                
                
            
            
                case 'a':
                case 'A':
                
                if ( balance < 1.00) {
                    
                    cout << "You don't have enough money!" << endl << endl << endl;
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                    
                    
                }
                
            
               else if (balance >= 1.00 && Trident < 1 ){
                    
                    
                    cout << "There aren't any packs of Trident" << endl;
                    
                   
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                }
                
                
                else {
                    
                    balance = balance - 1.00;
                    Trident = Trident - 1;
                    
                    cout << "You got a pack of Trident!" << endl << endl << endl;
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                    
                
                } break;
                
            case 'b':
            case 'B':
                
                if ( balance < 1.00) {
                    
                    cout << "You don't have enough money!" << endl << endl << endl;
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                    
                    
                }
                
                
                else if (balance >= 1.00 && Dentyne < 1 ){
                    
                    
                    cout << "There aren't any packs of Dentyne" << endl;
                    
                    
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                }
                
                
                else {
                    
                    balance = balance - 1.00;
                    Dentyne = Dentyne - 1;
                    
                    cout << "You got a pack of Dentyne!" << endl << endl << endl;
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                    
                    
                } break;
                
            case 'c':
            case 'C':
                
                if ( balance < 1.00) {
                    
                    cout << "You don't have enough money!" << endl << endl << endl;
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                    
                    
                }
                
                
                else if (balance >= 1.00 && Five < 1 ){
                    
                    
                    cout << "There aren't any packs of Five" << endl;
                    
                    
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                }
                
                
                else {
                    
                    balance = balance - 1.00;
                    Five = Five - 1;
                    
                    cout << "You got a pack of Five!" << endl << endl << endl;
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                    
                    
                } break;
                
            case 'f':
            case 'F':
                
                if ( balance < 1.00) {
                    
                    cout << "You don't have enough money!" << endl << endl << endl;
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                    
                    
                }
                
                
                else if (balance >= 1.00 && Orbit < 1 ){
                    
                    
                    cout << "There aren't any packs of Orbit" << endl;
                    
                    
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                }
                
                
                else {
                    
                    balance = balance - 1.00;
                    Orbit = Orbit - 1;
                    
                    cout << "You got a pack of Orbit!" << endl << endl << endl;
                    
                    cout << "Press s to report machine status" << endl;
                    
                    cout << "Press d to put in a quarter" << endl;
                    
                    cout << "Press a to pull 1st tab "<< endl;
                    
                    cout << "Press b to pull 2nd tab" << endl;
                    
                    cout << "Press c to pull 3rd tab " << endl;
                    
                    cout << "Press f to pull 4th tab" << endl;
                    
                    cout << "Press r to restock the machine" << endl;
                    
                    cout << "Press q to walk away like a boss"<< endl;
                    
                    cin >> decision;
                    
                    
                } break;
                
                
                
                
                
                
                
                
                
                
                
                
                case 'r':
                case 'R':
                
                Trident = Trident + 10;
                Dentyne = Dentyne + 10;
                Five = Five + 10;
                Orbit = Orbit + 10;
                
                cout << "Some creepy old guy comes over and fiddles with the machine..." << endl << endl << endl;
                
                cout << "Press s to report machine status" << endl;
                
                cout << "Press d to put in a quarter" << endl;
                
                cout << "Press a to pull 1st tab "<< endl;
                
                cout << "Press b to pull 2nd tab" << endl;
                
                cout << "Press c to pull 3rd tab " << endl;
                
                cout << "Press f to pull 4th tab" << endl;
                
                cout << "Press r to restock the machine" << endl;
                
                cout << "Press q to walk away like a boss"<< endl;
                
                cin >> decision;
                break;
                
            
            
            
            
            
            
            default:
                break;
                
                
                
                
                

                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
                
        }
        
        
        
        
        
        
        
        
        
    }
        
        
    

    
    
    
    
    cout << "Thanks for coming!" << endl;
    
    
    
    
    
    
    
    return 0;
}
