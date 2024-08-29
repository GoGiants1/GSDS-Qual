#include <iostream>
#include <string>
#include <map>

using namespace std;

// Implement definition of all classes and the member functions in this file.
// abstract class
// 모든 클래스의 부모 클래스
// float 타입으로 사이즈를 받는다.(constructor에서)
// Capacity는 size에 의해 결정된다.
class Container
{
public:
    float size;
    float capacity;
    enum ContainerType
    {
        B,
        C,
        PaB,
        PlB,
        etc
    } container_type;
    map<ContainerType, string> container_code_map = {
        {B, "B"},
        {C, "C"},
        {PaB, "PaB"},
        {PlB, "PlB"},
        {etc, "etc"}};
    string *container_code;

    Container(float size) : size(size), container_type(etc), container_code(nullptr){};
    virtual ~Container()
    {
        if (container_code != nullptr)
        {
            delete container_code;
        }
    };

    float get_size() const
    {
        return size;
    };

    float get_capacity() const
    {
        return capacity;
    };

    virtual void set_capacity() = 0;

    virtual void set_container_code()
    {
        int cap_code = 1;
        if (capacity < 100)
        {
            cap_code = 1;
        }
        else if (capacity >= 100 && capacity < 200)
        {
            cap_code = 2;
        }
        else
        {
            cap_code = 3;
        }

        container_code = new string(container_code_map[container_type] + to_string(cap_code));
    }

    string *get_container_code()
    {
        return container_code;
    }
};

// Box는 capacity = size * 1
class Box : public Container
{
public:
    Box(float size) : Container(size){};

    void set_capacity() override
    {
        capacity = size;
    };
};
// capacity = size * 1.3
class PaperBox : public Box
{
public:
    PaperBox(float size) : Box(size)
    {
        container_type = PaB;
    };
    void set_capacity() override
    {
        capacity = size * 1.3f;
    };
};
// capacity = size * 1.1
class PlasticBox : public Box
{
public:
    PlasticBox(float size) : Box(size)
    {
        container_type = PlB;
    };
    void set_capacity() override
    {
        capacity = size * 1.1f;
    };
};

// Bag는 capacity = size * 3
class Bag : public Container
{
public:
    Bag(float size) : Container(size)
    {
        container_type = B;
    };
    void set_capacity() override
    {
        capacity = size * 3.0f;
    };
};

// Carrier는 capacity = size * 5
// auxiliary class for Box class를 최대 2개까지 부착할 수 있다.
// Carrier capacity = carrier capacity + (aux 1 capacity * 1.1 + aux 2 capacity * 1.1) (optional)
class Carrier : public Container
{
public:
    Box *aux1;
    Box *aux2;
    int aux_count;

    Carrier(float size) : Container(size), aux_count(0), aux1(nullptr), aux2(nullptr)
    {
        container_type = C;
    };
    ~Carrier()
    {
        if (aux1 != nullptr)
        {
            delete aux1;
        }
        if (aux2 != nullptr)
        {
            delete aux2;
        }
    };
    void set_capacity() override
    {
        capacity = size * 5.0f;
        if (aux1 != nullptr)
        {
            capacity += aux1->get_capacity() * 1.1f;
        }
        if (aux2 != nullptr)
        {
            capacity += aux2->get_capacity() * 1.1f;
        }
    };
    void add_aux(Box *aux)
    {
        if (aux1 == nullptr)
        {
            aux1 = aux;
            aux_count++;
        }
        else if (aux2 == nullptr)
        {
            aux2 = aux;
            aux_count++;
        }
        set_capacity();
        // else do nothing
    };

    Box *get_aux(int idx)
    {
        if (idx > aux_count)
        {
            return nullptr;
        }
        if (idx == 1)
        {
            return aux1;
        }
        if (idx == 2)
        {
            return aux2;
        }
        return nullptr;
    };
};