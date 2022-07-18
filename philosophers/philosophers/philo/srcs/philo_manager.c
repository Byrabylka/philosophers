/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Danil <Danil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:01:08 by fooswyn           #+#    #+#             */
/*   Updated: 2022/07/18 11:46:12 by Danil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	lock_unlock_fork(t_pthread *philo, int flag)
{
	if (flag)
	{
		pthread_mutex_unlock(&philo->data->forks[(philo->i - 1)]);
		pthread_mutex_unlock(&philo->data->forks[(philo->i)
			% philo->data->nb_philo]);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->i - 1]);
		print_info(philo, "has taken a fork", 1);
		pthread_mutex_lock(&philo->data->forks[(philo->i)
			% philo->data->nb_philo]);
		print_info(philo, "has taken a fork", 1);
	}
}

void	print_info(t_pthread *philo, char *str, int flag)
{
	pthread_mutex_lock(&philo->data->end);
	if (str)
		printf("%lld ms :: %d philo %s\n", time_now() - philo->data->time,
			philo->i, str);
	if (flag)
		pthread_mutex_unlock(&philo->data->end);
}

int	check_nb_eat(int *count, t_pthread *philo)
{
	if (philo->eat_count >= philo->data->nb_eat)
		*count += 1;
	if (*count >= philo->data->nb_philo)
	{
		print_info(philo, NULL, 0);
		return (0);
	}
	return (1);
}

void	*routine(void *philosopher)
{
	t_pthread	*philo;

	philo = philosopher;
	if (!(philo->i % 2))
		usleep(50);
	while (1)
	{
		lock_unlock_fork(philo, 0);
		print_info(philo, "is eating", 1);
		spi(philo->data->time_eat);
		lock_unlock_fork(philo, 1);
		philo->eat_count++;
		philo->time = time_now();
		print_info(philo, "is sleeping", 1);
		spi(philo->data->time_sleep);
		print_info(philo, "is thinking", 1);
	}
}

void	*manage(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (1)
	{
		if (i == data->nb_philo)
		{
			i = 0;
			count = 0;
		}
		if (data->nb_eat)
			if (!check_nb_eat(&count, &data->philos[i]))
				return (NULL);
		if (time_now() - data->philos[i].time >= data->time_death)
		{
			print_info(&data->philos[i], "died", 0);
			return (NULL);
		}
		i++;
	}
	return (NULL);
}
