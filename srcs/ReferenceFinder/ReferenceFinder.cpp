/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceFinder.cpp                              created by ccantale    */
/*                                                                            */
/*    project: DLQsniper                       claudio.cantale93@gmail.com    */
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

refContainer const	&ReferenceFinder::getRefs(void) const
{
	return (this->_references);
}

refContainer const	&ReferenceFinder::getShortRefs(void) const
{
	return (_shortReferences);
}

// int	ReferenceFinder::setRefs(std::string &filePath)
#include "ReferenceFinder.setRefs.cpp"
