#pragma once
void startup();
void reception();
void playGame();
void playSlotMachine();
void playBlackjack();
void playRoulette();
void Clear();

//create user class and implement login funciton
class User {
	std::string username;
	std::string password;
	int chips;
	int balance;

	public:
		User(std::string newUsername, std::string newPassword, int newBalance);
		//void login(std::string loginName, std::string loginPassword);
		void buyChips(int chipsToBuy) { chips += chipsToBuy; balance -= chipsToBuy; }
		int getChips() { return chips; }
		void setChips(int newChips) { chips = newChips; }
		void deposit(int deposit) { balance += deposit; }
		int getBalance() { return balance; }
		void withdrawChips(int chipsToWithdraw) { chips -= chipsToWithdraw; balance += chipsToWithdraw;	}

};