/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:00:44 by mmoutawa          #+#    #+#             */
/*   Updated: 2022/06/27 02:44:57 by mmoutawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping_and_eating(int time)
{
	long long ttime;
	ttime = right_time();
	while(right_time() < time + ttime)
		usleep(50);
}

void print(t_philo *philo, int mv)
{
	pthread_mutex_lock(&(philo->write));
	if (mv == 1)
		printf("%lld %d has taken a fork \n", (right_time() - philo->start), philo->id + 1);
	else if(mv == 2)
		printf("%lld %d is eating\n", (right_time() - philo->start), philo->id + 1);
	else if(mv == 3)
		printf("%lld %d is sleeping\n", (right_time() - philo->start), philo->id + 1);
	else if(mv == 4)
		printf("%lld %d is thinking\n",(right_time() - philo->start), philo->id + 1);
	else if(mv == 5)
		printf("%lld %d died\n", (right_time() - philo->start), philo->id + 1);
	pthread_mutex_unlock(&(philo->write));
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork[philo->id]);
	print(philo, 1);
	pthread_mutex_lock(&philo->fork[(philo->id + 1) % philo->nb_philo]);
	print(philo, 1);
	pthread_mutex_lock(&philo->time);
	print(philo, 2);
	philo->lt_eat = right_time();
	pthread_mutex_unlock(&philo->time);
	philo->hmt_eat++;
	sleeping_and_eating(philo->time_to_eat);
	pthread_mutex_unlock(&philo->fork[philo->id]);
	pthread_mutex_unlock(&philo->fork[(philo->id + 1) % philo->nb_philo]);
}

void	*routine(void *philo)
{
	t_philo *philoo;
	
	philoo = (t_philo*)philo;
	while(!philoo->is_death)
	{
		eat(philoo);
		print(philoo, 3);
		sleeping_and_eating(philoo->time_to_sleep);
		print(philoo, 4);
	}
	return(NULL);
}

void creat_threads(t_philo *philo)
{
	int i;
	pthread_t *thread;

	i = 0;
	thread = malloc(sizeof(pthread_t) * philo->nb_philo);
	while(i < philo->nb_philo)
	{
		philo[i].start = right_time();
		pthread_create(&thread[i], NULL, &routine, &philo[i]);
		philo[i].lt_eat = right_time();
		i++;
		usleep(50);
	}
	check_died(philo);
	free(thread);
}