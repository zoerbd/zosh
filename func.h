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
int read_rc(char *user);
int write_hist(char *user, char *user_input);
void interp(char *line);
char *make_path(char *name, char *type);
int num_options(void);
int rc_prompt(char **theme);
int rc_alias(char **alias);

// ...
void start_in_debug();
char cdel(char *pointer,...);
char idel(int *pointer,...);

#endif
