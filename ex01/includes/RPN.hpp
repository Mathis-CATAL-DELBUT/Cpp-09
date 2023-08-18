/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcatal-d <mcatal-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:57:10 by mcatal-d          #+#    #+#             */
/*   Updated: 2023/08/18 10:55:44 by mcatal-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>

class RPN
{
    private:
        RPN();
        RPN(RPN const &copy);
        
        std::string input;
        std::stack<int> calculator;
    public:
        RPN operator=(RPN const &copy);
        RPN(std::string input);
        ~RPN();
        
        int do_calcul();
};

#endif