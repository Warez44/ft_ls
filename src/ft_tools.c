/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:12:52 by clingier          #+#    #+#             */
/*   Updated: 2018/10/21 15:15:13 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_sort(t_file *files, int (*f)(const char *, const char *))
{
	int		i;
	int		j;
	t_file *temp;

	i = 0;
	while (files[i])
	{
		j = i + 1;
		while (files[j])
		{
			if (f(files[i].directory, files[j].directory) > 0)
			{
				temp = files[i];
				files[i] = files[j]g;
				files[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void ft_puttab(char **tab)
{
	while(*tab)
		ft_putendl(*(tab++));
}

void	ft_revsort(char **argv, int (*f)(const char *, const char *))
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (f(argv[i], argv[j]) < 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_tabdel(char **tab)
{
	while (*tab)
	{
		free(*(tab++));
	}
}

int		ft_tablen(char **tab)
{
	int len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}
