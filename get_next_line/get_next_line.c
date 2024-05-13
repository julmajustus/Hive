/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:36:32 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/13 13:17:57 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static char	*read_fd(int fd, char *read_buf, char *static_buf)
{
	ssize_t read_count;
	char	*tmp;

	read_count = 1;
	while (read_count)
	{
		read_count = read(fd, read_buf, BUFFER_SIZE);
		if (read_count == -1)
			return (ft_free(&static_buf), NULL);
		if (read_count == 0)
			break ;
		read_buf[read_count] = '\0';
		//		printf("read_count %ld\n", read_count);
		if (!static_buf)
		{
			static_buf = ft_strdup("");
			if (!static_buf)
				return(NULL);
		}
		tmp = static_buf;
		static_buf = ft_strjoin(tmp, read_buf);
		ft_free(&tmp);
		if (!static_buf)
			return (ft_free(&static_buf), NULL);
		if (read_buf[read_count - 1] == '\n')
			break ;
	}	
	//	printf("read_count %ld\n", read_count);
	//	printf("static_buf content after reading fd >> '%s'\n", static_buf);
	return (static_buf);
}

static char	*rm_line(char *line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!line || !*line)
		return (ft_free(&line), ft_free(&tmp), NULL);
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	//	if (line[i] == '\0' || line[1] == '\0')
	//		return (NULL);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	//	printf("rm_line_check");
	if (!tmp || !*tmp)
	{
		ft_free(&tmp);
		return (NULL);
	}
	//	printf("rm_line_line2 check %s\n", line);
	line[i + 1] = '\0';
	//	printf("rm_line_line3 check %s\n", line);
	return (tmp);
}
char	*get_next_line(int fd)
{
	static char	*static_buf;
	char		read_buf[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
//	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
//	if (!read_buf)
//		return (NULL);
	line = read_fd(fd, read_buf, static_buf);
//	ft_free(&read_buf);
//	if (!line)
//	{
//		ft_free(&line);
//		ft_free(&static_buf);
//		return (NULL);
//	}
	//	printf("get_next_line line check1 %s\n", line);
	static_buf = rm_line(line);
	if (!static_buf || !*static_buf)
	{
		ft_free(&static_buf);
	}
	return (line);

}
