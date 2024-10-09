#ifndef COMMAND_H
#define COMMAND_H

class command
{
public:
    virtual ~command() {}
    virtual void execute() = 0; // Метод для виконання дії
};

#endif // COMMAND_H
