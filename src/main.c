/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 13:56:41 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/04/09 18:36:25 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gnltest.h"

int		error(char *errstr)
{
	printf("%s\n", errstr);
	return (1);
}

void	data_cleanup(char *line, t_fddata *data)
{
	free(line);
	free(data->fd);
	free(data->returnval);
	free(data->linenr);
	str2del(data->fdnames);
}

int		initial_checks(t_fddata *data, int argc, char **argv)
{
	if (argc < 2)
		return (error("No input was given."));
	if (!fds_create(argc - 1, &argv[1], data))
		return (error("An error occured while populating the fd array."));
	return (0);
}

void	print_line(t_fddata data, char *line, int namepadding, int fd_num)
{
	printf("FD:%-*s | linenr:%4d | ret:%d | %s\n", namepadding,
		data.fdnames[fd_num], data.linenr[fd_num],
		data.returnval[fd_num], line);
}

int		main(int argc, char **argv)
{
	char		*line;
	int			fd_num;
	int			namepadding;
	t_fddata	data;

	fd_num = 0;
	line = NULL;
	printf("BUFFERSIZE: %d | READEMPTYFD: %d\n", BUFFER_SIZE, READEMPTYFD);
	if (initial_checks(&data, argc, argv) == 1)
		return (1);
	namepadding = get_longestname(data.fdnames);
	while (fds_notempty(data.returnval, argc - 1))
	{
		fd_num = fds_pick(data.fd, data.returnval, fd_num, argc);
		data.linenr[fd_num] += data.returnval[fd_num];
		data.returnval[fd_num] = get_next_line(data.fd[fd_num], &line);
		print_line(data, line, namepadding, fd_num);
		free(line);
		line = NULL;
		fd_num = (rand() % (argc - 1));
	}
	data_cleanup(line, &data);
	return (0);
}
