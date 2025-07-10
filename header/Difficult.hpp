#ifndef DIFFICULT_HPP
#define DIFFICULT_HPP

#include <QDialog>
#include <QPushButton>

// класс для окна выбора сложности
class DifficultMenu : public QDialog {

    Q_OBJECT // Макрос, без которого не работают сигналы

public:
    DifficultMenu(QWidget* parent = nullptr); // конструктор
    virtual ~DifficultMenu();

// сигналы. Какая сложность выбрана
signals:
    void EasySelected();
    void NormalSelected();
    void HardSelected();
    void InsaneSelected();

public slots:
    void closeWindow();

private: // какие кнопки будут
    QPushButton* Easy;
    QPushButton* Normal;
    QPushButton* Hard;
    QPushButton* Insane;
    QPushButton* Exit;
};

#endif
