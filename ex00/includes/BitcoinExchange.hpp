/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:47:17 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/07/05 14:53:44 by mcatal-d         ###   ########.fr       */
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
        Bitcoin(Bitcoin const &copy);
        ~Bitcoin();
        Bitcoin &operator=(Bitcoin const &copy);
        int    get_line();
        void    print_map();
        int    data_to_map();
};

#endif