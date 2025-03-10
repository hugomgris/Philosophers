/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmunoz-g <hmunoz-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:56:52 by hmunoz-g          #+#    #+#             */
/*   Updated: 2025/01/20 16:27:46 by hmunoz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
Just prints.
*/
void	ph_print_status(t_philo *philo, char *status)
{
	printf("%ld %d %s\n", ph_get_time() - philo->table->t_start,
		philo->id, status);
}

/*
Printing pre-function. 
Checks status, calls printing function to output specific messages.
*/
void	ph_process_status(t_philo *philo, bool death, t_status status)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (ph_check_simulation_end(philo->table) == true && death == false)
	{
		pthread_mutex_unlock(&philo->table->print_lock);
		return ;
	}
	if (status == DEAD)
		ph_print_status(philo, "died");
	else if (status == EATING)
		ph_print_status(philo, "is eating");
	else if (status == SLEEPING)
		ph_print_status(philo, "is sleeping");
	else if (status == THINKING)
		ph_print_status(philo, "is thinking");
	else if (status == GOT_LEFT_FORK || status == GOT_RIGHT_FORK)
		ph_print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->table->print_lock);
}
