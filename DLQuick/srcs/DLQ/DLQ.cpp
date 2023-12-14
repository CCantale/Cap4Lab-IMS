/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    DLQ.cpp                                          created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "DLQ.hpp"

DLQ::DLQ(void)
{
	this->_status = ERROR;
}

DLQ::~DLQ(void)
{
	this->_references.clear();
}

DLQ::DLQ(std::string filePath)
{
	this->setRefs(filePath);
}

DLQ::DLQ(DLQ const &toCopy)
{
	this->_info = toCopy._info;
	this->_references = toCopy._references;
	this->_shortReferences = toCopy._shortReferences;
	this->_doubles = toCopy._doubles;
	this->_error = toCopy._error;
	this->_status = toCopy._status;
}

DLQ	&DLQ::operator=(DLQ const & toCopy)
{
	this->_info = toCopy._info;
	this->_references = toCopy._references;
	this->_shortReferences = toCopy._shortReferences;
	this->_doubles = toCopy._doubles;
	this->_error = toCopy._error;
	this->_status = toCopy._status;
	return (*this);
}

refContainer const	&DLQ::getInfo(void) const
{
	if (this->_status == SUCCESS)
		return (this->_info);
	else
		return (this->_error);
}

refContainer const	&DLQ::getRefs(void) const
{
	if (this->_status == SUCCESS)
		return (this->_references);
	else
		return (this->_error);
}

refContainer const	&DLQ::getShortRefs(void) const
{
	if (this->_status == SUCCESS)
		return (this->_shortReferences);
	else
		return (this->_error);
}

refContainer const	&DLQ::getDoubles(void) const
{
	if (this->_status == SUCCESS)
		return (this->_doubles);
	else
		return (this->_error);
}

short	DLQ::getStatus(void) const
{
	return (this->_status);
}

// int	DLQ::setRefs(std::string &filePath)
#include "DLQ.setRefs.cpp"
