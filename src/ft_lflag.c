/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 12:47:13 by clingier          #+#    #+#             */
/*   Updated: 2018/10/22 09:58:22 by clingier         ###   ########.fr       */
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

// char	*ft_params(char *filename, int maxlnk_format, int maxsiz_format)
// {
// 	char *str;
// 	char lnk_buf[maxlnk_format + 2];
// 	char siz_buf[maxsiz_format + 2];
// 	char uid_buf[maxuid_format];
// 	char *temp;
// 	struct stat stat_s;
//
// 	if(!(str = ft_strnew(13)))
// 		return (NULL);
// 	stat(filename, &stat_s);
// 	uid_buf[maxuid_format - 1] = '\0';
// 	ft_strpermission(stat_s.st_mode, str);
// 	ft_unsigneditoa((unsigned int)stat_s.st_nlink, maxlnk_format, lnk_buf);
// 	str = ft_freestrjoin(str,lnk_buf);
// 	uid_buf = ft_strformat(uid_name(stat_s.st_uid, uid_buf);
// 	str = ft_freestrjoin(str, uid_buf);
// 	str = ft_freestrjoin(str, "  ");
// 	str = ft_freestrjoin(str, gid_name(stat_s.st_gid));
// 	str = ft_freestrjoin(str, "  ");
// 	ft_unsigneditoa((unsigned long)stat_s.st_size, maxsiz_format, siz_buf);
// 	str = ft_freestrjoin(str, siz_buf);
// 	str = ft_freestrjoin(str, ft_time(&stat_s.st_mtime));
// 	return (str);
// }

void    ft_params(struct s_params param)
{
	char lnk_buf[param.maxlnk + 2];
	char siz_buf[param.maxsiz + 2];
	char gid_buf[param.maxgid + 1];
	char uid_buf[param.maxuid + 1];

	ft_putstr(param.permission);
	ft_unsigneditoa((unsigned int)param.statistics.st_nlink, param.maxlnk, lnk_buf);
	ft_putstr(lnk_buf);
	ft_strformat(uid_buf, param.uid, param.maxuid);
	ft_putstr(uid_buf);
	ft_putstr("  ");
	ft_strformat(gid_buf, param.gid, param.maxgid);
	ft_putstr(gid_buf);
	ft_putstr("  ");
	ft_unsigneditoa((unsigned long)param.statistics.st_size, param.maxsiz, siz_buf);
	ft_putstr(siz_buf);
	ft_putstr(ft_time(&param.statistics.st_mtime));
}

void	ft_lflag(char **tab, char *directory)
{
	struct s_params *parameters;
	int i;

	i = 0;
	parameters = (struct s_params *)malloc(sizeof(*parameters) * ft_tablen(tab));
	parameters = ft_getparams(directory, tab, parameters);
	while (tab[i])
	{
		ft_params(parameters[i]);
		ft_putendl(tab[i]);
		i++;
	}
}
