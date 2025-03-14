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


int	    ft_atoi(const char *str,char **array,t_list **head);
void    main_fun(char **str,int ac,t_list **head);
void    ft_lst_add_back(t_list **lst,int value);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
void	free_mem(char **array);
void    ft_lstclear(t_list **lst);
int     fun_eror(char **array,t_list **head);
int     check_double(t_list *head);
void    pb(t_list **stack_a,t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void    sa(t_list **stack_a);
void    sb(t_list **stack_b);
void    ss(t_list **stack_a,t_list **stack_b);
void    ra(t_list **stack_a);
void    rb(t_list **stack_b);
void    rr(t_list **stack_a,t_list **stack_b);
void    rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
t_list *min(t_list **stack_a);


#endif