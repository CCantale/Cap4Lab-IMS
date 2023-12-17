/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    Incidents.cpp                                    created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Incidents.hpp"

Incidents::Incidents(void)
{
	;
}

Incidents::~Incidents(void)
{
	this->_incidents.clear();
}

Incidents::Incidents(std::string const &path)
{
	this->setIncidents(path);
}

Incidents::Incidents(Incidents const &toCopy)
{
	this->_incidents = toCopy._incidents;
}

Incidents	&Incidents::operator=(Incidents const &toCopy)
{
	this->_incidents = toCopy._incidents;
	return (*this);
}

refContainer const	&Incidents::getIncidents(void) const
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

int	Incidents::setIncidents(std::string const &path)
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
		if (this->_incidents.size() == 0)
			throw IFException(EMPTY_INCIDENTS_FILE_ERROR);
	}
	catch (IFException &ex) {
		this->_status = ERROR;
		return (ERROR);
	}
	Log::lout << timestamp << "Incidents: Incidents successfully loaded!" << std::endl;
	for (std::string i : this->_incidents)
		Log::lout << i << std::endl;
	return (SUCCESS);
}
