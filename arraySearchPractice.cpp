#include <iostream>

int searchIndex(std::string array[], int size, std::string inputSearch);
void printArray(std::string array[], int size);

int main(){
    // make an array 1 to 10
    // create a function to find a user's number location index

    std::string fairy[] = {"Tinkerbell", "Cosmo", "Malificent", "Wanda"}; //example data
    int sizeNum = sizeof(fairy)/sizeof(fairy[0]); //get the size of the array

    std::string userInput;

    //get the input of user
    std::cout << "Enter the number and reveal its index location: ";
    printArray(fairy, sizeNum); // print to see the data set
    std::cout << std::endl;
    std::getline(std::cin, userInput);

    int index = searchIndex(fairy, sizeNum, userInput);

    if (index == -1){
        std::cout << "The '" << userInput << "' input doesn't exist\n";

    } else{ 
        std::cout << "The index of the number is: ";
        std::cout << index;
        std::cout << std::endl;
    }
}

int searchIndex(std::string array[], int size, std::string inputSearch){
    for (int i = 0; i < size; i++){
        if (array[i] == inputSearch){
            return i;
        }
    }
    return -1;
}

void printArray(std::string array[], int size){ // the function of printing the array for code organization

    for (int i = 0; i < size; i++){
        std::cout << array[i] << ", ";
    }

}