//
//This class will handle storing expenses, tracking income and calculating totals and balances
//a bunch of methods

#include "../include/ExpenseManager.h"
#include <ctime>
#include <sstream>
#include <iomanip>

ExpenseManager::ExpenseManager() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(now, "%B %Y"); // e.g. "November 2025"
    currentMonth = oss.str();
}

void ExpenseManager::setMonth(const std::string& month) {
    currentMonth = month;
}

std::string ExpenseManager::getMonth() const {
    return currentMonth;
}

void ExpenseManager::setIncome(double newIncome) {
    monthlyIncome[currentMonth] = newIncome;
}

double ExpenseManager::getIncome() const {
    if (monthlyIncome.count(currentMonth))
        return monthlyIncome.at(currentMonth);
    return 0.0;
}

void ExpenseManager::addExpense(const Expense& expense) {
    monthlyExpenses[currentMonth].push_back(expense);
}

const std::vector<Expense>& ExpenseManager::getExpenses() const {
    static std::vector<Expense> empty;
    auto it = monthlyExpenses.find(currentMonth);
    if (it != monthlyExpenses.end())
        return it->second;
    return empty;
}

double ExpenseManager::calculateTotalExpenses() const {
    double total = 0.0;
    auto it = monthlyExpenses.find(currentMonth);
    if (it != monthlyExpenses.end()) {
        for (const auto& e : it->second)
            total += e.getAmount();
    }
    return total;
}

double ExpenseManager::calculateRemainingBalance() const {
    return getIncome() - calculateTotalExpenses();
}
