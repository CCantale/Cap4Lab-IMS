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

//	std::cout << "SHORTIES" << std::endl;
//	refContainer const	&shorts = input.getShortRefs();
//	for (std::string s : shorts)
//		std::cout << s << std::endl;
//	std::cout << "endof(SHORTIES)\n\n";

//	std::cout << "INCIDENTS" << std::endl;
//	refContainer const	&inc = incidents.getIncidents();
//	for (std::string s : inc)
//		std::cout << s << std::endl;
//	std::cout << "ENDOFINCIDENTS\n\n";

	ReferenceAnalyser	diff(input.getShortRefs(), incidents.getIncidents());

//	for (std::string s : diff.getResult())
//		std::cout << s << std::endl;
	std::ofstream		output;
	refContainer const	&res = diff.getResult();

	output.open(OUTPUT_FILE, std::ifstream::trunc);
	for (std::string s : res)
		output << s;

	output.close();
	std::cout << "... Code ends." << std::endl;
	return (0);
}
