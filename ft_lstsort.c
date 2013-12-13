/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 17:41:24 by cheron            #+#    #+#             */
/*   Updated: 2013/12/11 19:56:56 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_STAT_H
# define SYS_STAT_H
# include <sys/stat.h>
#endif /* !SYS/STAT_H */
#ifndef LIBFT_H
# include <libft.h>
#endif /* !LIBFT_H */
#ifndef FT_LS_H
# include "ft_ls.h"
#endif /* !FT_LS_H */


void		ft_lstsort_time(t_list *files)
{
	int			sort;
	t_list		*run;
	time_t		time1;
	time_t		time2;

	sort = 0;
	run = files;
	while (run)
	{
		if (run->next && run->content && run->next->content)
		{
			time1 = ((t_data *)(run->content))->stat->st_mtime;
			time2 = ((t_data *)(run->next->content))->stat->st_mtime;
			if (time1 < time2)
			{
				sort = 1;
				ft_lstswap(run, run->next);
			}
		}
		run = run->next;
	}
	if (sort == 1)
		ft_lstsort_time(files);
}

