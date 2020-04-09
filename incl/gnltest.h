/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnltest.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/09 11:58:33 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/04/09 17:40:08 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNLTEST_H
# define GNLTEST_H

# include "get_next_line.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# ifndef READEMPTYFD
#  define READEMPTYFD 0
# endif
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_fddata
{
	int			*returnval;
	int			*linenr;
	char		**fdnames;
	int			*fd;
}				t_fddata;

void	str2del(char **str2);
size_t	get_longestname(char **fdnames);
int		fds_valid(int *fd, size_t amount);
int		*fds_create(size_t amnt, char **argv, t_fddata *data);
int		fds_notempty(int *ret, size_t amount);
int		fds_pick(int *fd, int *returnval, int fd_num, int argc);

#endif
