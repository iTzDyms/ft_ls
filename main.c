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
	files = NULL;
	ft_init_opt(&opt);
	while (i < argc)
	{
		ft_parse(argv[i], &opt, &files);
		i++;
	}
	if (!files)
	{
		ft_lstdir(&files, &opt, ".");
		ft_callsort(files, &opt);
		ft_lstiter(files, *ft_changepath);
		ft_printlst(files, &opt);
		return (0);
	}
	ft_callsort(files, &opt);
	ft_printfiles(files, &opt);
	ft_printdir(files, &opt);
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

