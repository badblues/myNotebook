#include "base.h"
#include "shared.h"

int main() {
    FILE* notebooks_ptr = fopen(notebooks_path, "rb+");
    FILE* notes_ptr = fopen(notes_path, "rb+");
    /*char name1[30] = "FIRST BOOK";
    char name2[30] = "SECOND BOOK";
    char name3[30] = "THIRD BOOK";
    addNotebook(notebook_ptr, name1);
    addNotebook(notebook_ptr, name2);
    addNotebook(notebook_ptr, name3);*/
    //testFunction(notebooks_ptr);
   /* char rec1[30] = "FIRST TARGET";
    char rec2[30] = "SECOND TARGET";
    char rec3[30] = "THIRD TARGET";
    addNote(notebooks_ptr, notes_ptr, rec1);
    addNote(notebooks_ptr, notes_ptr, rec2);
    addNote(notebooks_ptr, notes_ptr, rec3);*/
    showTables(notebooks_ptr, notes_ptr);
    fclose(notebooks_ptr);
    return 0;
}
