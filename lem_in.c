/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 21:10:02 by lnduna            #+#    #+#             */
/*   Updated: 2017/11/28 18:00:34 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	printerror(int errorno)
{
	if (errorno == 0)
		ft_putendl("Could not open the file");
	else if (errorno == -1)
		ft_putendl("Invalid file format");
	else if (errorno == -2)
		ft_putendl("Invalid file : multiple start commands");
	else if (errorno == -3)
		ft_putendl("Invalid file : multiple end commands");
	else if (errorno == -4)
		ft_putendl("Invalid file : no ants given in document");
	else if (errorno == -5)
		ft_putendl("Invalid file : insufficient rooms assigned
				in the document");
	else if (errorno == -6)
		ft_putendl("Invalid file : no links given int the document");
	else if (errorno == -7)
		ft_putendl("Invalid file : multiple rooms in the same spot");
	else if (errorno == -8)
		ft_putendl("Invalid map : no routes found");
	else if (errorno == -9)
		ft_putendl("Whoops, memory allocation problem");
	return (-1);
}

static char	getfilename(int numberofargs, char **args)
{
	if (numberofargs == 1 && ft_strncmp(args[0], "./lem_in<", 9) == 0)
		return (&args[0][9]);
	else if (numberofargs == 2 && ft_strcmp(args[0], "./lem_in") == 0)
	{
		if (ft_strncmp(args[1], "<", 1) == 0 && ft_strlen(args[1]) > 2)
			return (&args[1][1]);
		else
			return (args[1]);
	}
	else if (numberofargs == 2 && ft_strcmp(args[0], "./lem_in<") == 0)
		return (args[1]);
	else if (numberofargs == 3)
		return (args[2]);
	else
		return (NULL);
}

int		main(int argc, char **argv)
{
	int		*linkgraph;
	room_t	*antfarm;
	path_t	*routes;
	int		errorno;

	
	linkgraph = NULL;
	if (!antfarm = (room_t *)malloc(sizeof(room_t)))
		return (printerror(-9));
	if (errorno = fillelements(antfarm, linkgraph) < 0)
		return (printerror(errorno));
	if (errorno = checkallelements(antfarm, linkgraph) < 0)
		return (printerror(errorno));
	if (routes = findpathways(antfarm, linkgraph) == NULL)
		return (printerror(errorno));
	if (errorno = gruntworker(antfarm, routes) < 0)
		return (printerror(errorno));
	return (0);
}
