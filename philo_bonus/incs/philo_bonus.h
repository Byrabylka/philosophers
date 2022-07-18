/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Danil <Danil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:56:49 by fooswyn           #+#    #+#             */
/*   Updated: 2022/07/18 11:54:38 by Danil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <signal.h>
# include <sys/time.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pthread {
	long long		time;
	int				i;
	int				eat_count;
	struct s_data	*data;
	pthread_t		thread;
}	t_pthread;

typedef struct s_data
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	long long			time;
	t_pthread			*philos;
	sem_t				*end;
	sem_t				*sem;
}	t_data;

long		ft_atoi(const char *str);
long long	time_now(void);
void		spi(unsigned long time);
void		ft_kill(t_data *data, int *pids);
void		free_exit(t_data *data, int flag);

void		print_info(t_pthread *philo, char *str, int flag);
void		*routine(void *philo);
void		*manage(t_pthread *dphilo);
void		ft_exit(t_data *data, int *pids, int size);
#endif