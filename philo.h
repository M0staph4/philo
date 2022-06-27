/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:48:36 by mmoutawa          #+#    #+#             */
/*   Updated: 2022/06/27 02:14:58 by mmoutawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	write;
	pthread_mutex_t	time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				hw_eat;
	int 			hmt_eat;
	int				is_death;
	long long		start;
	int				is_eating;
	int				hw_philo;
	int				id;
	int				nb_philo;
	long long		lt_eat;
}	t_philo;

long	ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_num(int ac, char **av);
void	init_data(t_philo *philo, int ac, char **av);
void	init_list(char **av, t_philo *philo);
long	right_time(void);
void	creat_threads (t_philo *philo);
void print(t_philo *philo, int mv);
void	check_died(t_philo *philo);

#endif