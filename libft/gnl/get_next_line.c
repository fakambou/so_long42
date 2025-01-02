/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakambou <fakambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:41:04 by fakambou          #+#    #+#             */
/*   Updated: 2024/12/10 16:39:03 by fakambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

char	*ft_join(char *stash, char *s)
{
	char	*tmp;

	tmp = ft_strjoin(stash, s);
	free(stash);
	return (tmp);
}

char	*ft_read(int fd, char *stash)
{
	char	*s;
	int		bytes;

	if (!stash)
		stash = ft_strdup("");
	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, s, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(s);
			free(stash);
			return (NULL);
		}
		s[bytes] = '\0';
		stash = ft_join(stash, s);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(s);
	return (stash);
}

char	*ft_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_extract_line(char *stash)
{
	int		j;
	int		i;
	char	*new_stash;

	i = 0;
	while (stash && stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	j = 0;
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_line(stash);
	stash = ft_extract_line(stash);
	if (!line || line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}

// int main()
// {
// 	int fd = open("get_next_line.c", O_RDONLY);
// 	char	*line;

// 	while(1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		printf("line :%s", line);
// 		free (line);
// 	}
// }