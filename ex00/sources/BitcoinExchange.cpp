/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:50:41 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/07/04 15:32:07 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {}

Bitcoin::Bitcoin(const std::string inputa) : input(inputa) {}

// Bitcoin::Bitcoin(std::string input, Bitcoin const &copy)
// {
//     if (this != &copy)
//     {
//         this->input = copy.input;
//     }
// }

Bitcoin::~Bitcoin() {}

bool estChiffre(char c) {
    return c >= '0' && c <= '9';
}

bool check_date(std::string date)
{
    int annee = 0, mois = 0, jour = 0;
    
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') 
        return false;
    for (int i = 0; i < 4; ++i) {
        if (!estChiffre(date[i]))
            return false;
        annee *= 10 + (date[i] - '0');
    }
    for (int i = 5; i < 7; ++i) {
        if (!estChiffre(date[i]))
            return false;
        mois *= 10 + (date[i] - '0');
    }
    for (int i = 8; i < 10; ++i) {
        if (!estChiffre(date[i]))
            return false;
        jour *= 10 + (date[i] - '0');
    }
    if ((annee < 0 || mois < 1 || mois > 12 || jour < 1 || jour > 31) ||
        ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30))
        return false;
    if (mois == 2) {
        bool estAnneeBissextile = (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
        if ((estAnneeBissextile && jour > 29) || (!estAnneeBissextile && jour > 28))
            return false;
    }

    return true;
}

bool check_value(std::string value)
{
    (void)value;
    return true;
}

void Bitcoin::parsing(char separator)
{
    std::ifstream file(input.c_str());
    std::string line;
    std::string temp;
    double value;

    if (file.is_open())
    {
        while (getline(file, line, separator))
        {
            if (line.find('\n') < line.find('|'))
                line = line.substr(line.find('\n') + 1);
            temp = line;
            std::regex pattern ("^\\d{4}-\\d{2}-\\d{2}\\s$");
            if (!std::regex_match(temp, pattern))
                continue;
            temp = line.substr(0, line.find(' '));
            getline(file, line, '\n');
            std::regex pattern2 ("^(?:[0-9]{1,3}(?:\\.[0-9]+)?|1000(?:\\.0+)?)$");
            line = line.substr(1);
            if (!std::regex_match(line, pattern2))
                continue;
            value = std::stod(line);
            if(temp.length() >= 10 && line.length() > 0)
                values_input.insert(std::pair<std::string, double>(temp, value));
            line.clear();
            temp.clear();
        }
        file.close();
    }
    else
        std::cout << "Error: File not found" << std::endl;
}



void Bitcoin::print_map()
{
    std::multimap<std::string, double>::iterator it = values_input.begin();
    std::multimap<std::string, double>::iterator ite = values_input.end();
    while (it != ite)
    {
        std::cout << "[" << it->first << "] | [";
        std::cout << it->second << "]" << std::endl;
        it++;
    }
}
