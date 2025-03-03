/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cralarco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:29:05 by cralarco          #+#    #+#             */
/*   Updated: 2025/03/03 11:49:51 by cralarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int		counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = malloc(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*strdup_before(char *str, char c)
{
	char *sub_str;
	int i;
	int len;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c)
		len++;
	if (str[len] == c)
		len++;
	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = str[i];
		i++;
	}
	sub_str[len] = '\0';
	return (sub_str);
}

char	*strdup_after(char *str, char c)
{
	char	*sub_str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while	(str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (str[i] != '\0')
		sub_str[j++] = str[i++];
	sub_str[j] = '\0';
	return (sub_str);
}
