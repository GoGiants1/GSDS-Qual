// g++ [파일명].cpp -o [output 파일명 지정] -std=c++11
// ./[exe 파일명]

<Only C++ (vs. C)>
* Template programming: template <typename T> function_declaration;
* Overloading
* Object-oriented programming
* Reference parameters




<String>
* Reading a line: 
    getline(cin, variable)  
* 소수점 출력:
    setprecision(int n) << fixed   
    (from <iomanip>)
* 소문자, 대문자 변환:
    toupper(int c)
    tolower(int c)

<Containers>
* Vector (python의 list 같은)
    - push_back() / insert(iterator, value)
    - pop_back() / erase(iterator)

* List (doubly linked list 형태)
    - push_back() / push_front() / insert(iterator, value)
    - pop_back() / pop_front() / erase(iterator)
    - advance(iterator, n)

* Map (python의 dictionary 같은)
    // key 기준으로 sorting 되어 있음, balanced BST 형태
    // node는 std::pair의 object로 first(key), second(value)로 구성
    - insert({key,value})
    - map[key] = value
    - make_pair(key,value)

* Set
    - insert(value)
    - erase(iterator) or erase(value)
    - .count(value)