#include "MainWindow.hpp"

#include <QApplication>
 
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);  

    MainWindow window;

    window.resize(600, 500);
    window.show();
    window.raise();
    
    return app.exec();
}
