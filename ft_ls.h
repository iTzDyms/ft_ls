#ifndef FT_LS_H
# define FT_LS_H
#ifndef STRING_H
# define STRING_H
# include <string.h>
#endif /* !STRING_H */
#ifndef SYS_STAT_H
# define SYS_STAT_H
# include <sys/stat.h>
#endif /* !SYS/STAT_H */


typedef	struct			s_option
{
	char				rec;
	char				l;
	char				a;
	char				r;
	char				t;
	char				end;
}						t_option;

typedef	struct			s_data
{
	struct stat			*stat;
	char				*path;
}						t_data;

void	ft_parse(char *str, t_option *opt, t_list **files);
void	ft_parse_opt(char *str, t_option *opt);
int		ft_is_endopt(char *str, t_option *opt);
void	ft_enable_opt(char *str, t_option *opt);
void	ft_list_files(char *str, t_list **files);
void	ft_lstdir(t_list **lst, t_option *opt, char *path);
void	ft_init_opt(t_option *opt);
void	ft_lstswap(t_list *elem1, t_list *elem2);
void	ft_lstsort_asc(t_list *files);
void	ft_lststat(t_list *elem);
char	*ft_strfjoin(char *str1, char *str2);
void	ft_printfiles(t_list *file, t_option *opt);
void	ft_lstsort_time(t_list *file);
void	ft_printl(t_data *data);
void	ft_printdir(t_list *lst, t_option *opt);
void	ft_printlst(t_list *file, t_option *opt);
void	ft_callsort(t_list *files, t_option *opt);
void	ft_changepath(t_list *elem);

#endif /* !FT_LS_H */
