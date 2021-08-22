#include "base.h"
#include "shared.h"
#include "io.h"

void showMainMenu();
void mainMenu(FILE* notebooks_ptr, FILE* notes_ptr);
void showNotebookMenu();
void notebookMenu(FILE* notebooks_ptr, FILE* notes_ptr, int selected_id);
void showNoteMenu();
void noteMenu(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id);

int main() {
    FILE* notebooks_ptr = fopen(notebooks_path, "rb+");
    FILE* notes_ptr = fopen(notes_path, "rb+");
    mainMenu(notebooks_ptr, notes_ptr);
    fclose(notebooks_ptr);
    fclose(notes_ptr);
    return 0;
}

void showMainMenu() {
    std::cout << "===================\n"
                 "MENU\n  1 SHOW NOTEBOOKS\n"
                 "  2 SELECT NOTEBOOK\n  3 SHOW ALL\n  0 EXIT"
                 "\n===================\n";
}

void mainMenu(FILE* notebooks_ptr, FILE* notes_ptr) {
    int choice;
    int selected_id;
    bool flag = true;
    while (flag) {
        showMainMenu();
        choice = getChoice(0, 3);
        switch(choice) {
            case 0:
                flag = false;
                break;
            case 1:
                system("cls");
                showNotebooks(notebooks_ptr);
                break;
            case 2:
                system("cls");
                showNotebooks(notebooks_ptr);
                selected_id = getChoice(1, getNotebooksNumber(notebooks_ptr) + 1) - 1;
                system("cls");
                showNotebook(notebooks_ptr, notes_ptr, selected_id);
                notebookMenu(notebooks_ptr, notes_ptr, selected_id);
                break;
            case 3:
                system("cls");
                showTables(notebooks_ptr, notes_ptr);
                break;
        }
    }
}

void showNotebookMenu() {
    std::cout << "===================\n"
                 "MENU\n  1 SELECT NOTE\n"
                 "  2 ADD NOTE\n  0 BACK"
                 "\n===================\n";
}

void notebookMenu(FILE* notebooks_ptr, FILE* notes_ptr, int selected_id) {
    int choice;
    int note_id;
    char str[30];
    bool flag = true;
    while (flag) {
        showNotebook(notebooks_ptr, notes_ptr, selected_id);
        showNotebookMenu();
        choice = getChoice(0, 2);
        switch(choice) {
            case 0:
                system("cls");
                flag = false;
                break;
            case 1:
                system("cls");
                showNotebook(notebooks_ptr, notes_ptr, selected_id);
                note_id = getChoice(1, getNotesNumber(notebooks_ptr, selected_id)) - 1;
                noteMenu(notebooks_ptr, notes_ptr, selected_id, note_id);
                break;
            case 2:
                system("cls");
                std::cout << "ENTER TARGET:\n";
                std::cin.getline(str,30);
                std::cin.getline(str,30);
                std::cout << "got line: " << str << std::endl;
                addNote(notebooks_ptr, notes_ptr, selected_id, str);
                break;
        }
    }
}

void showNoteMenu() {
    std::cout << "===================\n"
            "MENU\n  1 DELETE\n"
            "  2 RENAME\n  3 SET COMPLITION\n  0 BACK"
            "\n===================\n";
}

void noteMenu(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id) {
    int choice;
    //char str[30];
    bool flag = true;
    while (flag) {
        showNote(notebooks_ptr, notes_ptr, notebook_id, note_id);
        showNoteMenu();
        choice = getChoice(0, 3);
        switch(choice) {
            case 0:
                system("cls");
                flag = false;
                break;
            case 1:
                deleteNote(notebooks_ptr, notes_ptr, notebook_id, note_id);
                flag = false;
                break;
        }
    }
}
