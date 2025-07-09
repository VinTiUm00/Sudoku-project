#include "MainWindow.hpp"
#include "header/Generator.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  //инициализация приложения

    MainWindow window; //инициализация главного окна
    window.setObjectName("mainWindow");
    window.setStyleSheet("MainWindow { background-color: #282C34; }");

    window.resize(600, 500);
    window.show();
    window.raise();

    return app.exec();
}
