#include <iostream>
#include <string.h>
#include <sstream>
#include <Windows.h>
#include <random>
#include "funcitons.h"

User player = User("Aidan", "1234", 1000);

using namespace std;

/*Class Setup*/
User::User(string newUsername, string newPassword, int newBalance) {
	username = newUsername;
	password = newPassword;
	chips = 0;
	balance = newBalance;
}

void startup() {
	string userInput;
	cout << "-------------------------------" << endl;
	cout << "|        AIDANS CASINO        |" << endl;
	cout << "-------------------------------" << endl;

	cout << "Do you have an account?" << endl;
	cin >> userInput;

	if (userInput == "Y" || userInput == "y") {
		reception();
	}
}


void reception() {
	Clear();
	string userInput;

	cout << "\n---Welcome to the Casino-------" << endl;
	cout << "---What would you like to do?--" << endl;
	cout << "---1: Buy Chips" << endl;
	cout << "---2: Cash Out" << endl;
	cout << "---3: Play A Game" << endl;
	cout << "---4: Leave the Casino" << endl;

	cin >> userInput;

	if (userInput == "1") {
		Clear();
		int chipsToBuy = 0;
		cout << "---Chips: " << player.getChips() << endl;
		cout << "---Balance: " << player.getBalance() << endl;
		cout << "---How may chips would you like to buy?" << endl;
		cin >> chipsToBuy;
		player.buyChips(chipsToBuy);
		cout << "---Chips: " << player.getChips() << endl;
		cout << "---Balance: " << player.getBalance() << endl;
		system("pause");
		reception();
	}
	else if (userInput == "2") {
		Clear();
		int withdrawal;
		cout << "---CASH OUT---" << endl;
		cout << "---Balance: " << player.getBalance() << endl;
		cout << "---Amount to cash out: ";
		cin >> withdrawal;
		player.withdrawChips(withdrawal);
		reception();
	} else if (userInput == "3") {
		playGame();
	} else {
		return;
	}
}


/*int buyChips() {
	int extraChips;

	cout << "You have X Chips" << endl;
	cout << "There is a fee of €1 for every €100 exchanged" << endl;
	cout << "How many chips would you like: ";
	cin >> extraChips;
	cout << endl;

	return extraChips;
}*/

void playGame() {
	Clear();
	int gameChoice;
	cout << "---Chips: " << player.getChips() << endl;
	cout << "\n\n";
	cout << "Which game would you like to play?" << endl;
	cout << "---1: Blackjack" << endl;
	cout << "---2: Slot Machines" << endl;
	cout << "---3: Texas HoldEm Poker" << endl;
	cout << "---4: Roulette" << endl;
	cout << "---9: Return to Reception" << endl;
	cin >> gameChoice;

	switch (gameChoice){
		case 1:
			playBlackjack();
			break;
		case 2:
			playSlotMachine();
			break;
		case 4:
			playRoulette();
			break;
		case 9:
			reception();
			break;
		default:
			cout << "END";
			break;
	}
}

//Slot Machine Game
void playSlotMachine() {
	Clear();
	cout << "---Chips: " << player.getChips() << endl;
	cout << "\n\n";

	string userInput;
	cout << "~~~~Slot Machines~~~~" << endl;
	cout << "  _____________    " << endl;
	cout << "  | X | X | X |   o " << endl;
	cout << "  -------------  | " << endl;
	cout << "  |           |--- " << endl;
	cout << "  |           |    " << endl;
	cout << "  |           |    " << endl;
	cout << "  |___________|    " << endl;
	cout << "                 " << endl;
	cout << "---5 Chips To Play" << endl;
	cout << "---1: Spin" << endl;
	cout << "---2: Quit" << endl;

	while (userInput != "1") {
		cin >> userInput;
		if (userInput == "2") {
			Clear();
			reception();
		}
		else if (userInput != "1" || userInput != "2") {
			cout << "Invalid response" << endl;
			cout << "---1: Spin" << endl;
			cout << "---2: Quit" << endl;
		}
	}

	if (player.getChips() < 5) {
		cout << "You do not have enought chips to play" << endl;
		system("pause");
		reception();
	}

	player.setChips(player.getChips() - 5);

	int slot1 = rand() % 3 + 1;
	int slot2 = rand() % 3 + 1;
	int slot3 = rand() % 3 + 1;

	Clear();
	cout << "---Chips: " << player.getChips() << endl;
	cout << "\n\n";
	cout << "------SPIN 1------" << endl;
	cout << "  _____________    " << endl;
	cout << "  | " << slot1 << " | X | X |  o " << endl;
	cout << "  -------------  | " << endl;
	cout << "  |           |--- " << endl;
	cout << "  |           |    " << endl;
	cout << "  |           |    " << endl;
	cout << "  |___________|    " << endl;
	cout << "                   " << endl;

	Sleep(1000);

	Clear();
	cout << "---Chips: " << player.getChips() << endl;
	cout << "\n\n";
	cout << "------SPIN 2------" << endl;
	cout << "  _____________    " << endl;
	cout << "  | " << slot1 << " | " << slot2 << " | X |  o " << endl;
	cout << "  -------------  | " << endl;
	cout << "  |           |--- " << endl;
	cout << "  |           |    " << endl;
	cout << "  |           |    " << endl;
	cout << "  |___________|    " << endl;
	cout << "                   " << endl;

	Sleep(1000);

	Clear();
	cout << "---Chips: " << player.getChips() << endl;
	cout << "\n\n";
	cout << "------SPIN 3------" << endl;
	cout << "  _____________    " << endl;
	cout << "  | " << slot1 << " | " << slot2 << " | " << slot3 << " |  o " << endl;
	cout << "  -------------  | " << endl;
	cout << "  |           |--- " << endl;
	cout << "  |           |    " << endl;
	cout << "  |           |    " << endl;
	cout << "  |___________|    " << endl;
	cout << "                   " << endl;

	Sleep(1000);

	if (slot1 == slot2 && slot2 == slot3) {
		cout << "WINNER!!!" << endl;
		player.setChips(player.getChips() + 200);
	}
	else {
		cout << "Better Luck New Time" << endl;
	}

	cout << "Play Again? Y/N" << endl;
	cin >> userInput;

	if (userInput == "Y" || userInput == "y") {
		playSlotMachine();
	} else {
		reception();
	}
}

//Blackjack Game
void playBlackjack() {
	Clear();
	string userInput;
	int cardDeck[] = { 1,1,1,1, 2,2,2,2, 3,3,3,3, 4,4,4,4, 5,5,5,5, 6,6,6,6, 7,7,7,7, 8,8,8,8, 9,9,9,9, 10,10,10,10, 11,11,11,11, 12,12,12,12, 13,13,13,13 };
	int dealersCardsTotal = 0;
	int playersCardsTotal = 0;

	//deal dealers cards
	int cardChoice = rand() % 52 - 1;
	cout << "DEBUG: Dealers Card 1: " << cardDeck[cardChoice] << endl;
	dealersCardsTotal += cardDeck[cardChoice];
	cardChoice = rand() % 52 + 1;
	cout << "DEBUG: Dealers Card 2: " << cardDeck[cardChoice] << endl;
	dealersCardsTotal += cardDeck[cardChoice];

	//deal players cards
	cardChoice = rand() % 52 + 1;
	cout << "DEBUG: Players Card 1: " << cardDeck[cardChoice] << endl;
	playersCardsTotal += cardDeck[cardChoice];
	cardChoice = rand() % 52 + 1;
	cout << "DEBUG: Players Card 2: " << cardDeck[cardChoice] << endl;
	playersCardsTotal += cardDeck[cardChoice];

	cout << "Delaers Total: " << dealersCardsTotal << endl;


	//if the dealer has 21
	if (dealersCardsTotal == 21) {
		cout << "Dealer has balckjack" << endl;
		cout << "You lose" << endl;
		cout << "Would you like to play again? Y/N" << endl;
		cin >> userInput;

		if (userInput == "Y") {
			playBlackjack();
		} else {
			reception();
		}
	}

	cout << "You have: " << playersCardsTotal << endl;
	cout << "Would you like to hit or stand?" << endl;
	cout << "1. Hit" << endl;
	cout << "2. Stand" << endl;
	cin >> userInput;

	while (userInput == "1") {
		cardChoice = rand() % 52 + 1;
		cout << "DEBUG: Players Card 2: " << cardDeck[cardChoice] << endl;
		playersCardsTotal += cardDeck[cardChoice];

		cout << "You have: " << playersCardsTotal << endl;

		//if the player has gone over 21
		if (playersCardsTotal > 21) {
			cout << "You have gone bust" << endl;
			cout << "Would you like to play again? Y/N" << endl;
			cin >> userInput;
			if (userInput == "Y") {
				playBlackjack();
			} else {
				reception();
			}

			break;
		}

		cout << "Would you like to hit or stand?" << endl;
		cout << "1. Hit" << endl;
		cout << "2. Stand" << endl;
		cin >> userInput;
	}

	//player total is less than 21
	//draw dealers card until they are at least 17
	while (dealersCardsTotal < 17) {
		cardChoice = rand() % 52 + 1;
		cout << "DEBUG: Dealers Card: " << cardDeck[cardChoice] << endl;
		dealersCardsTotal += cardDeck[cardChoice];
		cout << "Dealers Total: " << dealersCardsTotal << endl;
	}

	//if the dealer has gone over 21 or the player has higher than the dealer
	if (dealersCardsTotal > 21 || dealersCardsTotal < playersCardsTotal) {
		cout << "YOU WIN!!" << endl;
	}

	cout << "Would you like to play again? Y/N" << endl;
	cin >> userInput;

	if (userInput == "Y") {
		playBlackjack();
	} else {
		reception();
	}
}

void playRoulette() {
	Clear();
	string userInput;

	cout << "                            ROULETTE                              " << endl;
	cout << "  ________________________________________________________________" << endl;
	cout << "  |    |  3  6  9  12  |  15  18  21  24  |  27  30  33  36  | [D]" << endl;
	cout << "  |    |-----------------------------------------------------|----" << endl;
	cout << "  |  0 |  2  5  8  11  |  14  17  20  23  |  26  29  32  35  | [E]" << endl;
	cout << "  |    |-----------------------------------------------------|----" << endl;
	cout << "  |    |  1  4  7  10  |  13  16  19  22  |  25  28  31  34  | [F]" << endl;
	cout << "  ----------------------------------------------------------------" << endl;
	cout << "       |     [A]       |      [B]         |        [C]       |    " << endl;
	cout << endl;
	cout << "  A: Bet on first third   |  D: Bet on top row      |  Red: Bet on red      " << endl;
	cout << "  B: Bet on middle third  |  E: Bet on middle row   |  Black: Bet on black  " << endl;
	cout << "  C: Bet on final third   |  F: Bet on bottom row   |                       " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Pick a number to bet on: ";
	cin >> userInput;

	int rouletteWheel = rand() % 37; //Random number between 0 and 36

	cout << "Spinning." << endl;
	Sleep(1000);
	cout << "Spinning.." << endl;
	Sleep(1000);
	cout << "Spinning..." << endl;
	Sleep(1000);
	cout << "Roulette wheel has landed on " << rouletteWheel << endl;

	//if user picked a number
	if (stoi(userInput) == rouletteWheel) {
		cout << "WINNER" << endl;
	}

	cout << "Would you like to play again? Y/N" << endl;
	cin >> userInput;

	if (userInput == "Y") {
		playRoulette();
	} else {
		reception();
	}

}

//Clear screen function
void Clear()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}