/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:01:28 by clingier          #+#    #+#             */
/*   Updated: 2018/10/20 13:52:02 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_filenames(char **filenames, unsigned char flag, char *directory)
{
	DIR				*dir;
	struct dirent	*dp;
	char			*display;
	char			*temp;

	display = ft_strnew(1);
	if (!(dir = opendir(directory)))
	{
		ft_putstr_fd("ls: ", 2);
		perror(directory);
		return ;
	}
	while ((dp = readdir(dir)) != NULL)
	{
		temp = display;
		if (dp->d_name[0] != '.' || (flag & 2))
		{
			display = ft_strjoin(display, dp->d_name);
			free(temp);
			temp = display;
			display = ft_strjoin(display, "\n");
			free(temp);
		}
	}
	*filenames = display;
}

char	*ft_

char	*ft_params(char *filename)
{
	char *str;
	char *temp;

	if(!(str = ft_strnew(1)))
		return (NULL);
	
}

void	ft_lflag(char **tab)
{
	char *temp;
	char *str;
	while (*tab)
	{
		if(!(str = ft_params(*tab)))
		{
			ft_tabdel(tab);
			return ;
		}
		temp = *tab;
		*tab = ft_strjoin(str, tab);
		free(temp);
		tab++;
	}
}

void	ft_ls(char *directory, unsigned char flags)
{
	char *filenames;
	char **tab;

	ft_filenames(&filenames, flags, directory);
	tab = ft_filesorting(filenames, flags);
	while (*tab)
		ft_putendl(*(tab++));
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
