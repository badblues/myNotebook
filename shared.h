#ifndef PROGRESS_BAR_SHARED_H
#define PROGRESS_BAR_SHARED_H

int SHOWALLNOTES(FILE* notes_ptr);
int showNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id);
int showNotebook(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id);
int showNotebooks(FILE* ptr);
int showTables(FILE* notebooks_ptr, FILE* notes_ptr);
int addNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, char* target);
int addNotebook(FILE* ptr, char* name);
int getNotesNumber(FILE* notebooks_ptr, int id);
int getNotebooksNumber(FILE* notebook_ptr);
int deleteNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id);
int deleteNotebook(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id);
int renameNote(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id, char* target);
int renameNotebook(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, char* name);
int changeCompletition(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id, int comp);

#endif //PROGRESS_BAR_SHARED_H
