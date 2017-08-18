mystack:stack.o push.o pop.o display.o
	gcc -o mystack ./../object/stack.o ./../object/push.o ./../object/pop.o ./../object/display.o

stack.o:
	gcc -c stack.c -o ./../object/stack.o -I ./../headers 
push.o:
	gcc -c push.c -o ./../object/push.o -I ./../headers
pop.o:
	gcc -c pop.c -o ./../object/pop.o  -I ./../headers
display.o:
	gcc -c display.c  -o ./../object/display.o -I  ./../headers
clean:
	rm *.o mystack
