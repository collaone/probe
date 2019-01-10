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
    qDebug() << "CPU Load: " << GetCPULoadPercent();
}

QString Probe::getCpuTemperature()
{
    return "48";
}

QString Probe::GetCPULoadPercent()
{
    //grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {print usage "%"}'
    QString fileName = "/proc/stat";
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        //QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));
        return "";
    }

    QTextStream in(&file);
    QString line = in.readLine();
    QStringList tokens = line.split(" ");

    uint64_t now_cpu_user = tokens[2].toUInt();
    uint64_t now_cpu_nice = tokens[3].toUInt();
    uint64_t now_cpu_system = tokens[4].toUInt();
    uint64_t now_cpu_idle = tokens[5].toUInt();
    uint64_t now_cpu_ioWait = tokens[6].toUInt();

    uint64_t diff_cpu_user = now_cpu_user - _cpu_user;
    uint64_t diff_cpu_nice = now_cpu_nice - _cpu_nice;
    uint64_t diff_cpu_system = now_cpu_system - _cpu_system;
    uint64_t diff_cpu_idle = now_cpu_idle - _cpu_idle;
    uint64_t diff_cpu_ioWait = now_cpu_ioWait - _cpu_ioWait;

    double total_work = diff_cpu_user + diff_cpu_system;
    double total = diff_cpu_user + diff_cpu_system + diff_cpu_idle + diff_cpu_nice + diff_cpu_ioWait;
    double load = total_work/total;

    file.close();

    // update old values for next reading
    _cpu_user = now_cpu_user;
    _cpu_nice = now_cpu_nice;
    _cpu_system = now_cpu_system;
    _cpu_idle = now_cpu_idle;
    _cpu_ioWait = now_cpu_ioWait;

    return QString::number(load*100) + "%";
}

QString Probe::getDiskFreeSpace()
{
    QStorageInfo storage = QStorageInfo::root();

    return QString::number(storage.bytesAvailable()/1024/1024).append(" MB");
}
