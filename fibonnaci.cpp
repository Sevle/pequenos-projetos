#include <iostream>

using namespace std;

int main(void)
{
	int size;
	float qt_num;

	cin >> qt_num;

  // evitar o uso de int num[qt_num]
	int * num = (int *) malloc (sizeof(int) * qt_num);

	num[0] = 1;
	num[1] = 1;

	for(int i = 0; i < (qt_num - 1); i++)
	{
		int buffer = num[i];
		num[i+2] = num[i+1] + num[i];
		num[i] = buffer;
		cout << num[i] << " ";
	}
	cout << endl;
}
