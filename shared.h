#ifndef PROGRESS_BAR_SHARED_H
#define PROGRESS_BAR_SHARED_H

int addNotebook(FILE* ptr, char* name);
int addNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, char* target);
int showNotebook(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id);
int showNotebooks(FILE* ptr);
int showNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id);
int showTables(FILE* notebooks_ptr, FILE* notes_ptr);
void testFunction(FILE* ptr);
int getNotebooksNumber(FILE* ptr);
int getNotesNumber(FILE* ptr, int id);
int deleteNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id);

#endif //PROGRESS_BAR_SHARED_H
