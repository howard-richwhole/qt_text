#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextBlock>

QT_BEGIN_NAMESPACE
// 有個namespace Ui 裡頭有個class MainWindow
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// 有個MainWindow class
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
// 所有要連結 ui 動作的函式都要放在private slots
// 宣告pushButton2 click 動做
    void on_pushButton2_clicked();
    void newDocument();
    void addTextBlock();
    QString insertText(char*[],char*[]);

private:
    Ui::MainWindow* ui;
    QTextBlock* block = NULL;

};
QString innerTable(QString);
QString innerVal(QString,int = 18);
#endif // MAINWINDOW_H
