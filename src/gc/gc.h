/* Provides a simple conservative garbage collector. */

void  gc();
void *gcmalloc(int);
/* TODO, rename these, put somewhere more appropriate. */
char *gcstrdup(char *);
char *gcprintf(char *, ...);
