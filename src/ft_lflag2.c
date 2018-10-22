/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 07:26:22 by clingier          #+#    #+#             */
/*   Updated: 2018/10/22 09:11:34 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

unsigned int	ft_maxlnk(char **tab)
{
	unsigned int max;
	struct stat s_stat;

	max = 0;
	while (*tab)
	{
		stat(*tab, &s_stat);
		if ((unsigned int)s_stat.st_nlink > max)
			max = (unsigned int)s_stat.st_nlink;
		tab++;
	}
	return (max);
}

unsigned long	ft_maxsiz(char **tab)
{
	unsigned long max;
	struct stat s_stat;

	max = 0;
	while (*tab)
	{
		stat(*tab, &s_stat);
		if ((unsigned long)s_stat.st_size > max)
			max = (unsigned long)s_stat.st_size;
		tab++;
	}
	return (max);
}

char	*ft_time(const time_t *stat_time)
{
	time_t time;
	char *str;
	char year[5];

	year[4] = '\0';
	time = *stat_time;
	str = ctime(&time);
	ft_strncpy(year, (str + 20), 4);
	str[3] = '\0';
	ft_strclr(str);
	str += 4;
	str[12] = ' ';
	str[13] = ' ';
	ft_strclr(str + 13);
	return (str);
}
