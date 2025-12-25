#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <numeric>

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

std::vector <long> longint_to_vector(long x)
{
    std::vector <long> result_vector;
    while (true)
    {
    result_vector.insert(result_vector.begin(), x%10);
    x /= 10;
    if(x == 0)
        return result_vector;
    }
}

int main() 
{ 
    
    // Read the input file
    std::ifstream file("input.txt");
    std::string invalid_ids;
    std::string const file_delimiter = ",";
    std::string const invalid_id_delimiter = "-";

    while (std::getline(file, invalid_ids))
    {   
        long total_sum = 0;
        std::vector<std::string> invalid_ids_vector = split(invalid_ids, file_delimiter);
        for (auto invalid_id : invalid_ids_vector) {
            std::vector<std::string> invalid_id_vector = split(invalid_id, invalid_id_delimiter);
            std::vector<long> invalid_id_range;
            for (auto id : invalid_id_vector) {
                invalid_id_range.push_back(std::stol(id));
            }
            std::cout << "Invalid ID Range: " << invalid_id_range[0] << " , " << invalid_id_range[1] << std::endl;
            long sum = 0;
            for (long i = invalid_id_range[0]; i <= invalid_id_range[1]; i++) {
                std::vector <long> num_vector = longint_to_vector(i);
                // check if the vector has even number of elements & thus possibility of repeating halves
                if(num_vector.size() % 2 == 0) {
                    // Divide the Vector in half, compare and count the repeating elements
                    long vector_half = num_vector.size()/2;
                    long repeating_count = 0;
                    for (size_t j = 0; j < vector_half; j++) {
                        // Compare the two halves
                        if(num_vector[j] == num_vector[j + num_vector.size()/2]) {
                            repeating_count += 1;
                        }
                    }
                    // If repeating count is equal to half the vector size, then its a number with repeating halves
                    if(repeating_count == vector_half) {
                            sum += i;
                    }
                }
            }

            total_sum += sum;
        }
        std::cout << "Total Sum: " << total_sum << std::endl;
    }
}

