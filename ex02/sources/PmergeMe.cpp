/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:56:37 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/24 15:33:32 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdlib.h>

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};

void PmergeMe::ft_swap(std::pair<int, int>& pair)
{
    int tmp = pair.first;
    pair.first = pair.second;
    pair.second = tmp; 
}
void PmergeMe::printFinalVector()
{
    std::vector<int>::const_iterator it = this->vecResult.begin();
    std::cout << "After:    ";

    while (it != this->vecResult.end())
        std::cout << *it++ << " ";
    std::cout << std::endl;
}

int     PmergeMe::checkArg(char *str)
{
    int i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            return 1;
    return 0;       
}

int     PmergeMe::makePair(char **argv)
{
    int i = 1;
    
    while (argv[i] && argv[i + 1])
    {
        if (checkArg(argv[i]) == 1 || checkArg(argv[i + 1]) == 1)
            return -1;
        pairVector.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
        i += 2;
    }    
    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
        if (it->first < it->second)
            ft_swap(*it);
    if (argv[i])
	{
		if (checkArg(argv[i]) == 1)
			return -1;
        pairVector.push_back(std::make_pair(atoi(argv[i]), -1));
	}
    this->pairVector = Ford_Johnson(this->pairVector);
    jacobsthal();
    if (*vecResult.begin() == -1)
        this->vecResult.erase(this->vecResult.begin());
    return 0;
}

int PmergeMe::rechercheDichotomique(std::vector<int>& vec, int num) 
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) 
	{
        int midle = left + (right - left) / 2;
        if (vec[midle] == num) 
		{
            while (midle > 0 && vec[midle - 1] == num) 
                --midle;
            vec.insert(vec.begin() + midle, num);
            return midle;
        } 
		else if (vec[midle] < num)
            left = midle + 1;
        else
            right = midle - 1;
    }
    vec.insert(vec.begin() + left, num);
    return left;
}

int found_jacobsthal(int nb_elt)
{
    static int i = 0;
    int tab_jacob[15] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845};
    while (i < 15)
    {
        if (nb_elt >= tab_jacob[i])
            return i++, tab_jacob[i - 1];
        i++;
    }
    return 0;
}

void    PmergeMe::jacobsthal()
{
    std::vector<std::pair<int, int> >::iterator it_vec_pair = this->pairVector.begin();
    std::vector<int>::iterator                  it_vec_int;
    std::vector<std::pair<int, int> >::iterator it_jacob;
    std::vector<std::pair<int, int> >::iterator it_jacob_save;
    std::vector<std::pair<int, int> >::iterator it_jacob_save_save;
    int found_jacob;
    
    this->unsorted_size = this->pairVector.size();
    while (it_vec_pair != pairVector.end())
    {
		if (it_vec_pair == pairVector.begin())
			this->vecResult.push_back(it_vec_pair->second);
        this->vecResult.push_back(it_vec_pair->first);
		it_vec_pair++;
	}
    it_jacob = this->pairVector.begin() + found_jacobsthal(this->unsorted_size);
    it_jacob_save = it_jacob;
    rechercheDichotomique(this->vecResult, it_jacob->second);
    it_jacob = it_jacob - 1;
    while (this->vecResult.size() < this->pairVector.size() * 2)
    {
        found_jacob = found_jacobsthal(this->unsorted_size);
        if (found_jacob == 0)
            it_jacob = it_jacob_save_save + 1;
        else
            it_jacob = this->pairVector.begin() + found_jacob;
        it_jacob_save_save = it_jacob;
        while (it_jacob > it_jacob_save)
        {
            rechercheDichotomique(this->vecResult, it_jacob->second);
            it_jacob = it_jacob - 1;
        }
        it_jacob_save = it_jacob_save_save;
    }
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