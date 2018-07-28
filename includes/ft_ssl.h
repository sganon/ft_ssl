/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:18:40 by sganon            #+#    #+#             */
/*   Updated: 2018/07/28 19:40:51 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"

typedef enum FUNCTION_TYPES {MD5, SHA256} SSLFunctions;

void arg_parser(int argc, char **argv);
void print_help(int level);

#endif