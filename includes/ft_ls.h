/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:00:38 by clingier          #+#    #+#             */
/*   Updated: 2018/10/22 09:44:43 by clingier         ###   ########.fr       */
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

struct s_params
{
	struct stat statistics;
	int len;
	unsigned int maxlnk;
	unsigned long maxsiz;
	int maxuid;
	int maxgid;
	char permission[14];
	char *uid;
	char *gid;
	char *mtime;
};

typedef struct s_file
{
	struct s_params paramters;
	char *filename;
	char *file_path;
}								t_file;

struct s_file *ft_getfiles(unsigned char flags, char *directory);
void	ft_flagerror(char t);
unsigned char ft_case(char c, unsigned char flags);
unsigned char ft_flag(int argc, char **argv);
int		ft_namesorting(const char *str1, const char *str2);
void	ft_revsort(t_file *file, int (*f)(const char *, const char *));
void	ft_sort(char **argv, int(*f)(const char *, const char *));
int		ft_tablen(char **argv);
int		ft_timecmp(const char *a, const char *b);
void	ft_strpermission(mode_t mode, char *buf);
void	ft_tabdel(char **a);
t_file *ft_filesorting(t_file *tab, unsigned char flags);
void	ft_unsigneditoa(unsigned int a, int format, char *str);
void	ft_unsignedlongitoa(unsigned long a, int format, char *str);
void	ft_lflag(char **tab, char *directory);
int		ft_len(unsigned int nb);
char	*uid_name(uid_t uid);
char	*gid_name(gid_t gid);
unsigned long	ft_maxsiz(struct s_params *parameters);
unsigned int	ft_maxlnk(struct s_params *parameters);
unsigned int	ft_maxuid(char **tab);
int		ft_longlen(unsigned long n);
char	*ft_time(const time_t *t);
struct s_params *ft_getparams(char *directory, char **tab, struct s_params *parameters);
void  ft_params(struct s_params param);
void	ft_strformat(char *str, char *buf, int maxlen);
void	ft_getstatistics(char **tab, struct s_params *parameters, char *directory);
void    ft_malfailed(void *ptr);
int		number_of_files(char *directory, unsigned char flags);
char   *path_finder(char *directory, char *filename);
void		ft_puttab(char **tab);
void  nodirectory(char *directory);



#endif
