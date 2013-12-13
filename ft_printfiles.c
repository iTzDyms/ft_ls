/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 16:44:51 by cheron            #+#    #+#             */
/*   Updated: 2013/12/13 17:58:19 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYS_STAT_H
# define SYS_STAT_H
# include <sys/stat.h>
#endif /* SYS_STAT_H */
#ifndef PWD_H
# define PWD_H
# include <pwd.h>
#endif /* !PWD_H */
#ifndef UUID_UUID_H
# define UUID_UUID_H
# include <uuid/uuid.h>
#endif /* !UUID_UUID_H */
#ifndef STDLIB_H
# define STDLIB_H
# include <stdlib.h>
#endif /* !STDLIB_H */
#ifndef GRP_H
# define GRP_H
# include <grp.h>
#endif /* !GRP_H */
#ifndef LIBFT_H
# include <libft.h>
#endif /* !LIBFT_H */
#ifndef FT_LS_H
# include "ft_ls.h"
#endif /* !FT_LS_H */

void	ft_printl(t_data *data);
static void	ft_printmode(mode_t m);
static void	ft_printperm(mode_t m);
static void	ft_printid(struct stat *file);

void	ft_printfiles(t_list *file, t_option *opt)
{
	if ((opt->r == '1') && (file->next))
		ft_printfiles(file->next, opt);
	while (file)
	{
		if (file->content
			&& !S_ISDIR(((t_data *)(file->content))->stat->st_mode))
		{
			if (opt->l == '1')
				ft_printl(((t_data *)(file->content)));
			else
				ft_putendl(((t_data *)(file->content))->path);
		}
		if (opt->r == '1')
			return ;
		file = file->next;
	}
}

void	ft_printl(t_data *data)
{
	ft_printmode(data->stat->st_mode);
	ft_printperm(data->stat->st_mode);
	ft_putnbr(data->stat->st_nlink);
	ft_putstr("  ");
	ft_printid(data->stat);
	ft_putendl(data->path);
	return ;
}

static void	ft_printmode(mode_t m)
{
	if (S_ISDIR(m))
		ft_putchar('d');
	else if (S_ISREG(m))
		ft_putchar('-');
	else if (S_ISBLK(m))
		ft_putchar('b');
	else if (S_ISCHR(m))
		ft_putchar('c');
	else if (S_ISFIFO(m))
		ft_putchar('p');
	else if (S_ISLNK(m))
		ft_putchar('l');
	else if (S_ISSOCK(m))
		ft_putchar('s');
}

static void	ft_printperm(mode_t m)
{
	char	perm[10];

	perm[0] = (S_IRUSR & m ? 'r' : '-');
	perm[1] = (S_IWUSR & m ? 'w' : '-');
	perm[2] = (S_IXUSR & m ? 'x' : '-');
	perm[3] = (S_IRGRP & m ? 'r' : '-');
	perm[4] = (S_IWGRP & m ? 'w' : '-');
	perm[5] = (S_IWGRP & m ? 'x' : '-');
	perm[6] = (S_IROTH & m ? 'r' : '-');
	perm[7] = (S_IWOTH & m ? 'w' : '-');
	perm[8] = (S_IXOTH & m ? 'x' : '-');
	perm[9] = '\0';
	if (S_ISUID & m)
		perm[2] = (perm[2] == 'x' ? 's' : 'S');
	if (S_ISGID & m)
		perm[5] = (perm[5] == 'x' ? 's' : 'S');
	if (S_ISVTX & m)
		perm[8] = (perm[8] == 'x' ? 't' : 'T');
	ft_putstr(perm);
	ft_putstr("  ");
}

static void	ft_printid(struct stat *file)
{
	struct passwd *upwd;
	struct group *gpwd;

	upwd = malloc(sizeof(struct passwd));
	gpwd = malloc(sizeof(struct group));
	upwd = getpwuid(file->st_uid);
	gpwd = getgrgid(file->st_gid);
	ft_putstr(upwd->pw_name);
	ft_putstr("  ");
	ft_putstr(gpwd->gr_name);
	ft_putstr("  ");
}
