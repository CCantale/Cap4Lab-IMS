/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    main.cpp                                         created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "main.h"

char	getTask(void)
{
	char	task;

	std::cout << CYAN << APP_NAME << " " << VERSION << "\n\n" << YELLOW
			<< "Please, choose a task by typing the corresponding letter:\n\n"
			<< ENDCOLOR
			<< "1) Get DLQ info (ID, ref, short ref): " << CYAN << "\ti\n" << ENDCOLOR
			<< "2) Get DLQ references: " << CYAN << "\t\t\tr\n" << ENDCOLOR
			<< "3) Get DLQ short references: " << CYAN << "\t\ts\n" << ENDCOLOR
			<< "4) Get DLQ doubles: " << CYAN << "\t\t\td\n" << ENDCOLOR
			<< "5) Filter DLQ with incidents: " << CYAN << "\t\tf\n" << ENDCOLOR
			<< "6) " << YELLOW << "COMING SOON: Compare DLQs" << ENDCOLOR
			<< "\n\n"
			<< "Press " << CYAN << "q" << ENDCOLOR << " to exit"
			<< "\n\n";
	while (!(task == 'i' || task == 'r' || task == 's' || task == 'd' || task == 'f' || task == 'q'))
	{
		task = getch();
	}
	return (task);
}

int	main(void)
{
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

	ReferenceAnalyser	analysis(input, incidents.getIncidents());
//	for (std::string s : diff.getResult())
//		std::cout << s << std::endl;
	std::ofstream		output;
	refContainer		res;
	char			task;

	task = getTask();
	switch(task)
	{
		case 'i':
			res = input.getInfo();
			break ;
		case 'r':
			res = input.getRefs();
			break ;
		case 's':
			res = input.getShortRefs();
			break ;
		case 'd':
			res = input.getDoubles();
			break ;
		case 'f':
			res = analysis.getResult();
			break ;
		default :
			break ;
	}

	output.open(OUTPUT_FILE, std::ifstream::trunc);
	for (std::string s : res)
		output << s << std::endl;

	output.close();
	return (0);
}
