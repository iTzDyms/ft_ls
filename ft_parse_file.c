#ifndef SYS_STAT_H
# define SYS_STAT_H
# include <sys/stat.h>
#endif /* !SYS/STAT_H */
#ifndef ERRNO_H
# define ERRNO_H
# include <errno.h>
#endif /* !ERRNO_H */
#ifndef STDIO_H
# define STDIO_H
# include <stdio.h>
#endif /* !STDIO_H */
#ifndef STRING_H
# define STRING_H
# include <string.h>
#endif /* !STRING_H */
#ifndef STDLIB_H
# define STDLIB_H
# include <stdlib.h>
#endif /* !STDLIB_H */
#ifndef LIBFT_H
# include <libft.h>
#endif /* !LIBFT_H */
#ifndef FT_LS_H
# include "ft_ls.h"
#endif /* !FT_LS_H */

static void	ft_prtstaterror(char *path);

void		ft_list_files(char *path, t_list **files)
{
	t_list		*new;

	if (!(new = ft_lstnew(path, sizeof(char) * (ft_strlen(path) + 1))))
		exit(-1);
	ft_lstadd(files, new);
}

void		ft_lstswap(t_list *elem1, t_list *elem2)
{
	void		*tmp;

	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
}

void		ft_lstsort_asc(t_list *files)
{
	int			sort;
	t_list		*run;

	sort = 0;
	run = files;
	while (sort != 1 && run)
	{
		sort = 1;
		while (run->next && ft_strcmp(run->content, run->next->content) > 0)
		{
			sort = 0;
			ft_lstswap(run, run->next);
			run = run->next;
		}
		if (sort == 0)
			run = files;
		else if (run->next && sort == 1)
		{
			sort = 0;
			run = run->next;
		}
	}
}

void		ft_lststat(t_list *elem)
{
	struct stat	*file_stat;
	int			ret;
	t_data		*data;

	file_stat = malloc(sizeof(struct stat));
	ret = stat((const char *)elem->content, file_stat);
	if (ret == -1)
	{
		free(file_stat);
		ft_prtstaterror(elem->content);
		free(elem->content);
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		data = malloc(sizeof(t_data));
		data->stat = file_stat;
		data->path = elem->content;
		elem->content = data;
	}
}

static void	ft_prtstaterror(char *path)
{
	char		*error;

	error = strerror(errno);
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": ");
	ft_putstr(error);
	ft_putchar('\n');
}
