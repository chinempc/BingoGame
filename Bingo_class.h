#ifndef Bingo_class_h
#define Bingo_class_h

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//This is a class that reads, writes and generate the game
#pragma once
class Bingo_class
{
	private:
		vector<vector<int> > data;
		vector<int> int_list;
	public:
		Bingo_class();
		Bingo_class(string inputfile);
		void read(string inputfile);
		void write(string output);
		int playGame();
};

//shuffle function
vector<int> shuffle(vector<int>);

#endif

