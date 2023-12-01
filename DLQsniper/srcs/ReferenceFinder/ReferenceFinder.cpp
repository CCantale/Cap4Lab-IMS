/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceFinder.cpp                              created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "ReferenceFinder.hpp"

ReferenceFinder::ReferenceFinder(void)
{
	this->_status = ERROR;
}

ReferenceFinder::~ReferenceFinder(void)
{
	this->_references.clear();
}

ReferenceFinder::ReferenceFinder(std::string filePath)
{
	this->setRefs(filePath);
}

ReferenceFinder::ReferenceFinder(ReferenceFinder const &toCopy)
{
	this->_references = toCopy._references;
}

ReferenceFinder	&ReferenceFinder::operator=(ReferenceFinder const & toCopy)
{
	this->_references = toCopy._references;
	return (*this);
}

refContainer const	&ReferenceFinder::getInfo(void) const
{
	if (this->_status == SUCCESS)
		return (this->_info);
	else
		return (this->_error);
}

refContainer const	&ReferenceFinder::getRefs(void) const
{
	if (this->_status == SUCCESS)
		return (this->_references);
	else
		return (this->_error);
}

refContainer const	&ReferenceFinder::getShortRefs(void) const
{
	if (this->_status == SUCCESS)
		return (this->_shortReferences);
	else
		return (this->_error);
}

refContainer const	&ReferenceFinder::getDoubles(void) const
{
	if (this->_status == SUCCESS)
		return (this->_doubles);
	else
		return (this->_error);
}

short	ReferenceFinder::getStatus(void) const
{
	return (this->_status);
}

// int	ReferenceFinder::setRefs(std::string &filePath)
#include "ReferenceFinder.setRefs.cpp"
