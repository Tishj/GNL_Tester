/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/09 12:00:03 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/04/09 12:36:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gnltest.h"

void	str2del(char **str2)
{
	size_t	i;

	i = 0;
	while (str2[i])
	{
		free(str2[i]);
		i++;
	}
	free(str2);
}

size_t	get_longestname(char **fdnames)
{
	size_t	len;
	size_t	tmp;
	size_t	i;

	i = 0;
	len = 0;
	while (fdnames[i])
	{
		tmp = strlen(fdnames[i]);
		if (tmp > len)
			len = tmp;
		i++;
	}
	return (len);
}
