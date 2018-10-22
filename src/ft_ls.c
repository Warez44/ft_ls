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
	DIR				*dir;
	struct dirent	*dp;
	char			*display;

	display = ft_strnew(1);
	if (!(dir = opendir(directory)))
	{
		ft_putstr_fd("ls: ", 2);
		perror(directory);
		return ;
	}
	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] != '.' || (flag & 2))
		{
			display = ft_freestrjoin(display, dp->d_name);
			display = ft_freestrjoin(display, "\n");
		}
	}
	*filenames = display;
}


void	ft_ls(char *directory, unsigned char flags)
{
	char *filenames;
	char **tab;

	ft_filenames(&filenames, flags, directory);
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
	directory = (*argv) ? ft_strdup(*argv) : ft_strdup(".");
	ft_ls(directory, flags);
}
