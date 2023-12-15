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
	std::cout << "DLQuick version " << VERSION << "\n\n";
	std::cout << "Logs from last run:\n\n";
	system("cat Logbook/log.txt");
}

static char	prompt(void)
{
	char	task;

	task = 0;
	while (true)
	{
		if (task != '\n')
			std::cout << RESET << "\n> ";
		task = getchar();
		if (task == 'i' || task == 'r' || task == 's' || task == 'd' || task == 'f' || task == 'l' || task == 'q')
			break ;
	}
	return (task);
}


static char	getTask(void)
{
	char	task;

	system("clear");
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
			<< "Press " << CYAN << "q" << ENDCOLOR << " to exit" << std::endl;
	task = prompt();
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
	char	task;
	
	task = getTask();
	while (true)
	{
		if (task == 'l')
		{
			task = prompt();
			continue ;
		}
		if (task == 'q')
			break ;

		Log::init();
	
		DLQ		input(INPUT_FILE);
		std::ofstream	output;
		refContainer	result;

		if (input.getStatus() == ERROR)
		{
			displayLogs();
			Log::quit();
			task = prompt();
			continue ;
		}
		result = getResult(input, task);
		output.open(OUTPUT_FILE, std::ifstream::trunc);
		for (std::string s : result)
			output << s << std::endl;
		output.close();
		Log::quit();
		task = prompt();
	}
	return (0);
}
