/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:14:54 by elee              #+#    #+#             */
/*   Updated: 2017/05/16 01:11:00 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

static void	read_ants(t_farm *farm, int pos)
{
	t_ant	**ants;
	int		i;

	if (!ft_strisdigit(farm->map[pos]))
		error_msg("Number of ants not specified", farm, pos);
	if (ft_atoi(farm->map[pos]) <= 0)
		error_msg("Number of ants not positive", farm, pos);
	farm->n_ants = ft_atoi(farm->map[pos]);
	ants = (t_ant**)malloc(sizeof(t_ant*) * (farm->n_ants + 1));
	i = -1;
	while (++i < farm->n_ants)
	{
		ants[i] = malloc(sizeof(t_ant));
		ants[i]->num = i + 1;
		ants[i]->pos = -1;
	}
	ants[i] = NULL;
	farm->ants = ants;
}

static void	read_rooms(t_farm *f, char **parts, int p)
{
	int		i;
	int		se;

	se = 0;
	if ((parts[0][0] == 'L' || parts[0][0] == '#') && ft_free_two(parts))
		error_msg("Room name shouldn't start with L or #", f, p);
	if (!ft_strisdigit(parts[1]) && ft_free_two(parts))
		error_msg("Room should have a valid x coordinate", f, p);
	if (!ft_strisdigit(parts[2]) && ft_free_two(parts))
		error_msg("Room should have a valid y coordinate", f, p);
	if (f->rooms && (i = -1))
	{
		while (f->rooms[++i])
		{
			if (!ft_strcmp(f->rooms[i]->name, parts[0])
				&& ft_free_two(parts))
				error_msg("Room has same name as a previous one", f, p);
			if (f->rooms[i]->x == ft_atoi(parts[1])
				&& f->rooms[i]->y == ft_atoi(parts[2]) && ft_free_two(parts))
				error_msg("Room has same coordinates as a previous one", f, p);
		}
	}
	(p > 1 && !ft_strcmp(f->map[p - 1], "##start") && ++g_ns) ? (se = -1) : 0;
	(p > 1 && !ft_strcmp(f->map[p - 1], "##end") && ++g_ne) ? (se = 1) : 0;
	init_rooms(f, parts, se);
}

static int	read_links(t_farm *f, char **parts, int p)
{
	int		i;

	if (!(f->rooms) && ft_free_two(parts))
		error_msg("No rooms have been defined", f, -1);
	if (!ft_strcmp(parts[0], parts[1])
		&& stop_msg("You cannot build a tube with a single room", parts, p))
		return (0);
	if (!is_room(parts, f) && stop_msg("No room name found", parts, p))
		return (0);
	if (f->links && (i = -1))
	{
		while (f->links[++i])
		{
			if (((!ft_strcmp(parts[0], f->links[i]->start)
				&& !ft_strcmp(parts[1], f->links[i]->end))
				|| (!ft_strcmp(parts[0], f->links[i]->end)
				&& !ft_strcmp(parts[1], f->links[i]->start)))
				&& stop_msg("This tube has already been defined", parts, p))
				return (0);
		}
	}
	init_links(f, parts);
	return (1);
}

static int	stay_in_loop(char *line, int flag)
{
	if (!line)
		return (-1);
	if (flag == 1)
	{
		if (line[0] == '#')
			return (1);
		else if (ft_count_chr(line, ' ') == 2)
			return (1);
		return (0);
	}
	if (flag == 2)
	{
		if (line[0] == '#')
			return (1);
		else if (ft_count_chr(line, '-') == 1)
			return (1);
		return (0);
	}
	return (0);
}

int			read_farm(t_farm *f, int c[2])
{
	while (f->map[++c[0]])
		if (!(f->map[c[0]][0] == '#' && f->map[c[0]][1] != '#'))
			break ;
	read_ants(f, c[0]);
	while (f->map[++c[0]] && stay_in_loop(f->map[c[0]], 1))
	{
		if (f->map[c[0]][0] == '#')
			continue ;
		else if (ft_count_chr(f->map[c[0]], ' ') == 2)
			read_rooms(f, ft_strsplit(f->map[c[0]], ' '), c[0]);
	}
	check_start_end(f);
	while (f->map[c[0]] && stay_in_loop(f->map[c[0]], 2))
	{
		if (f->map[c[0]][0] == '#' && ++c[0])
			continue ;
		else if (ft_count_chr(f->map[c[0]], '-'))
        {
			c[1] = read_links(f, ft_strsplit(f->map[c[0]], '-'), c[0]);
            c[0]++;
        }
		if (!c[1])
			break ;
	}
	(!stay_in_loop(f->map[c[0]], 2)) ? stop_msg("Invalid line", NULL, c[0]) : 0;
	(!f->links) ? error_msg("No tubes have been defined", f, -1) : 0;
	return (c[0]);
}
