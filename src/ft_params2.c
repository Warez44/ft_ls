/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:34:29 by clingier          #+#    #+#             */
/*   Updated: 2018/11/06 09:34:30 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

 char   *path_finder(char *directory, char *filename)
 {
   char *file_path;
   char *temp;

   ft_malfailed(file_path = ft_strjoin(directory, "/"));
   temp = file_path;
   ft_malfailed(file_path = ft_strjoin(file_path,filename));
   free(temp);
   return(file_path);
}
