/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceAnalyser.analyse.cpp                    created by ccantale    */
/*                                                                            */
/*    project: DLQsniper                       claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

#include "ReferenceAnalyser.hpp"

static std::string	writeResult(refContainer &result)
{
	std::string	resultReport;

	resultReport += "DLQsniper ";
	resultReport += VERSION;
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

static std::string	writeDoubles(refContainer &doubles)
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

static void	writeIntro(refContainer &DLQcontent, refContainer const &incidents, refContainer &result, refContainer &doubles)
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

static refContainer	removeDoubles(refContainer &DLQcontent)
{
	refContainer	doubles;

	for (refContainer::iterator it = DLQcontent.begin(); it != DLQcontent.end(); ++it)
	{
		for (refContainer::iterator j = it + 1; j != DLQcontent.end(); ++j)
		{
			if (*it == *j)
			{
				doubles.push_back(*j);
				DLQcontent.erase(j);
				if (j == DLQcontent.end())
					break ;
			}
		}
	}
	return (doubles);
}

static refContainer	analysis(refContainer &DLQcontent, refContainer const &incidents, refContainer &result)
{
	refContainer	doubles;

	doubles = removeDoubles(DLQcontent);
	refDiff(DLQcontent, incidents, result);
	return (doubles);
}

// I don't want the original DLQcontent to be modified, that's why it is not a reference here
static refContainer	analyse(refContainer DLQcontent, refContainer const &incidents)
{
	refContainer	result;
	refContainer	doubles;
	std::string	intro;

	result.push_back(intro);
	doubles = analysis(DLQcontent, incidents, result);
	writeIntro(DLQcontent, incidents, result, doubles);
	return (result);
}
