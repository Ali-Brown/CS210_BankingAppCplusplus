#pragma once
#ifndef YEARLYBALANCE_H
#define YEARLYBALANCE_H

class YearlyBalance {
	public:
		YearlyBalance(int YearNumber = 1, double YearEndBalance = 0.0, double YearEndInterest = 0.0);
		void SetYearNumber(int number);
		void SetYearEndBalance(double total);
		void SetYearEndInterest(double interest);
		int GetYearNumber();
		double GetYearEndBalance();
		double GetYearEndInterest();
		void CalculateYearlyBalance(double initialInvestment, double monthlyDeposit, double annualInterest, int yearNumber);
	private:
		int yearNumber = 0;
		double yearEndBalance = 0.0;
		double yearEndInterest = 0.0;
};

#endif // !YEARLYBALANCE_H

