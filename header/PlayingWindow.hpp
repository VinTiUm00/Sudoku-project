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
    void InitialiseGameField(short int mesh_size); // Для инициализации после выбора сложности

signals:
    void windowClosed();

public slots:
    void startEasy();
    void startNormal();
    void startHard();
    void startInsane();
    void closeWindow();

    void Victory(); // Собственно слот победы
    void setFormatVal(int new_val); // Установка значения из ползунка Dif Menu
    void Highlight(ControlCell *CCell, int val);

private:
    QVector<GameCell*> CellButtons;
    QVector<ControlCell*> ControlButtons;

    std::vector<std::vector<short int>> Matrix; // Сохранение матрицы в текущей игре
    int format_chance = 45; // Шанс обнуления клеток, по умолчанию как в Dif Menu
    int left2victory = 0;   // Тот самый счетчик для определения законченности судоку
};

#endif
