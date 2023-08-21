/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:56:56 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/21 12:56:48 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        RPN test(argv[1]);
        if (test.push_to_stack())
            return std::cout << "Error" << std::endl , 1;
        return 0; 
    }
    return std::cout << "Error" << std::endl , 1;
}