//** This code is reading the files **// 
#include "Bingo.cpp"
using namespace std;
int main() 

{
	
    // we are testing our files to run the BIngo Game 
	
    string file = "test1.txt";
    Bingo_class newGame(file);
    newGame.read(file);
    newGame.write(file);
	
	/*************************************************/
	
    /*
    file = "Test 1.txt";
    newGame.read(file);
    file = "Test 2.txt";
    newGame.read(file);
    */
	
	/*************************************************/
	
	return 0;
	
}

