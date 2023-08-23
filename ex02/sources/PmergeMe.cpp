/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:56:37 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/23 14:31:14 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdlib.h>

const int PmergeMe::jacobsthalArray[15] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461};


PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};

void PmergeMe::ft_swap(std::pair<int, int>& pair)
{
    int tmp = pair.first;
    pair.first = pair.second;
    pair.second = tmp; 
}
void printVector(const std::vector<std::pair<int, int> >& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "(" << vec[i].first << ", " << vec[i].second << ") ";
    }
    std::cout << std::endl;
}

void   PmergeMe::makePair(char **argv)
{
    int i = 1;
    
    while (argv[i] && argv[i + 1]) //Faire les premieres paires
    {
        pairVector.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
        i += 2;
    }    
    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it) //Mettre le plus grand a gauche
        if (it->first < it->second)
            ft_swap(*it);
    if (argv[i]) //Si il reste un element
        pairVector.push_back(std::make_pair(atoi(argv[i]), -1));
    
    // AFFICHAGE
    // for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
    //     std::cout << "Pair [" << it->first << "," << it->second << "]" << std::endl;
    // if (argv[i])
    //     std::cout << "Reste [" << argv[i] << "]" << std::endl;


    printVector(Ford_Johnson(this->pairVector));
}


std::vector<std::pair<int, int> > PmergeMe::Ford_Johnson(std::vector<std::pair<int, int> > vectorPairOfPair)
{
    if (vectorPairOfPair.size() <= 1)
        return vectorPairOfPair;
    std::vector<std::pair<int, int> > left;
    std::vector<std::pair<int, int> > right;
    std::vector<std::pair<int, int> >::iterator it = vectorPairOfPair.begin();
    std::pair<int, int> pivot = *it;
    it++;
    while (it != vectorPairOfPair.end())
    {
        if (it->first <= pivot.first)
            left.push_back(*it);
        else
            right.push_back(*it);
        it++;
    }
    left = Ford_Johnson(left);
    right = Ford_Johnson(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}