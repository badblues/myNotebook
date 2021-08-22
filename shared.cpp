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

int showNotebook(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id) {
    int no_error = 1;
    if ((notebooks_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        notebook book;
        note record;
        int index = 0;
        int indent = 0;
        fseek(notebooks_ptr, 0, SEEK_SET);
        while ((!feof(notebooks_ptr)) && (fread(&book, sizeof(notebook), 1, notebooks_ptr))) {
            if (index < notebook_id) {
                indent += book.getNotesNumber();
            } else if (index == notebook_id) {
                cout << book.getName() << " - " << book.getNotesNumber() << endl;
                break;
            }
            index++;
        }
        fseek(notes_ptr, indent * sizeof(note), SEEK_SET);
        for (int i = 0; i < book.getNotesNumber(); i++) {
            fread(&record, sizeof(note), 1, notes_ptr);
            cout << "  " << i + 1 << ". " << record.getTarget()
            << " " << record.getCompletion() << endl;
        }
    }
    return no_error;
}

int showNotebooks(FILE* ptr) {
    int no_error = 1;
    if (ptr == nullptr) {
        no_error = 0;
    } else {
        notebook book;
        fseek(ptr, 0, SEEK_SET);
        while((!feof(ptr)) && (fread(&book, sizeof(notebook), 1, ptr))) {
            cout << book.getName() << " - " << book.getNotesNumber() << endl;
        }
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
                cout << "  " << i + 1 << ". " << record.getTarget()
                     << " " << record.getCompletion() << endl;
            }
        }
    }
    return no_error;
}

int getNotebooksNumber(FILE* ptr) {
    int num;
    fseek(ptr, 0, SEEK_END);
    num = ftell(ptr) / sizeof(notebook);
    return num;
}

int getNotesNumber(FILE* ptr, int id) {
    int num = -1;
    notebook book;
    fseek(ptr, id * sizeof(notebook), SEEK_SET);
    fread(&book, sizeof(notebook), 1, ptr);
    num = book.getNotesNumber();
    return num;
}

int showNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id) {
    int no_error = 1;
    if ((notebooks_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        notebook book;
        note record;
        int index = 0;
        int indent = 0;
        fseek(notebooks_ptr, 0, SEEK_SET);
        while (index < notebook_id) {
            fread(&book, sizeof(notebook), 1, notebooks_ptr);
            indent += book.getNotesNumber();
            index++;
        }
        fseek(notes_ptr, (indent + note_id + 1) * sizeof(note), SEEK_SET);
        fread(&record, sizeof(note), 1, notes_ptr);
        cout << "  " << note_id + 1 << ". " << record.getTarget()
        << " " << record.getCompletion() << endl;
    }
    return no_error;
}

int deleteNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id) {
    int no_error = 1;
    if ((notebooks_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        notebook book;
        note record;
        int index = 0;
        int indent = 0;
        fseek(notebooks_ptr, 0, SEEK_SET);
        while (index <= notebook_id) {
            fread(&book, sizeof(notebook), 1, notebooks_ptr);
            if (index < notebook_id) {
                indent += book.getNotesNumber();
            } else if (index == notebook_id) {
                book.decreaseNotesNumber();
                fseek(notebooks_ptr, -1 * (long)sizeof(notebook), SEEK_CUR);
                fwrite(&book, sizeof(notebook), 1, notebooks_ptr);
            }
            index++;
        }
        fseek(notes_ptr, (indent + note_id + 1) * sizeof(note), SEEK_SET);
        while (!feof(notes_ptr) && (fread(&record, sizeof(note), 1, notes_ptr))) {
            fseek(notes_ptr, -2 * (long)sizeof(note), SEEK_CUR);
            fwrite(&record, sizeof(note), 1, notes_ptr);
            fseek(notes_ptr, 2 * sizeof(note), SEEK_CUR);
        }
    }
    return no_error;
}
