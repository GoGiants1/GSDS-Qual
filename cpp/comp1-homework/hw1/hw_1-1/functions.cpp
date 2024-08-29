#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

#include "functions.hpp"

using namespace std;

void ParseCSV(const std::string &filename, std::map<int, std::string> &header_cols, map<std::string, vector<std::string>> &data_map)
{
    ifstream csv_file(filename);
    if (!csv_file.is_open())
    {
        cout << "Failed to open csv file." << endl;
        return;
    }

    string line;
    int line_count = 0;
    while (getline(csv_file, line))
    {
        stringstream ss(line);
        string column_value;
        int column_count = 0;
        // find double quotes and do not split by comma
        // otherwise, split by comma
        vector<string> temporary_columns;
        bool is_quote_started = false;

        while (getline(ss, column_value, ','))
        {
            if (line_count == 0)
            {
                header_cols[column_count++] = column_value;
                continue;
            }
            if (column_value.empty())
            {
                continue;
            }
            else
            {
                if (column_value[0] == '"')
                {
                    is_quote_started = true;
                }
                if (column_value[column_value.size() - 1] == '"' && is_quote_started)
                {
                    // merge the cells between the quotes
                    while (!temporary_columns.empty() && column_value[0] != '"')
                    {
                        string prev = temporary_columns.back();
                        column_value = prev + "," + column_value;
                        temporary_columns.pop_back();
                    }
                    is_quote_started = false;
                }
                temporary_columns.push_back(column_value);
            }
        }
        if (temporary_columns.size() == header_cols.size())
        {
            for (int i = 0; i < temporary_columns.size(); i++)
            {
                data_map[header_cols[i]].push_back(temporary_columns[i]);
            }
        }
        line_count++;
    }
    csv_file.close();
}

// Sum all elements in the column
int SumColumn(const std::string &column_name, map<std::string, vector<std::string>> &data_map)
{
    int sum = 0;
    for (auto it = data_map[column_name].begin(); it != data_map[column_name].end(); ++it)
    {
        sum += stoi(*it);
    }
    return sum;
}

double FilterMostFrequentAvg(const std::string &key_col, std::string &value_col, map<std::string, vector<std::string>> &data_map)
{
    map<string, int> freq_map;
    map<string, int> sum_map;
    for (int index = 0; index < data_map[key_col].size(); index++)
    {
        freq_map[data_map[key_col][index]] += 1;
        sum_map[data_map[key_col][index]] += stoi(data_map[value_col][index]);
    }
    int max_freq = 0;
    string max_freq_key = "";
    for (auto it = freq_map.begin(); it != freq_map.end(); ++it)
    {
        if (it->second > max_freq)
        {
            max_freq = it->second;
            max_freq_key = it->first;
        }
    }
    if (max_freq > 0)
    {
        return (double)sum_map[max_freq_key] / max_freq;
    }

    return -1;
}

void SumTwoColumns(std::string &value_col1, std::string &value_col2, const std::string &out_filename, std::map<int, std::string> &header_cols, map<std::string, vector<std::string>> &data_map)
{
    ofstream out_file(out_filename);
    if (!out_file.is_open())
    {
        cout << "Failed to open output file." << endl;
        return;
    }
    string new_col_name = "SumOf" + value_col1 + "And" + value_col2;
    // make header
    for (int i = 0; i < header_cols.size(); i++)
    {
        out_file << header_cols[i];
        out_file << ",";
        if (i == header_cols.size() - 1)
        {
            out_file << new_col_name;
            out_file << endl;
            break;
        }
    }

    for (int i = 0; i < data_map[value_col1].size(); i++)
    {

        int sum = stoi(data_map[value_col1][i]) + stoi(data_map[value_col2][i]);
        for (int j = 0; j < header_cols.size(); j++)
        {
            out_file << data_map[header_cols[j]][i];
            out_file << ",";
        }
        out_file << sum;
        if (i != data_map[value_col1].size() - 1)
        {
            out_file << endl;
        }
    }
    out_file.close();
}