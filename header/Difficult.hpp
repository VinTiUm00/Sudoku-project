#ifndef DIFFICULT_HPP
#define DIFFICULT_HPP

#include <QDialog>
#include <QPushButton>

class DifficultMenu : public QDialog {

    Q_OBJECT // Макрос, без которого не работают сигналы

public:
    DifficultMenu(QWidget* parent = nullptr);
    virtual ~DifficultMenu();

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
