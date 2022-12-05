/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:37:55 by tlemos-m          #+#    #+#             */
/*   Updated: 2022/12/05 11:20:56 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	stretch[BUFFER_SIZE + 1];

	i = 1;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	line = ft_strjoin(0, stretch);
	if (check_stretch(stretch))
		return (line);
	while (i > 0)
	{
		i = read(fd, stretch, BUFFER_SIZE);
		if (i == -1)
			return (ft_free(line));
		if (i == 0 && line[0] == '\0')
			return (ft_free(line));
		line = ft_strjoin(line, stretch);
		if (check_stretch(stretch))
			break ;
	}
	return (line);
}
