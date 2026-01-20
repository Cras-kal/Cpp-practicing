


#include <iostream>
#include <ctime>

int generateRandom(int range); // int function to generate a random number

int main(){

    int setSize; // the manual set size of the array

    std::cout << "\n\n**************************************************************\n\n";
    std::cout << "Input an amount of number that you want your array to have: ";
    std::cin >> setSize;
    
    int dataSamp[setSize]; // initialize the array with the chosen size
    srand(time(0));
    
    for (int i = 0; i < setSize; i++){ // generate the random array
        dataSamp[i] = generateRandom(setSize);
    }
    
    std::cout << "\n\nYour random set of data: ";

    for (int i = 0; i < setSize; i++){ // this for loop will print the unsorted data 
        if (i == setSize - 1){
            std::cout << dataSamp[i] << std::endl;
        } else{
            std::cout << dataSamp[i] << ", ";
        }
    }

    int holdNumber; // temporary number holder for greater index value


    // Standard Bubble Sort algorithm
    for (int i = 0; i < setSize - 1; i++) {
        for (int j = 0; j < setSize - i - 1; j++) {
            if (dataSamp[j] > dataSamp[j+1]) {
                // Swap the holdNumber and the next index
                holdNumber = dataSamp[j];
                dataSamp[j] = dataSamp[j+1];
                dataSamp[j+1] = holdNumber;
            }
        }
    }

    std::cout << "\n\nYour sorted data: ";

    for (int i = 0; i < setSize; i++){ // this for loop will print the data
        if (i == setSize - 1){
            std::cout << dataSamp[i] << std::endl;
        } else{
            std::cout << dataSamp[i] << ", ";
        }
    }


    return 0;
}

int generateRandom(int range){ // the random number generator function
    return rand() % range + 1;
}