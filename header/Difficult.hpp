#ifndef DIFFICULT_HPP
#define DIFFICULT_HPP

#include <QDialog>
#include <QPushButton>
#include <QSlider>
#include <QLabel>

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
    void SlValChanged(int new_val); // Сигнал со значением ползунка

public slots:
    void closeWindow();
    void changeValue();

private:
    // Кнопки
    QPushButton* Easy;
    QPushButton* Normal;
    QPushButton* Hard;
    QPushButton* Insane;
    QPushButton* Exit;
    QLabel* SliderValue; // Текст
    QSlider* FormatSlider;  // Ползунок
};

#endif
