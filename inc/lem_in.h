/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 15:22:09 by lnduna            #+#    #+#             */
/*   Updated: 2018/09/30 15:38:18 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <stdio.h>

typedef	struct		s_link
{
	int				**link_matrix;
	int				num_of_rooms;
}					t_link;

typedef	struct		s_room
{
	char			*room_name;
	int				room_no;
	char			*ants;
	int				xpos;
	int				ypos;
	struct s_room	*next;
}					t_room;

typedef struct		s_map
{
	size_t			num_of_routes;
	size_t			num_of_rooms;
	char 			**map;
}					t_map;

int					read_and_store(t_room *antfarm, t_link *links);
void				store_ants(char *line, t_room *antfarm, int *con);
void				store_room(char *line, t_room *antfarm, int *con);
void				store_link(char *line, t_room *af, t_link *lnks, int *con);
int					check_elements(t_room *antfarm, t_link *links);

t_map				*find_routes(t_link *links);
t_map				*create_map(char **route_matrix, int num_of_rooms);

int					count_rooms(t_room *rooms);
int					count_routes(char **route_matrix);

t_room				*return_room_by_name(t_room *room, char *room_to_find);
t_room				*return_room_by_index(t_room *room, int room_to_find);
int					check_room_by_name(t_room *room, char *room_to_find);
int					check_room_by_index(t_room *room, int room_to_find);
char				*get_room_name_by_index(t_room *antfarm, int room_index);

void				move_ants(t_room *antfarm, char *path);
int					endprog(int errorno, t_room *rooms, t_link *links, t_map *map);

void				print_rooms(t_room *rooms);
void				print_links(t_link *links);
void				print_artifacts(t_room *rooms, t_link *links, t_map *map);

#endif
