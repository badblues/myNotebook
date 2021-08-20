#include "base.h"
#include "shared.h"

int main() {
    FILE* notebooks_ptr = fopen(notebooks_path, "rb+");
    FILE* notes_ptr = fopen(notes_path, "rb+");
    //showTables(notebooks_ptr, notes_ptr);
    //testFunction(notes_ptr);
    char target[30] = "TEST TARGET4";
    addNote(notebooks_ptr, notes_ptr, 3, target);
    showTables(notebooks_ptr, notes_ptr);
    fclose(notebooks_ptr);
    return 0;
}
