/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 23:00:54 by sganon            #+#    #+#             */
/*   Updated: 2018/07/28 23:59:28 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void md5_parser(t_ssl *ssl, char **argv)
{
  char buf[512];
  char *stdin;
  (void)ssl;
  (void)argv;
  stdin = (char *)malloc(sizeof(char));
  //ft_putstr("Hello world from md5 parser\n");
  while (read(0, buf, sizeof(buf)) > 0)
  {
      stdin = ft_strjoin(stdin, buf);
  }
  if (!ssl->hasher)
  {
    ssl->hasher = (t_hasher *)malloc(sizeof(t_hasher));
  }
  ssl->hasher->msg = stdin;
  ssl->hasher->handler = md5_handler;
}
