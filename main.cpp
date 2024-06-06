#include <QCoreApplication>
#include <QDirIterator>
#include <QDebug>
#include <iostream>
#include <memory>
#include <iomanip>

#include "groupstrategy.h"
#include "groupstrategyfileextensions.h"

void doTheThing(GroupStrategy* groupStrategy, QString path) {
    GroupStrategyResult res = groupStrategy->use(path);

    std::cout << std::fixed << std::left << std::setprecision(2);

    int namew = 0;
    int sizew = 0;
    for (size_t i = 0; i < res.itemCount(); i++) {
        //1 for padding + 2 for *.
        namew = std::max(namew, res.m_names[i].size() + 3);
        //1 for log10 + 1 for padding
        sizew = std::max(sizew, (int)log10(res.m_sizes[i]) + 2);
    }

    std::cout << std::setw(namew) << "name" << std::setw(sizew) << "size" << "percentage\n";
    for (size_t i = 0; i < res.itemCount(); i++) {
        std::cout << "*." << std::setw(namew - 2) << qPrintable(res.m_names[i]) \
                  << std::setw(sizew) << res.m_sizes[i];

        float curPercentage = res.m_percentages[i] * 100;

        if (curPercentage < 1 && curPercentage > 0) {
            std::cout << "<1";
        }
        else if (curPercentage != 100 && curPercentage > 99.9) {
            std::cout << ">99.9";
        }
        else {
            std::cout << curPercentage;
        }

        std::cout << "%\n";
    }
    std::cout << "\ntotal size: " << res.m_totalSize;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    doTheThing(std::make_shared<GroupStrategyFileExtensions>().get(), "D:/");

    return a.exec();
}
