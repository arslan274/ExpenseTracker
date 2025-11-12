//
// Created by Arslan Shaikh on 12/11/2025.
//

#include "WelcomeWindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QWidget(parent) {

    setWindowTitle("Welcome");
    resize(400, 250);

    auto *layout = new QVBoxLayout(this);

    auto *label = new QLabel("👋 Hello, welcome to Expense Tracker!", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 18px; font-weight: bold;");

    auto *continueButton = new QPushButton("Continue", this);
    continueButton->setStyleSheet("font-size: 16px; padding: 8px;");

    layout->addStretch();
    layout->addWidget(label);
    layout->addSpacing(10);
    layout->addWidget(continueButton, 0, Qt::AlignCenter);
    layout->addStretch();

    connect(continueButton, &QPushButton::clicked, this, &WelcomeWindow::continueClicked);
}
