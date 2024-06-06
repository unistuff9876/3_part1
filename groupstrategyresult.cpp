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
        if (m_totalSize != 0) {
            m_percentages.push_back((float)curSize / (float)m_totalSize);
        }
        else {
            m_percentages.push_back(-0.01);
        }
    }
}
/*
int GroupStrategyResult::totalSize() const
{
    return m_totalSize;
}

std::vector<QString> &GroupStrategyResult::names() const
{
    return m_names;
}

std::vector<qint64> &GroupStrategyResult::sizes() const
{
    return m_sizes;
}

std::vector<float> &GroupStrategyResult::percentages() const
{
    return m_percentages;
}*/

size_t GroupStrategyResult::itemCount() const
{
    return m_names.size();
}

/*std::tuple<QString, qint64, float> GroupStrategyResult::operator[](int i) const
{
    return std::tuple<QString, qint64, float>{m_names[i], m_sizes[i], m_percentages[i]};
}/**/
