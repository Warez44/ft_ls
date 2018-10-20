/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:00:38 by clingier          #+#    #+#             */
/*   Updated: 2018/10/20 12:59:41 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# include <libft.h>
# include <dirent.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

void	ft_filenames(char **buf, unsigned char flag, char *str);
void	ft_flagerror(char t);
unsigned char ft_case(char c, unsigned char flags);
unsigned char ft_flag(int argc, char **argv);
int		ft_namesorting(const char *str1, const char *str2);
void	ft_revsort(char **argv, int (*f)(const char *, const char *));
void	ft_sort(char **argv, int(*f)(const char *, const char *));
int		ft_tablen(char **argv);
int		ft_timecmp(const char *a, const char *b);

#endif
