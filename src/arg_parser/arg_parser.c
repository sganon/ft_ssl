/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:20:15 by sganon            #+#    #+#             */
/*   Updated: 2018/07/29 00:04:31 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

#include <stdio.h>

static int setSSLFunction(t_ssl *ssl, char *f)
{
int ssl_func;

ssl_func = toSSLFunction(f);
if (ssl_func < 0)
return -1;
  ssl->current_function = ssl_func;
  return ssl->current_function;
}

int get_function_index(t_ssl *ssl, t_parsing_index *conv)
{
  int i;

  i = -1;
  while (++i < 1)
  {
    if (ssl->current_function == conv[i].func)
      return conv[i].index;
  }
  return -1;
}


void arg_parser(t_ssl *ssl, int argc, char **argv)
{
  int err;
  void (*parsing_functions[1])(t_ssl *ssl, char **argv) = {md5_parser};
  t_parsing_index conv[] = {
    {0, toSSLFunction("md5")}
  };
  
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

  (*parsing_functions[get_function_index(ssl, conv)])(ssl, argv);
  // ft_putstr(getSSLFunction(ssl->current_function));
}
