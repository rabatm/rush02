/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optique.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:47:26 by mrabat            #+#    #+#             */
/*   Updated: 2022/11/19 20:56:28 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sig;
	int	res;

	res = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r' || str[i] == ' '))
			i++;
	while (str[i] == '-- || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rest = res * 10 + str[i] - 48;
		i++;
	}
	return (res * signe);
}
