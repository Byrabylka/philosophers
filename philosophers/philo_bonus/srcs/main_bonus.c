/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <fooswyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:58:18 by fooswyn           #+#    #+#             */
/*   Updated: 2022/07/17 22:09:47 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

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

void    init_semaphor(t_data *data)
{
    sem_unlink("sem");
    sem_unlink("end");
    data->sem = sem_open("sem", O_CREAT, 0644, data->nb_philo);
    data->end = sem_open("end",  O_CREAT, 0644, 1);
    if (data->sem == SEM_FAILED || data->end == SEM_FAILED)
    {
        free(data->philos);
        exit(0);
    }
}

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->time = time_now();
	while (i < data->nb_philo)
	{
		data->philos[i].i = i + 1;
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		data->philos[i].time = data->time;
		i++;
	}
}

void    *init_thread(t_data *data)
{
    int i;
    int pid;
    int *pids;

    i = 0;
    init_semaphor(data);
	pids = malloc(sizeof(int) * data->nb_philo);
    while (i < data->nb_philo)
    {
        pid = fork();
        if (!pid)
            manage(&data->philos[i]);
		else
        	pids[i] = pid;
        i++;
    }
    return (pids);
}

int main(int argc, char **argv)
{
    t_data  data;
    int     *pid;

	if ((argc != 5 && argc != 6) || !check_args(argc, argv))
		return(printf("Wrong arguments\n"));
	data.nb_philo = ft_atoi(argv[1]);
	data.time_death = ft_atoi(argv[2]);
	data.time_eat = ft_atoi(argv[3]);
	data.time_sleep = ft_atoi(argv[4]);
	data.nb_eat = 0;
	if (argc == 6)
		data.nb_eat = ft_atoi(argv[5]);
	data.philos = malloc(sizeof(t_pthread) * data.nb_philo);
	if (!data.philos)
		return (printf("Allocation Error\n"), 1);
    init_data(&data);
 	pid = init_thread(&data);
	sem_close(data.end);
	sem_close(data.sem);
	ft_exit(&data, pid, 0);   
}