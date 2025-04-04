#include "lista_sequencial.hpp"

int main() {
	ListSeq ls(5);
	ls.add(1);
	ls.add(2);
	ls.add(4);
	ls.add(5);
	ls.addSorted(19);
	ls.print();
	return 0;
};
