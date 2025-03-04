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
	buff[num_char] = '\0';
	if (num_char == 0)
		return (get_last_line(&line, buff));
	return (get_fragment_of_line(&line, buff, fd));
}

void	ft_str_free(char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
}

char	*get_fragment_of_line(char **str_line, char *str_buff, int fd)
{
	char	*str_line_before_n;
	char	*str_tmp;

	str_tmp = *str_line;
	*str_line = ft_strjoin(str_tmp, str_buff);
	free(str_buff);
	free(str_tmp);
	if (has_new_line(*str_line))
	{
		str_tmp = *str_line;
		str_line_before_n = strdup_before(*str_line, '\n');
		*str_line = strdup_after(str_tmp, '\n');
		free(str_tmp);
		return (str_line_before_n);
	}
	return (get_next_line(fd));
}

char	*get_last_line(char **str_line, char *str_buff)
{
	char	*str_tmp;
	char	*str_line_before;
	
	free(str_buff);
	if (ft_strlen(*str_line))
	{
		if (has_new_line(*str_line))
		{
			str_tmp = *str_line;
			str_line_before = strdup_before(*str_line, '\n');
			*str_line = strdup_after(str_tmp, '\n');
			free(str_tmp);
			return (str_line_before);
		}
		str_line_before = strdup_before(*str_line, '\0');
		free(*str_line);
		*str_line = NULL;
		return (str_line_before);
	}
	free(*str_line);
	*str_line = NULL;
	return (*str_line);
}

/* int main()
{
     int fd;
     char *line;

     fd = open("text.txt", O_RDONLY);
     if (fd < 0)
     {
         perror("Error opening file");
         return (1);
    }

     while ((line = get_next_line(fd)))
     {
         printf("%s\n", line);
         free(line);
     }

     close(fd);
     return (0);
 } */