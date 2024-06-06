#ifndef GROUPSTRATEGY_H
#define GROUPSTRATEGY_H

#include "groupstrategyresult.h"

#include <QDirIterator>

class GroupStrategy
{
public:
    GroupStrategy();

    virtual GroupStrategyResult use(QString path) = 0;
};

#endif // GROUPSTRATEGY_H
