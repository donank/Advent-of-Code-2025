#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

int main() 
{ 
    // define the dial with 100 positions
    int arr[100];
    for (int i = 0; i<100; i++) arr[i] = i;
    // Read the input file
    std::ifstream file("input.csv");
    std::string str;

    char direction;
    int initial_pos = 50;
    int curr_value;
    int count = 0;
    int extra_clicks = 0;
    while (std::getline(file, str))
    {   
        std::string number_string;
        int new_pos;
        int curr_pos = 0;
        // Parse the string to get direction and number
        for(auto e : str)
        {
            if(isalpha(e))
                direction = e;
            else if(isdigit(e))
                number_string.push_back(e);
        }
        std::stringstream ss;
        ss << number_string;
        ss >> new_pos;
        
        if(new_pos >= 100){
            extra_clicks += int(new_pos / 100);
            new_pos = new_pos % 100;
        }
        // Adjust new position based on direction
        if(direction == 'L'){
            curr_pos = initial_pos - new_pos;
        }else if (direction == 'R')
        {
            curr_pos = initial_pos + new_pos;
        }
        
        if(curr_pos > 100)
        {
                std::cout<<curr_pos<<std::endl;
                curr_pos = curr_pos % 100;
                extra_clicks += 1;
        } else if (curr_pos < 0 && initial_pos != 0)
        {
                std::cout<<curr_pos<<std::endl;
                curr_pos = curr_pos + 100;
                extra_clicks += 1;

        }else if(curr_pos == 100)
        {
                curr_pos = curr_pos % 100;       
        }else if (curr_pos < 0 && initial_pos == 0)
        {
                curr_pos = curr_pos + 100;     
        }
             
        // Check the current value and increment count if it's zero
        if (arr[curr_pos] == 0)
        {
            count++;
        }
        // Reassign initial position to the current position
        initial_pos = curr_pos;
    }
    std::cout<<extra_clicks<<std::endl;
    std::cout<<count<<std::endl;
    std::cout<<count+extra_clicks<<std::endl;
}