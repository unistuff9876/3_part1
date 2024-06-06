#ifndef GROUPSTRATEGYRESULT_H
#define GROUPSTRATEGYRESULT_H

#include <vector>
#include <tuple>

#include <QString>

class GroupStrategyResult
{
//private:
public:
    std::vector<QString> m_names;
    std::vector<qint64> m_sizes;
    std::vector<float> m_percentages;
    qint64 m_totalSize;

public:
    GroupStrategyResult() = delete;
    GroupStrategyResult(QMap<QString, qint64> &nameSizesMap, qint64 totalSize = 1);
/*
    int totalSize() const;

    std::vector<QString> &names() const;

    std::vector<qint64> &sizes() const;

    std::vector<float> &percentages() const;*/

    size_t itemCount() const;

    //std::tuple<QString, qint64, float> operator[](int i) const;
};

#endif // GROUPSTRATEGYRESULT_H
