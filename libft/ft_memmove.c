/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cheron <cheron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:49:28 by cheron            #+#    #+#             */
/*   Updated: 2013/12/07 15:59:08 by cheron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char	*temp;
	unsigned char	*dest;

	if (!(temp = (unsigned char *) malloc(sizeof(unsigned char) * n)))
		return (NULL);
	ft_memcpy(temp, s2, n);
	i = 0;
	dest = s1;
	while (i < n)
		{
			dest[i] = temp[i];
			i++;
		}
	free(temp);
	return (s1);
}
