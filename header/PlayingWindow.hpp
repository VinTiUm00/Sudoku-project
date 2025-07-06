#ifndef PLAYINGWINDOW_HPP
#define PLAYINGWINDOW_HPP

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QGridLayout>

class PlayingWindow : public QWidget {
    Q_OBJECT
public:
    PlayingWindow(QWidget* parent = nullptr);
    virtual ~PlayingWindow();

signals:
    void windowClosed();
    void selectNumberOne();
    void selectNumberTwo();
    void selectNumberThree();
    void selectNumberFour();
    void selectNumberFive();
    void selectNumberSix();
    void selectNumberSeven();
    void selectNumberEight();
    void selectNumberNine();

public slots:
    void startEasy();
    void startNormal();
    void startHard();
    void startInsane();
    void closeWindow();

private:
    QVector<QPushButton*> buttons;
};

#endif
