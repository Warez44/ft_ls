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

void	ft_filenames(char **filenames, unsigned char flag, DIR *dir)
{
	struct dirent	*dp;
	char			*display;

	display = ft_strnew(1);
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' || (flag & 2))
		{
			display = ft_freestrjoin(ft_freestrjoin(display, dp->d_name), "\n");
			if (!display)
			{
				free(display);
				exit(EXIT_FAILURE);
			}
		}
	}
	*filenames = display;
}

void	ft_ls(char *directory, unsigned char flags)
{
	char *filenames;
	char **tab;
	DIR *dir;

	if (!(dir = opendir(directory)))
	{
		ft_putstr_fd("ls: ", 2);
		perror(directory);
		return ;
	}
	ft_filenames(&filenames, flags, dir);
	tab = ft_filesorting(filenames, flags);
	if (flags & 1)
		ft_lflag(tab);
	while (*tab)
		ft_putendl(*(tab++));
	ft_tabdel(tab);
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
