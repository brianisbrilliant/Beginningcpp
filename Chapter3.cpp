// Brian Foster IN200 Spring 2018
// Chapter 3 Beginning C++

/*	this is a block comment */

/* Last chapter we learned about:
	bool, if, else if, else
	relational operators
	switch
	while and do-while
	break and continue
	! NOT && AND || OR logical operators
	generating random numbers
*/

/* This chapter we will learn about:
	For loops
		for(initialization; test; action) 
			statement
	string variables
		data members and member functions
		index[0]
	arrays & multidimensional arrays
		the hero's inventory!
		collection initializer = string inv[3] = {"sword", "armor", "shield"};
		inv[0].size()		// string.size
		board[x][y] or board[horizontal][vertical]
*/

/* Last week's assignment
	welcome the player
	set up the game
	    int health = 10, attack, block, iterator
	    seed the random number generator
	start the loop
	    add 1 to the iterator
	    start the encounter
	        randomly generate numbers for attack (range = 0-4) and block (range = 0-4)
	        if block is greater or equal to attack, successful block
	        otherwise, subtract attack value from health.
	keep looping while health is greater than zero and fewer than 4 turns have happened
	
	if health is greater than 0, congratulate player
	otherwise, tell the player they're dead.
*/

/* Taking it further
	1. Make the number of turns before the adventure is over random.
	2. If the player's health is below a certain number, tell them to go see the doctor.
	3. Incorporate sleep() to change the pacing of the game and not have it all come out at once.
	4. Send me a link in the comments to your assignment hosted publicly, like on github.com (good for showing off what you know to future employers)
	5. Ask the player if they'd like to see all of the numbers used in the game (a debug mode) and if they do, post them at every point they're used.
*/

/*
#include <chrono>
#include <thread>

// put this line anywhere you want the program to wait. 1000ms = 1 second
std::this_thread::sleep_for(std::chrono::milliseconds(1000));

*/

#include <iostream>			// for sending and recieving text to the console
#include <ctime>			// for random numbers
#include <cstdlib>			// for random numbers
#include <chrono>			// for sleep()
#include <thread>			// for sleep()
#include <string>			// for strings!
using namespace std;		// so I don't have to type std::


void AdventureMode(){
	// welcome the player
	cout << "Welcome to Adventure Mode! Get ready for Adventure!\n";
	// set up the game
	//     seed the random number generator
	srand(time(0));
	bool debugMode = false;
	int password;
	
	cout << "Do you have the password? >>";
	cin >> password;
	
	if(password == 1234) {
		debugMode = true;
		cout << "DebugMode is now ON\n";
	} else {
		cout << "I'm sorry, that's not the correct password.\n";
	}
	
	int health = 10, attack = 0, block = 0, iterator = 0;
	int totalTurns = (rand() % 5) + 3;
	if(debugMode) cout << "totalTurns = " << totalTurns << endl;
	
	
	
	// start the loop
	do {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		//     add 1 to the iterator
		iterator++;
		if(debugMode) cout << "iterator = " << iterator << endl;
		//     start the encounter
		cout << "An enemy approaches!\n";
		//         randomly generate numbers for attack (range = 0-4) and block (range = 0-4)
		attack = rand() % 5;
		block = rand() % 5;
		if(debugMode) cout << "attack = " << attack << "\nblock = " << block << endl;
		//         if block is greater or equal to attack, successful block
		//         otherwise, subtract attack value from health.
		if(block >= attack) {
			cout << "You've successfully blocked the enemy attack!\n";
		} else {
			cout << "Your block was unsuccessful!\n";
			health -= attack;
			cout << "Your health is now = " << health << ".\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
		
		// keep looping while health is greater than zero and fewer than 4 turns have happened
	} while(health > 0 && iterator < totalTurns);
	
	// if health is greater than 0, congratulate player
	// otherwise, tell the player they're dead.
	if(health > 0) {
		cout << "Congrats! You survived!\n";
		if(health <= 4) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			cout << "You'd better go see the doctor, you look terrible.\n";
		}
	} else {
		cout << "You will be missed.\n";
	}
}

void CountingWithFor() {
	cout << "Counting forward:\n";
	
	//for(initialization; test; action) statement
	for(int i = 0; i < 10; i++) {
		cout << i << " ";
	}
	
	cout << "\nCounting backwards:\n";
	
	for(int i = 10; i >= 0; --i) {
		cout << i << " ";
	}
	
	cout << "\nNested for loops!\n";
	
	const int HORIZONTAL = 5;
	const int VERTICAL = 3;
	for(int i = 0; i < HORIZONTAL; ++i){
		for(int j = 0; j < VERTICAL; ++j) {
			cout << i << "." << j << "  ";
		}
		cout << endl;
	}
	
}

void StringTesting() {
	string welcome = "Hey! This is the string program!\n";
	cout << welcome;
	string numbers = "1234\n";
	cout << numbers;
	
	string first = "Darth";
	string last = "Vader";
	string punctuation = "!!?!";
	
	string phrase = first + " " + last + punctuation;
	cout << phrase << endl;
	cout << "Phrase = " << phrase << endl;
	cout << "phrase has " << phrase.size() << " characters.\n";
	
	cout << "The first character in phrase is '" << phrase[0] << "'.\n";
	
	for(int i = 0; i < phrase.size(); i++) {
		if(phrase[i] == '!' || phrase[i] == '?'){
			phrase[i] = ' ';
		}
		cout << phrase[i];
	}
	cout << "\n";
	
	cout << "The second word in phrase is at location " << phrase.find("Vader") << endl;
	
	phrase = "Now is the time for all good men to come to the aid of their country.";
	
	if(phrase.find("aid") == string::npos){
		cout << "'aid' is not in the phrase.\n";
	} else {
		cout << "'aid' starts at location " << phrase.find("aid") << ".\n";
	}
	
	//phrase.erase
	if(phrase.empty()) {
		cout << "The phrase is empty.\n";
	}
	
	
}

void HeroInv() {
	const int MAX_ITEMS = 10;
	string inv[MAX_ITEMS] = {"radio", "baseball", "gum"};					// an array is a list
	
	int numItems = 3;
	//inv[numItems++] = "transistor radio";				// inv[0]
	//inv[numItems++] = "baseball";
	//inv[numItems++] = "stick of gum";
	
	cout << "Your items:\n";
	for(int iter = 0; iter < numItems; iter++) {
		cout << iter + 1 << ". " << inv[iter] << endl;
	}
	
	cout << "Chewed the gum...\n";
	inv[2] = "chewed gum";
	
	cout << "Your items:\n";
	for(int iter = 0; iter < numItems; iter++) {
		cout << iter + 1 << ". " << inv[iter] << endl;
	}
	
	cout << "Picked up a yo-yo...\n";
	inv[numItems++] = "yo-yo";
	
	cout << "Your items:\n";
	for(int iter = 0; iter < numItems; iter++) {
		cout << iter + 1 << ". " << inv[iter] << endl;
	}
	
	cout << "inv[1] has " << inv[1].size() << " characters in it.\n";
	
}

void MultiArray() {
	cout << "Here we go!\n(It's too late for this)\n";
	// tictactoe board
	const int X = 3;
	const int Y = 3;
	
	// using a collection initializer
	char board[X][Y];
	
	board[0][0] = 'O';
	board[0][1] = 'X';
	board[0][2] = 'O';
	board[1][0] = ' ';
	board[1][1] = 'X';
	board[1][2] = 'X';
	board[2][0] = 'X';
	board[2][1] = 'O';
	board[2][2] = 'O';
	
	cout << "Here's the tictactoe board:\n";
	for(int i = 0; i < X; i++) {
		for(int j = 0; j < Y; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "X finishes the game.\n";
	board[1][0] = 'X';
	
	cout << "Here's the tictactoe board:\n";
	for(int i = 0; i < X; i++) {
		for(int j = 0; j < Y; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "'X' wins!\n";
	
}

int main() {
	cout << "What program would you like to run?\n>>";
	int choice;
	cin >> choice;
	
	switch(choice) {
		case 1: AdventureMode(); break;
		case 2: CountingWithFor(); break;
		case 3: StringTesting(); break;
		case 4: HeroInv(); break;
		case 5: MultiArray(); break;
		default: cout << "That's not one of the options, sorry.\n"; break;
	}

	return 0;
}
