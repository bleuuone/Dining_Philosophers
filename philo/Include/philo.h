/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbrahm <aelbrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:56:50 by aelbrahm          #+#    #+#             */
/*   Updated: 2023/08/02 08:58:37 by aelbrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>		
# include <math.h>
# include <string.h>
# include <sys/time.h>
# define MAX_P 210
# define MTX_INIT 0xA
# define W_ARGS 0xB
# define DATA 0xC
# define P_CRT 0xD

typedef struct s_philo	t_philo;

typedef enum e_bool{
	false,
	true
}	t_bool;

typedef enum s_stat{
	TS_ALIVE,
	TS_TERMINATED
}	t_stat;

typedef struct s_share_data{
	pthread_mutex_t	write_mtx;
	pthread_mutex_t	termainate;
	pthread_mutex_t	l_eat_time;
	pthread_mutex_t	stat_p;
	pthread_mutex_t	dead;
	unsigned long	philo_num;
	unsigned long	philo_die;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	num_of_meals;
	unsigned long	start_sim_time;
	int				sim;
	t_philo			*philo;
}	t_share_data;

typedef struct s_philo{
	t_share_data	*data;
	pthread_t		tid;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	unsigned long	pid;
	unsigned int	last_meal;
	int				num_of_meal_taken;
	int				stat;
}	t_philo;

unsigned long	ft_atoi_parse(char *str);
unsigned int	time_line(void);
int				_err_(int err_id);
int				p_init(t_share_data *data);
void			ft_usleep(unsigned int time);
void			ft_write_stat(char *str, t_philo *p);
void			halt_simulation(t_share_data *data);
void			canva(void);
t_bool			inti_mtx(t_share_data *data);
t_bool			simulate(t_share_data *data, t_philo *p);
t_bool			data_init(int ac, char **av, t_share_data *data);
t_bool			routine(t_philo *p);
#endif