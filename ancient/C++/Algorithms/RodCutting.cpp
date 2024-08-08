// Dynamic Programming for Rod Cutting problem
// Complexity = O(n^2)

#include <algorithm>
#include <iostream>
using namespace std;

void cutRod(int prices[], int n, int r[], int s[])
{
	r[0]= 0;
	int q;
	for (int j = 1; j<=n; j++){
		q = -10000;
		for (int i = 1; i<=j ; i++){
			if(q<prices[i]+r[j-i]){
				q = prices[i] + r[j-i];
				r[j] = q;
				s[j] = i;
			}
		}
	}
}

int main()
{
	int prices[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int n = 11;
	int r[n];
	int s[n];

	cout << "Maximum obtained value is " << endl;
	cutRod(prices, n, r, s);
	cout << "Originial Prices" <<endl;
	for (int i = 0; i<n; i++){
		cout << prices[i] << " ";
	}
	cout<<endl;
	cout<< endl;

	cout<<"Max val"<<endl;

	for (int i = 0; i<n; i++){
		cout << r[i] << " ";
	}

	cout<<endl;
	cout<<endl;

	cout << "Parent" <<endl;

	for (int i = 0; i<n; i++){
		cout << s[i] << " ";
	}
}
