/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:17:47 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/07/04 14:32:33 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return (1);
    }
    Bitcoin bitcoin(argv[1]);
    bitcoin.parsing('|');
    bitcoin.print_map();
    return (0);
}