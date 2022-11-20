/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:33:21 by mrabat            #+#    #+#             */
/*   Updated: 2022/11/20 04:09:17 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	checkline(dic_t *dic, int size, char **dic_tmp)
{
	int	i;
	int	j;
	int	k;
	int	check;

	check = 0;
	i = 0;
	while (i < size)
	{	j = 0;
		k = 0;
		while (dic_tmp[i][j] >= '0' && dic_tmp[i][j] <= '9')
		{
			dic[i].num = dic[i].num * 10 + dic_tmp[i][j] - 48;
			j++;
			check = j;
		}
		if (j == 0)
		{
			printstr("error base");
		}
		while (dic_tmp[i][j] == ' ')
		{
			j++;
		}
		if (dic_tmp[i][j] == ':')
			j++;
		else
			printstr("erreur :");
		while (dic_tmp[i][j] == ' ')
                {
                        j++;
                }
		while (dic_tmp[i][j] != '\n')
		{
			if(dic_tmp[i][j] == ' ' && dic_tmp[i][j+1] == ' ')
			{
				j++;
			}
			else
			{		
				dic[i].traduction[k]=dic_tmp[i][j];
				k++;
				j++;
			}
			
			
			
		}
		i++;
	}

}

