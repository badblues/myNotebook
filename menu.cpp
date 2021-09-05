#include "base.h"
#include "shared.h"
#include "io.h"

using namespace std;

void showNoteMenu() {
    std::cout << "\n===================\n"
                 "MENU\n  1 DELETE\n"
                 "  2 RENAME\n  3 FINISHED\n  4 NOT FINISHED\n  0 BACK"
                 "\n===================\n";
}

void noteMenu(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id) {
    int choice;
    char str[30];
    bool flag = true;
    while (flag) {
        showN(notebooks_ptr, notes_ptr, notebook_id, note_id);
        showNoteMenu();
        choice = getChoice(0, 4);
        switch(choice) {
            case 0:
                system("cls");
                flag = false;
                break;
            case 1:
                deleteN(notebooks_ptr, notes_ptr, notebook_id, note_id);
                system("cls");
                flag = false;
                break;
            case 2:
                system("cls");
                std::cout << "ENTER TARGET:\n";
                std::cin.getline(str,30);
                renameN(notebooks_ptr, notes_ptr, notebook_id, note_id, str);
                system("cls");
                break;
            case 3:
                system("cls");
                changeCompletition(notebooks_ptr, notes_ptr, notebook_id, note_id, 1);
                break;
            case 4:
                system("cls");
                changeCompletition(notebooks_ptr, notes_ptr, notebook_id, note_id, 0);
                break;
        }
    }
}

void showNotebookMenu() {
    std::cout << "\n===================\n"
                 "MENU\n  1 SELECT NOTE\n"
                 "  2 ADD NOTE\n  3 DELETE NOTEBOOK\n  4 RENAME NOTEBOOK\n  0 BACK"
                 "\n===================\n";
}

void notebookMenu(FILE* notebooks_ptr, FILE* notes_ptr, int selected_id) {
    int choice;
    int note_id;
    char str[30];
    bool flag = true;
    while (flag) {
        showN(notebooks_ptr, notes_ptr, selected_id);
        showNotebookMenu();
        choice = getChoice(0, 4);
        switch(choice) {
            case 0:
                system("cls");
                flag = false;
                break;
            case 1:
                system("cls");
                showN(notebooks_ptr, notes_ptr, selected_id);
                std::cout << "0 - BACK\n";
                note_id = getChoice(0, getAmountOfN(notebooks_ptr, selected_id));
                system("cls");
                if (note_id != 0) {
                    noteMenu(notebooks_ptr, notes_ptr, selected_id, note_id - 1);
                }
                break;
            case 2:
                system("cls");
                std::cout << "ENTER TARGET:\n";
                std::cin.getline(str,30);
                addN(notebooks_ptr, notes_ptr, selected_id, str);
                break;
            case 3:
                system("cls");
                deleteN(notebooks_ptr, notes_ptr, selected_id);
                flag = false;
                break;
            case 4:
                system("cls");
                std::cout << "ENTER NAME:\n";
                std::cin.getline(str,30);
                renameN(notebooks_ptr, notes_ptr, selected_id, str);
                break;
        }
    }
}

void showMainMenu() {
    std::cout << "\n===================\n"
                 "MENU\n  1 SHOW NOTEBOOKS\n"
                 "  2 ADD NOTEBOOK\n  3 SELECT NOTEBOOK\n  4 SHOW ALL\n"
                 "  0 EXIT"
                 "\n===================\n";
}

void mainMenu(FILE* notebooks_ptr, FILE* notes_ptr) {
    int choice;
    int selected_id;
    char str[30];
    bool flag = true;
    while (flag) {
        showMainMenu();
        choice = getChoice(0, 4);
        switch(choice) {
            case 0:
                flag = false;
                break;
            case 1:
                system("cls");
                showN(notebooks_ptr);
                break;
            case 2:
                system("cls");
                cout << "ENTER NAME\n";
                cin.getline(str, 30);
                addN(notebooks_ptr, str);
                break;
            case 3:
                system("cls");
                showN(notebooks_ptr);
                std::cout << "0 - BACK\n";
                selected_id = getChoice(0, getAmountOfN(notebooks_ptr));
                system("cls");
                if (selected_id != 0) {
                    notebookMenu(notebooks_ptr, notes_ptr, selected_id - 1);
                }
                break;
            case 4:
                system("cls");
                showN(notebooks_ptr, notes_ptr);
                break;
        }
    }
}
