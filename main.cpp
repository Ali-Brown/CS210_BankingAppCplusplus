#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;
#include "YearlyBalance.h"
#include "BalancesManager.h"



int main() {
	bool startBalance = false;
	bool stopBalance = false;
	bool restartBalance = false;
	bool continueToBalance = false;
	string userOption = " ";

	BalancesManager* balancesManager;
	balancesManager = new BalancesManager(0.0, 0.0, 0.0, 0);
	startBalance = true;

	while (!stopBalance) {
		balancesManager->ProcessData();
		cout << endl;
		cout << "ENTER 'c' KEY TO CONTINUE" << endl;

		cin >> userOption;
		
		if (userOption == "c") {
			balancesManager->PrintBalances();
		}

		cout << endl;
		cout << "ENTER 'q' TO QUIT" << endl;
		cout << "ENTER r TO TRY NEW INPUT" << endl;

		cin >> userOption;
		if (userOption == "q") {
			//balancesManager->PrintBalances();
			stopBalance = true;
		}
		else if (userOption == "r") {
			continue;
		}
	}
	return 0;
}




