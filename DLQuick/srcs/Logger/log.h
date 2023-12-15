/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   log.h                                                 by CanTale_Games   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   First call Log::init(), then use Log::lout, Log::lwar and Log::lerr      */
/*   instead of std::cout, std::cwar and std::cerr.                           */
/*   The macro "timestamp" can be inserted in the stream to have a nice       */
/*   timestamp in the entry.                                                  */
/*   Remember to call Log::quit() at the end of your program.                 */
/*   Logbook will create a new directory named "Logbook" with a log file      */
/*   inside. cat it to see the log in colors. The file is overwritten         */
/*   everytime the program runs.                                              */
/*                                                                            */
/*                                                                            */
/*   Example:                                                                 */
/*                                                                            */
/*   Log::init();                                                             */
/*                                                                            */
/*   ...                                                                      */
/*                                                                            */
/*   if (errcode == 0)                                                        */
/*   {                                                                        */
/*       Log::lout << timestamp << "Everything up and running!\n";            */
/*   }                                                                        */
/*   else                                                                     */
/*   {                                                                        */
/*       Log::lerr << timestamp << "Fuck. Not again...\n";                    */
/*   }                                                                        */
/*                                                                            */
/*   ...                                                                      */
/*                                                                            */
/*   Log::quit();                                                             */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*   If you use Vim, you can add something like this to your .vimrc to        */
/*   display the log file by just typing "log" while in normal mode:          */
/*                                                                            */
/*   nmap log :!cat Logbook/log                                               */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef LOG_H
# define LOG_H

# define LOGPATH	"Logbook/log.txt"
# define FOLDERPATH	"./Logbook"

# include <fstream>
# include <sys/stat.h>
# include <ctime>
# include <cstdio>
# include <sstream>
# include <sys/time.h>
# include <string>

# include "../colors.h"

namespace Log
{
	static std::ofstream	logbook;

	void			init(void);
	std::string		getTimeAndDate(void);
	std::ofstream		&print(std::string color);
	void			quit(void);
}

# define lout		print(GREEN)
# define lerr		print(RED)
# define lwar		print(YELLOW)
# define timestamp	Log::getTimeAndDate()

#endif
