/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmakkone <jmakkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:46:23 by jmakkone          #+#    #+#             */
/*   Updated: 2024/05/13 14:08:30 by jmakkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*line;
	int		line_count;
	int		fd;

	line_count = 0;
	fd = open("multiple_nl.txt", O_RDONLY);
	while (line_count < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		line_count++;
	}
	free(line);
	close(fd);
}
