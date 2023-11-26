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
//	std::cout << "SHORTIES" << std::endl;
//	refContainer const	&shorts = input.getShortRefs();
//	for (std::string s : shorts)
//		std::cout << s << std::endl;
//	std::cout << "endof(SHORTIES)\n\n";

	IncidentFinder	incidents(INCIDENTS_FILE);	
//	std::cout << "INCIDENTS" << std::endl;
//	refContainer const	&inc = incidents.getIncidents();
//	for (std::string s : inc)
//		std::cout << s << std::endl;
//	std::cout << "ENDOFINCIDENTS\n\n";

	ReferenceAnalyser	analysis(input.getShortRefs(), incidents.getIncidents());
//	for (std::string s : diff.getResult())
//		std::cout << s << std::endl;

	std::ofstream		output;
	refContainer		res;

	if (!incidents.getIncidents().size())
	{
		res = input.getRefs();
	}
	else
	{
		res = analysis.getResult();
	}

	output.open(OUTPUT_FILE, std::ifstream::trunc);
	for (std::string s : res)
		output << s << std::endl;

	output.close();
	std::cout << "... Code ends." << std::endl;
	return (0);
}
