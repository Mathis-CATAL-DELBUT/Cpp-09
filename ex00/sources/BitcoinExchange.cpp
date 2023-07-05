/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:50:41 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/07/05 13:15:44 by mcatal-d         ###   ########.fr       */
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
//     }std::cout << "value : '" << value << "'" << std::endl;
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
        annee = annee * 10 + (date[i] - '0');
    }
    for (int i = 5; i < 7; ++i) {
        if (!estChiffre(date[i]))
            return false;
        mois = mois * 10 + (date[i] - '0');
    }
    for (int i = 8; i < 10; ++i) {
        if (!estChiffre(date[i]))
            return false;
        jour = jour * 10 + (date[i] - '0');
    }
    if ((annee < 0 || mois < 1 || mois > 12 || jour < 1 || jour > 31))
        return false;
    if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30)
        return false;
    if (mois == 2) {
        bool estAnneeBissextile = (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
        if ((estAnneeBissextile && jour > 29) || (!estAnneeBissextile && jour > 28))
            return false;
    }

    return true;
}

int Bitcoin::data_to_map()
{
    std::ifstream file("data.csv");
    std::string line;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            if (line.find(",") == std::string::npos)
                return (std::cout << "Error : Invalid line, the format must be 'date | value'"<< std::endl, 1);
            std::string date = line.substr(0, line.find(","));
            std::string value = line.substr(line.find(",") + 1, line.size() + 1);
            double value_double;
            std::stringstream iss(value);
            iss >> value_double;
            values_data.insert(std::pair<std::string, double>(date, value_double));
        }
        file.close();
        return (0);
    }
    return (std::cout << "Error : File not found" << std::endl, 1);
}

int lower_date(const std::map<std::string, double>& baseDeDonnees, const std::string& date, double& value)
{
    std::map<std::string, double>::const_iterator it = baseDeDonnees.lower_bound(date);
    
    if (it == baseDeDonnees.begin())
        return (std::cout << "Error : No data available for this date : " << date << std::endl, 1);
    std::cout << date << " => " << value << " = " << it->second * value << std::endl;
    return (0);
}


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
        return (std::cout << "Error : File not found" << std::endl, 1);
    if (i == 0 && strcmp(line.c_str(), "date | value") != 0)
        return (std::cout << "Error : Invalid file" << std::endl, 1);
    else
    {
        if (i != 0 && line.size() > 0)
        {
            if (line.find(" | ") == std::string::npos)
                return (std::cout << "Error : Invalid line, the format must be 'date | value' => "<< line << std::endl, i++, 0);
            std::string date = line.substr(0, line.find(" | "));
            std::string value = line.substr(line.find(" | ") + 3);
            for (size_t j = 0; j < value.length(); j++)
                if (value[j] != '.' && !estChiffre(value[j]) && value[j] != '-')
                    return (std::cout << "Error : Invalid format, the format must be 'yyyy-mm-dd | value' => "<< line << std::endl, i++, 0);
            double value_double;
            std::stringstream iss(value);
            iss >> value_double;
            if (check_date(date) == false)
                return (std::cout << "Error : Invalid format, the format must be 'yyyy-mm-dd | value' => "<< line << std::endl, i++, 0);
            if (value_double < 0)
                return (std::cout << "Error : not a positive number."<< std::endl, i++, 0);
            if (value_double > 1000)
                return (std::cout << "Error : too large a number."<< std::endl, i++, 0);
            lower_date(values_data, date, value_double);
        }
    }
    i++;
    line.clear();
    return (0);
}

