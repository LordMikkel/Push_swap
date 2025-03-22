/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:11:10 by migarrid          #+#    #+#             */
/*   Updated: 2025/03/18 16:01:55 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus.h"

static t_fd	*get_fd_node(t_fd **head, int fd)
{
	t_fd	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_fd));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->stash = NULL;
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

static int	read_into_stash(int fd, char **stash)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (*stash == NULL)
		*stash = ft_strdup("");
	if (!*stash || !buffer)
		return (free(buffer), -1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), -1);
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = tmp;
		if (!*stash || !tmp)
			return (free(buffer), -1);
	}
	if (bytes_read == 0 && **stash == '\0')
		return (free(buffer), free(*stash), *stash = NULL, 0);
	return (free(buffer), 0);
}

static void	remove_fd_node(t_fd **head, int fd)
{
	t_fd	*prev;
	t_fd	*curr;

	prev = NULL;
	curr = *head;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev)
				prev->next = curr->next;
			else
				*head = curr->next;
			free(curr->stash);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

static char	*extract_line(char **stash)
{
	char	*newline_ptr;
	char	*line;
	char	*remaining;
	size_t	len;

	remaining = NULL;
	if (!*stash || **stash == '\0')
		return (NULL);
	newline_ptr = ft_strchr(*stash, '\n');
	if (newline_ptr)
	{
		len = newline_ptr - *stash + 1;
		line = ft_substr(*stash, 0, len);
		if (line)
			remaining = ft_strdup(newline_ptr + 1);
		if (!remaining || !line)
			return (free(line), NULL);
	}
	else
	{
		line = ft_strdup(*stash);
		if (!line)
			return (NULL);
	}
	return (free(*stash), *stash = remaining, line);
}

char	*get_next_line(int fd)
{
	static t_fd		*head;
	t_fd			*current;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = get_fd_node(&head, fd);
	if (!current)
		return (NULL);
	if (read_into_stash(fd, &(current->stash)) == -1)
	{
		remove_fd_node(&head, fd);
		return (NULL);
	}
	if (!current->stash)
	{
		remove_fd_node(&head, fd);
		return (NULL);
	}
	line = extract_line(&(current->stash));
	if (!line)
		remove_fd_node(&head, fd);
	return (line);
}
