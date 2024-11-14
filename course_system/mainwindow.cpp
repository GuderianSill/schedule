#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Teacher t(1, "A");
    Course c(2, "c++", 3, 4, 30, &t);
    qDebug() << "类创建成功";
    if (!c.has_teacher())
        qDebug() << "无老师";
    QString s = QString::fromStdString(c.getTeacherName());
    qDebug() << s;
}

