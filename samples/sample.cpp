#include "AVL_tree.h"
#include <iostream>
using namespace std;


int main() {
	setlocale(2, "rus");
	
	AVL_tree tree;
	int k = 0;
	cout << "Добавьте элементы в AVL-дерево" << endl;
	cin >> k;

	tree.insert(k);
	while (k != 1) {
		cin >> k;
		try {
			tree.insert(k);
		}
		catch (const std::logic_error& e) {
			std::cout << e.what() << std::endl;
			exit(-1);
		}
	}
	cout << "Удалите элементы в AVL-дереве" << endl;
	cin >> k;
	while (k != 1) {

		try {
			tree.erase(k);
		}
		catch (const std::logic_error& e) {
			std::cout << e.what() << std::endl;
			exit(-1);
		}
		cin >> k;
	}
	tree.print();
	
}
