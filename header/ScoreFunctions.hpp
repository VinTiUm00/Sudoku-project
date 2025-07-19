#ifndef SCORE_HPP
#define SCORE_HPP

#include <QStandardPaths>
#include <QDir>
#include <QBitArray>
#include <QString>
#include <QFile>
#include <QDataStream>
#include <QDateTime>
#include <vector>

QString getScoreFilePath(); // получение пути до файла со счетами
QByteArray simpleEncryptDecrypt(const QByteArray &data, const QString &key); // простая кодировка
                                                                             //
// Сериализация вектора в QByteArray
QByteArray serializeScores(const std::vector<int>& scores);
// Десериализация из QByteArray в std::vector
std::vector<int> deserializeScores(const QByteArray& data);

bool saveScores(const std::vector<int>& scores, const QString& encryptionKey = "StartMiningCryptoNow14");
std::vector<int> loadScores(const QString& encryptionKey = "StartMiningCryptoNow14");

#endif
