#include <SingleApplication>
#include <QMessageBox>

#include "window.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(stayawake);

    QCoreApplication::setOrganizationName("DerReisende77");
    QCoreApplication::setOrganizationDomain("org.derreisende77");
    QCoreApplication::setApplicationName("StayAwake");

    // prevent system wide start of any app
    constexpr auto startupFlags = SingleApplication::Mode::System | SingleApplication::Mode::ExcludeAppPath | SingleApplication::Mode::ExcludeAppVersion;
    SingleApplication app(argc, argv,true, startupFlags);

    if (app.isSecondary()) {
        QMessageBox::warning(nullptr, Window::APPLICATION_NAME,"Programm läuft bereits");
        exit(0);
    }
    QApplication::setQuitOnLastWindowClosed(false);

    Window window;

    return app.exec();
}
