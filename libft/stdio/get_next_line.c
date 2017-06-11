/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:02:08 by elee              #+#    #+#             */
/*   Updated: 2016/11/01 23:13:41 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*find_list(t_list **list, int fd)
{
	t_list *temp;

	temp = *list;
	while (temp)
	{
		if (fd == (int)temp->content_size)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", 1);
	temp->content_size = fd;
	ft_lstadd(list, temp);
	return (temp);
}

static int		read_finished(char **line, t_list **l)
{
	if ((*l)->content && ft_strlen((*l)->content))
	{
		*line = ft_strsub((*l)->content, 0, ft_strlen((*l)->content));
		(*l)->content = ft_strresub((*l)->content, ft_strlen((*l)->content));
		return (1);
	}
	else
		*line = ft_strsub((*l)->content, 0, 0);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*temp;
	char			input[BUFF_SIZE + 1];
	int				pos;
	int				ret;

	if (fd < 0 || line == NULL || read(fd, input, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	temp = list;
	list = find_list(&temp, fd);
	while ((pos = ft_nextchr(list->content, '\n')) == -1)
	{
		ft_bzero(input, BUFF_SIZE + 1);
		if ((ret = read(fd, input, BUFF_SIZE)) == 0)
			return (read_finished(line, &list) ? 1 : 0);
		list->content = ft_strrecat(list->content, input);
	}
	*line = ft_strsub(list->content, 0, pos);
	list->content = ft_strresub(list->content, pos + 1);
	list = temp;
	return (1);
}
