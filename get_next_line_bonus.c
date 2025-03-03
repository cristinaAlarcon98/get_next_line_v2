#include "get_next_line_bonus.h"




char *get_next_line(int fd)
{
    static char *line[1000];
    char *buff;
    int num_char;

    if (fd < 0 || BUFFSIZE <= 0)
        return NULL;
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
        return get_last_line(&line[fd], buff);
       

    return get_fragment_of_line(&line[fd], buff, fd);
 
}


char *get_fragment_of_line(char **str_line, char *str_buff, int fd)
{
    char *new_line;
    char *str_line_before_n;
    char *str_line_after_n;

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
    return get_next_line(fd);
}

char *get_last_line(char **str_line, char *str_buff)
{
    char *str_tmp;
    char *str_line_before_n;
    char *str_line_after_n;
    char *str_line_before_z;


   if (ft_strlen(*str_line))
   {
        if (has_new_line(*str_line))
        {   
            
            *str_line = ft_strjoin(str_tmp, str_buff);
            free(str_buff);
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




// int main()
// {
//     int fd;
//     char *line;

//     fd = open("text.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     while ((line = get_next_line(fd)))
//     {
//         printf("%s\n", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }
