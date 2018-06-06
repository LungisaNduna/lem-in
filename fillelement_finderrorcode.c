/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillelement_finderrorcode.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:40:53 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 16:26:44 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	handlecommands(char *line, int *con)
{
	if (*con == 1 && ft_strcmp(line, "##start") == 1)
		*con = 2;
	else if (*con == 4 && ft_strcmp(line, "##start") == 1)
		*con = 21;
	else if (*con == 1 && ft_strcmp(line, "##end") == 1)
		*con = 3;
	else if (*con == 5 && ft_strcmp(line, "##end") == 1)
		*con = 31;
	else
		return (-1);
	return (0);
}

int			finderrorcode(char *line, int *con, int errorcode)
{
	if (errorcode != 0)
		return (errorcode);
	else if (line[0] == '#' && line[1] != '#')
		return (errorcode);
	else if ((*con != 1 || *con != 4) && ft_strcmp(line, "##start"))
		return (-2);
	else if ((*con != 5 || *con != 1) && ft_strcmp(line, "##end"))
		return (-3);
	else if (line[0] == '#' && line[1] == '#')
		return (handlecommand(line, *con));
	else
		return (-1);
}
