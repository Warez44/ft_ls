/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:00:38 by clingier          #+#    #+#             */
/*   Updated: 2018/10/22 09:11:31 by clingier         ###   ########.fr       */
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
# include <pwd.h>
# include <grp.h>
# include <time.h>

void	ft_filenames(char **buf, unsigned char flag, char *str);
void	ft_flagerror(char t);
unsigned char ft_case(char c, unsigned char flags);
unsigned char ft_flag(int argc, char **argv);
int		ft_namesorting(const char *str1, const char *str2);
void	ft_revsort(char **argv, int (*f)(const char *, const char *));
void	ft_sort(char **argv, int(*f)(const char *, const char *));
int		ft_tablen(char **argv);
int		ft_timecmp(const char *a, const char *b);
void	ft_strpermission(mode_t mode, char *buf);
void	ft_tabdel(char **a);
char	**ft_filesorting(char *fi, unsigned char fl);
void	ft_unsigneditoa(unsigned int a, int format, char *str);
void	ft_unsignedlongitoa(unsigned long a, int format, char *str);
char	*ft_freestrjoin(char *a, char *b);
void	ft_lflag(char **tab);
int		ft_len(unsigned int nb);
char	*uid_name(uid_t uid);
char	*gid_name(gid_t gid);
unsigned long	ft_maxsiz(char **tab);
unsigned int	ft_maxlnk(char **tab);
int		ft_longlen(unsigned long n);
char	*ft_time(const time_t *t);

struc	s_params
{
	int	maxsiz;
	int	maxlnk;
	int maxuid;
	int maxgid;
	char *filename;
	char *uid_name;
	char *gid_name;
};

#endif
