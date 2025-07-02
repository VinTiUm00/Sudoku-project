#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QWidget {

    Q_OBJECT // Макрос, без которого не работают сигналы

public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

public slots:
    void OpenDifficultMenu();
    void closeWindow();

private: // какие кнопки будут
    QLabel* lblMaxScore;
    QPushButton* btnPlay;
    QPushButton* btnSettings;
    QPushButton* btnExit;
};

#endif
