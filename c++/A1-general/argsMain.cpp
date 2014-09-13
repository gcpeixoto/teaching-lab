/* \file   argsMain.cpp
 * \author Gustavo Charles P. de Oliveira
 * 
 * \description Understanding arguments of the main() function.
 *
 * \note The function <main> can be defined with or without parameters,
 * using any of the following four forms:
 *
 * i)   int main (void)
 * ii)  int main () 
 * iii) int main (int argc, char *argv[])
 * iv)  int main (int argc, char **argv)
 *
 * Any name can be given to the parameters, but "argc" and "argv" are
 * the usual forms.
 *
 * -- argc (argument count): integer that indicates how many arguments were
 * entered on the command line when the program was started.
 *
 * -- argv (argument vector): array of pointers to arrays "char".
 *
 * ---- (1st element) argv[0]: pointer to the "char" that contains the
 *  program name or invocation name;
 * ---- (2nd element and so on...) argv[n]: arguments
 */

#include <stdio.h>

/* Outputs the list of arguments called along with the main
 * For instance, compile and run this file: 
 * ./args alfa beta gamma 
 * to see the output "alfa beta gamma" */
int main(int argc, char *argv[])
{
	while ( --argc > 0 )
	 printf("%s", argv[argc]); // %s prints strings

}





