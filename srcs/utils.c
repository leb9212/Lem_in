/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 01:05:14 by elee              #+#    #+#             */
/*   Updated: 2016/12/15 01:04:24 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

void	error_msg(char *msg, t_farm *farm, int num)
{
	(g_color) ? ft_printf("\e[31m") : 0;
	if (num == -2)
		ft_putendl_fd("ERROR: Invalid option given", 2);
	else if (!g_debug)
		ft_putendl_fd("ERROR", 2);
	else
	{
		if (num != -1)
		{
			ft_putstr_fd("ERROR (Line #", 2);
			ft_putnbr_fd(num + 1, 2);
			ft_putstr_fd("): ", 2);
			ft_putendl_fd(msg, 2);
		}
		else
		{
			ft_putstr_fd("ERROR: ", 2);
			ft_putendl_fd(msg, 2);
		}
	}
	free_farm(farm);
	exit(0);
}

int		stop_msg(char *msg, char **parts, int num)
{
	(g_color) ? ft_printf("\e[31m") : 0;
	if (g_debug)
	{
		if (num != -1)
		{
			ft_printf("WARNING (Line #%d): %s ", num + 1, msg);
			ft_printf("so lem-in will proceed with lines read so far\n");
		}
		else
		{
			ft_printf("WARNING: %s ", msg);
			ft_printf("so lem-in will proceed with lines read so far\n");
		}
	}
	if (parts)
		ft_free_two(parts);
	return (1);
}

int		is_start_end(char *line)
{
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		return (1);
	return (0);
}

int		is_room(char **parts, t_farm *farm)
{
	int		i;

	i = -1;
	if (!farm || !parts || !parts[0] || !parts[1])
		return (0);
	while (farm->rooms[++i])
	{
		if (!ft_strcmp(farm->rooms[i]->name, parts[0]))
			return (1);
		if (!ft_strcmp(farm->rooms[i]->name, parts[1]))
			return (1);
	}
	return (0);
}

int		num_room(t_room **rooms)
{
	int		i;

	i = 0;
	if (!rooms)
		return (0);
	while (rooms[i])
		i++;
	return (i);
}
