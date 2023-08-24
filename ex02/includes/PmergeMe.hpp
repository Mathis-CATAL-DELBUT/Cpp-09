/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:24:11 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/24 15:26:52 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sys/time.h>

class PmergeMe
{
    private:
        // std::deque<std::pair<int, int> >    PairDeque;   
        std::vector<std::pair<int, int> >   pairVector;
        std::vector<int>                    vecResult;
        int                                 unsorted_size;

        void                                ft_swap(std::pair<int, int>& pair);
        void                                jacobsthal();
        std::vector<std::pair<int, int> >   Ford_Johnson(std::vector<std::pair<int, int> > vectorPairOfPair);
        int                                 checkArg(char *str);
        int                                 rechercheDichotomique(std::vector<int>& vec, int num);
    
    public:
        PmergeMe();
        ~PmergeMe();
        
        void   printFinalVector();
        int    makePair(char **argv);
        
};

#endif