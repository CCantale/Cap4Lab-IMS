/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceAnalyser.analyse.cpp                    created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "ReferenceAnalyser.hpp"

static std::string	writeResult(refContainer &result)
{
	std::string	resultReport;

	resultReport += APP_NAME;
	resultReport += " ";
	resultReport += VERSION;
	resultReport += "\n\nAnalysis of the DLQ.";
	if (result.size() == 1)
	{
		resultReport += "\n\nNo references were selected.\n\n";
	}
	else
	{
		resultReport += "\n\nThe analysis was successful and ";
		resultReport += std::to_string(result.size() - 1);
		resultReport += " references were selected:\n\n";
		refContainer::iterator it = result.begin();
		++it;
		for (; it != result.end(); ++it)
		{
			std::string	nextRef;

			nextRef = *it + "\n";
			resultReport.append(nextRef);
		}
		resultReport += "\n\n";
	}
	return (resultReport);
}

static std::string	writeDoubles(refContainer const &doubles)
{
	std::string	doublesReport;

	if (doubles.size())
	{
		doublesReport += std::to_string(doubles.size());
		doublesReport += " double(s) found:\n\n";
		for (std::string doub : doubles)
		{
			doublesReport += doub;
			doublesReport += "\n";
		}
		doublesReport += "\n";
	}
	else
	{
		doublesReport += "No doubles found.\n\n";
	}
	return (doublesReport);
}

static std::string	writeSource(refContainer &DLQcontent, refContainer const &incidents)
{
	std::string	sourceReport;

	sourceReport += "Source:\nDLQ refs\tIncidents\n\n";
	for (size_t i = 0; i < DLQcontent.size() || i < incidents.size(); ++i)
	{
		if (i < DLQcontent.size())
			sourceReport.append(DLQcontent[i]);
		else
			sourceReport.append("\t\t");
		sourceReport.append("\t");
		if (i < incidents.size())
			sourceReport.append(incidents[i]);
		sourceReport.append("\n");
	}
	return (sourceReport);
}

static void	writeIntro(refContainer &DLQcontent, refContainer const &incidents, refContainer &result, refContainer const &doubles)
{
	std::string	resultReport = writeResult(result);
	std::string	doublesReport = writeDoubles(doubles);
	std::string	sourceReport = writeSource(DLQcontent, incidents);

	result.clear();
	result.push_back(resultReport);
	if (doublesReport.size())
		result.push_back(doublesReport);
	result.push_back(sourceReport);
	result.push_back("\nHave a nice day!\n");
}

static void	refDiff(refContainer &DLQcontent, refContainer const &incidents, refContainer &result)
{
	bool	found;

	found = false;
	for (std::string ref : DLQcontent)
	{
		for (std::string inc : incidents)
		{
			if (ref == inc)
			{
				found = true;
				break ;
			}
		}
		if (found == false)
		{
			result.push_back(ref);
		}
		else
		{
			found = false;
		}
	}
}

static refContainer	analyse(ReferenceFinder &DLQ, refContainer const &incidents)
{
	refContainer	result;
	refContainer	refs;
	std::string	intro;

	result.push_back(intro);
	refs = DLQ.getShortRefs();
	refDiff(refs, incidents, result);
	//removeDoubles(refs, DLQ.getDoubles());
	writeIntro(refs, incidents, result, DLQ.getDoubles());
	return (result);
}
