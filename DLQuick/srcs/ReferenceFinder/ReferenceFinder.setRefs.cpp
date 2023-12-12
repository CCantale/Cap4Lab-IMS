/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*    ReferenceFinder.setRefs.cpp                      created by ccantale    */
/*                                                                            */
/*    project: DLQuick                         claudio.cantale93@gmail.com    */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

static short	checkDoubles(refContainer &_doubles, refContainer &_shortRefs, std::string &shortReference)
{
	for (std::string ref: _shortRefs)
	{
		if (ref == shortReference)
		{
			_doubles.push_back(shortReference);
			return (NOT_OK);
		}
	}
	return (OK);
}

static std::string	isolateRef(std::string key_value)
{
	size_t	beg;
	size_t	end;

	beg = key_value.find(":");
	beg = key_value.find("\"", beg) + 1;
	end = key_value.find("\"", beg);
	return (key_value.substr(beg, end - beg));
}

static int	checkValidRef(std::string reference)
{
	if (reference[0] < 'A' || reference[0] > 'Z'
		|| reference[1] < 'A' || reference[1] > 'Z')
	{
		return (ERROR);
	}
	return (SUCCESS);
}

static size_t	getRefBeg(std::string &payload)
{
	size_t	refBeg;

	refBeg = payload.find("\"internalReference\"");
	if (refBeg == std::string::npos || checkValidRef(isolateRef(payload.substr(refBeg))) == ERROR)
		refBeg = payload.find("\"externalReference\"");
	if (refBeg == std::string::npos || checkValidRef(isolateRef(payload.substr(refBeg))) == ERROR)
		refBeg = payload.find("\"entityRef\"");
	if (refBeg == std::string::npos || checkValidRef(isolateRef(payload.substr(refBeg))) == ERROR)
		refBeg = payload.find("\"rootEntityRef\"");
	if (refBeg == std::string::npos || checkValidRef(isolateRef(payload.substr(refBeg))) == ERROR)
		refBeg = std::string::npos;
	return (refBeg);
}

static std::string	getNextRef(std::string &payload)
{
	std::string	reference("");
	size_t		refBeg;
	size_t		refEnd;

	refBeg = getRefBeg(payload);
	if (refBeg == std::string::npos)
	{
		reference = REF_NOT_FOUND;
		return (reference);
	}
	refBeg = payload.find(":", refBeg);
	refBeg = payload.find("\"", refBeg) + 1;
	refEnd = payload.find(",", refBeg);
	if (payload.find("}", refBeg) < refEnd)
		refEnd = payload.find("}", refBeg);
	reference = payload.substr(refBeg, refEnd - refBeg - 1);
	return (reference);
}

static std::string	makeShort(std::string key_value)
{
	std::string	ret;
	size_t		pos;

	ret = isolateRef(key_value);
	pos = ret.find("-");
	if (pos == ret.size())
		return (ret);
	return (ret.substr(0, pos));
}


static void processLine(refContainer &_info, refContainer &_refs, refContainer &_shortRefs, refContainer &_doubles, std::string &line)
{
	static short		lineNumber = 0;
	static std::string	id;
	static std::string	reference;
	static std::string	shortReference;

	switch(lineNumber)
	{
		case 0:
			id = line;
			break ;
		case 1:
			break ;
		case 2:
			reference = getNextRef(line);
			shortReference = makeShort(reference);
			if (checkDoubles(_doubles, _shortRefs, shortReference) == NOT_OK)
				break ;
			_info.push_back("ID: " + id + "\t\"EntityRef\": \"" + reference + "\"\t\"shortForm\": \"" + shortReference + "\"");
			_refs.push_back(reference);
			_shortRefs.push_back(shortReference);
			break ;
		case 3:
			lineNumber = -1;
			break ;
		default:
			break ;
	}
	++lineNumber;
}

int	ReferenceFinder::setRefs(std::string &filePath)
{
	std::ifstream	input(filePath.c_str());
	std::string	nextLine;
	std::string	errorMsg;

	try {
		if (!input.is_open())
		{
			throw RFException(MISSING_INPUT_FILE_ERROR);
		}
		while (!input.eof())
		{
			std::getline(input, nextLine);
			if (input.eof())
				break ;
			processLine(_info, _references, _shortReferences, _doubles, nextLine);
		}
		if (this->_shortReferences.size() == 0)
			throw RFException(NO_DLQ_ERROR);

	}
	catch (RFException &ex) {
		this->_status = ERROR;
		this->_error.push_back(ex.getError());
		Log::lerr << timestamp << "ERROR: " << ex.what() << std::endl;
		return (ERROR);
	}
	this->_status = SUCCESS;
	Log::lout << timestamp << "DLQ successfully loaded." << std::endl;
	return (SUCCESS);
}
