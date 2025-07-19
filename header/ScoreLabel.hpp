#ifndef SCORELABEL_HPP
#define SCORELABEL_HPP

#include <QLabel>

class ScoreLabel : public QLabel{

    Q_OBJECT

public:
    ScoreLabel(QString Text, QWidget* parent = nullptr);
    virtual ~ScoreLabel();

public slots:
    void ChangeScore(int newScore);
};

#endif
