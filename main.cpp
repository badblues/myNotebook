#include "base.h"
#include "menu.h"

int main() {
    FILE* notebooks_ptr = fopen(notebooks_path, "rb+");
    FILE* notes_ptr = fopen(notes_path, "rb+");
    mainMenu(notebooks_ptr, notes_ptr);
    fclose(notebooks_ptr);
    fclose(notes_ptr);
    return 0;
}