/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:54:13 by mmoutawa          #+#    #+#             */
/*   Updated: 2022/06/27 02:17:07 by mmoutawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_num(int ac, char **av)
{
	int	i;
	
	if(ft_atoi(av[1]) > 200 || ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (0);
	if (av[5] && ft_atoi(av[5]) <= 0)
			return (0);
	while (--ac > 0)
	{
		i = 0;
		if (av[ac][i] == '-' || av[ac][i] == '+')
			i++;
		while (av[ac][i])
		{
			if (av[ac][i] < '0' || av[ac][i] > '9')
				return (0);
			i++;
		}
	}
	return(1);
}

int check(t_philo *philo)
{
	int i = 0;
	int x = 0;
	while(i <= philo->nb_philo)
	{
		if (philo->hw_eat  == philo[i].hmt_eat)
			x++;
		if (x == philo->nb_philo)
			return(1);
		i++;
	}
	return(0);
		
}
void	check_died(t_philo *philo)
{
	while(!philo->is_death)
	{
		pthread_mutex_lock(&philo->time);
		if(right_time() - philo->lt_eat >= philo->time_to_die)
		{
			philo->is_death = 1;
			print(philo, 5);
		}
		pthread_mutex_unlock(&philo->time);
		if (check(philo))
			philo->is_death = 1;
	}
}