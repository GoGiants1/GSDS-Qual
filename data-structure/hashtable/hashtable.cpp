#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class HashTable {
private:
    int max_len;
    vector<list<pair<string, string>>> table;

    // 해시 함수
    int _hash(const string& key) {
        int hash_value = 0;
        for (char s : key) {
            hash_value += static_cast<int>(s);
        }
        return hash_value % max_len;
    }

public:
    // 생성자
    HashTable(int length = 5) : max_len(length), table(length) {}

    // 키-값 삽입
    void set(const string& key, const string& value) {
        int index = _hash(key);
        table[index].emplace_back(key, value);
    }

    // 키로 값 검색
    string get(const string& key) {
        int index = _hash(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                return kv.second;
            }
        }
        return "";  // 해당 키가 없으면 빈 문자열 반환
    }

    // 해시 테이블 출력
    void print_table() const {
        for (int i = 0; i < max_len; i++) {
            cout << i << ": ";
            for (const auto& kv : table[i]) {
                cout << "(" << kv.first << ", " << kv.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable capital;
    vector<string> country = {"Korea", "America", "China", "England", "Türkiye"};
    vector<string> city = {"Seoul", "Washington", "Beijing", "London", "Ankara"};

    for (size_t i = 0; i < country.size(); ++i) {
        capital.set(country[i], city[i]);
    }

    cout << "해시 테이블의 상태" << endl;
    cout << "===============" << endl;
    capital.print_table();
    cout << endl;

    cout << "해시 테이블의 검색 결과" << endl;
    cout << "====================" << endl;
    cout << "Capital of America = " << capital.get("America") << endl;
    cout << "Capital of Korea = " << capital.get("Korea") << endl;
    cout << "Capital of England = " << capital.get("England") << endl;
    cout << "Capital of China = " << capital.get("China") << endl;
    cout << "Capital of Japan = " << capital.get("Japan") << endl; // Japan은 테이블에 없음
    cout << "Capital of Türkiye = " << capital.get("Türkiye") << endl;

    return 0;
}