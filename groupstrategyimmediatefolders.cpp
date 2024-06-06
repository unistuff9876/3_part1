#include "groupstrategyimmediatefolders.h"

#include <QMap>

#include <iostream>

GroupStrategyResult GroupStrategyImmediateFolders::use(QString path)
{
    qint64 totalFileSize = 0;
    QMap<QString, qint64> namesAndSizesMap;

    //do current folder
    QDirIterator itCurFolderFiles(path, QDir::Files);
    while (itCurFolderFiles.hasNext()) {
        itCurFolderFiles.next();

        QFileInfo currentFileInfo = itCurFolderFiles.fileInfo();
        qint64 currentFileSize = currentFileInfo.size();
        totalFileSize += currentFileSize;
        namesAndSizesMap["(Current dir)"] += currentFileSize;
    }

    //do immediate folders
    QDirIterator itImmediateFolders(path, QDir::AllDirs | QDir::NoDotAndDotDot);
    while (itImmediateFolders.hasNext()) {
        itImmediateFolders.next();
        //std::cout << qPrintable(itImmediateFolders.) << "\n";

        QFileInfo currentFileInfo = itImmediateFolders.fileInfo();
        QString currentDirName = currentFileInfo.fileName();

        QDirIterator itFilesInImmFolders(currentFileInfo.absoluteFilePath(),
            QDir::Files, QDirIterator::Subdirectories);

        while (itFilesInImmFolders.hasNext()) {
            itFilesInImmFolders.next();

            QFileInfo currentFileInfoInner = itFilesInImmFolders.fileInfo();
            qint64 currentFileSize = currentFileInfoInner.size();
            totalFileSize += currentFileSize;
            namesAndSizesMap[currentDirName] += currentFileSize;
        }/**/
    }

    return GroupStrategyResult(namesAndSizesMap, totalFileSize);
}

QString GroupStrategyImmediateFolders::prefix()
{
    return "";
}
