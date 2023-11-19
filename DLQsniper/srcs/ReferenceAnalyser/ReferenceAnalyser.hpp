/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceAnalyser.hpp                            created by ccantale    */
/*                                                                            */
/*    project: DLQsniper                       claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef REFERENCEANALYSER_HPP
# define REFERENCEANALYSER_HPP

# include <string>
# include <vector>
# include "../macros.h"

using	refContainer = std::vector<std::string>;

class ReferenceAnalyser
{
	private:
		refContainer		_result;
		refContainer		_DLQcontent;
		refContainer		_incidents;

	public:
					ReferenceAnalyser(void);
					~ReferenceAnalyser(void);
					ReferenceAnalyser(ReferenceAnalyser &toCopy);
					ReferenceAnalyser(refContainer const &DLQcontent, refContainer const &incidents);
		ReferenceAnalyser	&operator=(ReferenceAnalyser &toCopy);
		void			setDLQcontent(refContainer const &DLQcontent);
		void			setIncidents(refContainer const &incidents);
		refContainer const	&getResult(void) const;
};

#endif
