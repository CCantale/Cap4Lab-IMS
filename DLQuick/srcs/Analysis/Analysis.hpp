/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    Analysis.hpp                                     created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#ifndef ANALYSIS_HPP
# define ANALYSIS_HPP

# include <string>
# include <vector>
# include "../DLQ/DLQ.hpp"
# include "../macros.h"
# include "../Logger/Log.h"

class Analysis
{
	private:
		DLQ			_DLQ;
		refContainer		_incidents;
		refContainer		_result;

					Analysis(void);
	public:
					~Analysis(void);
					Analysis(Analysis &toCopy);
					Analysis(DLQ &input);
					Analysis(DLQ &input, refContainer const &incidents);
		Analysis		&operator=(Analysis &toCopy);
		void			setDLQ(DLQ &input);
		void			setIncidents(refContainer const &incidents);
		refContainer const	&getResult(void) const;
};

#endif
