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
    char **tab;
    int i = 0;
    int count = 0;

    t_list *head = NULL;
    int *nums;
    if(ac == 2)
    {
        tab = ft_split(av[1]);
        while(tab[count])
            count++;
        nums = malloc(sizeof(int) * (count));
        while(tab[i])
        {
            nums[i] = ft_atoi(tab[i]);
            ft_lst_add_back(&head,nums[i]);
            i++;
        }
        print_list(head);
        i = 0;
        while (tab[i])
            free(tab[i++]);
        free(tab);
        free(nums);
    }
}
