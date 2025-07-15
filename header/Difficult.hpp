#ifndef DIFFICULT_HPP
#define DIFFICULT_HPP

#include <QDialog>
#include <QPushButton>
#include <QSlider>
#include <QTextEdit>

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
    void SlValChanged(int new_val);

public slots:
    void closeWindow();
    void changeValue();

private: // какие кнопки будут
    QPushButton* Easy;
    QPushButton* Normal;
    QPushButton* Hard;
    QPushButton* Insane;
    QPushButton* Exit;
    QTextEdit* SliderValue;
    QSlider* FormatSlider;
};

#endif
