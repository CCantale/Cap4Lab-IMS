/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceAnalyser.hpp                            created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef REFERENCEANALYSER_HPP
# define REFERENCEANALYSER_HPP

# include <string>
# include <vector>
# include "../ReferenceFinder/ReferenceFinder.hpp"
# include "../macros.h"

class ReferenceAnalyser
{
	private:
		ReferenceFinder		_DLQ;
		refContainer		_incidents;
		refContainer		_result;

					ReferenceAnalyser(void);
	public:
					~ReferenceAnalyser(void);
					ReferenceAnalyser(ReferenceAnalyser &toCopy);
					ReferenceAnalyser(ReferenceFinder &DLQ);
					ReferenceAnalyser(ReferenceFinder &DLQ, refContainer const &incidents);
		ReferenceAnalyser	&operator=(ReferenceAnalyser &toCopy);
		void			setDLQ(ReferenceFinder &DLQ);
		void			setIncidents(refContainer const &incidents);
		refContainer const	&getResult(void) const;
};

#endif
