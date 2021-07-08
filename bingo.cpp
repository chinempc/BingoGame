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


void Bingo_class::read(string inputfile)
{
    int_list.clear();
    data.clear();

    ifstream indata; // indata is like cin
    int num; // variable for input value
    int temp;
    indata.open(inputfile); // opens the file
    string text_from_file;
    if (!indata) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    int count = 0;

    //insert bingo board into 2d array
    for (int i = 0; getline(indata, text_from_file) && i < 6; i++) {
        vector <int> row;
        char ch;
        //cout << text_from_file << endl;
        stringstream  ss(text_from_file);
        if (i == 5) {
            while (ss >> temp) {
                int_list.push_back(temp);
                //ss >> ch;
            }
            break;
        }
        while (ss >> temp) {
            row.push_back(temp);
            //ss >> ch;
        }
        data.push_back(row);
    }

    int x = playGame();
    if (x != -1) {
        cout << "Test: " << inputfile << " = " << x << endl;;
    }
    else {
        cout << "error" << endl;
    }
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
