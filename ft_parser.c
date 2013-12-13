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


void	ft_parse(char *str, t_option *opt, t_list **files)
{
	if (opt->end != '1' && *str == '-' && str[1] != '\0')
		ft_parse_opt(&str[1], opt);
	else
	{
		if (opt->end != '1')
			opt->end = '1';
		ft_list_files(str, files);
	}
}

void	ft_parse_opt(char *str, t_option *opt)
{
	if (*str == '-')
	{
		opt->end = '1';
		if (str[1] != '\0')
		{
			ft_putendl("ft_ls: illegal option -- -");
			ft_putendl("usage: ft_ls [-lRrta] [file ...]");
			exit(0);
		}
	}
	while (*str != '\0' && opt->end != '1')
		{
			if (*str == 'l' || *str == 'R' || *str == 'a'
				|| *str == 'r' || *str == 't')
				ft_enable_opt(str, opt);
			else
				{
					ft_putstr("ft_ls: illegal option -- ");
					ft_putchar(*str);
					ft_putendl("");
					ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
					exit(0);
				}
			str++;
		}
}

void	ft_enable_opt(char *str, t_option *opt)
{
	if (*str == 'a')
		opt->a = '1';
	else if (*str == 'l')
		opt->l = '1';
	else if (*str == 'r')
		opt->r = '1';
	else if (*str == 'R')
		opt->rec = '1';
	else if (*str == 't')
		opt->t = '1';
}

