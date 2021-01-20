#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(stayawake);

    QApplication app(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false);

    Window window;

    return app.exec();
}
