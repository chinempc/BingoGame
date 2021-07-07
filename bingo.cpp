#include "Bingo_class.h"

//Constructors ~Nick(Artsy03)
Bingo_class::Bingo_class()
{
    cout << "WELCOME TO THE BINGO GAME!!\n";
}

Bingo_class::Bingo_class(string inputfile)
{
    cout << "WELCOME TO THE BINGO GAME!!\n;
    Bingo_class::read(inputfile);
}



// Shuffle 
vector<int> shuffle(vector<int> arr) {
    int temp;
    int rand_selction;
    srand(time(NULL));

    for (int i = 0; i < arr.size(); i++) {

        rand_selction = rand() % arr.size();
        temp = arr[i];
        arr[i] = arr[rand_selction];
        arr[rand_selction] = temp;
    }
    return arr;
}
