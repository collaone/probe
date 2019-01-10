#ifndef PROBE_H
#define PROBE_H

#include <QCoreApplication>
#include <QTimer>

class Probe : public QObject
{
    Q_OBJECT

public:
    Probe(QObject *parent=nullptr);
    //~Probe(); //destructor

    int _SAMPLING;
    //QString showCpuTemperature();
    //void showCpuUsage();
    //void showRootFreeSpace();

signals:
    //void setSampling(int);

public slots:
    void doWork();
    QString getCpuTemperature();
    QString GetCPULoadPercent();
    QString getDiskFreeSpace();

private:
    QTimer timer;

    uint64_t _cpu_user;
    uint64_t _cpu_nice;
    uint64_t _cpu_system;
    uint64_t _cpu_idle;
    uint64_t _cpu_ioWait;
};

#endif // PROBE_H
