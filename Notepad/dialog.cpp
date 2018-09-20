#include "dialog.h"
#include "ui_dialog.h"

#include "timethread.h"

const int Dialog::WINDOW_HEIGHT = 600;
const int Dialog::WINDOW_WIDTH = 1000;


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setGeometry(0, 0, Dialog::WINDOW_WIDTH, Dialog::WINDOW_HEIGHT);

    frame = ui->frame;
    textArea = ui->textEdit;

    QHBoxLayout* boxLayout = new QHBoxLayout();
    boxLayout->addWidget(timeLabel);
    boxLayout->addWidget(cursorPositionLabel);

    frame->setLayout(boxLayout);

    QThread* thread = new TimeThread(timeLabel);
    thread->start();

    QMenu* fileMenu = new QMenu("File");
    QMenu* editMenu = new QMenu("Edit");
    QMenu* viewMenu = new QMenu("View");
    QMenu* helpMenu = new QMenu("Help");
    menus.push_back(fileMenu);
    menus.push_back(editMenu);
    menus.push_back(viewMenu);
    menus.push_back(helpMenu);
    menubar = new QMenuBar(this);

    for(int i=0;i<menus.size();++i)
    {
        menubar->addMenu(menus[i]);
    }

    ui->gridLayout->setMenuBar(menubar);
}

Dialog::~Dialog()
{
    delete ui;
}
