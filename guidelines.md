	
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline_supp
	//  __unused -> Variables not used
	//  __attribute__((unused)) -> Variables not used
	
	// TO _ DO
		1. Solve redir between pipes
		2. Remove doube iterator in (pipes.c maybe) or counting 2 times check || pos
		IGNORE //3. remove ft_redir, use the warning message//
		4. Add malloc to $ variables for more than one with echo
		5. Bombardear ALSA

	// DONE

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
	// redir doesn't work with pipes

	//OPTIONAL
	// delete ctrl c on signal
	// cmd options interpretate all exec options & ignore inextents