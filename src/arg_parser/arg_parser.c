/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:20:15 by sganon            #+#    #+#             */
/*   Updated: 2018/07/28 22:33:13 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void arg_parser(t_ssl *ssl, int argc, char **argv)
{
  int ssl_func;
  if (argc == 1)
  {
    print_help(0);
    return ;
  }
  
  ssl_func = toSSLFunction(argv[1]);
  if (ssl_func < 0)
  {
    print_available_funcs(argv[1]);
    return ;
  }
  ssl->current_function = ssl_func;
  // ft_putstr(getSSLFunction(ssl->current_function));
}