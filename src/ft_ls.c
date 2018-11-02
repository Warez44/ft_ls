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

void	ft_filenames(char **filenames, unsigned char flag, char *directory)
{
	struct dirent	*dp;
	DIR *dir;

	if (!(dir = opendir(directory)))
	{
		ft_putstr_fd("ls: ", 2);
		perror(directory);
		exit(EXIT_FAILURE);
	}
	*filenames = ft_strnew(1);
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' || (flag & 2))
		{
			*filenames = ft_freestrjoin(ft_freestrjoin(*filenames, dp->d_name), "\n");
			if (!*filenames)
			{
				free(*filenames);
				exit(EXIT_FAILURE);
			}
		}
	}
	closedir(dir);
}

void	ft_ls(char *directory, unsigned char flags)
{
	char *filenames;
	struct s_params *parameters;
	char **tab;
	char **R_tab;


	ft_filenames(&filenames, flags, directory);
	tab = ft_filesorting(filenames, flags);
	if (flags & 1)
		ft_lflag(tab);
	while (*tab)
		ft_putendl(*(tab++));
	ft_tabdel(tab);
	if (flags & 4)
	{
		R_tab = ft_filesorting(filenames, flags);
		parameters = (struct s_params*)malloc(sizeof(struct s_params) * ft_tablen(R_tab));
		ft_getstatistics(R_tab, parameters);
		while (*R_tab)
		{
			if (S_ISDIR(parameters->statistics.st_mode))
			{
				ft_putstr(*R_tab);
				ft_putendl(":");
				ft_ls(*R_tab, flags);
				break;
			}
			parameters++;
			R_tab++;
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
