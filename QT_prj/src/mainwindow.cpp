#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton *button = new QPushButton("Calculate", this);
    QLineEdit *text1 = new QLineEdit;
    QLabel *principle_label = new QLabel("priciple");
    QLineEdit *text2 = new QLineEdit;
    QLabel *ROI_label = new QLabel("Rate of interest");
    QLineEdit *text3 = new QLineEdit;
    QLabel *months_label = new QLabel("Months");
    QLineEdit *text4 = new QLineEdit;
    QLabel *EMI_label = new QLabel("EMI");
    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->addWidget(button);
    layout->addWidget(principle_label);
    layout->addWidget(text1);
    layout->addWidget(ROI_label);
    layout->addWidget(text2);
    layout->addWidget(months_label);
    layout->addWidget(text3);
    layout->addWidget(EMI_label);
    layout->addWidget(text4);
    this->setCentralWidget(widget);
    connect(button, &QPushButton::clicked, this, &MainWindow::button_pressed);
    connect(text1, &QLineEdit::textChanged, this, &MainWindow::principle_updated);
    connect(text2, &QLineEdit::textChanged, this, &MainWindow::ROI_updated);
    connect(text3, &QLineEdit::textChanged, this, &MainWindow::period_updated);
    connect(this, &MainWindow::setEMI, text4, &QLineEdit::setText);
}

MainWindow::~MainWindow()
{
}

void MainWindow::button_pressed(void)
{
    double value, factor, EMI;
    QString string1;
    qDebug()<<"button pressed";
    qDebug()<<"principle is "<<this->principle;
    qDebug()<<"rate of interest is "<<this->ROI;
    qDebug()<<"number of months is "<<this->months;
    value = 1 + (this->ROI/1200);
    qDebug()<<"value variable "<<value;
    factor = pow(value, this->months);
    qDebug()<<"factor value to calculate EMI "<<factor;
    EMI = this->principle*(this->ROI/1200)*(factor/(factor - 1));
    string1.setNum(EMI);
    this->emit setEMI(string1);
    //qDebug()<<"EMI calculated is "<<EMI;
}

void MainWindow::principle_updated(QString textinfo)
{
    this->principle = textinfo.toInt();
}

void MainWindow::ROI_updated(QString textinfo)
{
    this->ROI = textinfo.toFloat();
}

void MainWindow::period_updated(QString textinfo)
{
    this->months = textinfo.toInt();
}
