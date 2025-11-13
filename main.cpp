//COMSC-210|Ethan Aylard|Lab-32
//IDE used: Visual Studio Code

#include <iostream>
#include <deque>
#include "Car.h"

int LEAVE_CHANCE = 55, JOIN_CHANCE = 45;

void displayLine(deque<Car>);

int main(){
    //Using a random seed:
    srand(time(0));

    bool debug = true;
    int chance;
    int opNum = 1;
    deque<Car> tollLine;

    //Initializing the line:
    tollLine.push_back(Car());
    tollLine.push_back(Car());

    //Displaying the Initial line:
    cout << "Initial Queue:\n";
    displayLine(tollLine);

    //A while loop that will only exit when the deque is empty:
    while(!tollLine.empty() && debug){
        //using a random numnber between 100 and 1 to get the 
        chance = rand()%100 + 1;
        if(chance < JOIN_CHANCE){
            tollLine.push_back(Car());
            cout << "Time: " << opNum << " Operation: Car Joined: ";
        }

        opNum++;
    }


    return 0;
}

//displayLine() displays the whole deque provided.
//requires: a Car deque
//returns: none
void displayLine(deque<Car> line){
    for (Car element : line){
        element.print();
    }

}
