#include "Expense.h"

Expense::Expense(const std::string& date, const std::string& category, const std::string& description, double amount)
    : date(date), category(category), description(description), amount(amount) {}

std::string Expense::getDate() const { return date; }
std::string Expense::getCategory() const { return category; }
std::string Expense::getDescription() const { return description; }
double Expense::getAmount() const { return amount; }
