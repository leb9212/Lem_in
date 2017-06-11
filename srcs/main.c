/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:44:26 by elee              #+#    #+#             */
/*   Updated: 2017/05/16 01:12:26 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"

int			g_count = 0;
int			g_color = 0;
int			g_verbose = 0;
int			g_debug = 0;
int			g_hide = 0;
int			g_ns = 0;
int			g_ne = 0;
char		*g_start = NULL;
char		*g_end = NULL;
int			**g_vs = NULL;

static char	**parse_options(char **argv)
{
	char	**options;
	char	*temp;
	int		i;
	int		j;

	options = ft_ptrnew(0);
	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '-')
		{
			j = 0;
			while (argv[i][++j])
			{
				temp = ft_strnew(2);
				temp[0] = '-';
				temp[1] = argv[i][j];
				ft_twod_realloc(&options, temp);
				free(temp);
			}
		}
		else
			ft_twod_realloc(&options, argv[i]);
	}
	return (options);
}

static void	preset_options(char **options)
{
	int		i;

	i = -1;
	while (options[++i])
	{
		(!ft_strcmp(options[i], "-c")) ? (g_color = 1) : 0;
		(!ft_strcmp(options[i], "-v")) ? (g_verbose = 1) : 0;
		(!ft_strcmp(options[i], "-d")) ? (g_debug = 1) : 0;
		(!ft_strcmp(options[i], "-h")) ? (g_hide = 1) : 0;
	}
}

static void	set_options(char **options)
{
	int		i;

	preset_options(options);
	i = -1;
	while (options[++i])
	{
		if (!ft_strcmp(options[i], "-c") || !ft_strcmp(options[i], "-v")
				|| !ft_strcmp(options[i], "-d") || !ft_strcmp(options[i], "-h"))
			continue ;
		else if (!ft_strcmp(options[i], "-s"))
			(!options[i + 1] && ft_free_two(options)) ?
				error_msg("Specify a valid start room with -s option", NULL, -1)
				: (g_start = ft_strdup(options[++i]));
		else if (!ft_strcmp(options[i], "-e"))
			(!options[i + 1] && ft_free_two(options)) ?
				error_msg("Specify a valid end room with -e option", NULL, -1)
				: (g_end = ft_strdup(options[++i]));
		else if (ft_free_two(options))
			error_msg("Invalid option given", NULL, -2);
	}
	ft_free_two(options);
}

static void	read_map(t_farm *farm, int c[2])
{
	char	*line;

	farm->map = ft_ptrnew(0);
	while (get_next_line(0, &line) > 0)
	{
		ft_twod_realloc(&(farm->map), line);
		free(line);
	}
	c[0] = -1;
	c[1] = 0;
}

int			main(int argc, char **argv)
{
	t_farm	*farm;
	int		*dist;
	int		*prev;
	int		counter[2];
	int		pos;

	(argc > 1) ? set_options(parse_options(argv)) : 0;
	farm = init_farm();
	read_map(farm, counter);
	(g_start || g_end) ? recreate_map(farm) : 0;
	pos = read_farm(farm, counter);
	final_init(farm);
	dist = ft_intnew(farm->n_rooms);
	prev = ft_intnew(farm->n_rooms);
	ft_dijkstra(farm, farm->start, dist, prev);
	if (farm->end->num == -1 || prev[farm->end->num] == -1)
		error_msg("There is no possible route", farm, -1);
	(!g_hide) ? print_map(farm, farm->map, pos) : 0;
	(!g_hide) ? ft_printf("\n") : 0;
	move_ants(farm);
    free(dist);
    free(prev);
	free_farm(farm);
	return (0);
}
