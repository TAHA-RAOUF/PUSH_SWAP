#ifndef PUSH_SWAP_H
# define   PUSH_SWAP_H 


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct  s_list
{
    int content;
    struct s_list *next;
}                  t_list;


int ft_atoi(const char  *str);
void main_fun(char **str,int ac,t_list **head);
void ft_lst_add_back(t_list **lst,int value);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);



#endif