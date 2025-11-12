#include <QApplication>
#include "MainWindow.h"
#include "WelcomeWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    WelcomeWindow welcome;
    MainWindow mainWin;

    QObject::connect(&welcome, &WelcomeWindow::continueClicked, [&]() {
        welcome.close();
        mainWin.show();
    });

    welcome.show();
    return app.exec();
}
