/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fooswyn <fooswyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:52:33 by fooswyn           #+#    #+#             */
/*   Updated: 2022/07/17 22:02:18 by fooswyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo_bonus.h"

void    ft_kill(t_data *data, int *pids)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		kill(pids[i], SIGKILL);
		i++;
	}
}