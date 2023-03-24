	// TO _ DO
		// 1. EXIT STATUS
			// Exit Status can return a variety of differet numbers, depending on the outcome of the input:
			// How can we get the Exit Status of an Executed Command?
			// Simple, we just need to transfer the exit value of the child process (responsible for executing the command),
			// to the parent process.

			// To do this, reading some lines of the wait(2) manual of Linux is preferible.
			// We basically use a paramater inside wait & waitpid functions (int &wstatus), an integer that is most useful when we need to handle errors
			// With this integer and some macros, we can inspect the value that the child process WAS EXITED WITH!

			// We just need to put this value inside our structure, so to do that, we need to make the "exec_cmd" function return the value for the structure to handle it from above
			// or just give a pointer to the function.

			// Personally, I prefer to make it return the integer, so the type of the function is taken advantage of.
			// So it would look like this:
			// int	exec_cmd(char **cmd, t_env *env)
		// 2. REDIRECCIONES
			//format : "[in_command / out_command] [output / input]".
		// 3. PARSEO
			// lexer-> double quotes: [echo "$PWD $USER $TERM ..." | wc]

	// DONE
		// add int in exec funct to controll cmd error, if 1 fail, pipes stop.
			// Not needed anymore!
			// Bash executes the last command no matter 
			// what the input it is given by a pipe!
			// So we have it as we should -> Check.

	// STEPS TO MAKE MINISHELL
		//lexer(); //comillas simples, comillas dobles, pipes, redirecciones
		// 1.er paso
			//encuentro comilla, leo hasta la siguiente comilla 
			//(si no hay doy error), lo meto en un token
			//p.e.: ls 'hola buenas "tardes $hehe"' | pwd 
			//token 1 = ls, token 2 = 'hola buenas "tardes $hehe"' token 3 = pwd
				//p.e.: ls -la  'h''u'
				//p.e.:               ls    ' '  -l a  'h'
				//p.e.:   - l a a'' a
				//p.e: && prompt[i] == '\t'
				//$ recive numeros o letras no caracteres especiales. 
				//if $en mstring cortar.
				//while (prompt)
				//if (prompt[i] == '\'') -> else if 
				//(prompt[i] == '"') else if (prompt[i] == '|') else
		//builtings();
		//parser();
		//redirs();
		//execute();
	// PIPEX
	//args = ft_split(aux, ' ');
	//printf("cual es el resultado de args -> %s\n", *args);
	//path = get_cmd(*args, env);
	//execve(path, args, env);

	//FALLOS
	//SHLVL doesn't aument

	//OPTIONAL
	// delete ctrl c on signal
	// cmd options interpretate all exec options & ignore inextents