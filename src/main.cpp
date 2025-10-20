#include <iostream>
#include "Expense.h"

int main() {
    Expense lunch("2025-10-20", "Food", "Lunch at university canteen", 8.50);

    std::cout << "Expense: " << lunch.getDescription()
              << " | Category: " << lunch.getCategory()
              << " | Amount: £" << lunch.getAmount()
              << " | Date: " << lunch.getDate()
              << std::endl;

    return 0;
}
