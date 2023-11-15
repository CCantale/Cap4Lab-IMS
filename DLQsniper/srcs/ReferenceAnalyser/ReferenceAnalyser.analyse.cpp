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

static void	writeIntro(refContainer &DLQcontent, refContainer &incidents, refContainer &result, refContainer &doubles)
{
	std::string	resultReport;
	std::string	doublesReport;
	std::string	sourceReport;

	if (result.size() == 1)
	{
		resultReport = "DLQsniper " + VERSION + "\n\nNo references were selected.\n\n";
	}
	else
	{
		resultReport = "DLQsniper " + VERSION + "\n\nThe analysis was successful and "
			+ result.size() - 1 + " references were selected:\n\n";
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
	if (doubles.size())
	{
		//REPORT DOUBLES
	}
	sourceReport += "Source:\nDLQ refs\t\tIncidents\n\n";
	for (int i = 0; i < DLQcontent.size() && i < incidents.size(); ++i)
	{
		if (i < DLQcontent.size())
			sourceReport.append(DLQcontent[i]);
		else
			sourceReport.append("\t\t");
		sourceReport.append("\t");
		if (i < incidents.size())
			sourceReport.append(incidents[i]);
	}
	result[0] += "\nHave a nice day!\n";
}

static void	refDiff(refContainer &DLQcontent, refContainer &incidents, refContainer &result)
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
		if (found == true)
		{
			result.push_back(ref);
			found = false;
		}
	}
}

static refContainer	&removeDoubles(refContainer &DLQcontent)
{
	refContainer	doubles;

	for (refContainer::iterator it = DLQcontent.begin(); it != DLQcontent.end(); ++it)
	{
		for (refContainer::iterator j = it; j != DLQcontent.end(); ++j)
		{
			if (*it == *j)
			{
				doubles.push_back(*j);
				DLQcontent.erase(j);
			}
		}
	}
	return (doubles);
}

static refContainer	&analysis(refContainer &DLQcontent, refContainer &incidents, refContainer &result)
{
	refContainer	doubles;

	doubles = removeDoubles(DLQcontent);
	refDiff(DLQcontent, incidents, result);
	return (doubles);
}

// I don't want the original DLQcontent to be modified, that's why it is not a reference here
static refContainer	&analyse(refContainer DLQcontent, refContainer &incidents)
{
	refContainer	result;
	refContainer	doubles;
	std::string	intro;

	result.push_back(intro);
	doubles = analysis(DLQcontent, incidents, result);
	writeIntro(DLQcontent, incidents, result, doubles);
	return (result);
}
