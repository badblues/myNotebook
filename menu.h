#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

void showMainMenu();
void mainMenu(FILE* notebooks_ptr, FILE* notes_ptr);
void showNotebookMenu();
void notebookMenu(FILE* notebooks_ptr, FILE* notes_ptr, int selected_id);
void showNoteMenu();
void noteMenu(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id);

#endif //UNTITLED_MENU_H
