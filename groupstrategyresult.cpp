#include "groupstrategyresult.h"

#include <QMapIterator>

GroupStrategyResult::GroupStrategyResult(QMap<QString, qint64> &nameSizesMap, qint64 totalSize)
{
    m_totalSize = totalSize <= 0 ? 0 : totalSize;

    QMapIterator<QString, qint64> nameSizesMapIt(nameSizesMap);
    while (nameSizesMapIt.hasNext()) {
        nameSizesMapIt.next();
        m_names.push_back(nameSizesMapIt.key());
        qint64 curSize = nameSizesMapIt.value();
        m_sizes.push_back(curSize);
    }
}

int GroupStrategyResult::totalSize()
{
    return m_totalSize;
}

std::vector<QString> &GroupStrategyResult::names()
{
    return m_names;
}

std::vector<qint64> &GroupStrategyResult::sizes()
{
    return m_sizes;
}

size_t GroupStrategyResult::itemCount()
{
     return m_names.size();
}
