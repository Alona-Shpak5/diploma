#ifndef CONCRETECOMMAND_H
#define CONCRETECOMMAND_H

#include "command.h"
#include <QMessageBox>

class ConcreteCommand : public command {
public:
    void execute() override {
        QMessageBox::information(nullptr, "Command", "ConcreteCommand executed.");
    }
};

#endif // CONCRETECOMMAND_H
