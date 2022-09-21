/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:23:33 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/21 17:09:02 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/libft.h"

// 1. Get a string
// 2. Split into chars (1 char = 8 bits)
// 3. Split char into bits
// 4. Send SIGUSR1 -> Bit = 0
//    Send SIGUSR2 -> Bit = 1

typedef struct s_vars {
	int		len;
	int		i;
	int		current_bit;
	char	current_char;
}	t_vars;

void	send_message(int pid, char *str)
{
	t_vars	vars;

	vars.len = ft_strlen(str);
	vars.i = 0;
	while (vars.i < vars.len)
	{
		vars.current_char = str[vars.i];
		vars.current_bit = 0;
		while (vars.current_bit < 8)
		{
			if (vars.current_char & (1 << vars.current_bit))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(500);
			vars.current_bit++;
		}
		vars.i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	send_message(ft_atoi(av[1]), av[2]);
}
