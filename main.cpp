//COMSC-210|Ethan Aylard|Lab-32
//IDE used: Visual Studio Code

#include <iostream>
#include <deque>
#include "Car.h"

void displayLine(deque<Car>);

int main(){

    deque<Car> tollLine;

    //Initializing the line:
    tollLine.push_back(Car());
    tollLine.push_back(Car());

    //Displaying the Initial line:
    cout << "Initial Queue:\n";
    displayLine(tollLine);


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
