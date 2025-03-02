#ifndef PUSH_SWAP_H
# define   PUSH_SWAP_H 


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct  s_list
{
    int content;
    struct s_list *next;
}                  t_list;


int ft_atoi(const char  *str);
char    **ft_split(char *s);

#endif