#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>

#include "functions.hpp"

using namespace std;

int main(int argc, char *argv[])
{

    // argv[1]: Subproblem no.
    // argv[2]: CSV file name
    // argv[3~]: different by the subproblem no.
    string prob_no = argv[1];
    string filename = argv[2];

    std::map<string, vector<string>> data_map;
    std::map<int, string> header_cols;

    ParseCSV(filename, header_cols, data_map);

    if (prob_no == "a")
    {
        if (argc != 3)
        {
            std::cout << "Please check your command line arguments, Problem a requires two command line arguments: [Problem no.] [CSV file name]" << std::endl;
            return -1;
        }
    }
    else if (prob_no == "b")
    {
        if (argc != 4)
        {
            std::cout << "Please check your command line arguments, Problem b requires three command line arguments: [Problem no.] [CSV file name] [Target column]" << std::endl;
            return -1;
        }

        std::string target_col = argv[3];
        int sum = SumColumn(target_col, data_map);

        std::cout << sum; // << std::endl;
    }
    else if (prob_no == "c")
    {
        if (argc != 5)
        {
            std::cout << "Please check your command line arguments, Problem d requires three command line arguments: [Problem no.] [CSV file name] [Key column name] [Value column name]" << std::endl;
            return -1;
        }

        std::string key_col = argv[3];
        std::string target_col = argv[4];

        double avg = FilterMostFrequentAvg(key_col, target_col, data_map);

        std::cout << avg; // << std::endl;
    }
    else if (prob_no == "d")
    {

        if (argc != 6)
        {
            std::cout << "Please check your command line arguments, Problem d requires three command line arguments: [Problem no.] [CSV file name] [Value column name1] [Value column name2] [Output file name]" << std::endl;
            return -1;
        }

        std::string val_col1 = argv[3];
        std::string val_col2 = argv[4];
        std::string out_filename = argv[5];

        SumTwoColumns(val_col1, val_col2, out_filename, header_cols, data_map);
    }

    return 0;
}