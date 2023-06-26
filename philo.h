/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:10:17 by fayan             #+#    #+#             */
/*   Updated: 2022/08/26 16:10:19 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philoinfo
{
	int				philo_id;
	int				r_fork;
	int				l_fork;
	int				how_many_ate;
	long int		last_ate_time;
	struct s_data	*data;
	pthread_mutex_t	last_time_mutex;
	pthread_t		thread;
}t_philoinfo;

typedef struct s_data
{
	int				eating_t;
	int				sleeping_t;
	int				dying_t;
	int				num_of_p;
	int				ifmust_eat;
	long int		time;
	t_philoinfo		*info;
	pthread_mutex_t	*forks;
	pthread_mutex_t	pen;
}t_data;

int			is_digit(int argc, char **argv);
int			ft_atoi(char *str);
long int	timestamp(void);
void		sleep_sys(int x);
void		verror(int a);
int			start_process(t_data *data);
void		print_func(t_philoinfo *philo, char *str);
int			check_if_ate_enough(t_data *data);

#endif
