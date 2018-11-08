/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:01:28 by clingier          #+#    #+#             */
/*   Updated: 2018/10/21 13:17:05 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

// void	ft_filenames(char **filenames, unsigned char flag, char *directory)
// {
// 	struct dirent	*dp;
// 	DIR *dir;
//
// 	if (!(dir = opendir(directory)))
// 	{
// 		ft_putstr_fd("ls: ", 2);
// 		perror(directory);
// 		exit(EXIT_FAILURE);
// 	}
// 	ft_malfailed(*filenames = ft_strnew(1));
// 	while ((dp = readdir(dir)) != NULL)
// 	{
// 		if (dp->d_name[0] != '.' || (flag & 2))
// 		{
// 			*filenames = ft_freestrjoin(ft_freestrjoin(*filenames, dp->d_name), "\n");
// 			ft_malfailed((void *)filenames);
// 		}
// 	}
// 	closedir(dir);
// }


void	ft_ls(char *directory, unsigned char flags)
{
	struct s_params *parameters;
	struct s_file *files;
	char **tab;
	char *path;

	files = ft_getfiles(flags, directory);
	if (flags & 1)
		ft_lflag(tab, directory);
	(!(flags & 1)) ? ft_puttab(tab) : 0;
	if (flags & 4)
	{
		parameters = (struct s_params*)malloc(sizeof(struct s_params) * ft_tablen(tab));
		ft_getstatistics(tab, parameters, directory);
		while (*tab)
		{
			if (S_ISDIR(parameters->statistics.st_mode))
			{
				path = path_finder(directory, *tab);
				ft_putstr(path);
				ft_putendl(":");
				ft_ls(path, flags);
			}
			parameters++;
			tab++;
		}
	}
}

int		main(int argc, char **argv)
{
	char			*directory;
	unsigned char	flags;

	flags = ft_flag(argc, argv);
	if ((flags & 128))
		return (1);
	argv++;
	while (*argv && **argv == '-')
		argv++;
	directory = (*argv && argc != 1) ? ft_strdup(*argv) : ft_strdup(".");
	ft_ls(directory, flags);
}
