/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:52:03 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/18 11:01:13 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}

RPN::RPN(std::string input)
{this->input = input;}

RPN::RPN(RPN const &copy)
{*this = copy;}

RPN RPN::operator=(RPN const &copy)
{this->input = copy.input;}

int RPN::do_calcul()
{
    int i = 0;
    while (this->input[i]) // parcourir le input pour mettre la premiere fois dans la pile calculator 
    {
        if (isdigit(this->input[i]) || isoperator(this->input[i]))
            //push dans calculator
        else
            return -1; //erreur
    }
}