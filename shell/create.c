/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:13:36 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/07 13:37:26 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	update_level(t_shell shell)
{
	char	*level;
	char	c;

	level = get_env_var(&shell, "SHLVL");
	c = level[0];
	level[0] = ++c;
	set_env(&shell, "SHLVL", level, TRUE);
	return (shell);
}

t_shell	create_shell(char **env)
{
	t_shell	shell;

	shell.env = create_env(env);
	shell.prompt = NULL;
	shell.double_out = FALSE;
	update_prompt(&shell);
	init_container(&shell.cmd_container);
	shell.in_exec = FALSE;
	shell.exit_status = 0;
	shell.level = 0;
	shell = update_level(shell);
	return (shell);
}
