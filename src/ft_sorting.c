/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 13:31:59 by clingier          #+#    #+#             */
/*   Updated: 2018/10/20 13:48:16 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

int		ft_timecmp(const char *file1, const char *file2)
{
	struct stat stat1;
	struct stat stat2;

	stat(file1, &stat1);
	stat(file2, &stat2);
	if (stat1.st_mtime < stat2.st_mtime)
		return (1);
	return (-1);
}

char	**ft_filesorting(char *filenames, unsigned char flags)
{
	char		**tab;
	int			(*sort_function)(const char *, const char *);

	tab = ft_strsplit(filenames, '\n');
	free(filenames);
	sort_function = (flags & 16) ? &ft_timecmp : &ft_strcmp;
	if (flags & 8)
		ft_revsort(tab, sort_function);
	else
		ft_sort(tab, sort_function);
	return (tab);
}
