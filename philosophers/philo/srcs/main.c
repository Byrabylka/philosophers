/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <fooswyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:25:09 by fooswyn           #+#    #+#             */
/*   Updated: 2022/07/14 19:12:37 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

int check_args(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]) || ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philos[i].i = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		data->philos[i].time = data->time;
		i++;
	}	
}

void    init_threads(t_data *data)
{
	int i;

	i = 0;
	pthread_mutex_init(&data->death, NULL);
	while (i < data->nb_philo)
	{
		pthread_create(&data->philos[i].thread, NULL, routine, &data->philos[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_detach(data->philos[i].thread);
		i++;
	}
}

void    free_data(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&data->death);
	free(data->philos);
	free(data->forks);
}

int main(int argc, char **argv)
{
	t_data  data;

	if ((argc != 5 && argc != 6) || !check_args(argc, argv))
	{
		printf("Wrong arguments\n");
		return(0);
	}
	data.nb_philo = ft_atoi(argv[1]);
	data.time_death = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	data.nb_eat = 0;
	if (argc == 6)
		data.nb_eat = ft_atoi(argv[5]);
	data.philos = malloc(sizeof(t_pthread) * data.nb_philo);
	if (!data.philos)
		return (0);
	data.forks = malloc(sizeof(pthread_mutex_t) * data.nb_philo);
	 if (!data.forks)
		return (0);
	data.time = time_now();
	init_data(&data);
	init_threads(&data);
	manage(&data);
	free_data(&data);
}
