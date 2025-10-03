#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of lines: ";
    cin >> n;

    int oddpointer = 1;
    int evenpointer = 2;

    for (int i = 1; i <= n; ++i)
	{
        if (i % 2 != 0)
		{
            for (int j = 0; j < i; ++j)
			{
                cout << oddpointer << " ";
                oddpointer += 2;
            }
        }
		else
		{
            for (int j = 0; j < i; ++j)
			{
                cout << evenpointer << " ";
                evenpointer += 2;
            }
        }
        cout << endl;
    }
}
