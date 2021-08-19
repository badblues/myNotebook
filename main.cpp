#include "base.h"
#include "shared.h"

int main() {
    char name[30] = "FIRST TARGET";
    FILE* notebook_ptr = fopen(notebooks_path, "a+b");
    FILE* notes_ptr = fopen(notes_path, "a+b");
    showTable(notebook_ptr, notes_ptr);
    //addNote(notebook_ptr, notes_ptr, 0, name);
    return 0;
}
