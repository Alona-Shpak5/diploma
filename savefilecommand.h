#ifndef SAVEFILECOMMAND_H
#define SAVEFILECOMMAND_H

#include "command.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
class SaveFileCommand : public command {
    QTextEdit* editor;

public:
    SaveFileCommand(QTextEdit* editor) : editor(editor) {}

    void execute() override {
        QString fileName = QFileDialog::getSaveFileName(nullptr, "Зберегти файл", "", "Файли (*.txt);;Усі файли (*)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QFile::WriteOnly | QFile::Text)) {
                QTextStream out(&file);
                out << editor->toPlainText();
                file.close();
                QMessageBox::information(nullptr, "Зберегти файл", "Файл збережено: " + fileName);
            } else {
                QMessageBox::warning(nullptr, "Зберегти файл", "Не вдається зберегти файл.");
            }
        }
    }
};

#endif // SAVEFILECOMMAND_H
