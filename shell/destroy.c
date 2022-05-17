/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:34:44 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/07 13:37:33 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*destroy_shell(t_shell *shell)
{
	if (shell != NULL)
	{
		shell->env = ft_destroy_strarray(&shell->env);
		free(shell->prompt);
		shell->prompt = NULL;
		destroy_cmd_container(&shell->cmd_container);
	}
	return (NULL);
}

void	exit_shell(t_shell *shell, char*message, int exit_code)
{
	if (message != NULL)
		ft_putendl_fd(message, 2);
	destroy_shell(shell);
	exit(exit_code);
}
