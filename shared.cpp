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

int showNotebooks(FILE* ptr) {
    int no_error = 1;
    if (ptr == nullptr) {
        no_error = 0;
    } else {
        notebook book;
        fseek(ptr, 0, SEEK_SET);
        while ((!feof(ptr)) && (fread(&book, sizeof(notebook), 1, ptr))) {
            cout << book.getName() << " - " << book.getNotesNumber() << endl;
        }
    }
    return no_error;
}

void testFunction(FILE* ptr) {
    fseek(ptr, 0, SEEK_SET);

}