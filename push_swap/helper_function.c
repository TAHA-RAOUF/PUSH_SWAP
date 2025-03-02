#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
#include <stdio.h>
#include <stdlib.h>

int     is_space(char   c)
{
    return (c <= 32);
}

int     count_word(char *s)
{
    int     i;
    int     count;

    if (!s) 
        return (0);

    i = 0;
    count = 0;
    while (s[i])
    {
        while (s[i] && is_space(s[i]))
            i++;
        if (s[i] && !is_space(s[i]))
        {
            count++;
            while (s[i] && !is_space(s[i]))
                i++;
        }
    }
    return (count);
}

char    *split_word(char *s)
{
    int     i;
    char    *word;

    i = 0;
    while (s[i] && !is_space(s[i]))
        i++;

    word = malloc(sizeof(char) * (i + 1));
    if (!word) 
        return (NULL);

    i = 0;
    while (s[i] && !is_space(s[i]))
    {
        word[i] = s[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

void free_memory(char **list)
{
    int i = 0;
    while (list[i])
    {
        free(list[i]);
        i++;
    }
    free(list);
}

char    **ft_split(char *s)
{
    char    **list;
    int     i;

    if (!s) 
        return (NULL);

    i = 0;
    list = malloc(sizeof(char *) * (count_word(s) + 1));
    if (!list) 
        return (NULL);

    while (*s)
    {
        while (*s && is_space(*s))
            s++;
        if (*s && !is_space(*s))
        {
            list[i] = split_word(s);
            if (!list[i]) 
            {
                free_memory(list);
                return (NULL);
            }
            i++;
            while (*s && !is_space(*s))
                s++;
        }
    }
    list[i] = NULL; 
    return (list);
}


