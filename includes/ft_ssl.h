/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:18:40 by sganon            #+#    #+#             */
/*   Updated: 2018/07/28 23:55:06 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"

typedef enum FUNCTION_TYPES {MD5, SHA256} SSLFunction;

typedef struct  s_functions_value
{
  SSLFunction   f;
  char          *val;
}               t_functions_value;
typedef struct  s_hasher
{
  void(*handler)(char *msg);
  char          *msg;
}               t_hasher;
typedef struct  s_ssl
{
  t_hasher      *hasher;
  SSLFunction   current_function;
}               t_ssl;


typedef struct  s_parsing_index
{
  int           index;
  SSLFunction   func;
}               t_parsing_index;

void        arg_parser(t_ssl *ssl, int argc, char **argv);
void        md5_parser(t_ssl *ssl, char **argv);
void        print_help(int level);
const char  *getSSLFunction(SSLFunction f);
int         toSSLFunction(char *f);
void        print_available_funcs(char *tried);
void        md5_handler(char *msg);

#endif
