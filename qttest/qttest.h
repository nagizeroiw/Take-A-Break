#ifndef QTTEST_H
#define QTTEST_H

#include <QApplication>

#include <QSystemTrayIcon>
#include <QIcon>
#include <QPixmap>
#include <QDir>
#include <Qtimer>
#include <QObject>
#include <QMenu>
#include <QKeySequence>

#include "MyWindow.h"

// whatever, just let memory leak
class MyTray : public QSystemTrayIcon
{
    Q_OBJECT

public:
    MyTray() {

        // main window
        mainWindow = new MyWindow(this);

        // break time
        breaktime_msec = 1000 * 60 * 30; // half an hour

        // build timer
        timer = new QTimer();


        // tip
        QString tooltip("Take A Break!");
        this->setToolTip(tooltip);

        // contet menu
        menu = new QMenu();
        // quit
        action_quit = new QAction(menu);
        action_quit->setText("Quit      ");
        action_quit->setShortcut(QKeySequence(tr("Ctrl+Q")));
        menu->addAction(action_quit);
        connect(action_quit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));

        menu->addSeparator();

        // revive
        action_revive = new QAction(menu);
        action_revive->setText("Revive    ");
        action_revive->setShortcut(QKeySequence(tr("Ctrl+W")));
        menu->addAction(action_revive);
        connect(action_revive, SIGNAL(triggered(bool)), this, SLOT(reviveTimer()));
        // stop

        menu->addSeparator();

        action_stop = new QAction(menu);
        action_stop->setText("Stop      ");
        action_stop->setShortcut(QKeySequence(tr("Ctrl+T")));
        menu->addAction(action_stop);
        connect(action_stop, SIGNAL(triggered(bool)), this, SLOT(stopTimer()));
        // start
        action_start = new QAction(menu);
        action_start->setText("Start     ");
        action_start->setShortcut(QKeySequence(tr("Ctrl+O")));
        action_start->setDisabled(true);
        menu->addAction(action_start);
        connect(action_start, SIGNAL(triggered(bool)), this, SLOT(startTimer()));

        menu->addSeparator();

        window_open = new QAction(menu);
        window_open->setText("Config");
        menu->addAction(window_open);
        connect(window_open, SIGNAL(triggered(bool)), mainWindow, SLOT(open()));

        // add menu
        this->setContextMenu(menu);
    }
    void start() {
        this->show();
        

        QObject::connect(timer, SIGNAL(timeout()), 
                         this,  SLOT(timeoutMessage()));

        timer->start(breaktime_msec); // half an hour

        this->showMessage("Timer started!",
                          QString("Timer is started.\n"
                          "From now on, you will be reminded "
                          "to take a break for every 30 minutes."));
    }

public slots:
    void timeoutMessage() {
        this->showMessage("Take a break!", 
                          QString("You have beening working for too long.\n"
                          "Stand up and take a brief break!"));
    }
    void stopTimer() {
        timer->stop();
        this->showMessage("Timer stoped!", 
                          QString("Timer has been stoped.\n"
                          "Please do not to open it when came back."));
        action_stop->setDisabled(true);
        action_start->setEnabled(true);
    }
    void startTimer() {
        timer->start(breaktime_msec);
        this->showMessage("Timer started!", 
                          QString("Timer has been started.\n"
                          "Next reminder comes in 30 minutes."));
        action_start->setDisabled(true);
        action_stop->setEnabled(true);
    }
    void reviveTimer() {
        timer->stop();
        timer->start(breaktime_msec);
        this->showMessage("Timer revived!", 
                          QString("Timer has been cleared.\n"
                          "Next reminder comes in 30 minutes."));
    }
    void setBreaktimemsec(int new_index) {
        int new_msec;
        if (new_index == 0) {
            new_msec = 1000 * 60 * 30;
        }
        else if (new_index == 0) {
            new_msec = 1000 * 60 * 40;
        }
        else if (new_index == 0) {
            new_msec = 1000 * 60 * 60;
        }
        else if (new_index == 0) {
            new_msec = 1000 * 60 * 120;
        }
        breaktime_msec = new_msec;
        this->showMessage("Config Saved", "");
        reviveTimer();
    }
private:

    QMenu* menu;
    QAction* action_revive;
    QAction* action_stop;
    QAction* action_start;
    QAction* action_quit;
    QAction* window_open;
    QAction* window_close;

    QTimer* timer;

    MyWindow* mainWindow;

    int breaktime_msec;

    MyTray(const MyTray& t);
    MyTray& operator=(const MyTray& t);
};
#endif // QTTEST_H
