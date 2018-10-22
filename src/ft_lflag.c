/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 12:47:13 by clingier          #+#    #+#             */
/*   Updated: 2018/10/22 09:11:32 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void	ft_strpermission(mode_t mode, char *buf)
{
	size_t i;
	char *characters = "rwxrwxrwx";

	i = 0;
	buf[0] = '-';
	buf[0] = (S_ISDIR(mode)) ? 'd' : buf[0];
	buf[0] = (S_ISBLK(mode)) ? 'b' : buf[0];
	buf[0] = (S_ISLNK(mode)) ? 'l' : buf[0];
	buf[0] = (S_ISFIFO(mode)) ? 'p' : buf[0];
	buf[0] = (S_ISCHR(mode) && !S_ISLNK(mode)) ? 'c' : buf[0];
	buf[0] = (S_ISSOCK(mode)) ? 's' : buf[0];
	while (i < 9)
	{
		buf[i + 1] = (mode & 1 << (8 - i)) ? characters[i] : '-';
		i++;
	}
	buf[10] = ' ';
	buf[11] = ' ';
	buf[12] = '\0';
}

char	*gid_name(gid_t gid)
{
	struct group *grp;

	grp = getgrgid(gid);
	return(grp->gr_name);
}

char	*uid_name(uid_t uid)
{
	struct passwd *pwd;

	pwd = getpwuid(uid);
	return(pwd->pw_name);
}

char	*ft_params(char *filename, int maxlnk_format, int maxsiz_format)
{
	char *str;
	char lnk_buf[maxlnk_format + 2];
	char siz_buf[maxsiz_format + 2];
	char *temp;
	struct stat stat_s;

	if(!(str = ft_strnew(13)))
		return (NULL);
	stat(filename, &stat_s);
	ft_strpermission(stat_s.st_mode, str);
	ft_unsigneditoa((unsigned int)stat_s.st_nlink, maxlnk_format, lnk_buf);
	str = ft_freestrjoin(str,lnk_buf);
	str = ft_freestrjoin(str, uid_name(stat_s.st_uid));
	str = ft_freestrjoin(str, "  ");
	str = ft_freestrjoin(str, gid_name(stat_s.st_gid));
	str = ft_freestrjoin(str, "  ");
	ft_unsigneditoa((unsigned long)stat_s.st_size, maxsiz_format, siz_buf);
	str = ft_freestrjoin(str, siz_buf);
	str = ft_freestrjoin(str, ft_time(&stat_s.st_mtime));
	return (str);
}

void	ft_lflag(char **tab)
{
	char *temp;
	char *str;
	unsigned int maxlnk;
	unsigned long maxsiz;

	maxlnk = ft_maxlnk(tab);
	maxsiz = ft_maxsiz(tab);
	while (*tab)
	{
		if(!(str = ft_params(*tab, ft_len(maxlnk), ft_longlen(maxsiz))))
		{
			ft_tabdel(tab);
			return ;
		}
		temp = *tab;
		*tab = ft_strjoin(str, *tab);
		tab++;
	}
}
