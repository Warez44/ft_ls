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

t_file *ft_filesorting(t_file *files, unsigned char flags)
{
	int			(*sort_function)(const char *, const char *);
	char *temp;

	sort_function = (flags & 16) ? &ft_timecmp : &ft_strcmp;
	if (flags & 8)
		ft_revsort(files, sort_function);
	else
		ft_sort(files, sort_function);
	return (tab);
}

int		number_of_files(char *directory, unsigned char flags)
{
	int len;
	DIR *dir;
	struct dirent	*dp;


	len = 0;
	dir = opendir(directory);
	while ((dp = readdir(dir)) != NULL)
		if (dp->d_name[0] != '.' || (flags & 2))
		len++;
	closedir(dir);
	return (len);
}

t_file *ft_getfiles(unsigned char flags, char *directory)
{
	struct dirent	*dp;
	DIR *dir;
	int len;
	t_file *files;
	t_file *cp;

	if ((!(dir = opendir(directory))))
		nodirectory(directory);
	files = (t_file *)malloc(sizeof(*files) * number_of_files(directory, flags));
	cp = files;
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' || (flags & 2))
		{
			ft_malfailed(files->filename = ft_strdup(dp->d_name));
			ft_malfailed(files->file_path = ft_strdup(path_finder(directory, files->filename)));
			files++;
		}
	}
	//files = ft_filesorting(cp, flags, directory);
	closedir(dir);
	return(cp);
}
