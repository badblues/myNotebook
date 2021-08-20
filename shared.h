#ifndef PROGRESS_BAR_SHARED_H
#define PROGRESS_BAR_SHARED_H

int addNotebook(FILE* ptr, char* name);
int addNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, char* target);
int showTables(FILE* notebooks_ptr, FILE* notes_ptr);
void testFunction(FILE* ptr);

#endif //PROGRESS_BAR_SHARED_H
