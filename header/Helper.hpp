#ifndef HELPER_HPP
#define HELPER_HPP

#include <QObject>

#include "ControlCell.hpp"
#include "GameCell.hpp"

class Helper : public QObject{

    Q_OBJECT

public:
    Helper(int num);
    int SayCurNum();
    void setPrevCell(ControlCell* Cell);

signals:
    void SelectCell1();
    void SelectCell2();
    void SelectCell3();
    void SelectCell4();
    void SelectCell5();
    void SelectCell6();
    void SelectCell7();
    void SelectCell8();
    void SelectCell9();

public slots:
    void selectNum(ControlCell* Cell, int num);
    void ChangeCell(GameCell* Cell);

private:
    ControlCell* prevCell;
    int CurrentNum;
};

#endif
