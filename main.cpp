//COMSC-210|Ethan Aylard|Lab-32
//IDE used: Visual Studio Code

#include <iostream>
#include <deque>
#include "Car.h"

int SPLIT_PROB = 45; bool debug = true;

void displayLine(deque<Car>);

int main(){
    //Using a random seed:
    srand(time(0));

    bool loop = true;

    int chance;
    int opNum = 1;
    deque<Car> tollLine;

    //Initializing the line:
    tollLine.push_back(Car());
    tollLine.push_back(Car());

    //Displaying the Initial line:
    cout << "Initial Queue:\n";
    displayLine(tollLine);

    Car tempElement;

    //A while loop that will only exit when the deque is empty: It will also skip the loop if 
    while(loop){
        //using a random numnber between 100 and 1 to get what event plays out:
        chance = rand()%100 + 1;

        if(chance < SPLIT_PROB){ // if the random number is less than SPLIT_PROB (45)
            tollLine.push_back(Car());

            cout << "Time: " << opNum << " Operation: Car Joined: ";
            tollLine.back().print();
        }
        //if the 
        else if(chance >= SPLIT_PROB){
            cout << "Time: " << opNum << " Operation: Car Paid: ";
            tollLine.front().print();

            tollLine.pop_front();
        }

        opNum++;
        if (tollLine.empty()|| debug){
            loop = false;
        }
    }

    //clearing up any residual memory.
    tollLine.clear();
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
