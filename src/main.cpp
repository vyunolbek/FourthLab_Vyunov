#include <iostream>
#include "../headers/Matrix.h"
#include "../headers/Vector.h"
#include "../headers/Multi.h"
#include <time.h>

using namespace std;

int main()
{
	TVector<int> v1, v2, v3;
	TMatrix<int> m1, m2, m3;
	int n;
	cout << "Change operations:" << endl << "1. v + v" << endl <<
		"2. v - v" << endl << "3. v * v" << endl << "4. v / v" << endl << "5. m + m" << endl <<
		"6. m - m" << endl << "7. m * m" << endl << "8. m * v" << endl << "9. v * m" << endl << "Enter: ";
	cin >> n;
	switch (n)
	{
	case (1):
		cin >> v1;
		cin >> v2;
		cout << v1 + v2;
		return 0;
	case(2):
		cin >> v1;
		cin >> v2;
		cout << v1 - v2;
		return 0;
	case(3):
		cin >> v1;
		cin >> v2;
		cout << v1 * v2;
		return 0;
	case(4):
		cin >> v1;
		cin >> v2;
		cout << v1 / v2;
		return 0;
	case(5):
		cin >> m1;
		cin >> m2;
		cout << m1 + m2;
		return 0;
	case(6):
		cin >> m1;
		cin >> m2;
		cout << m1 - m2;
		return 0;
	case(7):
		cin >> m1;
		cin >> m2;
		cout << m1 * m2;
		return 0;
	case(8):
		cin >> m1;
		cin >> v2;
		cout << m1 * v2;
		return 0;
	case(9):
		cin >> v2;
		cin >> m1;
		cout << v2 * m1;
		return 0;
	default:
		break;
	}
	return 0;
}
