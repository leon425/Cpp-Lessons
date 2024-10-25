#include <iostream>
#include <time.h>

std::string getComputerChoice();

int main() {
// Random Number (Pseudo-random) => not ruly random, but close

    // Initialize the random number generator.
    srand(time(NULL)); // time() is the seed and most probgrammer use time() for the seed in the random number initialization

    int num = rand(); //entirely random number between 0 and 32767

    int num2 = (rand() % 6) + 1; //Get the random number of 0 to 6

    //random string (not using array or linked list, but using variable & switch)
    std::cout << getComputerChoice();

    return 0;
}

//random string (not using array or linked list, but using variable & switch)
std::string getComputerChoice () {
    
    int choices = (rand() % 3) + 1;

    switch(choices) {
        case 1:
            return "Rock"; // Don't have to 'break' because 'return' is already breaking from the switch
        case 2:
            return "Scissor";
        case 3: 
            return "Paper";
    }
}