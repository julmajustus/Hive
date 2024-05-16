/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:46:23 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/17 02:15:44 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
//
//int	main(void)
//{
//	char	*line;
//	int		line_count;
//	int		fd;
//
//	line_count = 0;
//	fd = open("bible.txt", O_RDONLY);
//	while ((line = get_next_line(fd)))
//		printf ("%d->>%s\n",line_count++, line);
//	free(line);
//	close(fd);
//}

int main(void)
{
	char *line;
    int fd1 = open("lines_around_10.txt", O_RDONLY);
    int fd2 = open("giant_line_nl.txt", O_RDONLY);
    int fd3 = open("a.out", O_RDONLY);
	int		line_count;

	line_count = 0;
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf ("%d->>%s\n",line_count++, line);
		free(line);
	}

	while ((line = get_next_line(fd2)) != NULL)
	{
		printf ("%d->>%s\n",line_count++, line);
		free(line);
	}
	
	while ((line = get_next_line(fd3)) != NULL)
	{
		printf ("%d->>%s\n",line_count++, line);
		free(line);
	}

	close(fd1);
    close(fd2);
    close(fd3);
    
    return (0);
}
