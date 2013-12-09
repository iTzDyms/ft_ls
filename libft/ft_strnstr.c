/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:39:36 by cheron            #+#    #+#             */
/*   Updated: 2013/11/28 12:25:19 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t n)
{
	char	c;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(find);
	while (ft_strncmp(&s[i], find, len) != 0)
		{
			c = s[i];
			if (c == '\0')
				return (NULL);
			i++;
		}
	if (i + len > n)
		return (NULL);
	return ((char *) &s[i]);
}
