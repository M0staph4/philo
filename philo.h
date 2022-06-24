/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 03:48:36 by mmoutawa          #+#    #+#             */
/*   Updated: 2022/06/22 21:09:32 by mmoutawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 #include <sys/time.h>

typedef struct t_data
{
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int hw_eat;
    int is_death;
    long long start;
    pthread_mutex_t *lf_fork;
    pthread_mutex_t *rg_fork;
    pthread_t philo;
    int hw_philo;
    pthread_mutex_t write;
    pthread_mutex_t meal;
    int id;
    long long lt_time;
}   t_data;


typedef struct s_philo
{
    t_data *data;
    pthread_mutex_t *fork;
    int nb_philo;
    int is_eat;
    
}   t_philo;

long	ft_atoi(const char *str);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    error_msg();


#endif