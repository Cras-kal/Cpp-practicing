#include <iostream>
#include <ctime>
//rock paper scissors game
//randomly make if r or p or s
// user chooses 
// if r and p then r looses
// if p and s then p looses
// if s and r then s looses
// practicing basic c++ syntax with rock paper scissors

char gameChoiceRand();
std::string translateChoice(char randChoice);
std::string theWinner(char userChoice, char gameChoice);
int yourScore;
int compScore;

int main(){
    int state = 1; //initialize
    srand(time(0));
    
    while (state == 1){
        char userChoice;
        char gameChoice = gameChoiceRand();
        char agreeOrNot;

        std::cout << "\n\n\n========== Welcome to BATO BATO PICK game ==========\n\n\n";

        do { // do this then if the choice is not r or p or s then loop
            std::cout << "Rock = r, Paper = p, scissors = s\n";
            std::cout << "Rock paper scissors, what's your choice?\n";
            std::cin >> userChoice; //get user's choice

            if (userChoice != 'r' && userChoice != 'p' && userChoice != 's'){
                std::cout << "\nINVALID INPUT\n\nPlease insert only in the choices:\n"; // send an invalid message when different choice
            }

        } while(userChoice != 'r' && userChoice != 'p' && userChoice != 's'); // loop when not within the choices
        
        std::string userChoiceString = translateChoice(userChoice);// tranlating their chars into strings for game interactive
        std::string gameChoiceString = translateChoice(gameChoice);

        std::cout << "\nBATO BATO PICK!\n\n"; 
        std::cout << "Your choice: " << userChoiceString << std::endl; // show their choices
        std::cout << "Computer's choice: " << gameChoiceString << std::endl;
        
        // we need to compare
        std::cout << "\nThe winner is: " << theWinner(userChoice, gameChoice) << std::endl;
        std::cout << "\n\n*****SCORE*****\n";
        std::cout << "You: " << yourScore << " | Computer: " << compScore << std::endl;

        do {
        std::cout << "\nDo you wanna play again?(y/n) ";
        std::cin >> agreeOrNot;
        
            if (agreeOrNot == 'y'){
                state = 1;
                std::cout << "\n\nLet's play again\n";
            } else if (agreeOrNot == 'n'){
                std::cout << "\n*****Thank you for playing*****\n\n\n";
                state = 0;
            } else if (agreeOrNot != 'y' && agreeOrNot != 'n'){
                std::cout << "\nINVALID INPUT\n";
            }

        } while (agreeOrNot != 'y' && agreeOrNot != 'n');
    }
    return 0;
}

char gameChoiceRand(){
    char choice;
    int randomChoice = (rand() % 3) + 1; // 1 = r (rock), 2 = p (paper), 3 = s (scissors)
    
    switch(randomChoice){
        case 1: choice = 'r'; break; //rock
        case 2: choice = 'p'; break; // paper
        case 3: choice = 's'; break; // scissors
    }
    return choice;
}

std::string translateChoice(char randChoice){ //translate choice into a readable string
    std::string string;

    switch (randChoice){
        case 'r': string = "Rock"; break;
        case 'p': string = "Paper"; break;
        case 's': string = "Scissors"; break;
    }
    return string;
}

std::string theWinner(char userChoice, char gameChoice){ //function in choosing the winner
    std::string whoIsWinner;

    switch(userChoice){
        case 'r': // the case where user choose rock
        switch(gameChoice){
            case 'r': whoIsWinner =  "DRAW!!!"; break; //comp choose rock draw
            case 'p': compScore++; whoIsWinner = "COMPUTER"; break;//comp choose paper you lose
            case 's': yourScore++; whoIsWinner = "YOU"; break; //comp choose scissors you win
        }
        break;

        case 'p': // the case where user choose paper
        switch(gameChoice){ 
            case 'r': yourScore++; whoIsWinner = "YOU"; break; // comp choose rock you win
            case 'p': whoIsWinner = "DRAW!!!"; break; // comp choose paper draw
            case 's': compScore++; whoIsWinner = "COMPUTER"; break; // comp choose scissors you lose
        }
        break;
        
        case 's':  // case where user choose scissors
        switch(gameChoice){
            case 'r': compScore++; whoIsWinner = "COMPUTER"; break; // comp choose rock you lose
            case 'p': yourScore++; whoIsWinner = "YOU"; break; // comp choose paper you win
            case 's': whoIsWinner = "DRAW!!!"; break; // comp choose scissors draw
        }
        break; // the case where user choose scissors
    }
    return whoIsWinner;
}

