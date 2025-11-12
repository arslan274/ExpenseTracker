//
// Created by Arslan Shaikh on 12/11/2025.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../include/ExpenseManager.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    ExpenseManager manager;

    QLineEdit *incomeInput;
    QLineEdit *dateInput;
    QLineEdit *categoryInput;
    QLineEdit *descriptionInput;
    QLineEdit *amountInput;

    QTableWidget *expenseTable;
    QLabel *totalLabel;
    QLabel *balanceLabel;

    QPushButton *addButton;
    QPushButton *updateSummaryButton;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setupUI();
    void refreshTable();

private slots:
    void addExpense();
    void updateSummary();
};

#endif
