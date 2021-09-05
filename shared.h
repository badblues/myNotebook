#ifndef PROGRESS_BAR_SHARED_H
#define PROGRESS_BAR_SHARED_H

int SHOWALLNOTES(FILE* notes_ptr);
int showN(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id);
int showN(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id);
int showN(FILE* ptr);
int showN(FILE* notebooks_ptr, FILE* notes_ptr);
int addN(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, char* target);
int addN(FILE* ptr, char* name);
int getAmountOfN(FILE* notebooks_ptr, int id);
int getAmountOfN(FILE* notebook_ptr);
int deleteN(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id);
int deleteN(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id);
int renameN(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id, char* target);
int renameN(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, char* name);
int changeCompletition(FILE* notebooks_ptr, FILE* notes_ptr, int notebook_id, int note_id, int comp);

#endif //PROGRESS_BAR_SHARED_H
