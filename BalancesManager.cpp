#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>
using namespace std;
using std::cin; using std::numeric_limits;
using std::cout; using std::endl;

#include "BalancesManager.h"
#include "YearlyBalance.h"

BalancesManager::BalancesManager(double initialInvestment, double monthlyDeposit, double annualInterest, int numberOfYears) {
	this->initialInvestment = initialInvestment;
	this->monthlyDeposit = monthlyDeposit;
	this->annualInterest = annualInterest;
	this->numberOfYears = numberOfYears;
}

void BalancesManager::ProcessData() {
	this->initialInvestment = 0.0;
	this->monthlyDeposit = 0.0;
	this->annualInterest = 0.0;
	this->numberOfYears = 0;

	double initialInvestment = 0.0;
	double monthlyDeposit = 0.0;
	double annualInterest = 0.0;
	int numberOfYears = 0;

	bool continueToPrintBalance = false;

	bool validDataEntries = false;

	while (!validDataEntries) {
		try {
			system("CLS");
			PrintDataInputHeader();
			cout << "ENTER INITIAL INVESTMENT" << endl;
			if (!(cin >> initialInvestment) || initialInvestment <= 0) {
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
				throw runtime_error("ENTER VALID INVESTMENT NUMBER");
			}

			cout << "ENTER MONTHLY DEPOSITS" << endl;
			if (!(cin >> monthlyDeposit) || monthlyDeposit <= 0) {
				throw runtime_error("ENTER VALID DEPOSIT NUMBER");
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			}

			cout << "ENTER ANNUAL INTEREST" << endl;
			if (!(cin >> annualInterest) || annualInterest <= 0) {
				throw runtime_error("ENTER VALID DEPOSIT NUMBER");
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			}

			cout << "ENTER NUMBER OF YEARS" << endl;
			if (!(cin >> numberOfYears) || numberOfYears <= 0) {
				throw runtime_error("ENTER VALID DEPOSIT NUMBER");
				cin.clear();
				cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			}

		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;

			cout << "CANNOT COMPUTE BALANCES WITH INVALID INPUTS!" << endl;
		}
		validDataEntries = true;
	}

	if (validDataEntries) {
		this->initialInvestment = initialInvestment;
		this->monthlyDeposit = monthlyDeposit;
		this->annualInterest = annualInterest;
		this->numberOfYears = numberOfYears;

		system("CLS");
		PrintInputConfirmation();
	}
}

void BalancesManager::PrintBalances() {
	vector<YearlyBalance*> balanceWithDeposits;
	vector<YearlyBalance*> balanceWithoutDeposits;
	double initialInvestment = this->initialInvestment; 
	double monthlyDeposit = this->monthlyDeposit;
	double annualInterest = this->annualInterest;
	int numberOfYears = this->numberOfYears;
	double lastYearBalance;
	unsigned int i;

	cout << flush << endl;

	monthlyDeposit = 0.0;
	lastYearBalance = this->initialInvestment;

	for (i = 0; i < numberOfYears; ++i) {
		YearlyBalance* currentBalance;
		int yearNumber = i + 1;
		initialInvestment = lastYearBalance;

		currentBalance = new YearlyBalance(0, 0.0, 0.0);
		currentBalance->CalculateYearlyBalance(initialInvestment, monthlyDeposit, annualInterest, yearNumber);
		lastYearBalance = currentBalance->GetYearEndBalance();

		balanceWithoutDeposits.push_back(currentBalance);
	}

	system("CLS");
	PrintBalanceHeader("no deposit");
	for (i = 0; i < balanceWithoutDeposits.size(); ++i) {
		cout << setfill(' ') << right << setw(6) << fixed << setprecision(2) << balanceWithoutDeposits.at(i)->GetYearNumber() << ""
			<< right << setw(24) << fixed << setprecision(2) << balanceWithoutDeposits.at(i)->GetYearEndBalance() << ""
			<< right << setw(34) << fixed << setprecision(2) << balanceWithoutDeposits.at(i)->GetYearEndInterest() << ""
			<< endl;
	}
	cout << endl;

	monthlyDeposit = this->monthlyDeposit;
	lastYearBalance = this->initialInvestment;

	for (i = 0; i < numberOfYears; ++i) {
		YearlyBalance* currentBalance;
		int yearNumber = i + 1;
		initialInvestment = lastYearBalance;

		currentBalance = new YearlyBalance(0, 0.0, 0.0);
		currentBalance->CalculateYearlyBalance(initialInvestment, monthlyDeposit, annualInterest, yearNumber);
		lastYearBalance = currentBalance->GetYearEndBalance();

		balanceWithDeposits.push_back(currentBalance);
	}

	PrintBalanceHeader("deposit");
	for (i = 0; i < balanceWithDeposits.size(); ++i) {
		cout << setfill(' ') << right << setw(6) << fixed << setprecision(2) << balanceWithDeposits.at(i)->GetYearNumber() << ""
			<< right << setw(24) << fixed << setprecision(2) << balanceWithDeposits.at(i)->GetYearEndBalance() << ""
			<< right << setw(34) << fixed << setprecision(2) << balanceWithDeposits.at(i)->GetYearEndInterest() << ""
			<< endl;
	}
	cout << endl;
}

void BalancesManager::centerString(string stringToCenter, int lineLength) {
	int spaces = 0;

	spaces = (lineLength - stringToCenter.size()) / 2;
	if (spaces > 0) {
		cout << string(spaces, ' ');
	}
	cout << stringToCenter;
	if (spaces > 0) {
		cout << string(spaces, ' ');
	}
}

void BalancesManager::PrintDataInputHeader() {
	cout << setfill('*') << setw(34) << "" << endl;
	centerString("Data Input", 34);
	cout << endl;
	cout << setfill('*') << setw(34) << "" << endl;
}

void BalancesManager::PrintBalanceHeader(string type) {
	cout << setfill('=') << setw(64) << "" << endl;
	if (type == "no deposit") {
		centerString("Balance and Interest Without Additional Monthly Deposits", 64);
	}
	else {
		centerString("Balance and Interest With Additional Monthly Deposits", 64);
	}
	cout << endl;
	cout << setfill('=') << setw(64) << "" << endl;

	cout << setfill(' ') << right << setw(6) << "Year" << ""
		<< right << setw(24) << "Year End Balance $" << ""
		<< right << setw(34) << "Year End Earned Interest $" << ""
		<< endl;

	cout << setfill('-') << setw(64) << "" << endl;
}

void BalancesManager::PrintInputConfirmation() {
	PrintDataInputHeader();
	cout << "Initial Investment Amount:  " << "$" << fixed << setprecision(2) << this->initialInvestment << endl;
	cout << "Monthly Deposit:  " << "$" << fixed << setprecision(2) << this->monthlyDeposit << endl;
	cout << "Annual Interest:  " << fixed << setprecision(2) << this->annualInterest << "%" << endl;
	cout << "Number of Years:  " << this->numberOfYears << endl;
	cout << endl;
}