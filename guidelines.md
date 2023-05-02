	
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline_supp
	//  __unused -> Variables not used
	//  __attribute__((unused)) -> Variables not used

	//Doxygen Documentation Generator. for create documentation in fuctions.
	
	// TO _ DO
	- || and special characters exit minishell;
	- ls |  | revienta y traba la shell;
	- echo $USER | echo $USER '' < segfault;
	- cat << a > h doesn't work;
	- << >> should not work;
	- commands interactivo no retorna valor de salida;
	- echo hola > | ls :leak should send error,
	2. Bombardear ALSA


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