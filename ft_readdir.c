#include <dirent.h>
#include "libft/includes/libft.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

void	ft_readdir(void)
{
	DIR				*dir;
	struct dirent	*dp;

		dir = opendir("existepas");
		while ((dp = readdir(dir)))
		{
			if (dp->d_name[0] != '.')
				ft_putendl(dp->d_name);
		}
		closedir(dir);
}

