#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

void showNoteMenu();
void noteMenu(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id);
void showNotebookMenu();
void notebookMenu(FILE* notebooks_ptr, FILE* notes_ptr, int selected_id);
void showMainMenu();
void mainMenu(FILE* notebooks_ptr, FILE* notes_ptr);

#endif //UNTITLED_MENU_H
