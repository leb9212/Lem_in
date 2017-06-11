/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 22:13:17 by elee              #+#    #+#             */
/*   Updated: 2016/12/15 05:18:48 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

t_room	**remove_room(t_room **rooms, char *name)
{
	t_room	**temp;
	int		num;
	int		i;
	int		j;

	if (!rooms)
		return (NULL);
	num = num_room(rooms);
	temp = (t_room**)malloc(sizeof(t_room*) * num);
	temp[num - 1] = NULL;
	i = -1;
	j = 0;
	while (rooms[++i])
		if (ft_strcmp(rooms[i]->name, name))
			temp[j++] = copy_room(rooms[i]);
	free_rooms(rooms);
	return (temp);
}

void	copy_one_to_two(int **p, int *dist, int *prev, int num)
{
	int		i;

	i = -1;
	while (++i < num)
		p[1][i] = dist[i];
	i = -1;
	while (++i < num)
		p[2][i] = prev[i];
}

void	copy_two_to_one(int **p, int *dist, int *prev, int num)
{
	int		i;

	i = -1;
	while (++i < num)
		dist[i] = p[1][i];
	i = -1;
	while (++i < num)
		prev[i] = p[2][i];
}

void	recreate_map(t_farm *f)
{
	int		i;
	char	**p;
	char	**new;

	i = -1;
	new = ft_ptrnew(0);
	while (f->map[++i])
	{
		if (!ft_strcmp(f->map[i], "##start"))
			(!g_start) ? ft_twod_realloc(&new, f->map[i]) : 0;
		else if (!ft_strcmp(f->map[i], "##end"))
			(!g_end) ? ft_twod_realloc(&new, f->map[i]) : 0;
		else if (ft_count_chr(f->map[i], ' ') == 2)
		{
			p = ft_strsplit(f->map[i], ' ');
			(g_start && !ft_strcmp(p[0], g_start)) ?
				ft_twod_realloc(&new, "##start") : 0;
			(g_end && !ft_strcmp(p[0], g_end)) ?
				ft_twod_realloc(&new, "##end") : 0;
			ft_twod_realloc(&new, f->map[i]);
		}
		else
			ft_twod_realloc(&new, f->map[i]);
	}
	(ft_free_two(f->map)) ? (f->map = new) : 0;
}

void	print_map(t_farm *f, char **m, int pos)
{
	int		i;
	char	**p;

	i = -1;
	while (++i < pos)
	{
		if (ft_strisdigit(m[i]))
			(g_color) ? ft_printf("\e[38;2;255;99;71m") : 0;
		else if (!ft_strncmp(m[i], "##", 2) && !is_start_end(m[i]))
			(g_color) ? ft_printf("\e[38;2;64;224;208m") : 0;
		else if (!ft_strncmp(m[i], "#", 1) && !is_start_end(m[i]))
			(g_color) ? ft_printf("\e[38;2;240;230;140m") : 0;
		else if (ft_count_chr(m[i], ' ') == 2)
		{
			((p = ft_strsplit(m[i], ' ')) && g_color) ?
				ft_printf("\e[38;2;64;224;208m") : 0;
			(room_by_name(f->rooms, p[0])->start) ? ft_printf("##start\n") : 0;
			(room_by_name(f->rooms, p[0])->end) ? ft_printf("##end\n") : 0;
			(ft_free_two(p) && g_color) ? ft_printf("\e[38;2;218;112;214m") : 0;
		}
		else if (ft_count_chr(m[i], '-') == 1)
			(g_color) ? ft_printf("\e[38;2;255;165;0m") : 0;
		(!is_start_end(m[i])) ? ft_printf("%s\n", m[i]) : 0;
		(g_color) ? ft_printf("\e[39m") : 0;
	}
}
