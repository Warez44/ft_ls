/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clingier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:05:51 by clingier          #+#    #+#             */
/*   Updated: 2018/11/05 14:05:54 by clingier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>

void    ft_malfailed(void *ptr) {
  if (ptr == NULL)
  {
    free(ptr);
    ft_putstr_fd("Not enough memory!", 2);
    exit(EXIT_FAILURE);
  }
}

void  nodirectory(char *directory)
{
  ft_putstr_fd("ls: ", 2);
  perror(directory);
}
