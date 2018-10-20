/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 12:58:38 by clingier          #+#    #+#             */
/*   Updated: 2018/10/20 13:10:37 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void			ft_flagerror(char t)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(t, 2);
	ft_putchar_fd('\n', 2);
	ft_putendl_fd("usage: ls [-Ralrt] [file ...]", 2);
}

unsigned char	ft_case(char c, unsigned char flags)
{
	flags = (c == 'l') ? (flags | 1) : flags;
	flags = (c == 'a') ? (flags | 2) : flags;
	flags = (c == 'R') ? (flags | 4) : flags;
	flags = (c == 'r') ? (flags | 8) : flags;
	flags = (c == 't') ? (flags | 16) : flags;
	return (flags);
}

unsigned char	ft_flag(int argc, char **argv)
{
	unsigned char	flags;
	int				i;
	int				j;

	i = 1;
	j = 1;
	flags = 0;
	while (i < argc && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			flags = ft_case(argv[i][j], flags);
			if (argv[i][j] != 't' && argv[i][j] != 'R' &&
			argv[i][j] != 'r' && argv[i][j] != 'a' && argv[i][j] != 'l')
			{
				ft_flagerror(argv[i][j]);
				flags = (flags | 128);
			}
			j++;
		}
		i++;
	}
	return (flags);
}
