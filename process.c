/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:09:48 by fayan             #+#    #+#             */
/*   Updated: 2022/08/26 16:09:50 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	begin(t_philoinfo *philo, int l, int r)
{
	pthread_mutex_lock(&philo->data->forks[l]);
	print_func(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[r]);
	print_func(philo, "has taken a fork");
	print_func(philo, "is eating");
	sleep_sys(philo->data->eating_t);
	pthread_mutex_lock(&philo->last_time_mutex);
	philo->last_ate_time = timestamp();
	pthread_mutex_unlock(&philo->last_time_mutex);
	philo->how_many_ate++;
	pthread_mutex_unlock(&philo->data->forks[l]);
	pthread_mutex_unlock(&philo->data->forks[r]);
	print_func(philo, "is sleeping");
	sleep_sys(philo->data->sleeping_t);
	print_func(philo, "is thinking");
}

int	check_if_died(t_data *data)
{
	int	x;

	while (1)
	{
		x = -1;
		while (++x < data->num_of_p)
		{
			pthread_mutex_lock(&data->info->last_time_mutex);
			if (timestamp() - data->info[x].last_ate_time >= data->dying_t)
			{
				pthread_mutex_lock(&data->pen);
				printf("%ldms %d %s", timestamp() - data->time,
					data->info[x].philo_id, "has died!\n");
				exit(0);
			}
			pthread_mutex_unlock(&data->info->last_time_mutex);
			if (data->ifmust_eat > 0 && check_if_ate_enough(data))
				exit(2);
		}
	}
	return (0);
}

void	*start_helper(void *name)
{
	t_philoinfo	*person;

	person = (t_philoinfo *) name;
	if (person->philo_id % 2 != 0)
		usleep(150);
	while (1)
		begin(person, person->l_fork, person->r_fork);
	return (NULL);
}

int	start_process(t_data *data)
{
	int	x;

	x = -1;
	while (++x < data->num_of_p)
		pthread_mutex_init(&data->forks[x], NULL);
	pthread_mutex_init(&data->pen, NULL);
	x = -1;
	data->time = timestamp();
	while (++x < data->num_of_p)
	{
		data->info[x].last_ate_time = timestamp();
		pthread_create(&data->info[x].thread,
			NULL, start_helper, (void *)&data->info[x]);
	}
	if (check_if_died(data))
		return (1);
	return (0);
}
