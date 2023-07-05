/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:47:17 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/07/05 12:36:02 by mcatal-d         ###   ########.fr       */
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

class Bitcoin
{
    private:
        const char* input;
        std::map<std::string, double> values_data;
        
    public:
        Bitcoin();
        Bitcoin(const char* input);
        Bitcoin(const char* input, Bitcoin const &copy);
        ~Bitcoin();
        int    get_line();
        void    print_map();
        int    data_to_map();
        // std::string open_file(int i);
};

#endif