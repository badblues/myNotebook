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

int addNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, char* target) {
    int no_error = 1;
    if ((notebooks_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        notebook book;
        note record;
        record.setTarget(target);
        int index = 0;
        int indent = 0;
        int notes_number = 0;
        fseek(notebooks_ptr, 0, SEEK_SET);
        while ((!feof(notebooks_ptr)) && (fread(&book, sizeof(notebook), 1, notebooks_ptr))) {
            if (index < notebook_id) {
                indent += book.getNotesNumber();
            } else if (index == notebook_id) {
                book.increaseNotesNumber();
                fseek(notebooks_ptr, -1 * (long)sizeof(notebook), SEEK_CUR);
                fwrite(&book, sizeof(notebook), 1, notebooks_ptr);
                fseek(notebooks_ptr, 0, SEEK_CUR);
            }
            notes_number += book.getNotesNumber();
            index++;
        }
        cout << "index = " << index << endl << "number of notes = " << notes_number
             << endl;
        while (notes_number >= indent) {
            fseek(notes_ptr, (notes_number-1) * sizeof(note), SEEK_SET);
            fread(&record, sizeof(note), 1, notes_ptr);
            fseek(notes_ptr, notes_number * sizeof(note), SEEK_SET);
            fwrite(&record, sizeof(note), 1, notes_ptr);
            notes_number--;
        }
        fseek(notes_ptr, (notes_number+1) * sizeof(note), SEEK_SET);
        record.setTarget(target);
        record.setCompletion(false);
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
    note record;
    char name1[30] = "FIRST TARGET";
    char name2[30] = "SECOND TARGET";
    char name3[30] = "THIRD TARGET";
    fseek(ptr, 0, SEEK_END);
    record.setTarget(name1);
    fwrite(&record, sizeof(note), 1, ptr);
    record.setTarget(name2);
    fwrite(&record, sizeof(note), 1, ptr);
    record.setTarget(name3);
    fwrite(&record, sizeof(note), 1, ptr);
}
