/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:16:49 by elee              #+#    #+#             */
/*   Updated: 2016/12/15 14:10:57 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_farm	*init_farm(void)
{
	t_farm	*farm;

	farm = (t_farm*)malloc(sizeof(t_farm));
	farm->map = NULL;
	farm->n_ants = 0;
	farm->n_rooms = 0;
	farm->n_links = 0;
	farm->ants = NULL;
	farm->rooms = NULL;
	farm->links = NULL;
	farm->start = NULL;
	farm->end = NULL;
	return (farm);
}

void	init_rooms(t_farm *farm, char **parts, int startend)
{
	t_room	*room;

	farm->n_rooms += 1;
	room = (t_room*)malloc(sizeof(t_room));
	room->name = ft_strdup(parts[0]);
	room->num = farm->n_rooms - 1;
	room->x = ft_atoi(parts[1]);
	room->y = ft_atoi(parts[2]);
	room->start = (startend < 0) ? 1 : 0;
	room->end = (startend > 0) ? 1 : 0;
	room->n_ants = 0;
	farm->rooms = add_room(farm, farm->rooms, room);
	free_room(room);
	ft_free_two(parts);
}

void	init_links(t_farm *farm, char **parts)
{
	t_link	*link;

	farm->n_links += 1;
	link = (t_link*)malloc(sizeof(t_link));
	link->start = ft_strdup(parts[0]);
	link->end = ft_strdup(parts[1]);
	farm->links = add_link(farm, farm->links, link);
	free_link(link);
	ft_free_two(parts);
}

void	check_start_end(t_farm *farm)
{
	if (g_ns == 0 && g_ne == 0)
		error_msg("No start and end rooms specified", farm, -1);
	else if (g_ns == 0 && g_ne == 1)
		error_msg("No start room specified", farm, -1);
	else if (g_ns == 0 && g_ne > 1)
		error_msg("No start room specified and too many start rooms specified",
					farm, -1);
	else if (g_ns == 1 && g_ne == 0)
		error_msg("No end room specified", farm, -1);
	else if (g_ns == 1 && g_ne == 1)
		return ;
	else if (g_ns == 1 && g_ne > 1)
		error_msg("Too many end rooms specified", farm, -1);
	else if (g_ns > 1 && g_ne == 0)
		error_msg("Too many start rooms specified and no end room specified",
					farm, -1);
	else if (g_ns > 1 && g_ne == 1)
		error_msg("Too many start rooms specified", farm, -1);
	else if (g_ns > 1 && g_ne > 1)
		error_msg("Too many start rooms and too many end rooms specified", farm,
					-1);
}

void	final_init(t_farm *farm)
{
	int		i;
	int		j;

	i = -1;
	while (farm->rooms[++i])
	{
		if (farm->rooms[i]->start)
		{
			farm->rooms[i]->n_ants = farm->n_ants;
			farm->start = farm->rooms[i];
			j = -1;
			while (farm->ants[++j])
				farm->ants[j]->pos = i;
		}
		if (farm->rooms[i]->end)
			farm->end = farm->rooms[i];
	}
}
