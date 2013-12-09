/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:54:19 by cheron            #+#    #+#             */
/*   Updated: 2013/11/29 17:35:22 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		{
			if (s[i] == c)
				return ((char * )&s[i]);
			i++;
		}
	if (c == '\0')
		return ((char * )&s[i]);
	return (NULL);
}