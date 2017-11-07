/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 18:02:49 by daleksan          #+#    #+#             */
/*   Updated: 2016/12/27 19:34:46 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_memfree(char **ap, int j)
{
	int	i;

	i = 0;
	if (ap && j)
	{
		while (i < j)
			i++;
		while (i--)
			free(ap[i]);
		free(ap);
	}
	return (NULL);
}
