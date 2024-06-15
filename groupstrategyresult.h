#ifndef GROUPSTRATEGYRESULT_H
#define GROUPSTRATEGYRESULT_H

#include <vector>
#include <tuple>

#include <QString>

class GroupStrategyResult
{
private:
    std::vector<QString> m_names;
    std::vector<qint64> m_sizes;
    qint64 m_totalSize;

public:
    GroupStrategyResult() = delete;
    GroupStrategyResult(QMap<QString, qint64> &nameSizesMap, qint64 totalSize = 1);

    std::vector<QString> &names();

    std::vector<qint64> &sizes();

    int totalSize();

    size_t itemCount();
};

#endif // GROUPSTRATEGYRESULT_H
