/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:55:54 by mmoutawa          #+#    #+#             */
/*   Updated: 2022/06/26 12:49:41 by mmoutawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_philo *philo, int ac, char **av)
{
	int i;
	int count;

	count = ft_atoi(av[1]);
	i = -1;
	while(++i < count)
	{
		philo[i].id = i;
		philo[i].nb_philo = ft_atoi(av[1]);
		philo[i].time_to_die = ft_atoi(av[2]);
		philo[i].time_to_eat = ft_atoi(av[3]);
		philo[i].time_to_sleep = ft_atoi(av[4]);
		philo[i].hw_eat = -1;
		philo[i].hmt_eat = 0;
		if (ac == 6)
			philo[i].hw_eat = ft_atoi(av[5]);
		philo[i].is_death = 0;
	}
}

void	init_list(char **av, t_philo *philo)
{	
	pthread_mutex_t *fork;
	int i;

	i = -1;
	fork = malloc(sizeof(pthread_mutex_t) * ft_atoi(av[1]));
	while (++i < philo->nb_philo)
		pthread_mutex_init(&fork[i], NULL);
	i = -1;
	while (++i < philo->nb_philo)
		philo[i].fork = fork;
	pthread_mutex_init(&(philo->write), NULL);
	pthread_mutex_init(&(philo->time), NULL);
}