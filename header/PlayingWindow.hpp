#ifndef PLAYINGWINDOW_HPP
#define PLAYINGWINDOW_HPP

#include <QWidget>
#include <QVector>
#include <QPushButton>
#include <QGridLayout>

#include "GameCell.hpp"
#include "ControlCell.hpp"

// класс игрового поля
class PlayingWindow : public QWidget {

    Q_OBJECT // Макрос, без которого не работают сигналы

public:
    PlayingWindow(QWidget* parent = nullptr);
    virtual ~PlayingWindow();
    void InitialiseGameField(short int mesh_size, short int format_chance);

signals:
    void windowClosed();

public slots:
    void startEasy();
    void startNormal();
    void startHard();
    void startInsane();
    void closeWindow();
    void Victory();
    void setFormatVal(int new_val);

private:
    QVector<GameCell*> CellButtons;
    QVector<ControlCell*> ControlButtons;

    std::vector<std::vector<short int>> Matrix;
    int format_chance = 45;
    int left2victory = 0;
};

#endif
