#include "base.h"

using namespace std;

int addNotebook(FILE* ptr, char* name) {
    int no_error = 1;
    if (ptr == nullptr) {
        no_error = 0;
    } else {
        notebook book;
        book.setName(name);
        fseek(ptr, 0, SEEK_END);
        fwrite(&book, sizeof(notebook), 1, ptr);
    }
    return no_error;
}

int addNote(FILE* notebooks_ptr, FILE* notes_ptr, char* target) {
    int no_error = 1;
    if ((notebooks_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        note record;
        record.setTarget(target);
        fseek(notes_ptr, 0, SEEK_END);
        fwrite(&record, sizeof(note), 1, notes_ptr);
    }
    return no_error;
}

int showTables(FILE* notebooks_ptr, FILE* notes_ptr) {
    int no_error = 1;
    if ((notebooks_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        notebook book;
        note record;
        fseek(notebooks_ptr, 0, SEEK_SET);
        fseek(notes_ptr, 0, SEEK_SET);
        while ((!feof(notebooks_ptr)) && (fread(&book, sizeof(notebook), 1, notebooks_ptr))) {
            cout << book.getName() << " - " << book.getNotesNumber() << endl;
            for (int i = 0; i < book.getNotesNumber(); i++) {
                fread(&record, sizeof(note), 1, notes_ptr);
                cout << "  " << i << ". " << record.getTarget()
                     << " " << record.getCompletion() << endl;
            }
        }
    }
    return no_error;
}

void testFunction(FILE* ptr) {
    fseek(ptr, 0, SEEK_SET);
    notebook book;
    fread(&book, sizeof(notebook), 1, ptr);
    book.increaseNotesNumber();
    book.increaseNotesNumber();
    book.increaseNotesNumber();
    fseek(ptr, 0, SEEK_SET);
    fwrite(&book, sizeof(notebook), 1, ptr);
}
