/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 18:02:07 by cheron            #+#    #+#             */
/*   Updated: 2013/12/13 16:23:50 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# include <libft.h>
#endif /* !LIBFT_H */
#ifndef STDLIB_H
# define STDLIB_H
# include <stdlib.h>
#endif /* !STDLIB_H */
#ifndef FT_LS_H
# include "ft_ls.h"
#endif /* !FT_LS_H */

void	ft_printdir(t_list *file, t_option *opt)
{
	t_list	*new;

	new = NULL;
	if (opt->r == '1' && file->next)
		ft_printdir(file->next, opt);
	while (file)
	{
		if (file->content
			&& S_ISDIR(((t_data *)(file->content))->stat->st_mode))
		{
			ft_lstdir(&new, opt, ((t_data *)(file->content))->path);
			ft_callsort(new, opt);
			ft_lstiter(new, *ft_changepath);
			ft_printlst(new, opt);
		}
		if (opt->r == '1')
			return ;
		file = file->next;
	}
}

void	ft_changepath(t_list *elem)
{
	char	*path;
	char	*begin;

	if ((begin = ft_strrchr(((t_data *)elem->content)->path + 1, '/')))
	{
		path = ft_strdup(&begin[1]);
		free(((t_data *)elem->content)->path);
		((t_data *)elem->content)->path = path;
	}
}
