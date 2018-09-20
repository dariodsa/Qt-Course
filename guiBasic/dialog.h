#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtWidgets>
#include <QtCore>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
public:
    static QString* BUTTON1_name;
    static QString* LABEL1_name;

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    void exitActionClicked();
    void buttonB1Clicked();

    QPushButton *button1;

    QPushButton *b1 = new QPushButton("b1");
    QPushButton *b2 = new QPushButton("b2");

    QLabel *label1;

    QMenu *menu;

    QMenuBar *menuBar;
};

#endif // DIALOG_H
