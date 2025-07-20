#include "ScoreFunctions.hpp"

QByteArray serializeScores(const std::vector<int>& scores) {
    QByteArray data;
    QDataStream stream(&data, QIODevice::WriteOnly);
    stream << static_cast<quint32>(scores.size()); // Сохраняем размер вектора
    for (int score : scores) {
        stream << score; // Сохраняем каждый элемент
    }
    return data;
}

std::vector<int> deserializeScores(const QByteArray& data){
    std::vector<int> scores;
    QDataStream stream(data);
    quint32 size;
    stream >> size; // Читаем размер вектора
    scores.resize(size);
    for (quint32 i = 0; i < size; ++i) {
        stream >> scores[i]; // Читаем каждый элемент
    }
    return scores;
}

QString getScoreFilePath(){
    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QDir documentsDir(documentsPath);

    // создаем подпапку
    if (!documentsDir.exists("Sudoku-project")){
        documentsDir.mkdir("Sudoku-project");
    }

    return documentsPath + "/Sudoku-project/score.dat";
}
QByteArray simpleEncryptDecrypt(const QByteArray &data, const QString &key){
    QByteArray result = data;

    for (int i = 0; i < data.size(); ++i) {
        result[i] = data[i] ^ key.at(i % key.size()).toLatin1();
    }

    return result;
}


bool saveScores(const std::vector<int>& scores, const QString& encryptionKey){
    // Получаем путь к файлу
    QString filePath = getScoreFilePath();
    
    // Создаем все необходимые директории
    QFileInfo fileInfo(filePath);
    QDir dir = fileInfo.dir();
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qWarning() << "Failed to create directory:" << dir.path();
            return false;
        }
    }

    // Открываем файл для записи (создаст новый, если не существует)
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open file for writing:" << file.errorString();
        return false;
    }

    // Шифруем и записываем данные
    QByteArray rawData = serializeScores(scores);
    QByteArray encryptedData = simpleEncryptDecrypt(rawData, encryptionKey);
    
    if (file.write(encryptedData) == -1) {
        qWarning() << "Write error:" << file.errorString();
        file.close();
        return false;
    }

    file.close();
    return true;
}

std::vector<int> loadScores(const QString& encryptionKey) {
QFile file(getScoreFilePath());
    if (!file.exists() || !file.open(QIODevice::ReadOnly)) {
        return {}; // Возвращаем пустой вектор, если файла нет
    }

    // Читаем зашифрованные данные
    QByteArray encryptedData = file.readAll();
    file.close();

    // Дешифруем
    QByteArray decryptedData = simpleEncryptDecrypt(encryptedData, encryptionKey);

    // Десериализуем в вектор
    return deserializeScores(decryptedData);
}

