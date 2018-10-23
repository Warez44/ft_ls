/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 12:47:13 by clingier          #+#    #+#             */
/*   Updated: 2018/10/22 09:58:22 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_maxstr(struct s_params *parameters)
{
	int i;
	int max[2];

	i = 0;
	max[0] = 0;
	max[1] = 0;
	while (i < parameters->len)
	{
		if (ft_strlen(parameters[i].uid) > max[0])
			max[0] = ft_strlen(parameters[i].uid);
		if (ft_strlen(parameters[i].gid) > max[1])
			max[1] = ft_strlen(parameters[i].gid);
		i++;
	}
	i = 0;
	while (i < parameters->len)
	{
		parameters[i].maxuid = max[0];
		parameters[i].maxgid = max[1];
		i++;
	}
}

void	ft_getstatistics(char **tab, struct s_params *parameters)
{
	struct stat stat_s;
	int i;

	i = 0;
	while (*tab)
	{
		stat(*tab, &parameters[i].statistics);
		parameters[i].len = ft_tablen(tab);
		tab++;
		i++;
	}
}

unsigned long	ft_maxsiz(struct s_params *parameters)
{
	unsigned long max;
	int i;

	i = 0;
	max = 0;
	while (i < parameters[i].len)
	{
		if ((unsigned long)parameters[i].statistics.st_size > max)
			max = (unsigned long)parameters[i].statistics.st_size;
		i++;
	}
	return (max);
}

unsigned int	ft_maxlnk(struct s_params *parameters)
{
	unsigned int max;
	int i;

	max = 0;
	i = 0;
	while (i < parameters[i].len)
	{
		if ((unsigned int)parameters[i].statistics.st_nlink > max)
			max = (unsigned int)parameters[i].statistics.st_nlink;
		i++;
	}
	return (max);
}

struct s_params *ft_getparams(char **tab, struct s_params *parameters)
{
	int i;
	int maxuidgid[2];

	ft_getstatistics(tab, parameters);
	i = 0;
	while (i < parameters->len)
	{
		ft_strpermission(parameters[i].statistics.st_mode, (char *)&(parameters[i].permission));
		parameters[i].maxlnk = ft_len(ft_maxlnk(parameters));
		parameters[i].maxsiz = ft_longlen(ft_maxsiz(parameters));
		parameters[i].uid = uid_name(parameters[i].statistics.st_uid);

		parameters[i].gid = gid_name(parameters[i].statistics.st_gid);
		parameters[i].mtime = ft_time(&parameters[i].statistics.st_mtime);
		i++;
		tab++;
	}
	ft_maxstr(parameters);
	return (parameters);
}
