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
int main_prompt(char **args);
int main_alias(char **args);

// prompt functions
char *getname(void);
char *if_user_in(char *line, char *uid);

// rc and hist
char *make_path(char *name, char *type);
int read_rc(char *user);
int write_hist(char *user, char *user_input);

// etc
void start_in_debug(void);

#endif
