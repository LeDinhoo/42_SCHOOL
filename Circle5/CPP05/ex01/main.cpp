#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "\n TEST 1 \n" << std::endl;
	{
		try
		{
			Bureaucrat	Joe("Joe", 150);
			std::cout << Joe;
			Form		Form("contrat", 100, 50);
			std::cout << Form;
			Joe.signForm(Form);
			std::cout << Form;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n TEST 2 \n" << std::endl;
	{
		try
		{
			Bureaucrat	Bob("Bob", 75);
			std::cout << Bob;
			Form		Form("contrat", 100, 50);
			std::cout << Form;
			Bob.signForm(Form);
			std::cout << Form;
			Bob.signForm(Form);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
