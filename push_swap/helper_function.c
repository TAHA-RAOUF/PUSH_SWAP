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
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if(result > INT_MAX && result < INT_MIN)
			p_eroor();
		i++;
	}
	check_input(str[i]);
	return (result * sign);
}
void p_eroor()
{
	write(1,"hadchi ghalat",14);
	exit(1);
}
void check_input(char c)
{
	if(!(c >= '0' && c <= '9'))
	{
		if(c != '\0' && !(c == 32 || (c >= 9 && c <= 13)))
			p_error();
	}
		
}
void insert_num(char *str)
{
	int num;

	num = ft_atoi(str);

}
void main_fun(char **str,int ac)
{
    int (i) , j;
    i = 0;
    j = 1;
    while(ac > j)
    {
        while(str[j][i] == 32 || (str[j][i] >= 9 && str[j][i] <= 13))
            i++;
        if(str[j][i])
             insert_num(str[j] + i);
        
    }   
}


