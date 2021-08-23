#ifndef UNTITLED_BASE_H
#define UNTITLED_BASE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>

#define notes_path "../data/notes"
#define notebooks_path "../data/notebooks"

//every function should set-up position in file first

//TODO deleting rec
//TODO deleting notebook
//TODO renaming things
//TODO

typedef class note note;
typedef class notebook notebook;
class notebook {
    private:

    char name[30]{};
    int notes_number;

    public:

    notebook() {
        *(this->name) = 0;
        this->notes_number = 0;
    }

    void setName(char* str) {
        strcpy(this->name, str);
    }

    char* getName() {
        return this->name;
    }

    void decreaseNotesNumber() {
        (this->notes_number)--;
    }

    void increaseNotesNumber() {
        (this->notes_number)++;
    }

    int getNotesNumber() {
        return this->notes_number;
    }
};

class note {
    private:

    char target[30]{};
    bool completion_flag;

    public:
    note() {
        *(this->target) = 0;
        this->completion_flag = false;
    }
    void setTarget(char* str) {
        strcpy(this->target, str);
    }

    char* getTarget() {
        return this->target;
    }

    void setCompletion(const bool a) {
        this->completion_flag = a;
    }

    bool getCompletion() {
        return this->completion_flag;
    }

};

#endif //UNTITLED_BASE_H
