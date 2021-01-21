#include <SingleApplication>
#include <QMessageBox>

#include "window.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(stayawake);

    SingleApplication app(argc, argv,true);

    if (app.isSecondary()) {
        QMessageBox::warning(nullptr, Window::APPLICATION_NAME,"Programm läuft bereits");
        exit(0);
    }
    QApplication::setQuitOnLastWindowClosed(false);

    Window window;

    return app.exec();
}
