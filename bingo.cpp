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
void Bingo_class::write(string outputfile) //Write out Board in txt file format
{
    ofstream outdata; // outdata is like cin
    vector<vector<int> > arr; // list of output values
    vector<int> int_arr;
    vector<vector<int> > results;
    //create lsit    

    for (int i = 0; i < 5; i++) {
        arr.push_back(vector<int>());
        for (int j = 0; j < 15; j++) {
            arr[i].push_back((j + 1) + (i * 15));
        }
    }
    //create 75 int list
    for (int i = 0; i < 75; i++) {
        int_arr.push_back(i + 1);
    }

    //shuffle list
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = shuffle(arr[i]);

    }
    //insert first 5 for each row  in result list
    for (int i = 0; i < 5; i++) {
        results.push_back(vector<int>());
        for (int j = 0; j < 5; j++) {
            results[i].push_back(arr[j][i]);
        }
    }

    //replace index [2][2] with free space "0"
    results[2][2] = 00;

    //shuffle 75 interger lsit
    int_arr = shuffle(int_arr);

    //write to file 
    outdata.open(outputfile); // opens the file
    if (!outdata) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }


    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; j++) {
            outdata << results[i][j] << " ";

        }
        outdata << endl;
    }
    for (int i = 0; i < 75; i++) {
        outdata << int_arr[i] << " ";
    }
    outdata << endl;
    outdata.close();
}

int Bingo_class::playGame() //both highlight and win condition in playGame() function
{
    for (int i = 0; i < 75;i++) {
        //check if number from stream is on board
        //cout << int_list[i] << endl;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5;k++) {
                if (int_list[i] == data[j][k]) {
                    data[j][k] = 0;
                }
            }
            
        }
        //check 4 coner case
        if (data[0][0]==data[0][4] && data[4][0]==data[4][4] && data[0][0] == data[4][4]) {
            cout << "corner";
            return int_list[i];
        }

        //check columns
        for (int j = 0; j < 5; j++) {
            if (data[0][j]== data[1][j] && data[2][j] == data[3][j] && data[4][j]==data[0][j] && data[4][j]==data[2][j]) {
                
                return int_list[i];
            }
        }
        //check rows
        for (int j = 0; j < 5; j++) {
            if (data[j][0] == data[j][1] && data[j][2] == data[j][3] && data[j][4] == data[j][0] && data[j][4] == data[j][2]) {
                return int_list[i];
            }
        }
        //check diagnols
        if (data[0][0]==data[1][1] &&data[2][2]==data[3][3]&&data[4][4] ==data[1][1] && data[4][4]==data[2][2]) {

            return int_list[i];
        }
        if (data[4][0] == data[3][1] && data[2][2] == data[1][3] && data[0][4]==data[4][0] && data[0][4]==data[2][2]) {
            return int_list[i];
        }
    }
    return -1;
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
