#include <QCoreApplication>
#include <QDirIterator>
#include <QDebug>
#include <iostream>

void traverse() {

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
    QDirIterator it("D:/Musique/3kliksphilip", QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        QFileInfo fInfo = it.fileInfo();

        qDebug() << fInfo.completeBaseName() << fInfo.isDir() << fInfo.size() << fInfo.completeSuffix();
    }/**/

    QDirIterator it("D:/Musique/3kliksphilip", QDir::Files, QDirIterator::Subdirectories);
    QMap<QString, qint64> extensionsSizeSumsMap;
    qint64 totalFileSize = 0;

    while (it.hasNext()) {
        it.next();
        QFileInfo currentFileInfo = it.fileInfo();

        qint64 currentFileSize = currentFileInfo.size();
        totalFileSize += currentFileSize;
        QString currentExtension = currentFileInfo.completeSuffix();
        extensionsSizeSumsMap[currentExtension] += currentFileSize;
        auto extensionItemInMap = extensionsSizeSumsMap.find(currentExtension);
        /*if (extensionItemInMap == extensionsSizeSumsMap.end()) {
            extensionsSizeSumsMap.insert(currentExtension, currentFileSize);
        } else {
            extensionItemInMap.key() += currentFileSize;
        }*/
        //qDebug() << currentFileInfo.completeBaseName() << currentFileInfo.isDir() << currentFileInfo.size() << currentFileInfo.completeSuffix();
    }

    QMapIterator<QString, qint64> extensionsSizeSumsMapIt(extensionsSizeSumsMap);
    std::cout << "Total: " << totalFileSize << '\n';
    while (extensionsSizeSumsMapIt.hasNext()) {
        extensionsSizeSumsMapIt.next();
        std::cout << "*." << qPrintable(extensionsSizeSumsMapIt.key()) << ": " << extensionsSizeSumsMapIt.value() << " bytes\n";
    }

    return a.exec();
}
