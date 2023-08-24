/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:13:31 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/24 15:36:09 by mcatal-d         ###   ########.fr       */
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
    // PmergeMe objDeque;

    if (argc < 2)
        return std::cout << "Error" << std::endl, 1;
    timeval start, end;
    gettimeofday(&start, NULL);
    if (objVector.makePair(argv) == -1)
        return std::cout << "Error" << std::endl, 1;
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double duration = seconds + microseconds / 1000000.0;
    aff_arg(argv);
    objVector.printFinalVector();
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << duration << "us" << std::endl;
}