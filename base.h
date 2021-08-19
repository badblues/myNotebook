#ifndef UNTITLED_BASE_H
#define UNTITLED_BASE_H

#include <iostream>
#include <cstring>

#define notes_path "../data/notes.txt"
#define notebooks_path "../data/notebooks.txt"

//every function should set-up position in file first

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
