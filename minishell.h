/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:41:08 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/09 18:31:06 by vzayas-s         ###   ########.fr       */
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
	int		n_cmd;
	int		size;

	int		words;
	int		quotes;
	int		double_quotes;
	int		pipes;

	int		lesser;
	int		greater;
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

	// GET_DATA
void	get_data(t_cmd	*args, char	*prompt);
int		i_cwords(t_cmd	*cmd, char	*prompt, int pos);
int		i_qwords(t_cmd	*cmd, char	*prompt, int pos);
int		i_dqwords(t_cmd	*cmd, char	*prompt, int pos);
int		i_pipes(t_cmd	*cmd, int i);
int		i_in(t_cmd	*cmd, int i);
int		i_out(t_cmd	*cmd, int i);

	// LEXER
char	*clean_words(t_cmd	*cmd, char	*prompt, int pos);
char	*quotes_lexer(t_cmd	*cmd, char	*prompt, int pos);
char	*double_quotes_lexer(t_cmd	*cmd, char	*prompt, int pos);
char	*pipes_lexer(t_cmd	*cmd, char	*prompt, int pos);
char	*out_lexer(t_cmd	*cmd, char	*prompt, int pos);
char	*in_lexer(t_cmd	*cmd, char	*prompt, int pos);

	// PIPEX
void	exec(t_cmd	*token, char	**env);
char	*ft_path(char	**enviroment_path);
char	*get_cmd(char	*arguments, char	**enviroment);

	// FREE_ARGS
void	free_args(t_cmd	*args);

	//BUILTINGS
void ft_builtings(t_cmd	*args, t_env *env);

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

	//UNSET
void    ft_unset(t_env *env, char *content);

	// TO _ DO
		//leak dup env
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

#endif


//EJEMPLO DE EXPORT SIN ARGUMENTO
/* 
vzaya-s@DESKTOP-JGC5LIT:~/42/minishell$ export
declare -x COLORTERM="truecolor"
declare -x GIT_ASKPASS="/home/vzaya-s/.vscode-server/bin/e2816fe719a4026ffa1ee0189dc89bdfdbafb164/extensions/git/dist/askpass.sh"
declare -x HOME="/home/vzaya-s"
declare -x HOSTTYPE="x86_64"
declare -x LANG="C.UTF-8"
declare -x LESSCLOSE="/usr/bin/lesspipe %s %s"
declare -x LESSOPEN="| /usr/bin/lesspipe %s"
declare -x LOGNAME="vzaya-s"
declare -x LS_COLORS="rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:"
declare -x NAME="DESKTOP-JGC5LIT"
declare -x OLDPWD="/home/vzaya-s/42"
declare -x PATH="/home/vzaya-s/.vscode-server/bin/e2816fe719a4026ffa1ee0189dc89bdfdbafb164/bin/remote-cli:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/usr/lib/wsl/lib:/mnt/c/WINDOWS/system32:/mnt/c/WINDOWS:/mnt/c/WINDOWS/System32/Wbem:/mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/:/mnt/c/WINDOWS/System32/OpenSSH/:/mnt/c/Program Files (x86)/NVIDIA Corporation/PhysX/Common:/mnt/c/Users/El F/AppData/Local/Microsoft/WindowsApps:/mnt/c/Users/El F/AppData/Local/Programs/Microsoft VS Code/bin"
declare -x PWD="/home/vzaya-s/42/minishell"
declare -x SHELL="/bin/bash"
declare -x SHLVL="2"
declare -x TERM="xterm-256color"
declare -x TERM_PROGRAM="vscode"
declare -x TERM_PROGRAM_VERSION="1.75.0"
declare -x USER="vzaya-s"
declare -x VSCODE_GIT_ASKPASS_EXTRA_ARGS=""
declare -x VSCODE_GIT_ASKPASS_MAIN="/home/vzaya-s/.vscode-server/bin/e2816fe719a4026ffa1ee0189dc89bdfdbafb164/extensions/git/dist/askpass-main.js"
declare -x VSCODE_GIT_ASKPASS_NODE="/home/vzaya-s/.vscode-server/bin/e2816fe719a4026ffa1ee0189dc89bdfdbafb164/node"
declare -x VSCODE_GIT_IPC_HANDLE="/tmp/vscode-git-263c834e1e.sock"
declare -x VSCODE_IPC_HOOK_CLI="/tmp/vscode-ipc-f5c8611d-281f-4657-b379-ca1cb87e4a2e.sock"
declare -x WSLENV="VSCODE_WSL_EXT_LOCATION/up"
declare -x WSL_DISTRO_NAME="Ubuntu-20.04"
declare -x WSL_INTEROP="/run/WSL/8_interop"
vzaya-s@DESKTOP-JGC5LIT:~/42/minishell$  */