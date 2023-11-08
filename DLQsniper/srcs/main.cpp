/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    main.cpp                                         created by ccantale    */
/*                                                                            */
/*    project: DLQsniper                      claudio.cantale93i@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "main.h"

int	main(void)
{
	std::cout << "Code starts..." << std::endl;


	ReferenceFinder	input(INPUT_FILE);
	// ReferenceAnalyser	comparer(input.getRefs(), INCIDENTS_FILE);
	// std::ostream		output(OUTPUT_FILE);

	// output << comparer.getComparison();


	std::cout << "... Code ends." << std::endl;
	return (0);
}
