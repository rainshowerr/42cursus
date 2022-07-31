/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:38:25 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/31 19:26:49 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	buff_read(int fd, char *buff)
{
	ssize_t	read_size;

	read_size = read(fd, buff, BUFFER_SIZE);
	if (read_size < 0)
	{
		free(buff);
		buff = 0;
		return (-1);
	}
	buff[read_size] = '\0';
	return (read_size);
}

static char	*meet_eof(char **backup, char *buff)
{
	char	*line;

	free(buff);
	buff = 0;
	if (ft_strlen(*backup) == 0)
	{
		free(*backup);
		*backup = 0;
		return (0);
	}
	else
	{
		line = *backup;
		*backup = 0;
		return (line);
	}
}

static char	*get_front(char	*backup)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 1;
	while (backup[i++] != '\n')
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*meet_line(char **backup, char *buff)
{
	char	*tmp;
	char	*line;

	tmp = (*backup);
	line = get_front(*backup);
	if (!line)
		return (0);
	*backup = ft_strdup(ft_strchr(*backup, '\n') + 1);
	if (!*backup)
		return (0);
	free(tmp);
	tmp = 0;
	free(buff);
	buff = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff;
	ssize_t		read_size;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	while (!(ft_strchr(backup, '\n')))
	{
		read_size = buff_read(fd, buff);
		if (read_size == -1)
			return (0);
		backup = ft_strjoin(backup, buff);
		if (!backup)
			return (0);
		if (read_size == 0)
			return (meet_eof(&backup, buff));
	}
	return (meet_line(&backup, buff));
}
