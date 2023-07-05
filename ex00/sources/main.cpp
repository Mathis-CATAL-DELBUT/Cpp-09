/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:17:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/07/05 13:13:48 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error : Invalid number of arguments" << std::endl;
        return (1);
    }
    Bitcoin bitcoin(argv[1]);
    if (bitcoin.data_to_map() != 0)
        return (std::cout << "Error : Invalid file data" << std::endl, 1);
    while (bitcoin.get_line() == 0)
        ;
    return (0);
}