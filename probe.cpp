#include "probe.h"
#include <QStorageInfo>
#include <QDebug>
#include <QTimer>

Probe::Probe(QObject *parent)
    : QObject(parent)
{
    connect(&timer, SIGNAL (timeout()), this, SLOT (doWork()));
    timer.start(1000);
}
/*
void Probe::setSampling(int sampling)
{
    timer.setInterval(sampling);
}*/

void Probe::doWork()
{
    qDebug() << "Root free space: " << getDiskFreeSpace();
    qDebug() << "CPU Temp: " << getCpuTemperature();
}

QString Probe::getCpuTemperature()
{
    return "48";
}

QString Probe::getDiskFreeSpace()
{
    QStorageInfo storage = QStorageInfo::root();

    return QString::number(storage.bytesAvailable()/1024/1024).append(" MB");
}
