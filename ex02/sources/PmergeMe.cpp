/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:56:37 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/25 15:31:50 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdlib.h>

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};

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

// Vector ######################################################################

void PmergeMe::ft_swapVector(std::pair<int, int>& pair)
{
    int tmp = pair.first;
    pair.first = pair.second;
    pair.second = tmp; 
}
void PmergeMe::printFinalVector()
{
    std::cout << "After:    ";
    for (std::vector<int>::iterator it = vecResultVector.begin(); it != vecResultVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int     PmergeMe::checkArgVector(char *str)
{
    int i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            return 1;
    return 0;       
}

int     PmergeMe::makePairVector(char **argv)
{
    int i = 1;
    
    while (argv[i] && argv[i + 1])
    {
        if (checkArgVector(argv[i]) == 1 || checkArgVector(argv[i + 1]) == 1)
            return -1;
        pairVector.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
        i += 2;
    }    
    for (std::vector<std::pair<int, int> >::iterator it = pairVector.begin(); it != pairVector.end(); ++it)
        if (it->first < it->second)
            ft_swapVector(*it);
    if (argv[i])
	{
		if (checkArgVector(argv[i]) == 1)
			return -1;
        pairVector.push_back(std::make_pair(atoi(argv[i]), -1));
	}
    this->pairVector = Ford_JohnsonVector(this->pairVector);
    jacobsthalVector();
    if (*vecResultVector.begin() == -1)
        this->vecResultVector.erase(this->vecResultVector.begin());
    return 0;
}

int PmergeMe::rechercheDichotomiqueVector(std::vector<int>& vec, int num) 
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

void    PmergeMe::jacobsthalVector()
{
    std::vector<std::pair<int, int> >::iterator it_vec_pair = this->pairVector.begin();
    std::vector<int>::iterator                  it_vec_int;
    std::vector<std::pair<int, int> >::iterator it_jacob;
    std::vector<std::pair<int, int> >::iterator it_jacob_save;
    std::vector<std::pair<int, int> >::iterator it_jacob_save_save;
    int found_jacob;
    
    this->unsorted_sizeVector = this->pairVector.size();
    while (it_vec_pair != pairVector.end())
    {
		if (it_vec_pair == pairVector.begin())
			this->vecResultVector.push_back(it_vec_pair->second);
        this->vecResultVector.push_back(it_vec_pair->first);
		it_vec_pair++;
	}
    if (this->vecResultVector.size() == this->pairVector.size() * 2)
        return;
    it_jacob = this->pairVector.begin() + found_jacobsthal(this->unsorted_sizeVector);
    it_jacob_save = it_jacob;
    rechercheDichotomiqueVector(this->vecResultVector, it_jacob->second);
    it_jacob = it_jacob - 1;
    while (this->vecResultVector.size() < this->pairVector.size() * 2)
    {
        found_jacob = found_jacobsthal(this->unsorted_sizeVector);
        if (found_jacob == 0)
            it_jacob = it_jacob_save_save + 1;
        else
            it_jacob = this->pairVector.begin() + found_jacob - 1;
        it_jacob_save_save = it_jacob;
        while (it_jacob > it_jacob_save)
        {
            rechercheDichotomiqueVector(this->vecResultVector, it_jacob->second);
            it_jacob = it_jacob - 1;
        }
        it_jacob_save = it_jacob_save_save;
    }
}

std::vector<std::pair<int, int> > PmergeMe::Ford_JohnsonVector(std::vector<std::pair<int, int> > vectorPairOfPair)
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
    left = Ford_JohnsonVector(left);
    right = Ford_JohnsonVector(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}


// Deque #######################################################################

void PmergeMe::ft_swapDeque(std::pair<int, int>& pair)
{
    int tmp = pair.first;
    pair.first = pair.second;
    pair.second = tmp; 
}

int     PmergeMe::checkArgDeque(char *str)
{
    int i = -1;
    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            return 1;
    return 0;       
}

int     PmergeMe::makePairDeque(char **argv)
{
    int i = 1;
    
    while (argv[i] && argv[i + 1])
    {
        if (checkArgDeque(argv[i]) == 1 || checkArgDeque(argv[i + 1]) == 1)
            return -1;
        pairDeque.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i + 1])));
        i += 2;
    }    
    for (std::deque<std::pair<int, int> >::iterator it = pairDeque.begin(); it != pairDeque.end(); ++it)
        if (it->first < it->second)
            ft_swapDeque(*it);
    if (argv[i])
	{
		if (checkArgDeque(argv[i]) == 1)
			return -1;
        pairDeque.push_back(std::make_pair(atoi(argv[i]), -1));
	}
    this->pairDeque = Ford_JohnsonDeque(this->pairDeque);
    jacobsthalDeque();
    if (*vecResultDeque.begin() == -1)
        this->vecResultDeque.erase(this->vecResultDeque.begin());
    return 0;
}

int PmergeMe::rechercheDichotomiqueDeque(std::deque<int>& vec, int num) 
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

void    PmergeMe::jacobsthalDeque()
{
    std::deque<std::pair<int, int> >::iterator it_vec_pair = this->pairDeque.begin();
    std::deque<int>::iterator                  it_vec_int;
    std::deque<std::pair<int, int> >::iterator it_jacob;
    std::deque<std::pair<int, int> >::iterator it_jacob_save;
    std::deque<std::pair<int, int> >::iterator it_jacob_save_save;
    int found_jacob;
    
    this->unsorted_sizeDeque = this->pairDeque.size();
    for(std::deque<std::pair<int, int> >::iterator it = this->pairDeque.begin(); it != this->pairDeque.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << std::endl;
    while (it_vec_pair != pairDeque.end())
    {
		if (it_vec_pair == pairDeque.begin())
			this->vecResultDeque.push_back(it_vec_pair->second);
        this->vecResultDeque.push_back(it_vec_pair->first);
		it_vec_pair++;
	}
    if (this->vecResultDeque.size() == this->pairDeque.size() * 2)
        return;
    it_jacob = this->pairDeque.begin() + found_jacobsthal(this->unsorted_sizeDeque) + 1;
    it_jacob_save = it_jacob;
    it_jacob_save_save = it_jacob;
    rechercheDichotomiqueDeque(this->vecResultDeque, it_jacob->second);
    it_jacob = it_jacob - 1;
    std::cout << "it_jacob -> second = " << it_jacob->second << std::endl;
    while (this->vecResultDeque.size() < this->pairDeque.size() * 2)
    {
        found_jacob = found_jacobsthal(this->unsorted_sizeDeque);
        if (found_jacob == 0)
            it_jacob = it_jacob_save_save + 1;
        else
            it_jacob = this->pairDeque.begin() + found_jacob - 1;
        it_jacob_save_save = it_jacob;
    for (std::deque<int>::iterator it = vecResultDeque.begin(); it != vecResultDeque.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "it_jacob->second = " << it_jacob->second << std::endl;
        while (it_jacob > it_jacob_save)
        {
            rechercheDichotomiqueDeque(this->vecResultDeque, it_jacob->second);
            it_jacob = it_jacob - 1;
        }
        it_jacob_save = it_jacob_save_save;
    }
}


std::deque<std::pair<int, int> > PmergeMe::Ford_JohnsonDeque(std::deque<std::pair<int, int> > dequePairOfPair)
{
    if (dequePairOfPair.size() <= 1)
        return dequePairOfPair;
    std::deque<std::pair<int, int> > left;
    std::deque<std::pair<int, int> > right;
    std::deque<std::pair<int, int> >::iterator it = dequePairOfPair.begin();
    std::pair<int, int> pivot = *it;
    it++;
    while (it != dequePairOfPair.end())
    {
        if (it->first <= pivot.first)
            left.push_back(*it);
        else
            right.push_back(*it);
        it++;
    }
    left = Ford_JohnsonDeque(left);
    right = Ford_JohnsonDeque(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}
