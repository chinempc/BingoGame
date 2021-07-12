#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cctype>
#include<string>
#include<windows.h>
using namespace std;

class Player
{
private:
	bool Win = false;
public:
	int board[5][5] = { {0,0,0,0,0} ,{0,0,0,0,0}, {0,0,0,0,0} ,{0,0,0,0,0} ,{0,0,0,0,0} };
	void SetBoard(int board[5][5]);//Set the value in the Player Board
	void ReadBoard();
	bool GetWin() { return Win; }
	void Highlight(int x);//recieve number and 'highlight'
	void FindWin();
};
void Player::ReadBoard()
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			cout << board[row][col] << " ";
		}
		cout << endl;
	}
}

void Player::SetBoard(int B[5][5])
{
	for(int row = 0; row < 5;row++)
	{
		for (int col = 0; col < 5; col++)
		{
			board[row][col] = B[row][col];
		}
	}
}

void Player::Highlight(int x)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == x)
			{
				board[i][j] = 0;
				FindWin();
			}
		}
	}
}
void Player::FindWin()
{
	for (int i = 0; i < 5; i++)//If all rows are zeros then bingo
	{
		if (board[i][0] == 0 && board[i][1] == 0 &&board[i][2] == 0 && board[i][3] == 0 && board[i][4] == 0)
		{
			Win = true;
		}
	}
	for (int j = 0; j < 5; j++)//If all cols are zero then bingo
	{
		if (board[0][j] == 0 && board[1][j] == 0 && board[2][j] == 0 && board[3][j] == 0 && board[4][j]==0)
		{
			Win = true;
		}
	}
	for (int i = 0; i < 1; i++ )//if diagonal either way bingo
	{
		switch (i)
		{
			case 0:
				if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0)
				{
					Win = true;
				}
			break;
			case 1:
				if (board[4][0] == 0 && board[3][1] == 0 && board[2][2] == 0 && board[1][3] == 0 && board[0][4] == 0)
				{
					Win = true;
				}
				break;
		}
	}
	if (board[0][0] == 0 && board[4][0] == 0 && board[0][4] == 0 && board[4][4] == 0)//else all corners are marked bingo
	{
		Win = true;
	}
	
	
}
class Game_Manager
{
	private:
		int counter = 0;
		int RandList[75];
		Player A;
	public:
		Game_Manager();
		void Write(string Outputfile);
		void Read(string inputfile);
		void Shuffle();
		int Caller();
		void SetRandList(vector<int> a, int b);
		void ReadRandList();
		int PlayGame();
		
		//void Read(string InputFile);
};
Game_Manager::Game_Manager()
{
	Shuffle();
	Write("Player's_Card");
	Read("Player's_Card");

}
void Game_Manager::Shuffle()
{
	srand(time(NULL));
	vector<int> col1;
	vector<int> col2;
	vector<int> col3;
	vector<int> col4;
	vector<int> col5;
	int randval[5];
	int val[5];
	for (int b = 1; b < 15; b++)
	{
		col1.push_back(b);
		col2.push_back(b+15);
		col3.push_back(b+30);
		col4.push_back(b+45);
		col5.push_back(b+60);
	}
	for (int k = 0; k < 5; k++)
	{
		for (int index = 0; index < 5; index++)
		{
			randval[index] = rand() % col1.size();
			switch (index)
			{
			case 0:
				val[index] = col1[randval[index]];
				break;
			case 1:
				val[index] = col2[randval[index]];
				break;
			case 2:
				val[index] = col3[randval[index]];
				break;
			case 3:
				val[index] = col4[randval[index]];
				break;
			case 4:
				val[index] = col5[randval[index]];
				break;
			}
		}
			col1.erase(col1.begin() + randval[0]);
			col2.erase(col2.begin() + randval[1]);
			col3.erase(col3.begin() + randval[2]);
			col4.erase(col4.begin() + randval[3]);
			col5.erase(col5.begin() + randval[4]);
			A.board[k][0] = val[0];
			A.board[k][1] = val[1];
			if (k == 2)
				A.board[k][2] = 0;
			else
				A.board[k][2] = val[2];
			A.board[k][3] = val[3];
			A.board[k][4] = val[4];	
	}
	int randvalue;
	int value;
	vector<int> proxy;
	int range = 75;
	int a = 0;
	for (int i = 1; i <= range; i++)
	{
		proxy.push_back(i);
	}
	for (int index = range; index > 0; --index)
	{
		randvalue = rand() % proxy.size();
		value = proxy[randvalue];
		proxy.erase(proxy.begin() + randvalue);
		RandList[a] = value;
		a++;
	}
}
int Game_Manager::Caller()
{
	int value;
	value=RandList[counter];
	counter++;
	return value;
}
void Game_Manager::ReadRandList()
{
	for (int i = 0; i < sizeof(RandList) / sizeof(RandList[0]); i++)
	{
		cout << RandList[i] << " ";
	}
}
void Game_Manager::SetRandList(vector<int> A, int x)
{
	int a = 0;
	for (int i = x; i < A.size(); i++)
	{
		RandList[a] = A[i];
		a++;
	}
}
void Game_Manager::Read(string inputfile)
{
	ifstream ifile;
	vector<int> list;
	int numb[5][5];
	int x = 0;
	int value;
	ifile.open(inputfile);
	if (!(ifile.is_open()))
	{
		cout << "The file doesn't exist!";
	}
	while (ifile >> value)
	{
		list.push_back(value);
	}
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			A.board[row][col] = list[x];
			x++;
		}
	}
	SetRandList(list, x);
}
void Game_Manager::Write(string Of)
{
	ofstream ofile;
	ofile.open(Of);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ofile << A.board[i][j] << " ";
		}
		ofile << endl;
	}
	for (int a = 0; a < sizeof(RandList) / sizeof(RandList[0]); a++)
	{
		ofile << RandList[a]<<" ";
	}
	ofile.close();
}
int Game_Manager::PlayGame()
{
	int LastVC=0;
	bool Gameover = false;
	while (Gameover!=true)
	{
		LastVC = Caller();
		cout << "Number: "<<LastVC<<endl;
		A.Highlight(LastVC);
		Gameover = A.GetWin();
		Sleep(500);
	}
	cout << "Player have bingo: ";
	return LastVC;
}
void Test1()
{
	int FNum = 0;
	Game_Manager GM;
	GM.Read("test1.txt");
	FNum = GM.PlayGame();
	cout << FNum<<endl;
	cout << "success"<<endl;
}
void Test2()
{
	int FNum = 0;
	Game_Manager GM;
	GM.Read("Test2.txt");
	FNum = GM.PlayGame();
	cout << FNum << endl;
	cout << "success"<<endl;
}
void Test3()
{
	int FNum = 0;
	Game_Manager GM;
	FNum = GM.PlayGame();
	cout << FNum << endl;
	cout << "success" << endl;
}
int main()
{
	Test1();//Test1.txt
	Test2();//Test2.txt
	Test3();//Play bingo with no test
	return 0;
}
