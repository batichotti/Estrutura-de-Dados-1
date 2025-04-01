#include "lista_sequencial.hpp"
#include "lista_sequencial.cpp"

int main() {
	ListSeq ls(5);
	ls.add(5);
	ls.add(9);
	ls.add(15);
	ls.add(7);
	ls.print();
	return 0;
};
