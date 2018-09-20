#include "dialog.h"
#include "ui_dialog.h"

QString* Dialog::BUTTON1_name = new QString("Klikni me");
QString* Dialog::LABEL1_name = new QString("Labela1");

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    button1 = new QPushButton(*Dialog::BUTTON1_name);
    label1 = new QLabel(*Dialog::LABEL1_name);

    menu = new QMenu("File");
    menuBar = new QMenuBar();

    QAction* exitAction = menu->addAction(tr("Exit"));


    connect(exitAction,  &QAction::triggered, this, &Dialog::exitActionClicked);
    connect(b1, &QPushButton::clicked, this, &Dialog::buttonB1Clicked);

    QGridLayout* gridLayout = new QGridLayout(this);

    gridLayout->addWidget(b1,0,0);
    gridLayout->addWidget(b2,0,1);
    gridLayout->addWidget(button1,1,0);
    gridLayout->addWidget(label1,1,1);



    menuBar->addMenu(menu);

    gridLayout->setMenuBar(menuBar);
    setWindowTitle("QGridLayout");

    setLayout(gridLayout);
}

void Dialog::buttonB1Clicked() {
    QTime* time = new QTime();
    QString dateTime = time->currentTime().toString();

    label1->setText(dateTime);
}

void Dialog::exitActionClicked() {
    QMessageBox mes;
    mes.setText("Exit Action is activated.");
    mes.exec();
}

Dialog::~Dialog()
{
    delete ui;
}
