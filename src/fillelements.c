/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillelements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:25:01 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:43:44 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		is_ant_declaration(char *line)
{
	size_t	index;

	index = 0;
	if (!ft_isdigit(line[index]))
		return (0);
	while (line[index] && ft_isdigit(line[index]))
		index++;
	if (index == 0)
		return (0);
	while (line[index] && ft_isspace(line[index]))
		index++;
	return (line[index] == '#' || line[index] == '\0');
}

static int		is_room_declaration(char *line)
{
	size_t	index;
	size_t	num_count;

	index = 0;
	num_count = 0;
	while (line[index] && !ft_isspace(line[index]))
		index++;
	if (line[index] != '\0' && line[index] == ' ')
		index++;
	else
		return (0);
	while (line[index])
	{
		while (line[index] && line[index] != '#' && ft_isdigit(line[index]))
			index++;
		num_count++;
		if (line[index] == ' ')
			index++;
	}
	while (line[index] && ft_isspace(line[index]))
		index++;
	return (num_count == 2 &&(line[index] == '#' || line[index] == '\0'));
}

static int		is_link_declaration(char *line, t_room *antfarm)
{
	size_t	index;
	size_t	index2;
	char	*room_name;

	index = 0;
	while (line[index] && line[index] != '#' && line[index] != '-')
		index++;
	room_name = ft_strsub(line, 0, index);
	if (check_room_by_name(antfarm, room_name) && line[index] == '-')
		index++;
	else
		return (0);
	index2 = 0;
	while (line[index + index2] && line[index + index2] != ' ')
		index2++;
	room_name = ft_strsub(line + index, 0, index2);
	if (!check_room_by_name(antfarm, room_name))
		return (0);
	else
		index = index + index2;
	while (line[index] && ft_isspace(line[index]))
		index++;
	return (line[index] == '#' || line[index] == '\0');
}

static int		find_error_code(char *line, int *con, int error_code)
{
	if ((error_code) || (line[0] == '#' && line[0] != '\0'&& line[1] != '#'))
		return (error_code);
	else if (*con == 1 && ft_strnequ(line, "##start", 7))
		*con = 2;
	else if (*con == 1 && ft_strnequ(line, "##end", 5))
		*con = 3;
	else if (*con == 5 && ft_strnequ(line, "##start", 7))
		*con = 21;
	else if (*con == 4 && ft_strnequ(line, "##end", 5))
		*con = 31;
	else if (*con > 1 && *con != 5 && ft_strnequ(line, "##start", 7))
		return (-3);
	else if (*con > 1 && *con != 4 && ft_strnequ(line, "##end", 5))
		return (-4);
	else
		return (-10);
	return (error_code);
}

int				read_and_store(t_room *antfarm, t_link *links)
{
	char	*line;
	static int	con = 0;
	static int	error_code = 0;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_putnbr(con);
		ft_putchar('\t');
		ft_putendl(line);
		if (con == 0 && is_ant_declaration(line) == 1)
			store_ants(line, antfarm, &con);
		else if (((0 < con && con < 7) || con == 21 || con == 31) &&
				error_code >= 0 && is_room_declaration(line))
			store_room(line, antfarm, &con);
		else if (error_code >= 0 && (con == 6 || con == 7) &&
				is_link_declaration(line, antfarm))
			store_link(line, antfarm, links, &con);
		else
			error_code = find_error_code(line, &con, error_code);
		free(line);
	}
	ft_putchar('\n');
	return (error_code);
}
