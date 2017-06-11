/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 01:05:14 by elee              #+#    #+#             */
/*   Updated: 2016/12/15 15:45:54 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_room		*room_by_num(t_room **rooms, int num)
{
	int		i;

	if (!rooms)
		return (NULL);
	i = -1;
	while (rooms[++i])
		if (rooms[i]->num == num)
			return (rooms[i]);
	return (NULL);
}

t_room		*room_by_name(t_room **rooms, char *name)
{
	int		i;

	if (!rooms)
		return (NULL);
	i = -1;
	while (rooms[++i])
		if (!ft_strcmp(rooms[i]->name, name))
			return (rooms[i]);
	return (NULL);
}

t_room		*min_vertex(t_room **rooms, int *dist)
{
	int		i;
	int		min;
	int		num;

	if (!rooms)
		return (NULL);
	min = 2147483647;
	i = -1;
	num = -1;
	while (rooms[++i])
		if (dist[rooms[i]->num] < min && (num = i) >= 0)
			min = dist[rooms[i]->num];
	return ((num > -1) ? rooms[num] : NULL);
}

static int	connected(t_farm *farm, int inter, int *prev)
{
	int		end;

	end = farm->end->num;
	while (end != inter && end != -1)
		end = prev[end];
	if (end == inter)
		return (1);
	return (0);
}

t_room		*find_dest(t_farm *farm, int pos, int *prev)
{
	int		i;
	int		j;
	int		min_index;

	min_index = -1;
	i = -1;
	while (++i < farm->n_rooms)
		if (prev[i] == pos && connected(farm, i, prev)
		&& (!room_by_num(farm->rooms, i)->n_ants ||
			room_by_num(farm->rooms, i)->end))
			min_index = i;
	j = -1;
	while (farm->rooms[++j])
		if (farm->rooms[j]->num == min_index)
			return (farm->rooms[j]);
	return (NULL);
}
