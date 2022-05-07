matrix_calculator: mymat.o mainmat.o input_handler.o matrix_utils.o
	gcc  -ansi -Wall -pedantic mainmat.o mymat.o input_handler.o matrix_utils.o -o matrix_calculator -lm
mymat.o: mymat.c mymat.h
	gcc -c -ansi -Wall -pedantic mymat.c 
mainmat.o: mainmat.c mymat.h
	gcc -c -ansi -Wall -pedantic mainmat.c
input_handler.o: input_handler.c mymat.h
	gcc -c -ansi -Wall -pedantic input_handler.c
matrix_utils.o: input_handler.c mymat.h
	gcc -c -ansi -Wall -pedantic matrix_utils.c 
