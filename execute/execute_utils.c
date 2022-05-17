/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:16:32 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/07 14:58:16 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_str_tolower(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = (char)ft_tolower(s[i]);
		i++;
	}
	return (s);
}

bool	exec_error(t_shell *shell, t_cmd *cmd)
{
	if (ft_strncmp(cmd->args[0], ".", 2) == 0)
	{
		put_error("minishell", "filename argument required", cmd->args[0]);
		shell->exit_status = 2;
		return (FALSE);
	}
	else if (ft_strncmp(cmd->args[0], "..", 3) == 0)
	{
		put_error("minishell", cmd->args[0], "command not found.");
		shell->exit_status = 127;
		return (FALSE);
	}
	else if (ft_strncmp(cmd->args[0], "./", 3) == 0
		|| ft_strncmp(cmd->args[0], "../", 4) == 0
		|| ft_strncmp(cmd->args[0], "//", 2) == 0
		|| ft_strncmp(cmd->args[0], "/./", 3) == 0
		|| ft_strncmp(cmd->args[0], ".//", 3) == 0)
	{
		put_error("minishell", "is a directory.", cmd->args[0]);
		shell->exit_status = 126;
		return (FALSE);
	}
	return (TRUE);
}

bool	check_exec(t_shell *shell, t_cmd *cmd, char *path)
{
	if (path == NULL)
	{
		put_error("minishell", "command not found.", cmd->args[0]);
		shell->exit_status = 127;
		return (FALSE);
	}
	if (!exec_error(shell, cmd))
		return (FALSE);
	return (TRUE);
}

void	waiting(t_shell *shell, t_cmd *cmd)
{
	int	status;

	waitpid(cmd->pid, &status, 0);
	if (WIFEXITED(status))
		shell->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		shell->exit_status = 128 + WTERMSIG(status);
}
