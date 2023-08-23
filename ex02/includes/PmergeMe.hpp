/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:24:11 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/23 16:02:25 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<std::pair<int, int> > pairVector;
        std::vector<int> vecResult;
        
        static const int jacobsthalArray[15];

        void                                ft_swap(std::pair<int, int>& pair);
        void                                jacob();
        std::vector<std::pair<int, int> >   Ford_Johnson(std::vector<std::pair<int, int> > vectorPairOfPair);
        int                                 checkArg(char *str);
        
        // std::deque<std::pair<int, int> >PairDeque;   
    public:
        PmergeMe();
        ~PmergeMe();
        
        int    makePair(char **argv);
        
};

#endif