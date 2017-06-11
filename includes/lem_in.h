/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:01:57 by elee              #+#    #+#             */
/*   Updated: 2016/12/15 15:46:01 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

extern int			g_count;
extern int			g_color;
extern int			g_verbose;
extern int			g_debug;
extern int			g_hide;
extern int			g_ns;
extern int			g_ne;
extern char			*g_start;
extern char			*g_end;
extern int			**g_vs;

typedef struct		s_ant
{
	int				num;
	int				pos;
}					t_ant;

typedef struct		s_link
{
	char			*start;
	char			*end;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				num;
	int				x;
	int				y;
	int				start;
	int				end;
	int				n_ants;
}					t_room;

typedef struct		s_farm
{
	char			**map;
	int				n_ants;
	int				n_rooms;
	int				n_links;
	t_ant			**ants;
	t_room			**rooms;
	t_link			**links;
	t_room			*start;
	t_room			*end;

}					t_farm;

/*
** utils.c
*/

void				error_msg(char *msg, t_farm *farm, int num);
int					stop_msg(char *msg, char **parts, int num);
int					is_start_end(char *line);
int					is_room(char **parts, t_farm *farm);
int					num_room(t_room **rooms);

/*
** utils2.c
*/

t_room				*copy_room(t_room *room);
t_link				*copy_link(t_link *link);
t_room				**copy_rooms(t_room **rooms);
t_room				**add_room(t_farm *farm, t_room **rooms, t_room *add);
t_link				**add_link(t_farm *farm, t_link **links, t_link *add);

/*
** utils3.c
*/

t_room				*room_by_num(t_room **rooms, int num);
t_room				*room_by_name(t_room **rooms, char *name);
t_room				*min_vertex(t_room **rooms, int *dist);
t_room				*find_dest(t_farm *farm, int pos, int *prev);

/*
** utils4.c
*/

t_room				**remove_room(t_room **rooms, char *name);
void				copy_one_to_two(int **p, int *dist, int *prev, int num);
void				copy_two_to_one(int **p, int *dist, int *prev, int num);
void				recreate_map(t_farm *f);
void				print_map(t_farm *f, char **m, int pos);

/*
** free.c
*/

int					free_room(t_room *room);
int					free_rooms(t_room **rooms);
int					free_link(t_link *link);
int					free_links(t_link **link);
int					free_farm(t_farm *farm);

/*
** read.c
*/

int					read_farm(t_farm *f, int c[2]);

/*
** init.c
*/

t_farm				*init_farm(void);
void				init_rooms(t_farm *farm, char **parts, int startend);
void				init_links(t_farm *farm, char **parts);
void				check_start_end(t_farm *farm);
void				final_init(t_farm *farm);

/*
** algo.c
*/

int					ft_dijkstra(t_farm *farm, t_room *start,
								int *dist, int *prev);
void				move_ants(t_farm *farm);

#endif
