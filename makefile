build:
	g++ main.cpp angajat.cpp manager.cpp operatorr.cpp asistent.cpp -o test
	./test
clean:
	rm -f test