//double-inclusion guard
#ifndef _head_h
#define _head_h

// main functions
char *main_read(void);
char **main_parse(char *line);
int main_exec(char **args);
int main_exec_prog(char **args);

// shell builtins
int main_cd(char **args);
int main_help(char **args);
int main_exit(char **args);

// prompt functions
char *getname(void);
char *if_user_in(char *line, char *uid);

// rc and hist
int main_read_rc_(char *user);
char *interp(char *line);

// ...
void start_in_debug();
char cdel(char *pointer,...);
char idel(int *pointer,...);

#endif
