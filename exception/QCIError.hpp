#ifndef EXCEPTION_QCIERROR_HPP_
#define EXCEPTION_QCIERROR_HPP_

#include <exception>
#include <sstream>

namespace qci {
namespace common {

class QCIException: public std::exception {
protected:

	std::string errorMessage;

public:

	QCIException(std::string error) :
			errorMessage(error) {
	}

	virtual const char * what() const throw () {
		return errorMessage.c_str();
	}

	~QCIException() throw () {
	}
};

#define QCI_Abort do {std::abort();} while(0);

#define QCIError(errorMsg)												\
	{																	\
    	throw qci::common::QCIException("\n\n QCI Error caught! \n\n"	\
            	+ std::string(errorMsg) + "\n\n");						\
	}

}
}
#endif /* EXCEPTION_QCIERROR_HPP_ */
