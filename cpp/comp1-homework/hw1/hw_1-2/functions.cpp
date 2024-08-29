#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include "json/json.h"

using namespace std;

void ParseJSON(const std::string filename, Json::Value &json_object)
{
    ifstream json_file(filename);
    if (!json_file.is_open())
    {
        cout << "Cannot open json file" << endl;
        return;
    }

    json_file >> json_object;
    json_file.close();
}

std::unique_ptr<std::string> CheckTarget(const Json::Value &json_object, std::string &target_key)
{

    if (json_object.isMember(target_key) && json_object[target_key].isString())
    {
        // 타입 체크는 하지 않아도 됨. 항상 string이라고 문제에서 가정하였음.
        unique_ptr<string> target_ptr(new string(json_object[target_key].asString()));
        return target_ptr;
    }

    return nullptr;
}

void CompleteList(const Json::Value &json_object, std::list<std::string> &empty_list)
{
    bool no_str = true;
    for (auto it = json_object.begin(); it != json_object.end(); it++)
    {
        if (it->isString() == true)
        {
            no_str = false;
            empty_list.push_back(it->asString());
        }
    }
    empty_list.reverse();
    if (no_str == true)
    {
        empty_list.push_back("NO_STRING");
    }
}

void SumTwoMembers(std::string &key1, std::string &key2, const std::string &out_filename, Json::Value &json_object)
{
    string field_name = "SumOf" + key1 + "And" + key2;
    ofstream out_file(out_filename);
    if (!out_file.is_open())
    {
        cout << "Failed to open output file." << endl;
        return;
    }

    // integer array from json_object
    bool is_array_1 = json_object[key1].isArray();
    bool is_array_2 = json_object[key2].isArray();
    Json::Value key1_array = json_object[key1];
    Json::Value key2_array = json_object[key2];
    Json::Value new_array;
    if (is_array_1 && is_array_2 && !(key1_array.size() == 0 or key2_array.size() == 0) && (key1_array.size() == key2_array.size()))
    {
        for (int i = 0; i < key1_array.size(); i++)
        {
            int sum = key1_array[i].asInt() + key2_array[i].asInt();
            new_array.append(sum);
        }
        json_object[field_name] = new_array;
    }

    out_file << json_object;
    out_file.close();
}