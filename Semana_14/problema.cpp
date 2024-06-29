#include "BST_ADN.h"
using namespace std;

#define LEN 4
char APHABET[] = {'A', 'C', 'G', 'T'};

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		cout << "Error. Debe ejecutarse como ./problema n k" << endl;
		exit(EXIT_FAILURE);
	}
	int n,k;
	n = atoi(argv[1]);
	k = atoi(argv[2]);

	
	
	cout << "### Fin Problema ###" << endl;
	return EXIT_SUCCESS;
}
