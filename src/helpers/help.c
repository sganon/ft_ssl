/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 19:08:06 by sganon            #+#    #+#             */
/*   Updated: 2018/07/28 22:16:24 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void print_help(int level)
{
  if (level == 0)
    ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
}

void print_available_funcs(char *tried)
{
  ft_putstr("ft_ssl: Error: '");
  ft_putstr(tried);
  ft_putstr("' is an invalid command\n");
}