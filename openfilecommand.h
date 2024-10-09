#ifndef OPENFILECOMMAND_H
#define OPENFILECOMMAND_H

#include "command.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>

class OpenFileCommand : public command {
    QTextEdit* editor;

public:
    OpenFileCommand(QTextEdit* editor) : editor(editor) {}

    void execute() override {
        QString fileName = QFileDialog::getOpenFileName(nullptr, "Відкрити файл", "", "Файли (*.txt);;Усі файли (*)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QFile::ReadOnly | QFile::Text)) {
                QTextStream in(&file);
                editor->setPlainText(in.readAll());
                file.close();
                QMessageBox::information(nullptr, "Відкрити файл", "Відкрито файл: " + fileName);
            } else {
                QMessageBox::warning(nullptr, "Відкрити файл", "Не вдається відкрити файл.");
            }
        }
    }
};

#endif // OPENFILECOMMAND_H
