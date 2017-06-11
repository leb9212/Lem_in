/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 01:05:10 by elee              #+#    #+#             */
/*   Updated: 2016/12/15 04:16:01 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_room	*copy_room(t_room *room)
{
	t_room	*new;

	if (!room)
		return (NULL);
	new = (t_room*)malloc(sizeof(t_room));
	new->name = ft_strdup(room->name);
	new->num = room->num;
	new->x = room->x;
	new->y = room->y;
	new->start = room->start;
	new->end = room->end;
	new->n_ants = room->n_ants;
	return (new);
}

t_link	*copy_link(t_link *link)
{
	t_link	*new;

	if (!link)
		return (NULL);
	new = (t_link*)malloc(sizeof(t_link));
	new->start = ft_strdup(link->start);
	new->end = ft_strdup(link->end);
	return (new);
}

t_room	**copy_rooms(t_room **rooms)
{
	t_room	**new;
	int		num;
	int		i;

	if (!rooms)
		return (NULL);
	num = num_room(rooms);
	new = (t_room**)malloc(sizeof(t_room*) * (num + 1));
	new[num] = NULL;
	i = -1;
	while (rooms[++i])
		new[i] = copy_room(rooms[i]);
	return (new);
}

t_room	**add_room(t_farm *farm, t_room **rooms, t_room *add)
{
	t_room	**temp;
	int		num;
	int		i;

	num = farm->n_rooms;
	temp = (t_room**)malloc(sizeof(t_room*) * (num + 1));
	temp[num] = NULL;
	if (rooms)
	{
		i = -1;
		while (rooms[++i])
			temp[i] = copy_room(rooms[i]);
		temp[i] = copy_room(add);
	}
	else
		temp[0] = copy_room(add);
	free_rooms(rooms);
	return (temp);
}

t_link	**add_link(t_farm *farm, t_link **links, t_link *add)
{
	t_link	**temp;
	int		num;
	int		i;

	num = farm->n_links;
	temp = (t_link**)malloc(sizeof(t_link*) * (num + 1));
	temp[num] = NULL;
	if (links)
	{
		i = -1;
		while (links[++i])
			temp[i] = copy_link(links[i]);
		temp[i] = copy_link(add);
	}
	else
		temp[0] = copy_link(add);
	free_links(links);
	return (temp);
}
