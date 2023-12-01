/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    IncidentFinder.cpp                               created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "IncidentFinder.hpp"

IncidentFinder::IncidentFinder(void)
{
	;
}

IncidentFinder::~IncidentFinder(void)
{
	this->_incidents.clear();
}

IncidentFinder::IncidentFinder(std::string const &path)
{
	this->setIncidents(path);
}

IncidentFinder::IncidentFinder(IncidentFinder const &toCopy)
{
	this->_incidents = toCopy._incidents;
}

IncidentFinder	&IncidentFinder::operator=(IncidentFinder const &toCopy)
{
	this->_incidents = toCopy._incidents;
	return (*this);
}

refContainer const	&IncidentFinder::getIncidents(void) const
{
	return (this->_incidents);
}

static void	trimLine(std::string &line)
{
	int	trim;

	if (!line.size())
		return ;
	trim = 0;
	while (!std::isalnum(line[trim]) && (size_t)trim < line.size())
		++trim;
	if ((size_t)trim >= line.size())
		return ;
	line.erase(0, trim);
	trim = line.size() - 1;
	while (!std::isalnum(line[trim]))
		--trim;
	line.erase(trim + 1);
}

static void	processLine(refContainer &_incidents, std::string &line)
{
	trimLine(line);
	if (line.size())
		_incidents.push_back(line);
}

int	IncidentFinder::setIncidents(std::string const &path)
{
	std::ifstream	input(path.c_str());
	std::string	nextLine;
	std::string	errorMsg;

	try {
		if (!input.is_open())
		{
			throw IFException(MISSING_INCIDENTS_FILE_ERROR);
		}
		while (!input.eof())
		{
			std::getline(input, nextLine);
			processLine(_incidents, nextLine);
		}
	}
	catch (IFException &ex) {
		this->_status = ERROR;
		return (ERROR);
	}
	return (SUCCESS);
}
