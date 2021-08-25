#include "base.h"

using namespace std;

int SHOWALLNOTES(FILE* notes_ptr) {
    int no_error = 1;
    if (notes_ptr == nullptr) {
        no_error = 0;
    } else {
        note record;
        fseek(notes_ptr, 0, SEEK_SET);
        while((!feof(notes_ptr)) && (fread(&record, sizeof(note), 1, notes_ptr))) {
            cout << record.getTarget()
            << " " << record.getCompletion() << endl;
        }
    }
    return no_error;
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
        fseek(notes_ptr, (indent + note_id) * sizeof(note), SEEK_SET);
        fread(&record, sizeof(note), 1, notes_ptr);
        cout << record.getTarget() << " - " << record.getCompletion() << endl;
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
            << " - " << record.getCompletion() << endl;
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
        int id = 1;
        fseek(ptr, 0, SEEK_SET);
        while((!feof(ptr)) && (fread(&book, sizeof(notebook), 1, ptr))) {
            cout << id << ". " << book.getName() << "[" << book.getNotesNumber() << "]" << endl;
            id++;
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
            cout << book.getName() << "[" << book.getNotesNumber() << "]" << endl;
            for (int i = 0; i < book.getNotesNumber(); i++) {
                fread(&record, sizeof(note), 1, notes_ptr);
                cout << "  " << i + 1 << ". " << record.getTarget()
                << " - " << record.getCompletion() << endl;
            }
        }
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
        notes_number--;
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

int getAmountOfNotes(FILE* notes_ptr) {
    int num;
    fseek(notes_ptr, 0, SEEK_END);;
    num = ftell(notes_ptr) / sizeof(note);
    return num;
}

int getNotesNumber(FILE* notebooks_ptr, int id) {
    int num = -1;
    notebook book;
    fseek(notebooks_ptr, id * sizeof(notebook), SEEK_SET);
    fread(&book, sizeof(notebook), 1, notebooks_ptr);
    num = book.getNotesNumber();
    return num;
}

int getNotebooksNumber(FILE* notebook_ptr) {
    int num;
    fseek(notebook_ptr, 0, SEEK_END);
    num = ftell(notebook_ptr) / sizeof(notebook);
    return num;
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
            fseek(notes_ptr, sizeof(note), SEEK_CUR);
        }
        ftruncate(fileno(notes_ptr), (getAmountOfNotes(notes_ptr) - 1) * sizeof(note));
    }
    return no_error;
}

int deleteNotebook(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id) {
    int no_error = 1;
    if ((notebooks_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        notebook book;
        note record;
        int index = 0;
        int indent = 0;
        int notes_to_delete;
        fseek(notebooks_ptr, 0, SEEK_SET);
        while ((!feof(notebooks_ptr)) && (fread(&book, sizeof(notebook), 1, notebooks_ptr))) {
            if (index < notebook_id) {
                indent += book.getNotesNumber();
            } else if (index == notebook_id) {
                notes_to_delete = book.getNotesNumber();
            } else if (index > notebook_id) {
                fseek(notebooks_ptr, -2 * (long)sizeof(notebook), SEEK_CUR);
                fwrite(&book, sizeof(notebook), 1, notebooks_ptr);
                fseek(notebooks_ptr, sizeof(notebook), SEEK_CUR);
            }
            index++;
        }
        ftruncate(fileno(notebooks_ptr), (getNotebooksNumber(notebooks_ptr) - 1) * sizeof(notebook));
        fseek(notes_ptr, (indent + notes_to_delete) * sizeof(note), SEEK_SET);
        while (!feof(notes_ptr) && (fread(&record, sizeof(note), 1, notes_ptr))) {
            fseek(notes_ptr, -1 * (notes_to_delete + 1) * (long)sizeof(note), SEEK_CUR);
            fwrite(&record, sizeof(note), 1, notes_ptr);
            fseek(notes_ptr, notes_to_delete * sizeof(note), SEEK_CUR);
        }
        ftruncate(fileno(notes_ptr), (getAmountOfNotes(notes_ptr) - notes_to_delete) * sizeof(note));
    }
    return no_error;
}

int renameNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id, char* target) {
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
        fseek(notes_ptr, (indent + note_id) * sizeof(note), SEEK_SET);
        fread(&record, sizeof(note), 1, notes_ptr);
        fseek(notes_ptr, -1 * (long)sizeof(note), SEEK_CUR);
        record.setTarget(target);
        fwrite(&record, sizeof(note), 1, notes_ptr);
    }
    return no_error;
}

int renameNotebook(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, char* name) {
    int no_error = 1;
    if ((notebooks_ptr == nullptr) || (notes_ptr == nullptr)) {
        no_error = 0;
    } else {
        notebook book;
        fseek(notebooks_ptr, notebook_id, SEEK_SET);
        fread(&book, sizeof(notebook), 1, notebooks_ptr);
        fseek(notebooks_ptr, notebook_id, SEEK_SET);
        book.setName(name);
        fwrite(&book, sizeof(notebook), 1, notebooks_ptr);
    }
    return no_error;
}

int changeCompletition(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id, int comp) {
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
        fseek(notes_ptr, (indent + note_id) * sizeof(note), SEEK_SET);
        fread(&record, sizeof(note), 1, notes_ptr);
        fseek(notes_ptr, -1 * (long)sizeof(note), SEEK_CUR);
        record.setCompletion(comp);
        fwrite(&record, sizeof(note), 1, notes_ptr);
    }
    return no_error;
}
