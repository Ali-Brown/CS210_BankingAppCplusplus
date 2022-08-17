#include <iostream>
#include <vector>
using namespace std;

#include "YearlyBalance.h"


class YearlyBalances {
	public:
		YearlyBalances(vector<YearlyBalance*> balancesWithoutDeposit, vector<YearlyBalance*> balancesWithDeposit);
		void AddBalanceWithDeposit(double initialInvestment = 0.0, double monthlyDeposit = 0.0, double annualInterest = 0.0, int yearNumber = 0);
		//vector<YearlyBalance> GetBalancesWithoutDeposit();
		vector<YearlyBalance*> GetBalancesWithDeposit();
	private:
		vector<YearlyBalance*> balancesWithoutDeposit;
		vector<YearlyBalance*> balancesWithDeposit;
};

YearlyBalances::YearlyBalances(vector<YearlyBalance*> balancesWithoutDeposit, vector<YearlyBalance*> balancesWithDeposit) {
	this->balancesWithDeposit = balancesWithDeposit;
	this->balancesWithoutDeposit = balancesWithoutDeposit;
}

void YearlyBalances::AddBalanceWithDeposit(double initialInvestment, double monthlyDeposit, double annualInterest, int yearNumber) {
	double lastYearBalance = initialInvestment;
	double monthlyInterest = (annualInterest * 0.01 / 12);
	cout << "monthlyInterest: " << monthlyInterest << endl;
	unsigned int i;
	unsigned int j;
	unsigned int numberOfYears = yearNumber;

	for (i = 0; i < numberOfYears; ++i) {
		YearlyBalance* currentBalance;
		int yearNumber = i + 1;
		double currentYearBalance = lastYearBalance;
		double totalYearInterest = 0.0;
		double currentMonthInterest = 0.0;



		for (j = 0; j < 12; ++j) {
			currentYearBalance = currentYearBalance + monthlyDeposit;
			currentMonthInterest = currentYearBalance * monthlyInterest;
			currentYearBalance = currentYearBalance + currentMonthInterest;
			totalYearInterest = totalYearInterest + currentMonthInterest;

			cout << yearNumber << " " << totalYearInterest << " " << currentYearBalance << endl;
		}

		cout << endl;

		currentBalance = new YearlyBalance(yearNumber, totalYearInterest, currentYearBalance);

		balancesWithDeposit.push_back(currentBalance);

		lastYearBalance = currentYearBalance;

	}
}

vector<YearlyBalance*> YearlyBalances::GetBalancesWithDeposit() {
	return this->balancesWithDeposit;
}