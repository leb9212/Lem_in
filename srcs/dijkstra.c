/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:14:20 by elee              #+#    #+#             */
/*   Updated: 2017/05/16 01:18:23 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static t_room	**setup(t_farm *farm, t_room *start, int *dist, int *prev)
{
	t_room	**set;
	int		i;

	set = copy_rooms(farm->rooms);
	i = -1;
	while (set[++i])
	{
		dist[i] = 2147483647;
		if (i == start->num)
			dist[i] = 0;
		prev[i] = -1;
	}
	return (set);
}

static void		dijkstra_loop(t_farm *farm, t_room **set, t_room *u, int **p)
{
	int		alt;
	t_room	*v;

	v = NULL;
	if (!ft_strcmp(farm->links[p[0][0]]->start, u->name))
		v = room_by_name(set, farm->links[p[0][0]]->end);
	else if (!ft_strcmp(farm->links[p[0][0]]->end, u->name))
		v = room_by_name(set, farm->links[p[0][0]]->start);
	if (v)
	{
		alt = p[1][u->num] + 1;
		alt += (g_vs && u->n_ants) ? g_vs[u->num][v->num] : 0;
		(alt < p[1][v->num]) ? (p[2][v->num] = u->num) : 0;
		(alt < p[1][v->num]) ? (p[1][v->num] = alt) : 0;
	}
}

int				ft_dijkstra(t_farm *farm, t_room *start, int *dist, int *prev)
{
	int		i;
	int		**p;
	t_room	*u;
	t_room	**set;

	p = ft_int_twodnew(3, farm->n_rooms);
	set = setup(farm, start, dist, prev);
	copy_one_to_two(p, dist, prev, farm->n_rooms);
	while (num_room(set) && (i = -1))
	{
		if (!(u = copy_room(min_vertex(set, p[1]))))
			break ;
		set = remove_room(set, u->name);
		while (farm->links[++i] && (p[0][0] = i) >= 0)
			dijkstra_loop(farm, set, u, p);
		free_room(u);
	}
	copy_two_to_one(p, dist, prev, farm->n_rooms);
	ft_int_twodfree(p, 3);
    free_rooms(set);
	return (1);
}

static void		move_ants_loop(t_farm *f, t_room *s, int *prev, int i)
{
	t_room	*d;

	d = find_dest(f, f->ants[i]->pos, prev);
	(d) ? g_vs[s->num][d->num]++ : 0;
	if (d && g_vs[s->num][d->num] == 1 && (!d->n_ants || d->end))
	{
		f->ants[i]->pos = d->num;
		s->n_ants -= 1;
		d->n_ants += 1;
		if (g_verbose)
			ft_printf("Ant #%d: %s->%s\n", f->ants[i]->num, s->name, d->name);
		else
			ft_printf("L%d-%s ", f->ants[i]->num, d->name);
	}
}

void			move_ants(t_farm *farm)
{
	t_room	*start;
	int		*dist;
	int		*prev;
	int		i;

	while (farm->end->n_ants < farm->n_ants && ++g_count && (i = -1))
	{
		g_vs = ft_int_twodnew(farm->n_rooms, farm->n_rooms);
		(g_color) ? ft_printf("\e[38;2;173;216;230m") : 0;
		(g_verbose) ? ft_printf("Turn %d:\n", g_count) : 0;
		(g_color) ? ft_printf("\e[38;2;173;255;47m") : 0;
		while (farm->ants[++i])
		{
			dist = ft_intnew(farm->n_rooms);
			prev = ft_intnew(farm->n_rooms);
			start = room_by_num(farm->rooms, farm->ants[i]->pos);
			if (!start->end && ft_dijkstra(farm, start, dist, prev))
				move_ants_loop(farm, start, prev, i);
			free(dist);
			free(prev);
		}
		ft_int_twodfree(g_vs, farm->n_rooms);
		(farm->end->n_ants == farm->n_ants && g_verbose) ? 0 : ft_printf("\n");
	}
}
