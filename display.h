#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <QCoreApplication>

#include "probe.h"

class Display : public QObject
{
public:
    Display(QObject *parent=0);
    //~Display();

    void WaitingChoice();

public slots:
    void showCpuTemperature(Probe* probe);
    void showDiskFreeSpace(Probe* probe);

};

#endif // DISPLAY_H
