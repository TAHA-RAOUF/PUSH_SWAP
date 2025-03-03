#include <unistd.h>
#include "push_swap.h"



t_list *ft_new_node(int content)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if(!node)
        return NULL;
    node ->content = content;
    node->next = NULL;
    return(node);
    
}
void print_list(t_list *head)
{

    while(head)
    {
        printf("%d\n",head->content);
        head = head->next;
    }
}
void ft_lst_add_back(t_list **lst,int value)
{
    t_list *last;

    t_list *new = ft_new_node(value);
    if(!lst || !new)
        return;
    if(*lst == NULL)
        *lst = new;
    else 
    {
        last = *lst;
        while(last->next)
            last = last->next;
        last->next = new;
    }
}
int main(int ac,char **av)
{
    t_list *head;
    

    head = NULL;
    if(ac >= 2) 
    {
        main_fun(av,ac);
    }
}
