#ifndef WINDOW_H
#define WINDOW_H

#include <QSystemTrayIcon>
#include <QDialog>
#include <QAction>
#include <QIcon>

class Window : public QDialog
{
    Q_OBJECT

public:
    Window();

signals:
    void powerManagementEnabled(bool enabled);

protected slots:
    void showTrayMessage(bool enabled);

private:
    void createActions();
    void createTrayIcon();

    void disable_power_management();
    void enable_power_management();

    QAction *togglePowerManagementAction;
    QAction *quitAction;
    QAction *aboutAction;
    QAction *aboutQtAction;

    QSystemTrayIcon *trayIcon;
    QIcon appIcon;
public:
    static constexpr auto APPLICATION_NAME = "StayAwake";
    static constexpr auto APPLICATION_VERSION = "1.3";
};
#endif
