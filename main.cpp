#include "base.h"
#include "shared.h"

int main() {
    notebook book1;
    char name[30] = "FIRST BOOK";
    FILE* notebook_ptr = fopen(notebooks_path, "a+b");
    FILE* notes_ptr = fopen(notes_path, "a+b");
    //addNotebook(notebook_ptr, name);
    showTable(notebook_ptr, notes_ptr);
    return 0;
}
