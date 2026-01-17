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
int delayThree();

int main(){
    int state = 1; //initialize

    while (state == 1){
        char userChoice;
        char gameChoice = gameChoiceRand();
        char agreeOrNot;

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
        std::cout << "\n**THE WINNER**\n";
        std::cout << "The winner is: " << theWinner(userChoice, gameChoice) << std::endl;

        std::cout << "\nDo you wanna play again?(y/n) ";
        std::cin >> agreeOrNot;

        if (agreeOrNot == 'y'){
            state = 1;
            std::cout << "\n\nLet's play again\n";
        } else if (agreeOrNot == 'n'){
            std::cout << "\n***Thank you for playing***\n";
            state = 0;
        }
    }
    return 0;
}

char gameChoiceRand(){
    
    char choice;
    srand(time(0));
    int randomChoice = (rand() & 3) + 1; // 1 = r (rock), 2 = p (paper), 3 = s (scissors)
    
    switch(randomChoice){
        case 1: return choice = 'r'; break; //rock
        case 2: return choice = 'p'; break; // paper
        case 3: return choice = 's'; break; // scissors
    }
    return 0;
}

std::string translateChoice(char randChoice){
    switch (randChoice){
        case 'r': return "Rock"; break;
        case 'p': return "Paper"; break;
        case 's': return "Scissors"; break;
    }
    return 0;
}

std::string theWinner(char userChoice, char gameChoice){
    switch(userChoice){
        case 'r': // the case where user choose rock
        switch(gameChoice){
            case 'r': return "DRAW!!!"; break;
            case 'p': return "YOU"; break;
            case 's': return "COMPUTER"; break;
        }
        break;

        case 'p': // the case where user choose paper
        switch(gameChoice){ 
            case 'r': return "YOU"; break;
            case 'p': return "DRAW!!!"; break;
            case 's': return "COMPUTER"; break;
        }
        break;
        
        case 's': 
        switch(gameChoice){
            case 'r': return "COMPUTER"; break;
            case 'p': return "YOU"; break;
            case 's': return "DRAW!!!"; break;
        }
        break; // the case where user choose scissors
    }
    return 0;
}

