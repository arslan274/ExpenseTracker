#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "../include/ExpenseManager.h"
#include <QMessageBox>
#include <QComboBox>
#include <QDate>

class MainWindow : public QMainWindow {
    Q_OBJECT   // <-- REQUIRED for Qt signals/slots!

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
    QComboBox *monthSelector;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setupUI();
    void refreshTable();

private slots:
    void addExpense();
    void updateSummary();
};

#endif
