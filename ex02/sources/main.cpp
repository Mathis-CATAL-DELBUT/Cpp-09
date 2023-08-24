/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:13:31 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/24 22:58:27 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    aff_arg(char **argv)
{
    int i = 1;
    
    std::cout << "Before:   ";
    while (argv[i])
        std::cout << argv[i++] << " ";
    std::cout << std::endl;
}

int     main(int argc, char **argv)
{
    PmergeMe objVector;
    PmergeMe objDeque;

    if (argc < 2)
        return std::cout << "Error" << std::endl, 1;
    timeval startVector, endVector, startDeque, endDeque;
    gettimeofday(&startVector, NULL);
    if (objVector.makePairVector(argv) == -1)
        return std::cout << "Error" << std::endl, 1;
    gettimeofday(&endVector, NULL);
    gettimeofday(&startDeque, NULL);
    if (objVector.makePairDeque(argv) == -1)
        return std::cout << "Error" << std::endl, 1;
    gettimeofday(&endDeque, NULL);
    long secondsVector = endVector.tv_sec - startVector.tv_sec;
    long microsecondsVector = endVector.tv_usec - startVector.tv_usec;
    double durationVector = secondsVector + microsecondsVector / 1000000.0;
    long secondsDeque = endDeque.tv_sec - startDeque.tv_sec;
    long microsecondsDeque = endDeque.tv_usec - startDeque.tv_usec;
    double durationDeque = secondsDeque + microsecondsDeque / 1000000.0;
    std::cout << "-----------------------------------------" << std::endl;
    aff_arg(argv);
    std::cout << "///" << std::endl;
    objVector.printFinalVector();
    std::cout << "///" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << durationVector << "us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << durationDeque << "us" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
}