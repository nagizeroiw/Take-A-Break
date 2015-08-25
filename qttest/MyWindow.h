#ifndef MYW_H
#define MYW_H
#include <QWidget>
#include <QSystemTrayIcon>
#include <QComboBox>
#include <QObject>
#include <QLayout>
#include <QCloseEvent>
#include <QLabel>

class MyWindow : public QWidget {
    Q_OBJECT
public:
    MyWindow() {

        this->setWindowTitle("Take-A-Break Config");

        QIcon* icon = new QIcon(":/qttest/Resources/copy.png");
        this->setWindowIcon(*icon);

        this->setFixedWidth(600);
        this->setFixedHeight(200);

        QBoxLayout* layout = new QBoxLayout(QBoxLayout::Direction::TopToBottom, this);

        QLabel* text = new QLabel(QString("Break time config"));
        text->setFixedHeight(50);
        layout->addWidget(text);
        layout->setAlignment(text, Qt::AlignHCenter);

        timeChoose = new QComboBox();
        timeChoose->setFixedWidth(200);
        timeChoose->setFixedHeight(50);

        layout->addWidget(timeChoose);
        layout->setAlignment(timeChoose, Qt::AlignHCenter);

        timeChoose->addItem("30 minutes");
        timeChoose->addItem("40 minutes");
        timeChoose->addItem("1 hour");
        timeChoose->addItem("2 hour");

        connect(timeChoose, SIGNAL(currentIndexChanged(int)), this, SLOT(commitConfig(int)));

        this->setHidden(true);
    }
    void closeEvent(QCloseEvent* e) {
        emit currentClose();
        this->setVisible(false);
        e->ignore();
    }
signals:
    void userConfig(int index);
    void currentClose();
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