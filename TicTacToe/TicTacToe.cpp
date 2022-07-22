#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::endl;

void Welcome();
void gameMap();
void gameStart(string x_or_o);
void gameRules();
void playerTurns(string x_or_o);
int notationToNum(char character);
void checkWinner();


bool win = false;
string winner;
int numOfTurns = 0;


string x_o_entries[3][3] = {

	{"-", "-", "-"},
	{"-", "-", "-"},
	{"-", "-", "-"}

};



void gameStart(string x_or_o)
{

	while (!win && numOfTurns != 9) {
		playerTurns(x_or_o);
		if (x_or_o == "x") x_or_o = "o";
		else x_or_o = "x";
		numOfTurns++;
		checkWinner();
	}
	gameMap();
	if(numOfTurns == 9 && win == false) cout << "It's a draw!" << endl;
	else cout << "The winner is " + winner << endl;
	}

void Welcome()
{
	string userChoice_1, userChoice, finalChoice;
	bool validInput = false;

	cout << "Welcome to my Tik Tac Toe Game!!!" << endl;

	while (!validInput) {

		cout << "Press 1 to start." << endl;
		cout << "Press 2 to review the rules." << endl;
		cout << "Press 3 to exit:";

		std::getline(cin, userChoice_1);
		if (userChoice_1 == "1")
		{
			validInput = true;
		}
		else if (userChoice_1 == "2")
		{
			gameRules();
		}
		else if (userChoice_1 == "3")
		{
			exit(0);
		}else cout << "not a valid input. Please pick a number between 1 - 3." << endl;
	}

	validInput = false;

	cout << "Would you like x or o to start?: ";
	while (!validInput) {
		std::getline(cin, userChoice);
		transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);
		if (userChoice.at(0) == 'x' || userChoice.at(0) == 'o')
		{
			validInput = true;
			finalChoice = userChoice.at(0);
		}else cout << "Not a valid input. Try again: " << endl;
		
		}
	gameStart(finalChoice);
	}



void gameMap()
{
	cout << "   a     b     c  " << endl;
	cout << "      |     |     " << endl;
	cout << "1  " + x_o_entries[0][0] + "  |  " + x_o_entries[0][1] + "  |  " + x_o_entries[0][2] + "  " << endl;
	cout << " _____|_____|_____" << endl;
	cout << "      |     |     " << endl;
	cout << "2  " + x_o_entries[1][0] + "  |  " + x_o_entries[1][1] + "  |  " + x_o_entries[1][2] + "  " << endl;
	cout << " _____|_____|_____" << endl;
	cout << "      |     |     " << endl;
	cout << "3  " + x_o_entries[2][0] + "  |  " + x_o_entries[2][1] + "  |  " + x_o_entries[2][2] + "  " << endl;
	cout << "      |     |     " << endl;
}
int notationToNum(char character)
{
	switch(character)
	{
	case 'a':
		return 1;
		break;

	case 'b':
		return 2;
		break;

	case 'c':
		return 3;
		break;

	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;

	default:
		return 100;
		break;
	}
}
void playerTurns(const string x_or_o)
{

	gameMap();

	string tempInput;
	char column;
	int row;

	bool validInput = false;

	cout << endl;
	cout << "It is " + x_or_o + "'s turn" << endl;
	cout << "Enter the column letter you want " + x_or_o + " to go: ";
	while (!validInput) {
		cin >> tempInput;
		if (tempInput == "a" || tempInput == "b" || tempInput == "c") {
			column = tempInput.at(0);
			validInput = true;
		}else cout << "Not a valid input. Try again: ";
		
		}

	validInput = false;

	cout << "Enter the row number you want " + x_or_o + " to go: ";
	while (!validInput) {
		cin >> tempInput;
		if (tempInput == "1" || tempInput == "2" || tempInput == "3") {
			row = notationToNum(tempInput.at(0));
			validInput = true;
		}else cout << "Not a valid input. Try again: " << endl;

		}
	if(x_o_entries[row - 1][notationToNum(column) - 1] != "-")
		{
		cout << "Slot is already taken. Try again." << endl;
		playerTurns(x_or_o);
	}else x_o_entries[row - 1][notationToNum(column) - 1] = x_or_o;
	
}
void checkWinner()
{
	/*
	 [n][0] == [n][1] == [n][2]
	 [0][n] == [1][n] == [2][n]

	 [0][0] == [1][1] == [2][2]
	 [2][0] == [1][1] == [0][2]
	 
	 */

	if ((x_o_entries[0][0] == "x" || x_o_entries[0][0] == "o") && x_o_entries[0][0] == x_o_entries[1][1] && x_o_entries[1][1] == x_o_entries[2][2]) {
		win = true;
		winner = x_o_entries[0][0];
		return;
	}
	if ((x_o_entries[2][0] == "x" || x_o_entries[2][0] == "o") && x_o_entries[2][0] == x_o_entries[1][1] && x_o_entries[1][1] == x_o_entries[0][2]) {
		win = true;
		winner = x_o_entries[2][0];
		return;
	}


	for(int n = 0; n < 3; n++)
	{
		if ((x_o_entries[n][0] == "x" || x_o_entries[n][0] == "o") && x_o_entries[n][0] == x_o_entries[n][1] && x_o_entries[n][1] == x_o_entries[n][2]) {
			win = true;
			winner = x_o_entries[n][0];
			return;
		}
		if ((x_o_entries[0][n] == "x" || x_o_entries[0][n] == "o") && x_o_entries[0][n] == x_o_entries[1][n] && x_o_entries[1][n] == x_o_entries[2][n]) {
			win = true;
			winner = x_o_entries[0][n];
			return;
		}
	}

}
void gameRules()
{
	cout << "The game will be displayed like this:" << endl;
	gameMap();
	cout << endl;
	cout << "The columns are labeled a-c." << endl;
	cout << "The rows are labeled 1-3." << endl;
	cout << "First type in the letter of the column where you want to place your letter." << endl;
	cout << "Then type in the number of the row where you want to place your letter." << endl;
	cout << endl;
}



int main()
{
	Welcome();
	return 0;
}
/*

	   a     b     c
	      |     |     
	1  o  |  -  |  x  
	 _____|_____|_____
	      |     |     
	2  -  |  o  |  x  
	 _____|_____|_____
	      |     |     
	3  -  |  -  |  o  
	      |     |     
	
	notation:

	a1
	b2
	c1
	c3
 
 */
