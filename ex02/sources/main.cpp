/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:13:31 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/23 15:35:50 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    (void) argc;
    PmergeMe objVector;
    // PmergeMe objDeque;

    if (objVector.makePair(argv) == -1)
        return std::cout << "Error" << std::endl, 1;
}