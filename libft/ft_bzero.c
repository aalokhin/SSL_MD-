/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:03:50 by aalokhin          #+#    #+#             */
/*   Updated: 2017/11/07 21:03:56 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *dest, size_t length)
{
	size_t			i;
	unsigned char	*dest1;

	dest1 = dest;
	i = 0;
	while (i < length)
	{
		dest1[i] = 0;
		i++;
	}
}
