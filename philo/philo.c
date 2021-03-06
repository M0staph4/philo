/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoutawa <mmoutawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:51:29 by mmoutawa          #+#    #+#             */
/*   Updated: 2022/07/06 18:55:17 by mmoutawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac >= 5 && ac <= 6)
	{
		if (!check_num(ac, av))
		{
			printf("ERROR\n");
			return (0);
		}
		philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
		init_data(philo, ac, av);
		init_list(av, philo);
		creat_threads(philo);
	}
	return (0);
}
