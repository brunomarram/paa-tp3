linux:
	gcc file.h file.c hash.h hash.c piramide.h piramide.c main.c -o exec
mac:
	gcc -Wall -g  *.c -o exec
clean:
	rm exec
analysis:
	./exec analysis	
run:
	./exec run