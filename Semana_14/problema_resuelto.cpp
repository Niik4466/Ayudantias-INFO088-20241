#include "BST_ADN.h"
using namespace std;

#define LEN 4
char APHABET[] = {'A', 'C', 'G', 'T'};

int main(int argc, char **argv) {
	if(argc != 3) {
		cout << "Error. Debe ejecutarse como ./problema n k" << endl;
		exit(EXIT_FAILURE);
	}
	int n,k, m;
	n = atoi(argv[1]);
	k = atoi(argv[2]);
    BST_ADN t;

    for (int i = 0; i < n; ++i) {
        m = rand()%(k+1) + 1;
        char* new_word = new char[m];
        for (int j = 0; j < m; ++j) {
            new_word[j] = APHABET[rand()%sizeof(APHABET)];
        }

        t.insert(&t.root, new_word, m);
    }

    t.printInorder(t.root);
    t.sizeTree(t.root);
	
	cout << "### Fin Problema ###" << endl;
	return EXIT_SUCCESS;
}
