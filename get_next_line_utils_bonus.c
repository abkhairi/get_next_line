/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:33:26 by abkhairi          #+#    #+#             */
/*   Updated: 2023/03/23 14:38:55 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	s2 = malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		c;
	int		c2;

	if (!s1)
		s1 = ft_strdup("");
	i = 0;
	c = ft_strlen(s1);
	c2 = ft_strlen(s2);
	join = (char *) malloc(c + c2 +1);
	if (join == NULL)
		return (NULL);
	ft_memcpy(join, s1, c);
	ft_memcpy(join + c, s2, c2 + 1);
	free (s1);
	return (join);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (*s == 0 || start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s) || (start + len > ft_strlen(s)))
		len = ft_strlen(s) - start;
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < len && start < ft_strlen(s))
		str[j++] = s[start++];
	str[j] = '\0';
	return (str);
}
