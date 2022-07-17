/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <fooswyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:34:22 by fooswyn           #+#    #+#             */
/*   Updated: 2022/07/17 22:19:04 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

void    print_info(t_pthread *philo, char *str, int flag)
{
	sem_wait(philo->data->end);
	if (str)
		printf("%lld ms :: %d philo %s\n", time_now() - philo->data->time, philo->i, str);
	if (flag)
		sem_post(philo->data->end);
}

void    take_put_fork(t_pthread *philo, int flag)
{
	if (flag)
	{
        sem_post(philo->data->sem);
        sem_post(philo->data->sem);
	}
	else
	{
        sem_wait(philo->data->sem);
		print_info(philo, "has taken a fork", 1);
        sem_wait(philo->data->sem);
		print_info(philo, "has taken a fork", 1);
	}
}

void    *routine(void *philosopher)
{
	t_pthread   *philo;

	philo = philosopher;
	if (!(philo->i % 2))
		spi(philo->data->time_eat / 2);
	while (1)
	{
		take_put_fork(philo, 0);
		print_info(philo, "is eating", 1);
		spi(philo->data->time_eat);
		take_put_fork(philo, 1);
		philo->eat_count++;
		philo->time = time_now();
		print_info(philo, "is sleeping", 1);
		spi(philo->data->time_sleep);
		print_info(philo, "is thinking", 1);
	}  
}

void    *manage(t_pthread *philo)
{
    pthread_t proc;
    
    pthread_create(&proc, NULL, routine, philo);
    pthread_detach(proc);
	while (1)
	{
		if (philo->data->nb_eat)
			if (philo->eat_count >= philo->data->nb_eat)
                free_exit(philo->data, 0);
		if (time_now() - philo->time >= philo->data->time_death)
		{
			print_info(philo, "died", 0);
			free_exit(philo->data, 1);
		}
        usleep(50);
	}
}

void	ft_exit(t_data *data, int *pids, int size)
{
	int	status;

	if (size == data->nb_philo)
	{
		free(pids);
		free_exit(data, 0);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 1)
			ft_kill(data, pids);
		else
			ft_exit(data, pids, size + 1);
	}
	else
		ft_kill(data, pids);
	if (size == data->nb_philo)
	{
		free(pids);
		free_exit(data, 0);
	}
}	