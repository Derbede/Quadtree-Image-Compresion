build:
	gcc  -std=gnu11 -g -Wall -o quadtree quadtree.c functions.c struct.h
clean:
	rm quadtree
run: 
	./quadtree