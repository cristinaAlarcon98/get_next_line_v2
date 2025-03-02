#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H



#include <unistd.h>
#include  <stdlib.h>
#include <stdio.h>
#include <sys/fcntl.h>


int has_new_line(char *str);
int ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char *strdup_before(char *str, char c);
char *strdup_after(char *str, char c);
char *get_next_line(int fd);
char *get_fragment_of_line(char **str_line, char **str_buff, int fd);
char *get_last_line(char **str_line, char **str_buff);

#ifndef BUFFSIZE
#define BUFFSIZE 1
#endif

#endif





