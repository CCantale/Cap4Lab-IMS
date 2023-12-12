/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceFinder.hpp                              created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef REFERENCEFINDER_HPP
# define REFERENCEFINDER_HPP

# define MISSING_INPUT_FILE_ERROR	"ReferenceFinder: Couldn't find " INPUT_FILE ". It should be placed in the same folder as the executable."
# define NO_DLQ_ERROR			"ReferenceFinder: DLQuick couldn't find any valid references."
# define REF_NOT_FOUND			"Reference not found."

# include <vector>
# include <string>
# include <iostream>
# include <cctype>
# include <fstream>
# include "../macros.h"
# include "../Logger/Log.h"

using refContainer = std::vector<std::string>;

class	ReferenceFinder
{
	private:
		refContainer		_info;
		refContainer		_references;
		refContainer		_shortReferences;
		refContainer		_doubles;
		refContainer		_error;
		short			_status = ERROR;

	public:
					ReferenceFinder(void);
					~ReferenceFinder(void);
					ReferenceFinder(std::string filePath);
					ReferenceFinder(ReferenceFinder const &toCopy);
		ReferenceFinder		&operator=(ReferenceFinder const &toCopy);
		int			setRefs(std::string &filePath);
		refContainer const	&getInfo(void) const;
		refContainer const	&getRefs(void) const;
		refContainer const	&getShortRefs(void) const;
		refContainer const	&getDoubles(void) const;
		short 			getStatus(void) const;

		class			RFException : public std::exception
		{
			private:
				std::string	_errorMsg = "ReferenceFinder error";

			public:
				RFException(void) {}
				RFException(std::string errorMsg) : _errorMsg(errorMsg) {}
				virtual const char	*what(void) const throw() {
					return (this->_errorMsg.c_str());
				}
				std::string		&getError(void)
				{
					return (this->_errorMsg);
				}
		};
};

#endif
