/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:12:15 by elee              #+#    #+#             */
/*   Updated: 2016/12/14 23:06:40 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int		free_room(t_room *room)
{
	if (room)
	{
		free(room->name);
		free(room);
		return (1);
	}
	return (0);
}

int		free_rooms(t_room **rooms)
{
	int		i;

	if (rooms)
	{
		i = -1;
		while (rooms[++i])
			free_room(rooms[i]);
		free(rooms);
		return (1);
	}
	return (0);
}

int		free_link(t_link *link)
{
	if (link)
	{
		free(link->start);
		free(link->end);
		free(link);
		return (1);
	}
	return (0);
}

int		free_links(t_link **links)
{
	int		i;

	if (links)
	{
		i = -1;
		while (links[++i])
			free_link(links[i]);
		free(links);
		return (1);
	}
	return (0);
}

int		free_farm(t_farm *farm)
{
	int		i;

	(g_start) ? free(g_start) : 0;
	(g_end) ? free(g_end) : 0;
	if (farm)
	{
		if (farm->ants)
		{
			i = -1;
			while (farm->ants[++i])
				free(farm->ants[i]);
			free(farm->ants);
		}
		free_rooms(farm->rooms);
		free_links(farm->links);
		ft_free_two(farm->map);
		free(farm);
		return (1);
	}
	return (0);
}
