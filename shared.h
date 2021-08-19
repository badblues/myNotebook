#ifndef PROGRESS_BAR_SHARED_H
#define PROGRESS_BAR_SHARED_H

int getNumberOfNotes(FILE* notebook_ptr);
int showTable(FILE* notebook_ptr, FILE* notes_ptr);
int addNotebook(FILE* notebook_ptr, char* name);
int addNote(FILE* notebook_ptr, FILE* notes_ptr, int notebook_id, char* target);

#endif //PROGRESS_BAR_SHARED_H
