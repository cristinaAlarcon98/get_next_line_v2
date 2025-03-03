/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cralarco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:14:19 by cralarco          #+#    #+#             */
/*   Updated: 2025/03/03 11:28:35 by cralarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	int			num_char;

	if (fd < 0 || BUFFSIZE <= 0)
		return (NULL);
	buff = malloc(BUFFSIZE + 1);
	if (!buff)
		return (NULL);
	num_char = read(fd, buff, BUFFSIZE);
	if (num_char < 0)
	{
		free(buff);
		return (NULL);
	}
	if (num_char == 0)
		return (get_last_line(&line, buff));
	return (get_fragment_of_line(&line, buff, fd));
}

char	*get_fragment_of_line(char **str_line, char *str_buff, int fd)
{
	char	*new_line;
	char	*str_line_before_n;
	char	*str_line_after_n;

	if (*str_line == NULL)
		*str_line = "";
	new_line = ft_strjoin(*str_line, str_buff);
	free(str_buff);
	*str_line = new_line;
	if (has_new_line(*str_line))
	{
		str_line_before_n = strdup_before(*str_line, '\n');
		str_line_after_n = strdup_after(*str_line, '\n');
		free(*str_line);
		*str_line = str_line_after_n;
		return (str_line_before_n);
	}
	return (get_next_line(fd));
}

char	*get_last_line(char **str_line, char *str_buff)
{
	char	*new_line;
	char	*str_line_before_n;
	char	*str_line_after_n;
	char	*str_line_before_z;

	if (ft_strlen(*str_line))
	{
		new_line = ft_strjoin(*str_line, str_buff);
		free(str_buff);
		*str_line = new_line;
		if (has_new_line(*str_line))
		{
			str_line_before_n = strdup_before(*str_line, '\n');
			str_line_after_n = strdup_after(*str_line, '\n');
			free(*str_line);
			*str_line = str_line_after_n;
			return (str_line_before_n);
		}
		str_line_before_z = strdup_before(*str_line, '\0');
		free(*str_line);
		*str_line = NULL;
		return (str_line_before_z);
	}
	free (*str_line);
	*str_line = NULL;
	return (*str_line);
}
