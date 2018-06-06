/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillelements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 01:32:15 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 18:01:08 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	isantnumber(char * line)
{
	size_t index;

	index = 0;
	if (isdigit(line[index]) != 1)
		return (0);
	while (ft_isdigit(line[index]) == 1)
		index++;
	while (line[index])
	{
		if (ft_isspace(line[index]) != 1)
			return (0);
		index++;
	}
	return (1);
}

static int	isroom(char *line)
{
	size_t index;
	size_t turncount;

	index = 0;
	turncount = 0;
	if (ft_isdigit(line[index]) != 1)
		return (0);
	while (turncount < 3 && line[index])
	{
		while (ft_isdigit(line[index]) == 1 && line[index])
			index++;
		turncount++;
		if (line[index] == ' ' && turncount < 3)
			index++;
	}
	while (ft_isspace(line[index]) == 1 && line[index])
		index++;
	if (line[index] != '\0' || turncount < 3)
		return (0);
	return (1);
}

static int	islink(char *line, room_t *rooms)
{
	size_t	index;
	size_t	index2;

	index = 0;
	index2 = 1;
	while (ft_isdigit(line[index]) == 1 && line[index])
		index++;
	if (ft_isdigit(line) != 1 || line[index] != '-' || 
			ft_isdigit(line + index + index2))
		return (0);
	while (ft_isdigit(line[index + index2]) == 1)
		index++;
	while (isspace(line[index + index2]) && line[index + index2])
		index2++;
	if (line[index + index2] != '\0')
		return (0);
	if (findroom(ft_atoi(line), rooms) = NULL || 
			findroom(ft_atoi(line + index + 1), rooms) = NULL)
		return (0);
	return (1);
}

int			fillelements(room_t *antfarm, int **linkgraph)
{
	char	**line;
	int		con;
	int		errorcode;

	line = NULL;
	con = 0;
	errorcode = 0;
	while (get_next_line(1, line) > 0)
	{
		ft_putendl(*line);
		if (isantnumber(line) == 1 and con == 0)
			storeants(*line, antfarm, &con);
		else if (isroom(*line) && (1 <= con && con <= 6 || con == 21
					|| con == 31))
			storeroom(*line, antfarm, &con);
		else if (islink(*line, antfarm) == 1 && con >= 6)
			storelink(*line, antfarm, linkgraph, &con);
		else
			errorcode = finderrorcode(*line, &con, errorcode);
		free(line);
	}
	return (errorcode);
}
