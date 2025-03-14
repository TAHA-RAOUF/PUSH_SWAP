#include "push_swap.h"

t_list	*ft_new_node(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	print_list(t_list *stack_a)
{
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
}
void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	ft_lst_add_back(t_list **lst, int value)
{
	t_list	*new;
	t_list	*last;

	new = ft_new_node(value);
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*temp;


	if (ac >= 2)
	{
		stack_a = NULL;

		//t_list *stack_b = NULL;
		main_fun(av, ac, &stack_a);
		print_list(stack_a);
		t_list *min_node = min(&stack_a);
		printf("%d", min_node->content);
		//pb(stack_a,min_node);
		//pb(min_node);
		while (stack_a)
		{
			temp = stack_a;
			stack_a = stack_a->next;
			free(temp);
		}
		return (0);
	}
	else
	{
		write(1, "error2\n", 6);
		exit(1);
	}
}
