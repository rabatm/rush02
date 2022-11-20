/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:41:31 by mrabat            #+#    #+#             */
/*   Updated: 2022/11/20 03:11:29 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct dicStructure
{
	int     num;
	char    *traduction;
}		dic_t;

int	ft_atoi(char *str);
void    print(char c);
void    printstr(char *c);
int     checkline(dic_t *dic, int size, char **dic_tmp);

#endif
