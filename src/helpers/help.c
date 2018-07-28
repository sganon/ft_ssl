/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 19:08:06 by sganon            #+#    #+#             */
/*   Updated: 2018/07/28 19:42:37 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void print_help(int level)
{
  (void)level;
  ft_putstr("usage: ft_ssl command [command opts] [command args]\n");
}