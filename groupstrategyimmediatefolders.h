#ifndef GROUPSTRATEGYIMMEDIATEFOLDERS_H
#define GROUPSTRATEGYIMMEDIATEFOLDERS_H

#include "groupstrategy.h"

class GroupStrategyImmediateFolders : public GroupStrategy
{
public:
    GroupStrategyImmediateFolders() = default;

    GroupStrategyResult use(QString path) final;

    QString prefix() final;
};

#endif // GROUPSTRATEGYIMMEDIATEFOLDERS_H
