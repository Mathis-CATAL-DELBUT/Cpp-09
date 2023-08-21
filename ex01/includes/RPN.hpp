/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:57:10 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/21 12:54:16 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

class RPN
{
    private:
        RPN();
        RPN(RPN const &copy);
        
        std::string input;
        std::stack<int> calculator;
        
        int isoperator(char c);
    public:
        RPN operator=(RPN const &copy);
        RPN(std::string input);
        ~RPN();
        
        int calcul(int i);
        int push_to_stack();
};

#endif