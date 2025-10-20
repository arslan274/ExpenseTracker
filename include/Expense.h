#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

class Expense {
private:
    std::string date;
    std::string category;
    std::string description;
    double amount;

public:
    Expense(const std::string& date, const std::string& category, const std::string& description, double amount);

    std::string getDate() const;
    std::string getCategory() const;
    std::string getDescription() const;
    double getAmount() const;
};

#endif
