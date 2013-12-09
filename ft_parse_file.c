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

void		ft_list_files(char *path, t_list **files, t_option *opt)
{
	t_list	*new;

	if (opt->t == '0')
	{
		if (!(new = ft_lstnew(path, sizeof(char) * (ft_strlen(path) + 1))))
			exit(-1);
		ft_lstadd(files, new);
	}
}

