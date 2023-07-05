/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:50:41 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/06/30 17:36:09 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::Bitcoin(const char* input) : input(input) {}

// Bitcoin::Bitcoin(std::string input, Bitcoin const &copy)
// {
//     if (this != &copy)
//     {
//         this->input = copy.input;
//     }
// }

Bitcoin::~Bitcoin() {}

int Bitcoin::get_line()
{
    std::ifstream file(input);
    std::string line;
    static int i = 0;
    if (file.is_open())
    {
        for(int j = i; j > 0; j--)
            std::getline(file, line);
        if (!std::getline(file, line)) {
            file.close();
            return (1);
        }
        file.close();
    }
    else
    {
        std::cout << "Error: File not found" << std::endl;
        return (1);
    }
    if (i == 0 && strcmp(line.c_str(), "date | value") != 0)
    {
        std::cout << "Error: Invalid file" << std::endl;
        return (1);
    }
    else
    {
        if (i != 0 && line.size() > 0)
        {
            if (line.find(" | ") == std::string::npos)
                return (std::cout << /*"Error : Invalid line"*/ ""<< std::endl, i++, 0);
            std::string date = line.substr(0, line.find(" | "));
            std::string value = line.substr(line.find(" | ") + 3, line.size());
            static std::map<std::string, double>::iterator it = values_input.begin();
            double value_double;
            std::stringstream iss(value);
            iss >> value_double;
            values_input.insert(it, std::pair<std::string, double>(date, value_double));
            it++;
            std::cout << "Date: '" << date << "'" << std::endl;
            std::cout << "Value: '" << value_double << "'" << std::endl;
        }
    }
    i++;
    line.clear();
    return (0);
}

void Bitcoin::print_map()
{
    std::map<std::string, double>::iterator it = values_input.begin();
    std::map<std::string, double>::iterator ite = values_input.end();
    while (it != ite)
    {
        std::cout << it->first << " | " << it->second << std::endl;
        it++;
    }
}
