/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguruge <sguruge@student.42tokyo.jp>       #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-11 12:54:22 by sguruge           #+#    #+#             */
/*   Updated: 2025-05-11 12:54:22 by sguruge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_next_line(int fd)
{
	static size_t	location = 0;
	static char		*buffer = NULL;
	t_gnl			gnl;
	char			*result;
	char			*init;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > REASONABLE_SIZE)
		return (NULL);
	gnl.line = NULL;
	gnl.temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!gnl.temp)
		return (NULL);
	if (!buffer)
	{
		init = ft_calloc(1, sizeof(char));
		if (!init)
			return (free(gnl.temp), NULL);
		buffer = init;
	}
	result = gnl_read_process(fd, &gnl, &buffer, &location);
	free(gnl.temp);
	return (result);
}

char	*gnl_read_process(int fd, t_gnl *gnl, char **buf, size_t *loc)
{
	ssize_t	read_b;

	*gnl = gnl_process_buffer(*gnl, *loc, *buf, ft_strlen(*buf));
	if (gnl->line)
	{
		*loc = gnl->i + 1;
		return (gnl->line);
	}
	read_b = read(fd, gnl->temp, BUFFER_SIZE);
	while (read_b > 0)
	{
		gnl->temp[read_b] = '\0';
		*buf = ft_strjoin(*buf, gnl->temp);
		if (!*buf)
			return (NULL);
		*gnl = gnl_process_buffer(*gnl, *loc, *buf, ft_strlen(*buf));
		if (gnl->line)
		{
			*loc = gnl->i + 1;
			return (gnl->line);
		}
		read_b = read(fd, gnl->temp, BUFFER_SIZE);
	}
	return (gnl_handle_eof(gnl, buf, loc, read_b));
}

t_gnl	gnl_process_buffer(t_gnl gnl, size_t loc, char *buf, size_t buf_len)
{
	gnl.i = loc;
	if (!buf || buf_len == 0)
	{
		gnl.line = NULL;
		return (gnl);
	}
	while (gnl.i < buf_len)
	{
		if (buf[gnl.i] == '\n')
		{
			gnl.line = ft_substr(buf, loc, gnl.i - loc + 1);
			return (gnl);
		}
		gnl.i++;
	}
	gnl.line = NULL;
	return (gnl);
}

char	*gnl_handle_eof(t_gnl *gnl, char **buffer, size_t *loc, ssize_t read_b)
{
	if (read_b == 0 && *buffer && (*buffer)[*loc])
	{
		gnl->line = ft_strdup(*buffer + *loc);
		free(*buffer);
		*buffer = NULL;
		*loc = 0;
		return (gnl->line);
	}
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	*loc = 0;
	return (NULL);
}

void	*ft_memset_gnl(void *s, int c, size_t n)
{
	unsigned char	*char_s;
	unsigned char	char_c;
	size_t			i;

	char_s = (unsigned char *)s;
	char_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		char_s[i] = char_c;
		i++;
	}
	return (s);
}

// #include <fcntl.h>
// #include <stdio.h>

// void	test_file(const char *filename)
// {
// 	int		fd;
// 	char	*line;
// 	int		line_count;

// 	fd = open(filename, O_RDONLY);
// 	// fd = 100;
// 	line_count = 0;
// 	printf("\n--- Testing: %s ---\n", filename);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line %d: %s", line_count++, line);
// 		free(line); // メモリ解放を忘れずに
// 	}
// 	close(fd);
// 	printf("\nTotal lines: %d\n", line_count);
// }

// int	main(void)
// {
// 	const char	*filename1 = "test1.txt";

// 	// const char *filename2 = "test2.txt";
// 	// const char *filename3 = "test3.txt";
// 	// const char *filename4 = "test4.txt";
// 	// const char *filename5 = "test5.txt";
// 	printf("=== Testing files ===\n");
// 	test_file(filename1);
// 	// test_file(filename2);
// 	// test_file(filename3);
// 	// test_file(filename4);
// 	// test_file(filename5);
// 	printf("\n=== All tests completed ===\n");
// 	return (0);
// }

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char *line;
// 	int i = 0;

// 	while ((line = get_next_line(0)) != NULL) // 0がstdin
// 	{
// 		printf("line: %s", line);
// 		free(line); // 解放を忘れずにね
// 		i++;
// 		printf("%d", i);
// 	}
// 	printf("EOFに到達したよ…バイバイ\n");
// 	return (0);
// }