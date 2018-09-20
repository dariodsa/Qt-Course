#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <vector>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    static const int WINDOW_HEIGHT;
    static const int WINDOW_WIDTH;

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

    QLabel* timeLabel = new QLabel("");
    QLabel* cursorPositionLabel = new QLabel("");

    QFrame* frame;
    QTextEdit* textArea;

    QMenuBar* menubar;
    std::vector<QMenu*>menus;

};

#endif // DIALOG_H
