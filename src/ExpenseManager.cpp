//
//This class will handle storing expenses, tracking income and calculating totals and balances
//a bunch of methods

#include "../include/ExpenseManager.h"

#include "ExpenseManager.h"
#include <iostream>

//setter method to set the user's new income
void ExpenseManager::setIncome(double newIncome) {
    income = newIncome;
}
//getter method to retrieve the user's new income
double ExpenseManager::getIncome() const {
    return income;
}

//add a new expense entry to the recorded responses
void ExpenseManager::addExpense(const Expense& expense) {
    expenses.push_back(expense);
}

//displays all recorded expenses in a list.
void ExpenseManager::viewExpenses() const {
    std::cout << "\n----- All Expenses -----\n";
    for (const auto& e : expenses) {

        //fields we will be focusing on
        std::cout << e.getDate() << " | "
                  << e.getCategory() << " | "
                  << e.getDescription() << " | £"
                  << e.getAmount() << "\n";
    }
    std::cout << "------------------------\n";
}

//calculates and returns the sum (total) of all the expense amounts
double ExpenseManager::calculateTotalExpenses() const {
    double total = 0.0;
    for (const auto& e : expenses)
        total += e.getAmount();
    return total;
}

//calculate the remaining balance subtracting income from total expenses
double ExpenseManager::calculateRemainingBalance() const {
    return income - calculateTotalExpenses();
}
