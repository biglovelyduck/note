#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include "textquery.h"

/**
 * @brief Query Result
 */
class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    //! constructor
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> sp_l,
                StrBlob f) :
        sought(s), sp_lines(sp_l), file(f) { }

    //! added for ex12.33
    //! ? Think about wether the "const"s here are expected.
    const StrBlob& get_file() const{ return file; }

    std::set<TextQuery::line_no>::iterator
    begin() { return sp_lines->begin(); }

    std::set<TextQuery::line_no>::iterator
    end()   { return sp_lines->end();   }



private:
    //! three data members
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> sp_lines;
    StrBlob file;

};

/**
 * @brief print the result to the output stream specified.
 */
std::ostream&
print(std::ostream&, const QueryResult &);

std::ostream
&print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.sp_lines->size() << " "
       << "times"   <<  "\n";

    //! print each line in which the word appears
    for ( auto &index : *qr.sp_lines)
    {
        os << "\t(line " << index + 1 << ") ";
        const StrBlobPtr wp(qr.file, index);
        os << wp.deref() << "\n";
    }
    return os;

}

#endif // QUERYRESULT_H

