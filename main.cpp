#include "probe.h"
#include "display.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv); //renamed the a to app

    Display display;
    display.WaitingChoice();

    return app.exec(); //and we run the application
}
