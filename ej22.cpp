using namespace std;
#include <iostream>

int main(int argc, char* argv[]) {
	
	int N = atoi(argv[1]);
	
	double sup = 0;
	double sdown = 0;
	
	for (int n = 1; n <= N; n++) {
		sup += 1./n;
	}
	
	for (int n = N; n >= 1; n--) {
		sdown += 1./n;
	}
	
	cout << "Sup: Sum of 1/n from n = 1 to N = " << N << " : " << sup << endl;
	cout << "Sdown: Sum of 1/n from n = 1 to N = " << N << " : " << sdown << endl;
	
	
	return 0;
}