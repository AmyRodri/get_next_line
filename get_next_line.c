/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:17:07 by amyrodri          #+#    #+#             */
/*   Updated: 2025/08/04 10:28:18 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*extract_line_and_stash(char *line, char **stash)
{
	char	*new_line;
	int		i;

	if (!line || line[0] == '\0')
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	new_line = ft_substr(line, 0, i);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	if (line[i] != '\0')
		*stash = ft_strdup(line + i);
	else
		*stash = NULL;
	free(line);
	return (new_line);
}

char	*read_line(char *line, int fd)
{
	int			bytes;
	char		*buffer;
	char		*tmp;

	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!new_line(line) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_strjoin(line, buffer);
		free(line);
		if (!tmp)
		{
			return (NULL);
			free(buffer);
		}
		line = tmp;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash)
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
	}
	else
		line = NULL;
	line = read_line(line, fd);
	if (!line)
	{
		free(stash);
		return (stash = NULL);
	}
	if (new_line(line))
		line = extract_line_and_stash(line, &stash);
	else
		stash = NULL;
	if (!line || *line == '\0')
	{
		free(line);
		free(stash);
		return (stash = NULL);
	}
	return (line);
}
