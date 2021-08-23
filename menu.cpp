#include "base.h"
#include "shared.h"
#include "io.h"

using namespace std;

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
                addNote(notebooks_ptr, notes_ptr, selected_id, str);
                break;
        }
    }
}

void showMainMenu() {
    std::cout << "===================\n"
                 "MENU\n  1 SHOW NOTEBOOKS\n"
                 "  2 ADD NOTEBOOK\n  3 SELECT NOTEBOOK\n  4 SHOW ALL\n"
                 "  5 SHOW ALL NOTES(DEBUG)\n  0 EXIT"
                 "\n===================\n";
}

void mainMenu(FILE* notebooks_ptr, FILE* notes_ptr) {
    int choice;
    int selected_id;
    char str[30];
    bool flag = true;
    while (flag) {
        showMainMenu();
        choice = getChoice(0, 5);
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
                cout << "ENTER NAME\n";
                                //TODO fix in normally
                cin.getline(str, 30);
                cin.getline(str, 30);
                addNotebook(notebooks_ptr, str);
                break;
            case 3:
                system("cls");
                showNotebooks(notebooks_ptr);
                selected_id = getChoice(1, getNotebooksNumber(notebooks_ptr) + 1) - 1;
                system("cls");
                notebookMenu(notebooks_ptr, notes_ptr, selected_id);
                break;
            case 4:
                system("cls");
                showTables(notebooks_ptr, notes_ptr);
                break;
            case 5:
                system("cls");
                SHOWALLNOTES(notes_ptr);
                break;
        }
    }
}
