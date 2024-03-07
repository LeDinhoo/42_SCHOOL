/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:35:48 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 07:38:21 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

  public:
	ShrubberyCreationForm ( std::string const target );
	ShrubberyCreationForm ( ShrubberyCreationForm const &src );
	~ShrubberyCreationForm ();

	ShrubberyCreationForm &operator= ( ShrubberyCreationForm const &rhs );

	void execute ( Bureaucrat const &executor ) const;
};

#endif