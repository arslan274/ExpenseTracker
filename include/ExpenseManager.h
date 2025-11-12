#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "Expense.h"
#include <map>
#include <string>
#include <vector>

class ExpenseManager {
private:
    std::map<std::string, std::vector<Expense>> monthlyExpenses;
    std::map<std::string, double> monthlyIncome;
    std::string currentMonth;

public:
    ExpenseManager();

    void setMonth(const std::string& month);
    std::string getMonth() const;

    void setIncome(double newIncome);
    double getIncome() const;

    void addExpense(const Expense& expense);
    const std::vector<Expense>& getExpenses() const;

    double calculateTotalExpenses() const;
    double calculateRemainingBalance() const;
};

#endif
