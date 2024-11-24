/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 02:31:49 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/24 03:34:26 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strchr(const char *s, int c)
{
    size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while(s[len])
        len++;
    return(len);
}

char *ft_strdup(const char *s)
{
    size_t len;
    char *str;

    len = ft_strlen(s);
    str = malloc(sizeof(char) * (len + 1 ));
    if(!str)
        return NULL;
    len = 0;
    while(s[len])
    {
        str[len] = s[len];
        len++;
    }
    str[len] = '\0';
    return (str);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	lenght;

	if (!s)
		return (NULL);
	lenght = ft_strlen(s);
	if (start >= lenght)
		return (ft_strdup(""));
	if (len > lenght - start)
		len = lenght - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
char *ft_strjoin(const char *s1, const char *s2)
{
    size_t len1;
    size_t len2;
    size_t k;
    char *str;

    if(!s1 || !s2)
        return NULL;
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = malloc(sizeof(char) * (len1 + len2 + 1));
    if(!str)
        return NULL;
    len1  = 0;
    k = 0;
    while(s1[len1])
        str[k++] = s1[len1++];
    len2 = 0;
    while(s2[len2])
        str[k++] = s2[len2++];
    str[k] = '\0';
    return(str);
}
int main()
{
    ft_strjoin("", "hello");   // Expected: "hello"
    ft_strjoin("hello", "");   // Expected: "hello"
    ft_strjoin("", "");        // Expected: ""

}






















