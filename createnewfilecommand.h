#ifndef CREATENEWFILECOMMAND_H
#define CREATENEWFILECOMMAND_H

#include <QMessageBox>
#include "command.h"

class CreateNewFileCommand: public command {
public:
    void execute() override {
        QMessageBox::information(nullptr, "Новий файл", "Створення нового файлу...");
    }
};

#endif // CREATENEWFILECOMMAND_H
