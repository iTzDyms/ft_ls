#ifndef FT_LS_H
# define FT_LS_H
#ifndef STRING_H
# define STRING_H
# include <string.h>
#endif /* !STRING_H */

typedef	struct			s_option
{
	char				rec;
	char				l;
	char				a;
	char				r;
	char				t;
	char				end;
}						t_option;

typedef	struct			s_stat
{
	char				rec;
	char				l;
	char				a;
	char				r;
	char				t;
	char				end;
}						t_option;

void	ft_parse(char *str, t_option *opt, t_list **files);
void	ft_parse_opt(char *str, t_option *opt);
int		ft_is_endopt(char *str, t_option *opt);
void	ft_enable_opt(char *str, t_option *opt);
void	ft_list_files(char *str, t_list **files, t_option *opt);
void	ft_readdir(void);
void	ft_init_opt(t_option *opt);


#endif /* !FT_LS_H */
