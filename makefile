build:
	g++ main.cpp angajat.cpp manager.cpp operatorr.cpp asistent.cpp stergere.cpp validare_cnp.cpp -o test
	./test
clean:
	rm -f test