#include "base.h"
#include "shared.h"

int main() {
    FILE* notebook_ptr = fopen(notebooks_path, "rb+");
    /*char name1[30] = "FIRST BOOK";
    char name2[30] = "SECOND BOOK";
    char name3[30] = "THIRD BOOK";
    addNotebook(notebook_ptr, name1);
    addNotebook(notebook_ptr, name2);
    addNotebook(notebook_ptr, name3);*/
    showNotebooks(notebook_ptr);
    fclose(notebook_ptr);
    return 0;
}
