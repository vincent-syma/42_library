/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:01:49 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/11 18:59:02 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static void	*free_stash(char **stash);
static int	read_to_stash(int fd, char **stash, char *buffer);
static char	*extract_line_trim_stash(char **stash);

/**
 * @brief Reads and returns a line read from a file descriptor (file / stdin).
 * Uses malloc, frees itself.
 * @param fd File descriptor.
 * @return Last line read / NULL if empty or error.
 */
char	*get_next_line(int fd)
{
	static char		*stash[MAX_FD];
	char			*buffer;
	char			*next_line;
	ssize_t			bytes;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
		stash[fd] = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_stash(&stash[fd]));
	bytes = read_to_stash(fd, &stash[fd], buffer);
	free(buffer);
	if (bytes < 0)
		return (free_stash(&stash[fd]));
	next_line = extract_line_trim_stash(&stash[fd]);
	return (next_line);
}

/**
 * @brief Frees char *stash, if it is allocated and sets it to NULL.
 * @return NULL.
 */
static void	*free_stash(char **stash)
{
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

/**
 * @brief If stash does not contain a newline,
 * it is filled with new read to buffer.
 * @param fd File descriptor.
 * @return 0 if nothing is read, -1 on reading error,
 * otherwise number of bytes read.
 */
static int	read_to_stash(int fd, char **stash, char *buffer)
{
	char		*tmp;
	ssize_t		bytes;
	ssize_t		start;

	tmp = NULL;
	bytes = 0;
	start = 0;
	if (!stash || !*stash)
		return (0);
	while (!ft_strchr(*stash + start, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (bytes);
		buffer[bytes] = 0;
		tmp = ft_strjoin(*stash, buffer);
		if (!tmp)
			return (-1);
		free(*stash);
		*stash = tmp;
		start = ft_strlen(*stash) - bytes;
	}
	return (1);
}

/**
 * @brief Reads the stash and returns the first line ended with a newline
 * or the whole stash if the input is not ended with a newline.
 *
 * It also modifies the stash (trims the returned part).
 * @return First line from stash / end of the stash / NULL if empty or error.
 */
static char	*extract_line_trim_stash(char **stash)
{
	char	*new_stash;
	char	*line;
	int		line_len;

	if (!stash || !*stash || **stash == 0)
		return (free_stash(stash));
	line_len = 0;
	while ((*stash)[line_len] && (*stash)[line_len] != '\n')
		line_len++;
	if ((*stash)[line_len] == '\n')
		line_len++;
	line = ft_substr(*stash, 0, line_len);
	if (!line)
		return (free_stash(stash));
	new_stash = ft_strdup(*stash + line_len);
	free(*stash);
	if (!new_stash)
	{
		*stash = NULL;
		return (line);
	}
	*stash = new_stash;
	return (line);
}
