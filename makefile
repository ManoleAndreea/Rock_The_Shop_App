build:
	g++ -std=c++17 main.cpp angajat.cpp manager.cpp operatorr.cpp asistent.cpp validare_cnp.cpp produs.cpp articol_vestimentar.cpp disc.cpp disc_vintage.cpp gestiune.cpp comanda.cpp -o test
	./test
clean:
	rm -f test