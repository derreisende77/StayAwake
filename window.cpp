#include <QAction>
#include <QCoreApplication>
#include <QCloseEvent>
#include <QMenu>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QMessageBox>

#include "window.h"


#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>


Window::Window()
    : appIcon(QIcon(":/images/nuclear-power.svg"))
{
    createActions();
    createTrayIcon();

    connect(this,&Window::powerManagementEnabled,this, &Window::showTrayMessage);
    disable_power_management();
    togglePowerManagementAction->setChecked(true);
}

void Window::disable_power_management() {
    ::SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);
    emit powerManagementEnabled(false);
}

void Window::enable_power_management() {
    ::SetThreadExecutionState(ES_CONTINUOUS);
    emit powerManagementEnabled(true);
}

void Window::showTrayMessage(bool enabled) {
    if (enabled)
        trayIcon->showMessage("Power Management aktiv","Stromsparfunktionen sind wieder aktiv..");
    else
        trayIcon->showMessage("Power Management inaktiv","Stromsparfunktionen sind deaktiviert.\nHappy PowerPointing!");
}

void Window::createActions()
{
    togglePowerManagementAction = new QAction("Power Management deaktivieren", this);
    togglePowerManagementAction->setCheckable(true);
    connect(togglePowerManagementAction,&QAction::triggered,this,[this]() {
        if (togglePowerManagementAction->isChecked()) {
            disable_power_management();
        }
        else {
            enable_power_management();
        }
    });

    aboutAction = new QAction("Über dieses Programm...", this);
    connect(aboutAction,&QAction::triggered,this,[this]() {
        aboutAction->setDisabled(true);
        QString text = "StayAwake\n";
        text += "Version 1.1\n\n";
        text += "Written by derreisende77.\n";
        text += "Licensed under GPLv3.\n\n";
        text += "Source code available on GitHub.com";
        QMessageBox::information(nullptr, Window::APPLICATION_NAME, text);
        aboutAction->setEnabled(true);
    });

    aboutQtAction = new QAction("Über Qt...", this);
    connect(aboutQtAction, &QAction::triggered, this, [] {
        QMessageBox::aboutQt(nullptr);
    });

    quitAction = new QAction("&Beenden", this);
    connect(quitAction,&QAction::triggered, this, []() {
       qApp->quit();
    });
}

void Window::createTrayIcon()
{
    auto trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(togglePowerManagementAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(aboutAction);
    trayIconMenu->addAction(aboutQtAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setToolTip("StayAwake Power Manager");
    trayIcon->setIcon(appIcon);
    trayIcon->show();
}
