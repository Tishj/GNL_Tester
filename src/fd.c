/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fd.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/09 12:06:29 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/04/09 17:23:42 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gnltest.h"

int		fds_pick(int *fd, int *returnval, int fd_num, int argc)
{
	if (READEMPTYFD == 0)
	{
		while (!returnval[fd_num])
			fd_num = (rand() % (argc - 1));
	}
	else
		fd_num = (rand() % (argc - 1));
	return (fd_num);
}

int		fds_valid(int *fd, size_t amount)
{
	size_t	i;

	i = 0;
	while (i < amount)
	{
		if (read(fd[i], (void *)0, 0) == -1)
			return (0);
		i++;
	}
	return (1);
}

int		*fds_create(size_t amnt, char **argv, t_fddata *data)
{
	int		*fds;
	size_t	i;
	char	*fdnamestart;

	i = 0;
	printf("Amount of FDs: %ld\n", amnt);
	data->fd = malloc(sizeof(int) * amnt);
	data->returnval = malloc(sizeof(int) * amnt);
	data->linenr = malloc(sizeof(int) * amnt);
	data->fdnames = malloc(sizeof(char *) * (amnt + 1));
	if (!data->fd || !data->fdnames || !data->returnval || !data->linenr)
		return (NULL);
	while (i < amnt)
	{
		data->fd[i] = open(argv[i], O_RDONLY);
		fdnamestart = strrchr(argv[i], '/');
		data->fdnames[i] = (fdnamestart) ? strdup(fdnamestart + 1)
							: strdup(argv[i]);
		data->returnval[i] = 1;
		data->linenr[i] = 0;
		i++;
	}
	data->fdnames[i] = 0;
	return (!fds_valid(data->fd, amnt)) ? (NULL) : (data->fd);
}

int		fds_notempty(int *ret, size_t amount)
{
	size_t	i;

	i = 0;
	while (i < amount && ret[i] == 0)
		i++;
	if (i >= amount)
		return (0);
	return (1);
}
