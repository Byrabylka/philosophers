/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Danil <Danil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:27:41 by fooswyn           #+#    #+#             */
/*   Updated: 2022/07/18 11:47:52 by Danil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

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
	pthread_mutex_t		end;
	pthread_mutex_t		*forks;
}	t_data;

long		ft_atoi(const char *str);
long long	time_now(void);
void		spi(unsigned long time);

int			check_nb_eat(int *count, t_pthread *philo);
void		print_info(t_pthread *philo, char *str, int flag);
void		*routine(void *philo);
void		*manage(t_data *data);
#endif