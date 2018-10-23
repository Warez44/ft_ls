/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:21:59 by clingier          #+#    #+#             */
/*   Updated: 2018/10/22 12:22:24 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_strformat(char *buf, char *str, int maxlen)
{
	int i;

	i = 0;
	while (i < maxlen)
	{
		buf[i] = ' ';
		i++;
	}
	i = 0;
	while (str[i])
	{
		buf[i] = str[i];
		i++;
	}
	buf[maxlen] = '\0';
}
