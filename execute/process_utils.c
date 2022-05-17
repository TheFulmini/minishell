/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:01:25 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/07 09:57:00 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_append_env_var_to_str(t_shell *shell, char *str, char *key)
{
	char	*res;

	res = ft_append_str(str, get_env_var(shell, key), TRUE, TRUE);
	free(key);
	return (res);
}

char	*get_env_var_name(char *arg, size_t len, size_t *i)
{
	char	*res;

	res = NULL;
	(*i)++;
	while (*i < len && (ft_isalnum(arg[*i])
			|| arg[*i] == '?' || arg[*i] == '_'))
	{
		res = ft_append_char_to_str(res, arg[*i]);
		(*i)++;
		if (arg[*i - 1] == '?')
			break ;
	}
	return (res);
}

bool	is_redir(char *arg)
{
	if (ft_strcmp(arg, ">>") == 0
		|| ft_strcmp(arg, ">") == 0
		|| ft_strcmp(arg, "<<") == 0
		|| ft_strcmp(arg, "<") == 0)
		return (TRUE);
	return (FALSE);
}
