#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H

#include "command.h"

class CommandInvoker {
public:
    void executeCommand(command *cmd) {
        if (cmd) {
            cmd->execute();  // Виконуємо команду
        }
    }
};

#endif // COMMANDINVOKER_H
