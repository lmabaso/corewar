#include "libft.h"

int			ft_read_memory(const int fd, unsigned char **line)
{
	unsigned char	*str = NULL;
	// int		    *next_line;
	int			        readchars;
    // unsigned char	    *buff;

	if ((!str && !(str = (unsigned char *)malloc(sizeof(*str)))) ||
			!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
    readchars = read(fd, str, BUFF_SIZE);

	*line = str;
	free(str);
	return (readchars);
}