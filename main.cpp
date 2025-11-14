//COMSC-210|Ethan Aylard|Lab-32
//IDE used: Visual Studio Code

#include <iostream>
#include <deque>
#include "Car.h"

int SPLIT_PROB = 45; bool debug = false;

void displayLine(deque<Car>);

int main(){
    //Using a random seed:
    srand(time(0));

    //a bool variable that determines if the while loop continues
    bool loop = true;

    int chance; // a number that will contain a random number between 1 and 100.
    int opNum = 1; // the number that is the current operation
    deque<Car> tollLine;

    //Initializing the line:
    tollLine.push_back(Car());
    tollLine.push_back(Car());

    //Displaying the initial line:
    cout << "Initial Queue:\n";
    displayLine(tollLine);


    //A while loop that will only exit when the deque is empty: It will also skip the loop if 
    while(loop){
        //using a random numnber between 100 and 1 to get what event plays out:
        chance = rand()%100 + 1;

        if(chance < SPLIT_PROB){ // if the random number is less than SPLIT_PROB (45) so that is has a 45% chance to happen.
            tollLine.push_back(Car()); //a new car joins the queue

            cout << "Time: Operation " << opNum << " : Car Joined: ";
            tollLine.back().print();
        }
        //if the random number is more or equal to than SPLIT_PROB (45) sor that it has a 55% chance to happen.
        else if(chance >= SPLIT_PROB){//The first car pays its toll
            cout << "Time: Operation " << opNum << " : Car Paid: ";
            tollLine.front().print();

            tollLine.pop_front();
        }

        //Displaying the current line:
        cout << "Queue:\n";
        displayLine(tollLine);

        opNum++;
        //if the deque or debug is true end the loop:
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
