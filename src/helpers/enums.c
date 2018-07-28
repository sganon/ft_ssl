/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:24:36 by sganon            #+#    #+#             */
/*   Updated: 2018/07/28 22:32:54 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

const char *getSSLFunction(SSLFunction f)
{
  const char *strings[] = {"md5", "sha256"};
  return strings[f];
}

int toSSLFunction(char *f)
{
  int i;
  const t_functions_value conversions[] = {
    {0, "md5"},
    {1, "sha256"}
  };

  i = -1;
  while (++i < 2)
  {
    if (!ft_strcmp(conversions[i].val, f))
      return conversions[i].f;
  }
  return -1;
} 