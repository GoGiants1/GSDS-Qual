#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Animal {
 public:
  Animal(string name) : name(name), age(0) {};
  virtual void makeSound() const = 0;  // Pure virtual function
  virtual ~Animal() {
    cout << "Base Destructor" << endl;
  }  // Virtual destructor
  // Copy constructor
  Animal(const Animal& other) : name(other.getName()), age(other.getAge()) {}
  // ... (if needed, other member functions and data members)
  virtual string getName() const { return name; }
  virtual int getAge() const { return age; }
  void setAge(int new_age) { age = new_age; }

 private:
  string name;
  int age;
};

class Lion : public Animal {
 public:
  Lion(string name) : Animal(name) {};
  Lion(string name, int age) : Animal(name) { setAge(age); };
  ~Lion() { cout << "lion destructor" << endl; }
  void makeSound() const override {
    cout << "Roar!" << endl;
  };  // Should print "Roar!"
  // ... (if needed, other member functions)
};
class Elephant : public Animal {
 public:
  Elephant(string name) : Animal(name) {};
  void makeSound() const override {
    cout << "Trumpet!" << endl;
  }  // Should print "Trumpet!"
  // ... (if needed, other member functions)
};

class Bird : public Animal {
 public:
  Bird(string name) : Animal(name) {};
  void makeSound() const override {
    cout << "Tweet!" << endl;
  }  // Should print "Tweet!"
  // ... (if needed, other member functions)
};

class Enclosure {
 public:
  Enclosure(string name) : name(name) {};
  void addAnimal(Animal* animal) { animals.push_back(animal); };
  void removeAnimal(Animal* animal) {
    for (int i = 0; i < animals.size(); i++) {
      if (animals[i] == animal) {
        animals.erase(animals.begin() + i);
      }
    }
  }
  void listAnimals() const {
    for (auto ani : animals) {
      cout << "Animal: " << ani->getName() << ", Sound: ";
      ani->makeSound();
    }
  };

  string getName() const { return name; };
  // ... (if needed, other member functions and operator overloads)
 private:
  string name;
  vector<Animal*> animals;
};

class ZooGraph {
 public:
  ZooGraph() {}
  void addEnclosure(Enclosure* enclosure) {
    enclosures[enclosure->getName()] = enclosure;
  }
  void addPath(string enclosureA, string enclosureB) {
    adjacencyList[enclosureA].push_back(enclosureB);
  }
  vector<string> findShortestPath(string startEnclosure, string endEnclosure) {
    queue<string> q;
    unordered_map<string, string> prev;
    unordered_set<string> visited;
    q.push(startEnclosure);
    visited.insert(startEnclosure);

    while (!q.empty()) {
      string enc = q.front();
      q.pop();
      if (enc == endEnclosure) {
        break;
      }

      for (auto neighbor : adjacencyList[enc]) {
        if (visited.find(neighbor) == visited.end()) {
          // if (visited.count(neighbor) == 0) {
          q.push(neighbor);
          visited.insert(neighbor);
          prev[neighbor] = enc;
        }
      }
    }

    return makePath(endEnclosure, prev);
  }

  vector<string> makePath(string end, unordered_map<string, string>& prev) {
    vector<string> path;
    string curr = end;
    while (prev.count(curr) > 0) {
      path.push_back(curr);
      curr = prev[curr];
    }
    path.push_back(curr);

    reverse(path.begin(), path.end());
    return path;
  }

  // ... (if needed, other member functions and data members)
 private:
  map<string, vector<string>>
      adjacencyList;  // Data member to store adjacency list representation of
                      // the graph
  map<string, Enclosure*>
      enclosures;  // Data member to store enclosures by their names
};

template <typename T>
class Info {
 public:
  Info(T info)
      : info(info) {

        };
  T getInfo() const { return info; }
  // ... (if needed, other member functions)
 private:
  T info;
};