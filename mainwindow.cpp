#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
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
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(showText()));
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

void MainWindow::showText()
{

    char *main[] = {u8"哈", u8"壓", u8"壓", u8"壓"};
    char *sub[] = {"ha", "yasdasdasd", "ya", "iu"};

    QString outHtml = genHtml(main, sub);
    ui->textBrowser->setHtml(outHtml);

    std::cout << ui->textBrowser->toHtml().toUtf8().constData() << std::endl;
}

QString MainWindow::genHtml(char *mainText[], char *subText[])
{
    QString style = "<style>td{padding:0 1px;}</style>";
    QString tr1 = "";
    QString tr2 = "";
    for (int i = 0; i < 4; i++)
    {
        tr1 += innerVal(QString(subText[i]), 12);
        tr2 += innerVal(QString(mainText[i]));
    }

    tr1 = "<tr align=\"center\">" + tr1 + "</tr>";
    tr2 = "<tr align=\"center\">" + tr2 + "</tr>";
    return style + "<table>" + tr1 + tr2 + "</table>";
}

QString innerVal(QString text, int fontSize)
{
    // int 轉string
    std::string fs = std::to_string(fontSize).c_str();
    text = "<td align=\"center\" style=\"font-size:" + QString(fs.c_str()) + "px;\">" + text + "</td>";
    return text;
}
