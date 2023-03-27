	
	//  __unused -> Variables not used
	//  __attribute__((unused)) -> Variables not used
	
	// TO _ DO
		1. Solve redir between pipes
		2. Add malloc to $ variables for more than one with echo
		3. Bombardear ALSA
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