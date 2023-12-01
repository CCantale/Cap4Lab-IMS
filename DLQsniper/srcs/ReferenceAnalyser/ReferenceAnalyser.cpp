/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceAnalyser.cpp                            created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "ReferenceAnalyser.hpp"
#include "ReferenceAnalyser.analyse.cpp"

ReferenceAnalyser::ReferenceAnalyser(ReferenceFinder &DLQ) : _DLQ(DLQ)
{
	;
}

ReferenceAnalyser::ReferenceAnalyser(ReferenceFinder &DLQ, refContainer const &incidents) : _DLQ(DLQ), _incidents(incidents)
{
	if (this->_incidents.size())
		this->_result = analyse(this->_DLQ, this->_incidents);
}

ReferenceAnalyser::~ReferenceAnalyser(void)
{
	if (this->_result.size())
		this->_result.clear();
	if (this->_incidents.size())
		this->_incidents.clear();
}

ReferenceAnalyser::ReferenceAnalyser(ReferenceAnalyser &toCopy)
{
	if (toCopy._result.size())
		this->_result = toCopy._result;
	if (toCopy._DLQ.getStatus() == SUCCESS)
		this->_DLQ = toCopy._DLQ;
	if (toCopy._incidents.size())
		this->_incidents = toCopy._incidents;
}

ReferenceAnalyser	&ReferenceAnalyser::operator=(ReferenceAnalyser &toCopy)
{
	if (toCopy._result.size())
		this->_result = toCopy._result;
	if (toCopy._DLQ.getStatus() == SUCCESS)
		this->_DLQ = toCopy._DLQ;
	if (toCopy._incidents.size())
		this->_incidents = toCopy._incidents;
	return (*this);
}

void	ReferenceAnalyser::setDLQ(ReferenceFinder &DLQ)
{
	this->_DLQ = DLQ;
	if (this->_incidents.size())
		this->_result = analyse(this->_DLQ, this->_incidents);
}

void	ReferenceAnalyser::setIncidents(refContainer const &incidents)
{
	this->_incidents = incidents;
	if (this->_DLQ.getStatus() == SUCCESS)
		this->_result = analyse(this->_DLQ, this->_incidents);
}

refContainer const	&ReferenceAnalyser::getResult(void) const
{
	return (this->_result);
}
