//double-inclusion guard
#ifndef _head_h
#define _head_h

// main functions
char *zosh_read(void);
char **zosh_parse(char *line);
int zosh_exec(char **args);
int zosh_exec_prog(char **args);

// shell builtins
int zosh_cd(char **args);
int zosh_help(char **args);
int zosh_exit(char **args);

// prompt functions
char *prompt_handler(int buffer, char *pwd);
char *getname(void);
char *if_user_in(char *line, char *uid);

// rc and hist
int zosh_read_rc_(char *user);
char *interp(char *line);

// ...
void start_in_debug();
char cdel(char *pointer,...);
char idel(int *pointer,...);

#endif
