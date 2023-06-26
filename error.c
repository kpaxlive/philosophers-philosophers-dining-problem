/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:10:26 by fayan             #+#    #+#             */
/*   Updated: 2022/08/26 16:10:28 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_ate_enough(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->num_of_p)
		if (data->info[x].how_many_ate < data->ifmust_eat)
			return (0);
	return (1);
}

void	print_func(t_philoinfo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->pen);
	printf("%ldms %d %s\n", timestamp() - philo->data->time,
		philo->philo_id, str);
	pthread_mutex_unlock(&philo->data->pen);
}

void	verror(int a)
{
	if (a == 1)
		printf("Error: There should be 5 or 6 arguments\
 without any non-digit characters\n");
	else if (a == 2)
		printf("Error: Failed to allocate for data\n");
	if (a == 3)
		printf("Error: num_of_p, dying_t, sleeping_t,\
 eating_t and ifmust_eat can not be 0.\n");
	else if (a == 4)
		printf("Error: Failed to allocate for 'data->info'.\n");
	exit(1);
}
