	
	
	
	// LEAKS && SEGFAULT
	[SOLVED] || and special characters exit minishell;
		[SIMPLE FUNCTION INSIDE MAIN_ERROR ADDED]
	[SOLVED FOR 1st Command] ls |  | revienta y traba la shell;
		[NEED TO CREATE SEPARATED FILES TO CREATE GENERAL FUNCTIONS THAT CHECK EVERY COMMAND FROM START TO END]
	[NON SOLVED] - echo $USER | echo $USER '' < segfault;
		[DIFFICULT TO DO, REQUIRES TIME & EFFORT]
	[SOLVED]- cat << a > h doesn't work;
		[LAST COMMIT SOLVED IT]
	[NON_SOLVED] << >> should not work;
		[CHECK INSIDE DELIMITER IF THERE IS ANY SP_CHARACTER]
	[NON_SOLVED] commands interactivo no retorna valor de salida;
	[NON_SOLVED] echo hola > | ls :leak should send error,
	[NON_SOLVED] Bombardear ALSA

	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=readline_supp
	//  __unused -> Variables not used
	//  __attribute__((unused)) -> Variables not used