/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:47:07 by kkaneko           #+#    #+#             */
/*   Updated: 2022/03/24 23:45:21 by kkaneko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <signal.h>

static void	sig_handler_rl(sig_atomic_t sig);
static void	sig_handler_exec(sig_atomic_t sig);

void	receiver(sig_atomic_t sig, void (*handler)(sig_atomic_t))
{
	int					err_fg;
	struct sigaction	act;

	err_fg = 0;
	ft_bzero(&act, sizeof(struct sigaction));
	act.sa_handler = handler;
	act.sa_flags = SA_RESTART;
	err_fg += sigemptyset(&(act.sa_mask));
	err_fg += sigaction(sig, &act, NULL);
	if (err_fg < 0)
	{
		printf(INIT_ERR);
		exit(1);
	}
}

void	receiver_for_readline(void)
{
	receiver(SIGINT, sig_handler_rl);
	receiver(SIGQUIT, SIG_IGN);
}

void	receiver_for_exec(void)
{
	receiver(SIGINT, sig_handler_exec);
	receiver(SIGQUIT, sig_handler_exec);
}

static void	sig_handler_rl(sig_atomic_t sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	sig_handler_exec(sig_atomic_t sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: ", STDERR_FILENO);
		ft_putnbr_fd(sig, STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
}
