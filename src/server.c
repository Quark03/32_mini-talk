/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acinca-f <acinca-f@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:23:29 by acinca-f          #+#    #+#             */
/*   Updated: 2022/09/21 16:54:13 by acinca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <sys/types.h>
#include <unistd.h>

// 1. Get a string
// 2. Split into chars
// 3. Split chars into bits
// 4. Send SIGUSR1 -> Bit = 0
//    Send SIGUSR2 -> Bit = 1

typedef struct s_char {
	char	current_char;
	int		current_bit;
}	t_char;

t_char	g_character;

void	display_pid(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	msg_handler(int sig)
{
	if (sig == SIGUSR2)
		g_character.current_char |= (1 << g_character.current_bit);
	g_character.current_bit++;
	if (g_character.current_bit == 8)
	{
		ft_putchar_fd(g_character.current_char, 1);
		g_character.current_bit = 0;
		g_character.current_char = 0;
	}
}

int	main(void)
{
	display_pid();
	signal(SIGUSR1, msg_handler);
	signal(SIGUSR2, msg_handler);
	while (1)
		pause();
}
