/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    Analysis.cpp                                     created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "Analysis.hpp"
#include "Analysis.analyse.cpp"

Analysis::Analysis(DLQ &input) : _DLQ(input)
{
	;
}

Analysis::Analysis(DLQ &input, refContainer const &incidents) : _DLQ(input), _incidents(incidents)
{
	if (this->_incidents.size())
		this->_result = analyse(this->_DLQ, this->_incidents);
}

Analysis::~Analysis(void)
{
	if (this->_result.size())
		this->_result.clear();
	if (this->_incidents.size())
		this->_incidents.clear();
}

Analysis::Analysis(Analysis &toCopy)
{
	if (toCopy._result.size())
		this->_result = toCopy._result;
	if (toCopy._DLQ.getStatus() == SUCCESS)
		this->_DLQ = toCopy._DLQ;
	if (toCopy._incidents.size())
		this->_incidents = toCopy._incidents;
}

Analysis	&Analysis::operator=(Analysis &toCopy)
{
	if (toCopy._result.size())
		this->_result = toCopy._result;
	if (toCopy._DLQ.getStatus() == SUCCESS)
		this->_DLQ = toCopy._DLQ;
	if (toCopy._incidents.size())
		this->_incidents = toCopy._incidents;
	return (*this);
}

void	Analysis::setDLQ(DLQ &input)
{
	this->_DLQ = input;
	if (this->_incidents.size())
		this->_result = analyse(this->_DLQ, this->_incidents);
}

void	Analysis::setIncidents(refContainer const &incidents)
{
	this->_incidents = incidents;
	if (this->_DLQ.getStatus() == SUCCESS)
		this->_result = analyse(this->_DLQ, this->_incidents);
}

refContainer const	&Analysis::getResult(void) const
{
	return (this->_result);
}
