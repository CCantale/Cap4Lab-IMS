/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceAnalyser.cpp                            created by ccantale    */
/*                                                                            */
/*    project: DLQsniper                       claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "ReferenceAnalyser.hpp"
#include "ReferenceAnalyser.analyse.cpp"

static int	checkFormat(refContainer toCheck);
//////////// END OF DECLARATIONS ///////////////

ReferenceAnalyser::ReferenceAnalyser(void)
{
	;
}

ReferenceAnalyser::~ReferenceAnalyser(void)
{
	if (this->_result.size())
		this->_result.clear();
	if (this->_DLQcontent.size())
		this->_DLQcontent.clear();
	if (this->_incidents.size())
		this->_incidents.clear();
}

ReferenceAnalyser::ReferenceAnalyser(ReferenceAnalyser &toCopy)
{
	if (toCopy._result.size())
		this->_result = toCopy._result;
	if (toCopy._DLQcontent.size())
		this->_DLQcontent = toCopy._DLQcontent;
	if (toCopy._incidents.size())
		this->_incidents = toCopy._incidents;
}

ReferenceAnalyser	&ReferenceAnalyser::operator=(ReferenceAnalyser &toCopy)
{
	if (toCopy._result.size())
		this->_result = toCopy._result;
	if (toCopy._DLQcontent.size())
		this->_DLQcontent = toCopy._DLQcontent;
	if (toCopy._incidents.size())
		this->_incidents = toCopy._incidents;
	return (*this);
}

ReferenceAnalyser::ReferenceAnalyser(refContainer const &DLQcontent, refContainer const &incidents)
{
	if (checkFormat(DLQcontent) == OK)
		this->_DLQcontent = DLQcontent;
	if (checkFormat(incidents) == OK)
		this->_incidents = incidents;
	if (this->_DLQcontent.size() && this->_incidents.size())
		this->_result = analyse(DLQcontent, incidents);
}

void	ReferenceAnalyser::setDLQcontent(refContainer const &DLQcontent)
{
	if (checkFormat(DLQcontent) == NOT_OK)
		return ;
	this->_DLQcontent = DLQcontent;
	if (this->_incidents.size())
		this->_result = analyse(DLQcontent, this->_incidents);
}

void	ReferenceAnalyser::setIncidents(refContainer const &incidents)
{
	if (checkFormat(incidents) == NOT_OK)
		return ;
	this->_incidents = incidents;
	if (this->_DLQcontent.size())
		this->_result = analyse(this->_DLQcontent, incidents);
}

refContainer const	&ReferenceAnalyser::getResult(void) const
{
	return (this->_result);
}

static int	checkFormat(refContainer toCheck)
{
	(void)toCheck;
	// actual check
	return (OK);
}
