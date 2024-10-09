#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "createnewfilecommand.h"
#include "openfilecommand.h"
#include "savefilecommand.h"
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    editor = new QTextEdit(this);  // Ініціалізація текстового редактора
    setCentralWidget(editor);      // Встановлюємо текстовий редактор як центральний віджет

    // Створюємо ToolBar
    QToolBar *mainToolBar = addToolBar("Main Toolbar");

    // Створюємо дії (кнопки)
    QAction *newFileAction = new QAction(QIcon(":/rec/img/w256h2561390727869addfile256.png"), "New File", this);
    QAction *openFileAction = new QAction(QIcon(":/rec/img/25402.png"), "Open File", this);
    QAction *saveFileAction = new QAction(QIcon(":/rec/img/3240364.png"), "Save File", this);

    // Підключаємо дії до слотів
    connect(newFileAction, &QAction::triggered, this, &MainWindow::createNewFile);
    connect(openFileAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveFileAction, &QAction::triggered, this, &MainWindow::saveFile);

    // Додаємо дії до ToolBar
    mainToolBar->addAction(newFileAction);
    mainToolBar->addAction(openFileAction);
    mainToolBar->addAction(saveFileAction);

    // Додаємо дії до меню
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(newFileAction);
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(saveFileAction);
    fileMenu->addSeparator();

    // Додаємо дію виходу
    QAction *exitAction = new QAction("Exit", this);
    connect(exitAction, &QAction::triggered, this, &MainWindow::exitApplication);
    fileMenu->addAction(exitAction);

    // Створюємо меню Допомога
    QMenu *helpMenu = menuBar()->addMenu("Help");
    QAction *aboutAction = new QAction("About project", this);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAbout);
    helpMenu->addAction(aboutAction);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Реалізація слотів
void MainWindow::createNewFile() {
    CreateNewFileCommand cmd;  // Створюємо команду для нового файлу
    commandInvoker.executeCommand(&cmd);  // Виконуємо команду через invoker
}

void MainWindow::openFile() {
    OpenFileCommand cmd(editor);  // Створюємо команду для відкриття файлу
    commandInvoker.executeCommand(&cmd);  // Виконуємо команду через invoker
}

void MainWindow::saveFile() {
    SaveFileCommand cmd(editor);  // Створюємо команду для збереження файлу
    commandInvoker.executeCommand(&cmd);  // Виконуємо команду через invoker
}

void MainWindow::exitApplication() {
    QApplication::quit();  // Закриваємо додаток
}

void MainWindow::showAbout() {
    QMessageBox::information(this, "Про програму", "Це простий текстовий редактор.");
}
