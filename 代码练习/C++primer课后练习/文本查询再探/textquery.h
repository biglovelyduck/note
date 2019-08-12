#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "StrBlob.h"
#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>

class QueryResult;

/**
 * @brief The TextQuery class using StrBlob
 */
class TextQuery
{
public:
    typedef StrBlob::size_type line_no;

    //! constructor
    TextQuery(std::ifstream& fin);

    //! query operation
    QueryResult query(const std::string&) const;

private:
    //! data members
    StrBlob file;

    std::map<std::string,
             std::shared_ptr<std::set<line_no>>> wordMap;

};

#endif // TEXTQUERY_H

