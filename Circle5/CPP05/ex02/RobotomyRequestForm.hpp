/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:35:48 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 08:53:32 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
  private:
	std::string _target;

  public:
	RobotomyRequestForm ( std::string const target );
	RobotomyRequestForm ( RobotomyRequestForm const &src );
	~RobotomyRequestForm ();

	RobotomyRequestForm &operator= ( RobotomyRequestForm const &rhs );

	void execute ( Bureaucrat const &executor ) const;
};

#endif