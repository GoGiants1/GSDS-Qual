#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool nextPermutation(vector<int> &a, int n){
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1; //뒤에서 앞으로 가면서 i-1>=i가 아니면 끝(1번)
	if (i <= 0) return false; //만약 마지막 순열이라면 끝난다
	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1; //뒤에서 앞으로 가면서 크면서 가장 작은 수를 구한다(2번)
	swap(a[i - 1], a[j]); //두 수의 위치를 바꾼다 (3번)
	j = n - 1;
	while (i < j) { //i<n-1까지의 수열을 뒤집는다 (4번)
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true; //다음 수열이 존재한다 true
}

bool nextPermutationStr(string& a, int n){
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1; //뒤에서 앞으로 가면서 i-1>=i가 아니면 끝(1번)
	if (i <= 0) return false; //만약 마지막 순열이라면 끝난다
	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1; //뒤에서 앞으로 가면서 크면서 가장 작은 수를 구한다(2번)
	swap(a[i - 1], a[j]); //두 수의 위치를 바꾼다 (3번)
	j = n - 1;
	while (i < j) { //i<n-1까지의 수열을 뒤집는다 (4번)
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true; //다음 수열이 존재한다 true
}

bool prevPermutation(vector<int> &a, int n){
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) i -= 1; //(1번)
	if (i <= 0) return false;
	int j = n - 1;
	while (a[j] >= a[i - 1]) j -= 1; //(2번)
	swap(a[i - 1], a[j]); //(3번)
	j = n - 1;
	while (i < j) { //4번)
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}

bool prevPermutationStr(string &a, int n){
	int i = n - 1;
	while (i > 0 && a[i - 1] <= a[i]) i -= 1; //(1번)
	if (i <= 0) return false;
	int j = n - 1;
	while (a[j] >= a[i - 1]) j -= 1; //(2번)
	swap(a[i - 1], a[j]); //(3번)
	j = n - 1;
	while (i < j) { //4번)
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}

vector<string> str_perm(string& s){
    sort(s.begin(), s.end());
    vector<string> result;
    result.push_back(s);
    while(next_permutation(s.begin(), s.end())){
        result.push_back(s);
    }
    return result;
}

void Print(vector<string> &result){
    cout<<"[";
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<", ";
    }
    cout<<"]"<<endl;
}

int main(){
    string s = "abc";
    vector<string> result = str_perm(s);
    Print(result);

    // 직접 구현 nextPermutation - vector<int> 버전
    vector<int> a = {1, 2, 3};
    do{
        for(int i=0; i<a.size(); i++){
            cout<<a[i]<<", ";
        }
        cout<<endl;
    }while(nextPermutation(a, a.size()));

    // 직접 구현 nextPermutation - string 버전
    string c = "abc";
    do{
        cout<<c<<endl;
    }while(nextPermutationStr(c, c.size()));

    // 직접 구현 prevPermutation - vector<int> 버전
    vector<int> b = {3, 2, 1};
    do{
        for(int i=0; i<b.size(); i++){
            cout<<b[i]<<", ";
        }
        cout<<endl;
    }while(prevPermutation(b, b.size()));

    // 직접 구현 prevPermutation - string 버전
    string d = "cba";
    do{
        cout<<d<<endl;
    }while(prevPermutationStr(d, d.size()));

    return 0;
}