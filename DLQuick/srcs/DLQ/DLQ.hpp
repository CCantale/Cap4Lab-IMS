/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    DLQ.hpp                                          created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef DLQ_HPP
# define DLQ_HPP

# define MISSING_INPUT_FILE_ERROR	"DLQ: Couldn't find \"" INPUT_FILE "\". It should be placed in the same folder as the executable."
# define EMPTY_INPUT_ERROR		"DLQ: \"" INPUT_FILE "\" is empty"
# define REF_NOT_FOUND			"Reference not found."

# include <vector>
# include <string>
# include <iostream>
# include <cctype>
# include <fstream>
# include "../macros.h"
# include "../Logger/Log.h"

using refContainer = std::vector<std::string>;

class	DLQ
{
	private:
		refContainer		_info;
		refContainer		_references;
		refContainer		_shortReferences;
		refContainer		_doubles;
		refContainer		_error;
		short			_status = ERROR;

	public:
					DLQ(void);
					~DLQ(void);
					DLQ(std::string filePath);
					DLQ(DLQ const &toCopy);
		DLQ		&operator=(DLQ const &toCopy);
		int			setRefs(std::string &filePath);
		refContainer const	&getInfo(void) const;
		refContainer const	&getRefs(void) const;
		refContainer const	&getShortRefs(void) const;
		refContainer const	&getDoubles(void) const;
		short 			getStatus(void) const;

		class			RFException : public std::exception
		{
			private:
				std::string	_errorMsg = "DLQ error";

			public:
				RFException(void) {}
				RFException(std::string errorMsg) : _errorMsg(errorMsg)
				{
					Log::lerr << timestamp << "Error: " << _errorMsg << std::endl;
				}
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
