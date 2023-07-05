/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:47:17 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/07/04 15:31:29 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <fstream>
# include <map>
# include <cstring>
# include <algorithm>
# include <iterator>
# include <sstream>
# include <regex>

class Bitcoin
{
    private:
        const std::string input;
        std::multimap<std::string, double> values_input;
        
    public:
        Bitcoin();
        Bitcoin(const std::string inputa);
        Bitcoin(const std::string input, Bitcoin const &copy);
        ~Bitcoin();
        void    parsing(char separator);
        void    print_map();
};

#endif