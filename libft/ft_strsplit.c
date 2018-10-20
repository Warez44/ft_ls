/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:54:44 by clingier          #+#    #+#             */
/*   Updated: 2018/10/19 10:10:05 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, int i, char c)
{
	int len;

	len = 0;
	while (s[i + len] != c && s[i + len])
		len++;
	return (len);
}

static int	ft_num_word(char const *str, int c)
{
	int sh;
	int num;

	sh = 0;
	num = 1;
	while (*str)
	{
		if (*str != c)
			sh = 0;
		if (*str == c && sh == 0)
		{
			sh = 1;
			num++;
		}
		str++;
	}
	return (num);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**ar;
	size_t	j;

	if (!s || !(ar = ft_memalloc(ft_num_word(s, c) + 1)))
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] && ar)
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(ar[j++] = ft_strsub(s, i, ft_len(s, i, c))))
				while (*ar)
					free(ar++);
			i = i + ft_len(s, i, c);
		}
	}
	if (ar)
		ar[j] = 0;
	return (ar);
}
