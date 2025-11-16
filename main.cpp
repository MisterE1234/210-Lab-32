//COMSC-210|Ethan Aylard|Lab-33
//IDE used: Visual Studio Code

#include <iostream>
#include <deque>
#include <array>
#include "Car.h"

int const PAY_PROB = 50, JOIN_PROB = PAY_PROB + 39, LINE_AMOUNT = 4, SIM_AMOUNT = 20; bool debug = false; 

void displayLine(deque<Car>);

int main(){
    //Using a random seed:
    srand(time(0));

    //a bool variable that determines if the while loop continues
    bool loop = true;

    int chance; // a number that will contain a random number between 1 and 100.
    int opNum = 1; // the number that is the current operation

    array <deque <Car>, LINE_AMOUNT> tollLine ;

    //Initializing the line:
    //using a for loop to fill each line with 2 cars each:
    for(int i = 0; i < LINE_AMOUNT;i++){
    tollLine[i].push_back(Car());
    tollLine[i].push_back(Car());

    //Displaying the initial line:
    cout << "Initial Queue: Lane " << i << endl;
    displayLine(tollLine[i]);

    }


    //A while loop that will only exit when the all the loops are complete: It will also skip the loop if 
    for(int i = 0; i < SIM_AMOUNT; i++){

        cout << "Time: " << i + 1 << endl;

        for(int j = 0; j < SIM_AMOUNT; j++){
            //using a random numnber between 100 and 1 to get what event plays out:
            chance = rand()%100 + 1;

            if(chance < PAY_PROB){ // if the random number is less than PAY_PROB (46) so that the front car has a 46% chance to pay.
                cout << "Lane " << j + 1 << ": Car Paid: ";
                tollLine[j].front().print();

                tollLine[j].pop_front();
            
            }
            //if the random number is less than JOIN_PROB (85): a car has a 39% chance to join the queue.
            else if(chance >= PAY_PROB){//The first car to join the toll
                tollLine[j].push_back(Car()); //a new car joins the queue

                cout << "Lane " << j + 1<< ": Car Joined: ";
                tollLine[j].back().print();
            }
            //If the random number is greater than or equal to JOIN_PROB(85): a car has a 15% chance to switch to a different lane.
           
        
            if (!tollLine.empty()){ //if there are cars in line:
                //Displaying the current line:
                cout << "Queue:\n";
                displayLine(tollLine[j]);
            }
            else{//if there are no cars in line:
                cout << "No cars in line.\n";
                break;
            }
    
        
            //if the deque or debug is true end the loop:
            
        }

        //increasing the operating number:
        opNum++;

    }

    cout << "End of Program.\n";
    //clearing up any residual memory.
    for(int i = 0; i < LINE_AMOUNT; i++){
        tollLine[i].clear();
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
