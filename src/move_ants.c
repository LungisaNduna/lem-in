/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 13:18:00 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:46:30 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	**get_room_names(char *path, t_room *antfarm)
{
	size_t	index;
	char	**path_room_names;
	char	**path_room_num;
	int		room_num;

	path_room_num = ft_strsplit(path, '-');
	path_room_names = (char **)malloc(sizeof(char *) *
			ft_count_2dlines(path_room_num));
	index = 1;
	while (path_room_num[index])
	{
		room_num = ft_atoi(path_room_num[index]);
		path_room_names[index - 1] = get_room_name_by_index(antfarm, room_num);
		index++;
	}
	path_room_names[index - 1] = NULL;
	ft_freestrarr(path_room_num);
	return (path_room_names);
}

static void	print_move(char *room_name, int ant)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putendl(room_name);
}

void		move_ants(t_room *antfarm, char *path)
{
	char	**path_room_names;
	int		ant;
	int		num_of_ants;
	int		room_index;

	path_room_names = get_room_names(path, antfarm);
	ant = 1;
	num_of_ants = (int)(antfarm->ants[ft_strlen(antfarm->ants) - 1] - 48);
	while (ant <= num_of_ants)
	{
		room_index = 0;
		while (path_room_names[room_index])
		{
			print_move(path_room_names[room_index], ant);
			room_index++;
		}
		ant++;
	}
	free(path_room_names);
}
