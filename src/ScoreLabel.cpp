#include "ScoreLabel.hpp"

ScoreLabel::ScoreLabel(QString Text, QWidget* parent) : QLabel(Text, parent){}

ScoreLabel::~ScoreLabel() = default;

void ScoreLabel::ChangeScore(int newScore){
    this->setText(QString::number(newScore));
}
