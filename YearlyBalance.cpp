#include <iostream>
#include <vector>
using namespace std;

#include "YearlyBalance.h"

YearlyBalance::YearlyBalance(int yearNumber, double yearEndBalance, double yearEndInterest) {
	this->yearNumber = yearNumber;
	this->yearEndBalance = yearEndBalance;
	this->yearEndInterest = yearEndInterest;
}

void YearlyBalance::SetYearNumber(int number) {
	this->yearNumber = number;
}
void YearlyBalance::SetYearEndBalance(double balance) {
	this->yearEndBalance = balance;
}
void YearlyBalance::SetYearEndInterest(double interest) {
	this->yearEndInterest = interest;
}
int YearlyBalance::GetYearNumber() {
	return this->yearNumber;
}
double YearlyBalance::GetYearEndBalance() {
	return this->yearEndBalance;
}
double YearlyBalance::GetYearEndInterest() {
	return this->yearEndInterest;
}
void YearlyBalance::CalculateYearlyBalance(double initialInvestment, double monthlyDeposit, double annualInterest, int yearNumber) {
	double lastYearBalance = initialInvestment;
	double monthlyInterest = (annualInterest * 0.01 / 12);
	unsigned int i;

	double currentYearBalance = lastYearBalance;
	double totalYearInterest = 0.0;
	double currentMonthInterest = 0.0;

	for (i = 0; i < 12; ++i) {
		currentYearBalance = currentYearBalance + monthlyDeposit;
		currentMonthInterest = currentYearBalance * monthlyInterest;
		currentYearBalance = currentYearBalance + currentMonthInterest;
		totalYearInterest = totalYearInterest + currentMonthInterest;
	}
	this->SetYearNumber(yearNumber);
	this->SetYearEndBalance(currentYearBalance);
	this->SetYearEndInterest(totalYearInterest);
}