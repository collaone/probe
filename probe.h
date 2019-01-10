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
    QString getDiskFreeSpace();

private:
    QTimer timer;
    QString reading;
};

#endif // PROBE_H
