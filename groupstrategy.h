#ifndef GROUPSTRATEGY_H
#define GROUPSTRATEGY_H

#include "groupstrategyresult.h"

#include <QDirIterator>
#include <QString>

class GroupStrategy
{
public:
    GroupStrategy() = default;

    virtual GroupStrategyResult use(QString path) = 0;

    virtual QString prefix() = 0;
};

#endif // GROUPSTRATEGY_H
