/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:52:03 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/21 13:02:35 by mcatal-d         ###   ########.fr       */
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
{
    this->input = copy.input;
    return *this;
}

int RPN::push_to_stack()
{
    int i = 0;

    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
    while (this->input[i])
    {
        // std::cout << "input[i] = " << input[i] << std::endl;
        if (isdigit(this->input[i]))
        {
            calculator.push(this->input[i] - '0');
            // std::cout << "push in stack : " << input[i] << std::endl;   
        }
        else if (isoperator(this->input[i]))
        {
            if (calcul(i))
                return -1;
        }
        else
            return -1;
        i++;
    }
    if (calculator.size() != 1)
        return -1;
    std::cout << calculator.top() << std::endl;
    return 0;
}

int RPN::isoperator(char c)
{
    if (c == '-' || c == '*' || c == '/' || c == '+')
        return 1;
    return 0;
}


int RPN::calcul(int i)
{
    int res = 0;
    int size = this->calculator.size();

    if (size < 2)
        return 1;
        
    int first_elt = calculator.top();
    calculator.pop();
    int second_elt = calculator.top();
    calculator.pop();

    // std::cout << "premier elt: " << first_elt << " / " << "second elt: " << second_elt << " / size : "<< size << std::endl;
    
    if (this->input[i] == '*')
        res = (second_elt) * (first_elt); 
    if (this->input[i] == '-')
        res = (second_elt) - (first_elt); 
    if (this->input[i] == '+')
        res = (second_elt) + (first_elt); 
    if (this->input[i] == '/')
    {
        if (first_elt == '0')
            return 1;
        res = (second_elt) / (first_elt); 
    }
    calculator.push(res);
    // std::cout << "apres cette opration : " << this->input[i] << " le resultat est : " << res << std::endl;
    return 0;
}