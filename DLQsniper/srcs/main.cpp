/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    main.cpp                                         created by ccantale    */
/*                                                                            */
/*    project: DLQsniper                       claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "main.h"

using refContainer = std::vector<std::string>;
int	main(void)
{
	std::cout << "Code starts..." << std::endl;


	ReferenceFinder	input(INPUT_FILE);
	IncidentFinder	incidents(INCIDENTS_FILE);	

	refContainer const	&inc = incidents.getIncidents();
	for (std::string s : inc)
		std::cout << s << std::endl;

	ReferenceAnalyser	diff(input.getRefs(), incidents.getIncidents());

	refContainer const	&res = diff.getResult();
	for (std::string s : res)
		std::cout << s << std::endl;
	// std::ostream		output(OUTPUT_FILE);

	// output << comparer.getComparison();


	std::cout << "... Code ends." << std::endl;
	return (0);
}
