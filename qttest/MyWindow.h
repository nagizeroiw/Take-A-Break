#ifndef MYW_H
#define MYW_H
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QComboBox>
#include <QObject>

class MyWindow : public QMainWindow {
    Q_OBJECT
public:
    MyWindow() {

        this->setWindowTitle("Take-A-Break Config");

        this->setFixedWidth(600);
        this->setFixedHeight(400);

        timeChoose = new QComboBox(this);

        timeChoose->setGeometry(200, 100, 200, 50);
        timeChoose->setFixedWidth(200);
        timeChoose->setFixedHeight(50);

        timeChoose->addItem("30 minutes");
        timeChoose->addItem("40 minutes");
        timeChoose->addItem("1 hour");
        timeChoose->addItem("2 hour");

        connect(timeChoose, SIGNAL(currentIndexChanged(int)), this, SLOT(commitConfig(int)));

        this->setHidden(true);
    }
signals:
    void userConfig(int index);
public slots:
    void open() {
        this->setHidden(false);
    }
    void close() {
        this->setHidden(true);
    }
    void commitConfig(int index) {
        emit userConfig(index);
    }
private:
    QComboBox* timeChoose;
};

#endif 