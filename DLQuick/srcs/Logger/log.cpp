/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   Log.cpp                                               by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Log.h"

void	Log::init(void)
{
	_mkdir(FOLDERPATH);
	logbook.open(LOGPATH, std::ifstream::trunc);
}

static std::string	toString(long val)
{
	std::ostringstream	os;

	os << val;
	return (os.str());
}

std::string Log::getTimeAndDate(void)
{
	struct timeval	tv;
	std::time_t	currentTime = std::time(NULL);
	std::string	timeString = std::ctime(&currentTime);
	std::string	milliString(":");
	std::string	end("]\t");
	std::string	beg("[");

	timeString.erase(timeString.length() - 6, timeString.length() - 1);
	timeString.erase(0, 11);
	gettimeofday(&tv, NULL);
	milliString += toString(tv.tv_usec / 1000)
			+ std::string("_") + toString(tv.tv_usec % 1000);
	
	return (beg + timeString + milliString + end);
}

std::ofstream	&Log::print(std::string color)
{
	logbook << color;
	return (logbook);
}

void	Log::quit(void)
{
	logbook << RESET;
	logbook.close();
}
