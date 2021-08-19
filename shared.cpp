#include "base.h"

using namespace std;

int getNumberOfNotes(FILE* notebook_ptr) {
    int num = -1;
    if (notebook_ptr != nullptr) {
        notebook book;
        fseek(notebook_ptr, 0, SEEK_SET);
        while (!feof(notebook_ptr)) {
            fread(&book, sizeof(notebook), 1, notebook_ptr);
            num += book.getNotesNumber();
        }
    }
    return num;
}

int showTable(FILE* notebook_ptr, FILE* notes_ptr) {
    int no_error = 1;
    if ((notebook_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        note record;
        notebook book;
        fseek(notebook_ptr, 0, SEEK_SET);
        fseek(notes_ptr, 0, SEEK_SET);
        while (!feof(notebook_ptr) || (fread(&book, sizeof(notebook), 1, notebook_ptr) != 1)) {
            cout << book.getName() << endl;
            cout << sizeof(notebook);
            for (int i = 0; i < book.getNotesNumber(); i++) {
                fread(&record, sizeof(note), 1, notes_ptr);
                cout << i << " " << record.getTarget()
                     << " " << record.getCompletion() << endl;
            }
        }
    }
    return no_error;
}

int addNotebook(FILE* notebook_ptr, char* name) {
    int no_error = 1;
    if (notebook_ptr == nullptr) {
        no_error = 0;
    } else {
        fseek(notebook_ptr, 0 , SEEK_END);
        notebook book;
        book.setName(name);
        cout << book.getName() << "|" << book.getNotesNumber();
        fwrite(&book, sizeof(notebook), 1, notebook_ptr);
    }
    return no_error;
}

int addNote(FILE* notebook_ptr, FILE* notes_ptr, int notebook_id, char* target) {
    int no_error = 1;
    if ((notebook_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        int indent = 0;
        int index = 0;
        notebook book;
        while (index < notebook_id) {
            fseek(notebook_ptr, index * sizeof(notebook), SEEK_SET);
            fread(&book, sizeof(notebook), 1, notebook_ptr);
            indent += book.getNotesNumber();
            index++;
        }
        fread(&book, sizeof(notebook), 1, notebook_ptr);
        book.increaseNotesNumber();
        fseek(notebook_ptr, index * sizeof(notebook), SEEK_SET);
        fwrite(&book, sizeof(notebook), 1, notebook_ptr);
        index = getNumberOfNotes(notebook_ptr) - 1;
        note tmp;
        while (index >= indent) {
            fseek(notes_ptr, index * sizeof(note), SEEK_SET);
            fread(&tmp, sizeof(note), 1, notes_ptr);
            fseek(notes_ptr, (index + 1) * sizeof(note), SEEK_SET);
            fwrite(&tmp, sizeof(note), 1, notes_ptr);
            index--;
        }
        fseek(notes_ptr, (index + 1) * sizeof(note), SEEK_SET);
        tmp.setTarget(target);
        fwrite(&tmp, sizeof(note), 1, notes_ptr);
    }
    return no_error;
}
