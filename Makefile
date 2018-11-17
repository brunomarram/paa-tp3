linux:
	gcc file.h file.c hash.h hash.c piramide.h piramide.c main.c -o exec
clean:
	rm exec
run:
	./exec