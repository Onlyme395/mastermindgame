// Mastermind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "codecalc.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <string>

/*
The Game Mastermind. The game where you have to guess the numbers correctly in as few attempts as possible.

Tasks the game requires:
Create a random number between 0000, and 9999
Split the number into 4 separate ones. {w, x, y, z}. Track the positions of each number.
Set the attempts number to 0.
Get User Input with a 4 digit number
Incriment attempt count
Split the number into an array. {a, b, c, d}
Compare the input with each number separately.
If number is wrong, display a -. If that number exists, but the position is wrong, show an O. If it exists, and the position is correct, display an X.

Game is won when user has guessed the correct combination

*/

// Ask the user to input a 4 digit number.
int AskNumber() {
	int guess;
	printf("Enter your 4 digit number: ");
	std::cin >> guess;
	return guess;
}


// Compare the Guess with the Master, using strings.
std::string CompareGuess(const int &iGuess, const int &iMaster) {

	int strPos = 0;
	// convert the integers to strings
	std::string sGuess = (std::to_string(iGuess));
	std::string sMaster = (std::to_string(iMaster));
	std::string iResult;

	while (sMaster.length() < 4) {
		sMaster.insert(0, "0");
	}

	while (sGuess.length() < 4) {
		sGuess.insert(0, "0");
	}

	// debugging - seeing the master with the guess.

	if (sGuess.compare(sMaster) == 0)
	{
		std::cout << "Guess is Correct!" << std::endl;
		iResult = "Correct";
		return iResult;
	}

	do { // Now compare the strings together using the rules of the game
		std::string cAnswer("O");
		//std::cout << "Master is: " << sMaster << std::endl;
		//std::cout << "Guess is: " << sGuess << std::endl;
		bool found = false;

		if (sGuess.at(strPos) != sMaster.at(strPos))
		{
			for (int i = 0; i < 4; i++) {
				if (sGuess.at(strPos) == sMaster.at(i))
					found = true;
			}
			// did it find the number somwehre?
			if (found == true)
				cAnswer.replace(0, 1, "0");

		}

		// Is the number in the correct slot?
		if (sGuess.at(strPos) == sMaster.at(strPos))
			cAnswer.replace(0, 1, "X");


		//put the answer in the result string
		iResult.append(cAnswer);
		strPos++;
	} while (strPos < 4);

	return iResult;
}


int DisplayResult()
{
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	// establish variables for the game, as well as the lists for comparison.
	bool win = 0;
	int mastermind, guess, attempts = 0;
	std::string compared = "";
	// Generate the random seed for the mastermind..

	srand(time(NULL));
	mastermind = rand() % 10000;

	// for Debugging less than 1000
	//mastermind = 254;

	std::cout << "Welcome to mastermind. The code has been generated. Break it, if you can!"; // << mastermind << std::endl;
	std::cout << std::endl;
	// The Loop for the game. Keeps going until you win.

	do {

		// Ask user for X digit number Number
		guess = AskNumber();

		// Compare digits against the mastermind
		compared = CompareGuess(guess, mastermind);

		// Display their results, with placements
		//DisplayResult();
		if (guess != mastermind)
			std::cout << compared << std::endl;

		if (guess == mastermind)
			win = 1;

		attempts++;

	} while (win == 0);

	std::cout << "Congratulations! You won! It took you " << attempts << " attempts" << std::endl;

	// Ignore Below
	char STOP;
	std::cin >> STOP;
	return 0;

}

