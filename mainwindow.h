#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "concretecommand.h"
#include "commandinvoker.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createNewFile();
    void openFile();
    void saveFile();
    void exitApplication();
    void showAbout();

private:
    Ui::MainWindow *ui;
    CommandInvoker commandInvoker; // Додано: виконавець команд
    QTextEdit* editor;             // Додано: текстовий редактор
};
#endif // MAINWINDOW_H
