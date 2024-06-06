#include "groupstrategyfileextensions.h"

#include <QMap>

GroupStrategyResult GroupStrategyFileExtensions::use(QString path)
{
    QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    QMap<QString, qint64> extensionsNamesAndSizeSumsMap;
    qint64 totalFileSize = 0;

    while (it.hasNext()) {
        it.next();
        QFileInfo currentFileInfo = it.fileInfo();

        qint64 currentFileSize = currentFileInfo.size();
        totalFileSize += currentFileSize;
        QString currentExtension = currentFileInfo.suffix();
        extensionsNamesAndSizeSumsMap[currentExtension] += currentFileSize;
    }

    return GroupStrategyResult(extensionsNamesAndSizeSumsMap, totalFileSize);
}

QString GroupStrategyFileExtensions::prefix()
{
    static const QString ret = "*.";
    return ret;
}
