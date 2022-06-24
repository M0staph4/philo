#include "philo.h"

void	error_msg()
{
	printf("ERROR\n");
	exit(0);
}

void	check_num(int ac, char **av)
{
	int	i;

	while (--ac > 0)
	{
		i = 0;
		if (av[ac][i] == '-' || av[ac][i] == '+')
			i++;
		while (av[ac][i])
		{
			if (av[ac][i] < '0' || av[ac][i] > '9')
				error_msg();
			i++;
		}
	}
}

long right_time()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void mutex_init(t_philo *philo, int count)
{
	int i;
	i = -1;
	philo->fork = malloc(count * sizeof(pthread_mutex_t));
	while (++i < count)
		pthread_mutex_init(&philo->fork[i], NULL);
	pthread_mutex_init(&(philo->data->write), NULL);
	pthread_mutex_init(&(philo->data->meal), NULL);

}

void	init_data(t_philo *philo, int ac, char **av)
{
	int i;
	i = -1;
	while(++i < philo->nb_philo)
	{
		philo->data[i].time_to_die = ft_atoi(av[2]);
		philo->data[i].time_to_eat = ft_atoi(av[3]);
		philo->data[i].time_to_sleep = ft_atoi(av[4]);
		philo->data[i].hw_eat = -1;
		if (ac == 6)
			philo->data[i].hw_eat = ft_atoi(av[5]);
		philo->data[i].start = right_time();
		philo->data[i].id = i + 1;
		philo->data[i].lf_fork = &philo->fork[i];
		philo->data[i].rg_fork = &philo->fork[(i + 1) % philo->nb_philo];
	}
}

void	init_list(int ac, char **av, t_philo *philo)
{
	
	philo->nb_philo = ft_atoi(av[1]);
	philo->data = malloc(sizeof(t_data) * philo->nb_philo);
	mutex_init(philo, philo->nb_philo);
	init_data(philo, ac, av);
	
}

void print(t_data *data, int mv)
{
	
	pthread_mutex_lock(&(data->write));
	if (mv == 1)
		printf("%lld %d has taken a fork \n", (right_time() - data->start), data->id);
	else if(mv == 2)
	{
		printf("%lld %d is eating\n", (right_time() - data->start),data->id);
		data->hw_eat += 1;
	}
	else if(mv == 3)
		printf("%lld %d is sleeping\n", (right_time() - data->start), data->id);
	else if(mv == 4)
		printf("%lld %d is thinking\n",(right_time() - data->start), data->id);
	else if(mv == 5)
		printf("%lld %d died\n", (right_time() - data->start), data->id);
	pthread_mutex_unlock(&(data->write));
}

void	check_died(t_data *data)
{
	
	if(right_time() - data->lt_time > data->time_to_die)
	{
		print(data, 5);
		data->is_death = 1;
	}
}

void	sleeping(int time)
{
	long long ttime;
	ttime = right_time();
	while(right_time() < time + ttime)
		usleep(100);
}

void	eat(t_data *data)
{
	pthread_mutex_lock(data->lf_fork);
	print(data, 1);
	pthread_mutex_lock(data->rg_fork);
	print(data, 1);
	print(data, 2);
	sleeping(data->time_to_eat);
	pthread_mutex_unlock(data->lf_fork);
	pthread_mutex_unlock(data->rg_fork);
}

void	*routine(void *philo)
{
	t_data *data;;
	data = (t_data*)philo;
	
	while(!data->is_death)
	{
		eat(data);
		print(data, 3);
		sleeping(data->time_to_sleep);
		print(data, 4);
		check_died(data);
	}
	return(NULL);
}

void creat_threads(t_philo *philo)
{
	int i;
	i = 0;

	while(philo->nb_philo > i)
	{
		pthread_create(&philo->data[i].philo, NULL, &routine, &philo->data[i]);
		philo->data->lt_time = right_time();
		i++;
		usleep(50);
	}
	i = -1;
	while (philo->nb_philo > ++i)
		pthread_join(philo->data[i].philo, NULL);
}

int	main(int ac, char **av)
{
	t_philo philo;

	check_num(ac, av);
	init_list(ac, av, &philo);
	creat_threads(&philo);
	return(0);
}