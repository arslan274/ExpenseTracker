//
// Created by Arslan Shaikh on 12/11/2025.
//

#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setupUI();
}

void MainWindow::setupUI() {
    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QVBoxLayout *layout = new QVBoxLayout(central);

    incomeInput = new QLineEdit(this);
    incomeInput->setPlaceholderText("Enter your income (£)");

    dateInput = new QLineEdit(this);
    dateInput->setPlaceholderText("Date (YYYY-MM-DD)");

    categoryInput = new QLineEdit(this);
    categoryInput->setPlaceholderText("Category");

    descriptionInput = new QLineEdit(this);
    descriptionInput->setPlaceholderText("Description");

    amountInput = new QLineEdit(this);
    amountInput->setPlaceholderText("Amount (£)");

    addButton = new QPushButton("Add Expense", this);
    updateSummaryButton = new QPushButton("Update Summary", this);

    expenseTable = new QTableWidget(0, 4, this);
    expenseTable->setHorizontalHeaderLabels({"Date", "Category", "Description", "Amount"});
    expenseTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    totalLabel = new QLabel("Total: £0.00", this);
    balanceLabel = new QLabel("Balance: £0.00", this);

    layout->addWidget(incomeInput);
    layout->addWidget(dateInput);
    layout->addWidget(categoryInput);
    layout->addWidget(descriptionInput);
    layout->addWidget(amountInput);
    layout->addWidget(addButton);
    layout->addWidget(updateSummaryButton);
    layout->addWidget(expenseTable);
    layout->addWidget(totalLabel);
    layout->addWidget(balanceLabel);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addExpense);
    connect(updateSummaryButton, &QPushButton::clicked, this, &MainWindow::updateSummary);

    setWindowTitle("Expense Tracker");
    resize(600, 700);
}

void MainWindow::addExpense() {
    QString date = dateInput->text();
    QString category = categoryInput->text();
    QString desc = descriptionInput->text();
    double amount = amountInput->text().toDouble();

    Expense e(date.toStdString(), category.toStdString(), desc.toStdString(), amount);
    manager.addExpense(e);

    refreshTable();
}

void MainWindow::refreshTable() {
    expenseTable->setRowCount(0);
    // Access internal expense data via print or loop — modify your ExpenseManager later to return vector<Expense>
    // For now, this can be left as placeholder.
}

void MainWindow::updateSummary() {
    double income = incomeInput->text().toDouble();
    manager.setIncome(income);

    double total = manager.calculateTotalExpenses();
    double balance = manager.calculateRemainingBalance();

    totalLabel->setText(QString("Total: £%1").arg(total, 0, 'f', 2));
    balanceLabel->setText(QString("Balance: £%1").arg(balance, 0, 'f', 2));
}
