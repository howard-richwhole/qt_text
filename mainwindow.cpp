#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QChar>
#include <String>

#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect 綁action，action 可在ui宣告，及設定調用位置
    //(哪個送，哪格信號，接收者，執行的函示)
    connect(ui->actionDo, &QAction::triggered, this, &MainWindow::newDocument);
    // 綁一般的原件
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addTextBlock()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 宣告pushButton2 click 實作
void MainWindow::on_pushButton2_clicked()
{
    QCoreApplication::quit();
}
void MainWindow::newDocument()
{
    QCoreApplication::quit();
}

void MainWindow::addTextBlock()
{

    char *main[] = {u8"哈", u8"壓", u8"壓"};
    char *sub[] = {"ha", "yasdasdasd", "ya"};
    QString outHtml = insertText(main, sub);
    ui->textBrowser->setHtml(outHtml);
    std::cout << ui->textBrowser->toHtml().toUtf8().constData() << std::endl;
}

QString MainWindow::insertText(char *mainText[], char *subText[])
{
    QString tr1 = "<tr align=\"center\">";
    QString tr2 = "<tr align=\"center\">";
    for (int i = 0; i < 3; i++)
    {
        tr1 += innerVal(QString(subText[i]), 12);
        tr2 += innerVal(QString(mainText[i]));
    }
    tr1 += "</tr>";
    tr2 += "</tr>";
    return innerTable(tr1 + tr2);
}

QString innerTable(QString text)
{
    text = "<table>" + text + "</table>";
    return text;
}

QString innerVal(QString text, int fontSize)
{
    std::string fs = std::to_string(fontSize).c_str();
    text = "<td align=\"center\" style=\"padding:0 5px;font-size:" + QString(fs.c_str()) + "px;\">" + text + "</td>";
    return text;
}
