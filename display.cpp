#include "display.h"

#include <QBasicTimer>

Display::Display(QObject *parent) : QObject(parent)
{

}


bool isNumber(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}

void Display::WaitingChoice()
{
    std::cout << "Type:";
    std::cout << "\nT to start displaying CPU temperature";
    std::cout << "\nU to start displaying CPU usage";
    std::cout << "\nF to start displaying free space of the root partition";
    std::cout << "\nS to stop displaying";
    std::cout << "\na number from 500 to 5000 to set the probing interval\n";

    std::string userChoice;
    std::getline(std::cin, userChoice);
    //QString qString(userChoice.c_str());
    //qDebug() << qString;

    Probe *probe = new Probe;

    if (isNumber(userChoice)) {
        std::cout << "\nSetting the probing interval at: " << userChoice;
        //probe->setSampling(atoi(userChoice.c_str()));
    }
    else if (userChoice.compare("T") == 0) {
        probe->doWork();
    }/*
    else if (userChoice.compare("F") == 0) {
        showDiskFreeSpace(probe);
    }*/

}
/*
void Display::showCpuTemperature(Probe* probe)
{
    QString cpuTemp(probe->getCpuTemperature());
    std::cout << cpuTemp.toStdString();
}

void Display::showDiskFreeSpace(Probe* probe)
{
    QString free(probe->getDiskFreeSpace());
    std::cout << free.toStdString();
}*/
