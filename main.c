#ifndef LIBFT_H
# include <libft.h>
#endif /* !LIBFT_H */
#ifndef FT_LS_H
# include "ft_ls.h"
#endif /* !FT_LS_H */

int		main(int argc, char **argv)
{
	int			i;
	t_list		*files;
	t_option	opt;

	i = 1;
	ft_init_opt(&opt);
	while (i < argc)
	{
		ft_parse(argv[i], &opt, &files);
		i++;
	}
/*	ft_putstr("opt.R == ");
	ft_putchar(opt.rec);
	ft_putendl("");
	ft_putstr("opt.l == ");
	ft_putchar(opt.l);
	ft_putendl("");
	ft_putstr("opt.a == ");
	ft_putchar(opt.a);
	ft_putendl("");
	ft_putstr("opt.t == ");
	ft_putchar(opt.t);
	ft_putendl("");
	ft_putstr("opt.r == ");
	ft_putchar(opt.r);
	ft_putendl("");
	ft_putstr("opt.end == ");
	ft_putchar(opt.end);
	ft_putendl("");*/
	while (files)
	{
		ft_putendl(files->content);
		files = files->next;
	}
	return (0);
}

void	ft_init_opt(t_option *opt)
{
	opt->rec = '0';
	opt->l = '0';
	opt->a = '0';
	opt->r = '0';
	opt->t = '0';
	opt->end = '0';
}
