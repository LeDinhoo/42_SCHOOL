/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:09:58 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/08 09:19:51 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

class Base
{
  public:
	virtual ~Base ();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif