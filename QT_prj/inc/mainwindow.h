#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QLocale>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //QString setEMI(QString &str);
public slots:
    void button_pressed(void);
    void principle_updated(QString textinfo);
    void ROI_updated(QString textinfo);
    void period_updated(QString textinfo);
signals:
    QString setEMI(QString &str);
private:
    QPushButton *button;
    QLineEdit *text1;
    QLineEdit *text4;
    QLabel *principle_label;
    int principle, months;
    float ROI;
};
#endif // MAINWINDOW_H
