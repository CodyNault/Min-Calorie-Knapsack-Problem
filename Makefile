all:
	g++ -o chipotle -I./include/ src/chipotle.C
debug:
	g++ -g -DDEBUG_MODE -o chipotle -I./include/ src/chipotle.C
run:
	g++ -o chipotle -I./include/ src/chipotle.C
	./chipotle < bin/inSample1.txt
test:
	g++ -o chipotle -I./include/ src/chipotle.C
	./chipotle < bin/inSample1.txt > bin/outTest1.txt
	diff bin/outTest1.txt bin/outSample1.txt
	./chipotle < bin/inSample2.txt > bin/outTest2.txt
	diff bin/outTest2.txt bin/outSample2.txt
	./chipotle < bin/inSample3.txt > bin/outTest3.txt
	diff bin/outTest3.txt bin/outSample3.txt
	./chipotle < bin/inSample4.txt > bin/outTest4.txt
	diff bin/outTest4.txt bin/outSample4.txt
clean:
	rm ./chipotle bin/outTest*
