/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Danil <Danil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:32:00 by fooswyn           #+#    #+#             */
/*   Updated: 2022/07/18 11:52:35 by Danil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(const char *str)
{
	int		i;
	long	s;
	long	result;

	i = 0;
	s = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * s);
}

long long	time_now(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, 0);
	return (curr_time.tv_sec * 1000 + (curr_time.tv_usec / 1000));
}

void	spi(unsigned long time)
{
	unsigned long	curr_time;

	curr_time = time_now();
	while (time_now() - curr_time < time)
		usleep(10);
}

void	free_exit(t_data *data, int flag)
{
	free(data->philos);
	exit(flag);
}
