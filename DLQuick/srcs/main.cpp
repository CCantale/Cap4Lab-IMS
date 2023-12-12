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
			<< "6) Read logs from previous run: " << CYAN << "\tl\n" << ENDCOLOR
			<< "7) " << YELLOW << "COMING SOON: Compare DLQs" << ENDCOLOR
			<< "\n\n"
			<< "Press " << CYAN << "q" << ENDCOLOR << " to exit"
			<< "\n\n";
	while (!(task == 'i' || task == 'r' || task == 's' || task == 'd' || task == 'f' || task == 'l' || task == 'q'))
	{
		task = getch();
	}
	return (task);
}

static void	displayLogs(void)
{
	system("type Logbook\\log.txt");
	std::cout << RESET << "Press any key to exit... " << std::endl;
	getch();
}

int	main(void)
{
	char	task;
	task = getTask();
	switch(task)
	{
		case 'l':
			displayLogs();
			return (0);
		case 'q':
			return (0);
		default:
			break ;
	}

	Log::init();

	ReferenceFinder		input(INPUT_FILE);
	IncidentFinder		incidents(INCIDENTS_FILE);	
	ReferenceAnalyser	analysis(input, incidents.getIncidents());
//	for (std::string s : diff.getResult())
//		std::cout << s << std::endl;
	std::ofstream		output;
	refContainer		res;

	if (input.getStatus() == ERROR)
	{
		displayLogs();
		Log::quit();
		return (0);
	}
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
	Log::quit();
	return (0);
}
