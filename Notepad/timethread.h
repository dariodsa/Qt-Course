#ifndef TIMETHREAD_H
#define TIMETHREAD_H


#include <QtCore>
#include <QtWidgets>
#include <QtGui>

class TimeThread : public QThread
{
public:
    TimeThread(QLabel*);
private:
    QLabel* timeLabel;
    void run() {

        while(true) {
            sleep(1);
            QTime* time = new QTime();
            timeLabel->setText(time->currentTime().toString());
        }

    }

};

#endif // TIMETHREAD_H
