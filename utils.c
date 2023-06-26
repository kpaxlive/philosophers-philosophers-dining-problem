/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:10:00 by fayan             #+#    #+#             */
/*   Updated: 2022/08/26 16:10:02 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	timestamp(void)
{
	struct timeval	current;
	long int		time;

	gettimeofday(&current, NULL);
	time = current.tv_sec * 1000;
	time += current.tv_usec / 1000;
	return (time);
}

void	sleep_sys(int x)
{
	long int	t;

	t = timestamp() + x;
	while (timestamp() < t)
		usleep(10);
}

int	is_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	a;
	int	i;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		a = str[i] - 48 + (10 * a);
		i++;
	}
	return (a);
}
