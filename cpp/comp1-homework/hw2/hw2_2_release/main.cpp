#include "custommap.hpp"

int main(void)
{
    CustomMap<int, string> map;
    map.insert(5, "Five");
    map.insert(3, "Three");
    map.insert(8, "Eight");
    map.insert(10, "Ten");
    map.print_map();

    map[5] = "FiveFive";
    map[11] = "Eleven";
    cout << "After updating 5 and adding 11: \n"
         << endl;
    map.print_map();
}