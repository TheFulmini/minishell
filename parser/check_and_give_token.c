/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_give_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:19:46 by afulmini          #+#    #+#             */
/*   Updated: 2022/03/07 13:35:17 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_and_give_token(t_cmd_container *cmd_container, char c)
{
	if (c == ' ')
		next_token(cmd_container);
	else if (c == '\'' || c == '\"')
		tokenise_quote(cmd_container, c);
	else if (c == '>' || c == '<')
		tokenise_redir(cmd_container, c);
	else if (c == '|')
		tokenise_pipe(cmd_container);
	else if (c == ';')
		next_cmd(cmd_container);
	else
		cmd_container->token = ft_append_char_to_str(cmd_container->token, c);
}
