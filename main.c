/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:09:29 by fayan             #+#    #+#             */
/*   Updated: 2022/08/26 16:09:33 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philoinfo	*get_philos(t_data *data)
{
	t_philoinfo	*info;
	int			x;

	x = -1;
	info = malloc(data->num_of_p * sizeof(t_philoinfo));
	while (++x < data->num_of_p)
	{
		info[x].philo_id = x + 1;
		info[x].r_fork = x;
		info[x].l_fork = x - 1;
		if (info[x].l_fork == -1)
			info[x].l_fork = data->num_of_p - 1;
		info[x].how_many_ate = 0;
		info[x].last_ate_time = 0;
		info[x].data = data;
	}
	return (info);
}

t_data	*get_infos(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->num_of_p = ft_atoi(argv[1]);
	data->dying_t = ft_atoi(argv[2]);
	data->eating_t = ft_atoi(argv[3]);
	data->sleeping_t = ft_atoi(argv[4]);
	if (argv[5])
		data->ifmust_eat = ft_atoi(argv[5]);
	else
		data->ifmust_eat = -1;
	if (data->num_of_p == 0 || data->dying_t == 0 || data->sleeping_t == 0
		|| data->eating_t == 0 || data->ifmust_eat == 0)
		verror(3);
	data->info = get_philos(data);
	if (!data->info)
		verror(4);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_p);
	if (!data->forks)
		return (NULL);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if ((argc != 5 && argc != 6) || (!is_digit(argc, argv)))
		verror(1);
	data = get_infos(argv);
	if (!data)
		verror(2);
	start_process(data);
}
