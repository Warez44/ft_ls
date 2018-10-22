/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigneditoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 12:19:35 by clingier          #+#    #+#             */
/*   Updated: 2018/10/22 07:58:52 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_len(unsigned int n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int		ft_longlen(unsigned long n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void		ft_unsigneditoa(unsigned int nbr, int format, char *str)
{
	int		len;
	int		i;

	len = ft_len(nbr);
	i = format - 1;
	str[format] = ' ';
	str[format + 1] = '\0';
	ft_memset(str, ' ', format);
	while (format - len <= i)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
}

void		ft_unsignedlongitoa(unsigned long nbr, int format, char *str)
{
	int		len;
	int		i;

	len = ft_len(nbr);
	i = format - 1;
	str[format] = ' ';
	str[format + 1] = '\0';
	ft_memset(str, ' ', format);
	while (format - len <= i)
	{
		str[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
}
