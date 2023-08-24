/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:24:11 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/24 23:00:13 by mcatal-d         ###   ########.fr       */
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
    private: // Deque
        std::deque<std::pair<int, int> >    pairDeque;   
        std::deque<int>                     vecResultDeque;
        int                                 unsorted_sizeDeque;
        
        void                                ft_swapDeque(std::pair<int, int>& pair);
        void                                jacobsthalDeque();
        std::deque<std::pair<int, int> >    Ford_JohnsonDeque(std::deque<std::pair<int, int> > vectorPairOfPair);
        int                                 checkArgDeque(char *str);
        int                                 rechercheDichotomiqueDeque(std::deque<int>& vec, int num);
        
    private: // Vector
        std::vector<std::pair<int, int> >   pairVector;
        std::vector<int>                    vecResultVector;
        int                                 unsorted_sizeVector;

        void                                ft_swapVector(std::pair<int, int>& pair);
        void                                jacobsthalVector();
        std::vector<std::pair<int, int> >   Ford_JohnsonVector(std::vector<std::pair<int, int> > vectorPairOfPair);
        int                                 checkArgVector(char *str);
        int                                 rechercheDichotomiqueVector(std::vector<int>& vec, int num);
    
    public: // Vector
        PmergeMe();
        ~PmergeMe();
        
        void   printFinalVector();
        int    makePairVector(char **argv);
        
    public: // Deque
        int    makePairDeque(char **argv);
};

#endif