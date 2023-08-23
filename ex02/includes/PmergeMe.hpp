/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:24:11 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/23 14:31:01 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

// #include <chrono>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
// #include <utility>

class PmergeMe
{
    private:
        std::vector<std::pair<int, int> > pairVector;
        static const int jacobsthalArray[15];

        void    ft_swap(std::pair<int, int>& pair);
        // std::deque<std::pair<int, int> >PairDeque;   
    public:
        PmergeMe();
        ~PmergeMe();
        void    makePair(char **argv);
        std::vector<std::pair<int, int> > Ford_Johnson(std::vector<std::pair<int, int> > vectorPairOfPair);
        
};

#endif