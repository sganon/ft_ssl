/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:20:15 by sganon            #+#    #+#             */
/*   Updated: 2018/07/28 22:40:42 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int setSSLFunction(t_ssl *ssl, char *f)
{
  int ssl_func;

  ssl_func = toSSLFunction(f);
  if (ssl_func < 0)
    return -1;
  ssl->current_function = ssl_func;
  return ssl->current_function;
}

void arg_parser(t_ssl *ssl, int argc, char **argv)
{
  int err;

  if (argc == 1)
  {
    print_help(0);
    return;
  }

  err = setSSLFunction(ssl, argv[1]);
  if (err < 0)
  {
    print_available_funcs(argv[1]);
    return;
  }
  // ft_putstr(getSSLFunction(ssl->current_function));
}