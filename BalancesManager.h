#pragma once
#ifndef BALANCESMANAGER_H
#define BALANCESMANAGER_H

class BalancesManager {
public:
	BalancesManager(double initialInvestment = 0.0, double monthlyDeposit = 0.0, double annualInterest = 0.0, int numberOfYears = 0);
	void ProcessData();
	void PrintBalances();
	void PrintDataInputHeader();
	void PrintBalanceHeader(string type);
	void PrintInputConfirmation();
	void centerString(string stringToCenter, int lineLength);
private:
	double initialInvestment = 0.0;
	double monthlyDeposit = 0.0;
	double annualInterest = 0.0;
	int numberOfYears = 0;
};

#endif
