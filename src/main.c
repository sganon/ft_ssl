/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:15:42 by sganon            #+#    #+#             */
/*   Updated: 2018/07/28 22:11:45 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		main(int argc, char **argv)
{
  t_ssl  *ssl;

  ssl = (t_ssl *)malloc(sizeof(t_ssl));
  if (!ssl)
    return (1);
  arg_parser(ssl, argc, argv);
}