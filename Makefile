all: hw1 hw3 hw5 hw7

clean:
	rm -f hw1 hw3 hw5 hw7

hw1: hw1.c
	gcc -o hw1 hw1.c -Wall
hw3: hw1.c
	gcc -o hw3 hw3.c -Wall
hw5: hw1.c
	gcc -o hw5 hw5.c -Wall
hw7: hw1.c
	gcc -o hw7 hw7.c -Wall
