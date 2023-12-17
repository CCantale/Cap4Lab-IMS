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

static void	displayLogs(void)
{
	system("cls");
	std::cout << "DLQuick version " << VERSION << "\n\n";
	std::cout << "Logs from last run:\n\n";
	system("type Logbook\\log.txt");
	std::cout << RESET << "Press any key to exit... " << std::endl;
	getch();
}

static char	getTask(void)
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
			<< "\n\n"
			<< "Press " << CYAN << "q" << ENDCOLOR << " to exit"
			<< "\n\n";
	while (!(task == 'i' || task == 'r' || task == 's' || task == 'd' || task == 'f' || task == 'l' || task == 'q'))
	{
		task = getch();
	}
	if (task == 'l')
		displayLogs();
	return (task);
}

static refContainer	getResult(DLQ &input, char task)
{
	Incidents	incidents;	
	Analysis	analysis(input);
	refContainer	result;

	switch(task)
	{
		case 'i':
			result = input.getInfo();
			break ;
		case 'r':
			result = input.getRefs();
			break ;
		case 's':
			result = input.getShortRefs();
			break ;
		case 'd':
			result = input.getDoubles();
			break ;
		case 'f':
			incidents.setIncidents(INCIDENTS_FILE);
			analysis.setIncidents(incidents.getIncidents());
			result = analysis.getResult();
			break ;
		default :
			break ;
	}
	return (result);
}

int	main(void)
{
	char	task = getTask();
	if (task == 'l' || task == 'q')
		return (0);

	Log::init();

	DLQ		input(INPUT_FILE);
	std::ofstream	output;
	refContainer	result;

	if (input.getStatus() == ERROR)
	{
		displayLogs();
		Log::quit();
		return (0);
	}
	result = getResult(input, task);
	output.open(OUTPUT_FILE, std::ifstream::trunc);
	for (std::string s : result)
		output << s << std::endl;
	output.close();
	Log::quit();
	return (0);
}
