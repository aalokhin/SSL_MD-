/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_hex_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalokhin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 04:26:24 by aalokhin          #+#    #+#             */
/*   Updated: 2018/06/01 04:26:26 by aalokhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				ft_hash_xs(char **str)
{
	int				i;
	int				j;
	char			*res;

	j = 0;
	i = 2;
	res = ft_strdup(*str);
	ft_strdel(&(*str));
	(*str) = ft_strnew(ft_strlen(res) + 2);
	(*str)[0] = '0';
	(*str)[1] = 'x';
	(*str)[2] = '\0';
	while (res[j] != '\0')
		(*str)[i++] = res[j++];
	(*str)[i] = '\0';
	ft_strdel(&res);
}

void				hexs1(char **res, uintmax_t ival, t_flags *box)
{
	if (box->hash && (box->zero || box->pre > box->wid))
	{
		box->wid -= 2;
		(*res) = ft_dec_wp((*res), box);
		ft_hash_xs(res);
	}
	else if ((box->hash && !box->zero &&\
	!(box->pre == 0 && ival == 0 && box->wid == 0)))
	{
		ft_hash_xs(res);
		(*res) = ft_dec_wp((*res), box);
	}
	else
		(*res) = ft_dec_wp((*res), box);
}

void				hex_s(va_list ap, t_flags *box, size_t *count)
{
	uintmax_t		ival;
	char			*res;

	res = NULL;
	ival = 0;
	if (box->dot)
		box->zero = 0;
	ival = va_arg(ap, uintmax_t);
	ft_mod_u(&ival, box);
	box->sign = 0;
	if (box->dot == 1 && box->pre == 0 && ival == 0)
		res = ft_strdup("");
	else
		res = ft_itoa_base_small(ival, 16);
	hexs1(&res, ival, box);
	ft_putstr2(res, count);
	ft_strdel(&res);
	fill_struct(box);
}
