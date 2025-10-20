#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "Expense.h"
#include <vector>
#include <string>

class ExpenseManager {
private:
    std::vector<Expense> expenses;
    double income = 0.0;

public:
    // Income handling
    void setIncome(double newIncome);
    double getIncome() const;

    // Expense handling
    void addExpense(const Expense& expense);
    void viewExpenses() const;

    // Calculations
    double calculateTotalExpenses() const;
    double calculateRemainingBalance() const;
};

#endif
