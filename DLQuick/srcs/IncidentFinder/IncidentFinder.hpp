/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    IncidentFinder.hpp                               created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef INCIDENTFINDER_HPP
# define INCIDENTFINDER_HPP

# define MISSING_INCIDENTS_FILE_ERROR	"IncidentFinder: Couldn't find \"" INCIDENTS_FILE "\". It should be placed in the same folder as the executable."
# define EMPTY_INCIDENTS_FILE_ERROR	"IncidentFinder: \"" INCIDENTS_FILE "\" is empty."

# include <string>
# include <vector>
# include <iostream>
# include <cctype>
# include <fstream>
# include "../macros.h"
# include "../Logger/Log.h"

using	refContainer = std::vector<std::string>;

class	IncidentFinder
{
	private:
		refContainer		_incidents;
		short			_status;

	public:
					IncidentFinder(void);
					~IncidentFinder(void);
					IncidentFinder(std::string const &path);
					IncidentFinder(IncidentFinder const &toCopy);
		IncidentFinder		&operator=(IncidentFinder const &toCopy);
		int			setIncidents(std::string const &path);
		refContainer const	&getIncidents(void) const;

		class	IFException : public std::exception
		{
			private:
				std::string	_errorMsg = "IncidentFinder error";

			public:
				IFException(void) {}
				IFException(std::string errorMsg) : _errorMsg(errorMsg)
				{
					Log::lerr << timestamp << "Error: " << _errorMsg << std::endl;
				}
				virtual const char	*what(void) const throw() {
					return (_errorMsg.c_str());
				}
		};
};

#endif
