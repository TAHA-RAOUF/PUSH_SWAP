#include "push_swap.h"

t_list *ft_new_node(int content)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

void print_list(t_list *head)
{
    while (head)
    {
        printf("%d\n", head->content);
        head = head->next;
    }
}
void ft_lstclear(t_list **lst)
{
    t_list *current;
    t_list *next;

    if (!lst || !*lst)
        return;

    current = *lst;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *lst = NULL;
}

void ft_lst_add_back(t_list **lst, int value)
{
    t_list *new = ft_new_node(value);
    if (!lst ||!new)
        return;
    if (*lst == NULL)
        *lst = new;
    else
    {
        t_list *last = *lst;
        while (last->next)
            last = last->next;
        last->next = new;
    }
}

int main(int ac, char **av)
{
    if (ac >= 2)
    {
        t_list *head = NULL;
        main_fun(av, ac, &head);
        print_list(head);
        t_list *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
        return 0;
    }
    else
    {
        write(1, "error2\n", 6);
        exit(1);
    }
}