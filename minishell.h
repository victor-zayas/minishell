/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:41:08 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/16 18:57:23 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
	char	**args;
	char	**cmd;
	char	**atrb;
	int		n_cmd;
	int		size;

	int		words;
	int		quotes;
	int		double_quotes;
	int		pipes;
	int		lesser;
	int		greater;
	int		dollars;
}		t_cmd;

typedef struct s_env
{
	char	*oldpwd;
	char	*pwd;
	char	**env;
}	t_env;

	// MAIN
void	init_args(t_cmd	*new);
void	print(t_cmd	*cmd);
void	ft_chopeadito(t_cmd	*args, t_env *env, char	*prompt);

	//LEXER
	// GET_TOKEN
void	get_token(t_cmd	*cmd, char	*prompt);
void	get_inter(t_cmd *cmd, t_env *env);

	// GET_DATA
void	get_data(t_cmd	*args, char	*prompt);
int		i_cwords(t_cmd	*cmd, char	*prompt, int pos);
int		i_qwords(t_cmd	*cmd, char	*prompt, int pos);
int		i_dqwords(t_cmd	*cmd, char	*prompt, int pos);
int		i_pipes(t_cmd	*cmd, int i);
int		i_in(t_cmd	*cmd, int i);
int		i_out(t_cmd	*cmd, int i);
int		i_dollars(t_cmd	*cmd, char	*prompt, int pos);

	// LEXER
char	*clean_words(t_cmd	*cmd, char	*prompt, int pos);
char	*quotes_lexer(t_cmd	*cmd, char	*prompt, int pos);
char	*double_quotes_lexer(t_cmd	*cmd, char	*prompt, int pos);
char	*pipes_lexer(t_cmd	*cmd, char	*prompt, int pos);
char	*out_lexer(t_cmd	*cmd, char	*prompt, int pos);
char	*in_lexer(t_cmd	*cmd, char	*prompt, int pos);

	// PIPEX
void	exec(char	**cmd, char	**env);
void	ft_child(char	**cmd, char	**enviroment1, int	*fds1);
void	ft_adult(char	**cmd, char	**enviroment2, int	*fds2);
char	*ft_path(char	**enviroment_path);
char	*get_cmd(char	*arguments, char	**enviroment);
void	error(char	*error);
void	ft_fd(t_cmd	*cmd, t_env	*env);

	// FREE_ARGS
void	free_args(t_cmd	*args);

	//BUILTINGS
void	ft_builtings(t_cmd	*args, t_env *env);

	//PWD
void	ft_pwd(void);

	//ECHO
void	ft_echo(t_cmd *args);

	//ENV
void	ft_env(t_env *env);

	//EXIT
int		ft_exit(t_cmd *args);

	//CD
bool	ft_cd(t_cmd *args, t_env *env);

	//EXPORT
void	ft_export(t_env	*env, char *content);
int		content_check(t_env	*env, char	*content);
void	print_export(char	**env);

	//UNSET
void	ft_unset(t_env *env, char *content);

	// CMD
void	ft_selector(t_cmd	*cmd, t_env	*env);
void	exec_cmd(char	**cmd, char	**enviroment);
char	*ft_stephen_jokin(t_cmd	*cmd, char	*str, int	i);
int		find_pipe(char	**args, int i);

#endif

	//  __unused -> Variables not used
	//  __attribute__((unused)) -> Variables not used

	// TO _ DO
		// repiping -> pipes
		// PARSEO
		// Execv	
	//lexer(); //comillas simples, comillas dobles, pipes, redirecciones
	// 1.er paso
		//encuentro comilla, leo hasta la siguiente comilla (si no hay doy error), lo meto en un token
			//p.e.: ls 'hola buenas "tardes $hehe"' pwd token 1 = ls, token 2 = 'hola buenas "tardes $hehe"' token 3 = pwd
			//p.e.: ls -la  'h''u'
			//p.e.:               ls    ' '  -l a  'h'
			//p.e.:   - l a a'' a
			//p.e: && prompt[i] == '\t'
			//$ recive numeros o letras no caracteres especiales. if $en mstring cortar.
			//while (prompt)
				//if (prompt[i] == '\'') -> else if (prompt[i] == '"') else if (prompt[i] == '|') else
	//builtings();
	//parser();
	//redirs();
	//execute();

	// PIPEX
	//args = ft_split(aux, ' ');
	//printf("cual es el resultado de args -> %s\n", *args);
	//path = get_cmd(*args, env);
	//execve(path, args, env);

//EXAMPLE expan $
/* c4r6s2:~ jaizpuru$ $PWD
bash: /Users/jaizpuru: is a directory
c4r6s2:~ jaizpuru$ env
TERM_PROGRAM=vscode
TERM=xterm-256color
HOMEBREW_TEMP=/tmp/jaizpuru/Homebrew/Temp
SHELL=/bin/zsh
TMPDIR=/var/folders/zz/zyxvpxvq6csfxvn_n000cbsw0032yg/T/
TERM_PROGRAM_VERSION=1.74.0
OLDPWD=/Users/jaizpuru/minishell
ORIGINAL_XDG_CURRENT_DESKTOP=undefined
MallocNanoZone=0
USER=jaizpuru
COMMAND_MODE=unix2003
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.VtdN9AeX7m/Listeners
__CF_USER_TEXT_ENCODING=0x18BCF:0x0:0x0
HOMEBREW_CACHE=/tmp/jaizpuru/Homebrew/Caches
PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Users/jaizpuru/.brew/bin
LaunchInstanceID=2F6E4AB0-C50B-46E0-95BE-E893CEB83AC5
a=0
c4r6s2:~ jaizpuru$ $pwd
c4r6s2:~ jaizpuru$ $PWD
bash: /Users/jaizpuru: is a directory
c4r6s2:~ jaizpuru$ env
TERM_PROGRAM=vscode
TERM=xterm-256color
HOMEBREW_TEMP=/tmp/jaizpuru/Homebrew/Temp
SHELL=/bin/zsh
TMPDIR=/var/folders/zz/zyxvpxvq6csfxvn_n000cbsw0032yg/T/
TERM_PROGRAM_VERSION=1.74.0
OLDPWD=/Users/jaizpuru/minishell
ORIGINAL_XDG_CURRENT_DESKTOP=undefined
MallocNanoZone=0
USER=jaizpuru
COMMAND_MODE=unix2003
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.VtdN9AeX7m/Listeners
__CF_USER_TEXT_ENCODING=0x18BCF:0x0:0x0
HOMEBREW_CACHE=/tmp/jaizpuru/Homebrew/Caches
PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Users/jaizpuru/.brew/bin
LaunchInstanceID=2F6E4AB0-C50B-46E0-95BE-E893CEB83AC5
a=0
PWD=/Users/jaizpuru
LANG=es_ES.UTF-8
VSCODE_GIT_ASKPASS_EXTRA_ARGS=--ms-enable-electron-run-as-node
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/jaizpuru
VSCODE_GIT_ASKPASS_MAIN=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass-main.js
LOGNAME=jaizpuru
VSCODE_GIT_IPC_HANDLE=/var/folders/zz/zyxvpxvq6csfxvn_n000cbsw0032yg/T/vscode-git-b7a04e0640.sock
VSCODE_GIT_ASKPASS_NODE=/Applications/Visual Studio Code.app/Contents/Frameworks/Code Helper.app/Contents/MacOS/Code Helper
GIT_ASKPASS=/Applications/Visual Studio Code.app/Contents/Resources/app/extensions/git/dist/askpass.sh
SECURITYSESSIONID=186a6
COLORTERM=truecolor
_=/usr/bin/env
c4r6s2:~ jaizpuru$ $PWD=
bash: /Users/jaizpuru=: No such file or directory
c4r6s2:~ jaizpuru$  */