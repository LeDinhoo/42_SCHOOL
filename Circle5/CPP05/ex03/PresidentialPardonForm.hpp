/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonform.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdupuy <hdupuy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 07:35:48 by hdupuy            #+#    #+#             */
/*   Updated: 2024/03/07 08:53:32 by hdupuy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:
	std::string _target;

  public:
	PresidentialPardonForm ( std::string const target );
	PresidentialPardonForm ( PresidentialPardonForm const &src );
	~PresidentialPardonForm ();

	PresidentialPardonForm &operator= ( PresidentialPardonForm const &rhs );

	void execute ( Bureaucrat const &executor ) const;
};

#endif