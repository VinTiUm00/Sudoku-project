#ifndef SCOREWINDOW_HPP
#define SCOREWINDOW_HPP

#include <QWidget>
#include <QLabel>
#include <QVector>
#include <vector>

class ScoreWindow : public QWidget {

    Q_OBJECT

public:
    ScoreWindow(QWidget* parent = nullptr);
    virtual ~ScoreWindow();

signals:
    void windowClosed();

public slots:
    void closeWindow();

private:
    std::vector<int> scoreList;
};

#endif
