#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include "TextQuery.h"

using namespace std;

class QueryResult 
{
friend ostream &print(ostream &, const QueryResult &);
public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p, shared_ptr<StrBlob> f):
        sought(s), lines(p), file(f) {}

    set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
    set<TextQuery::line_no>::iterator end() { return lines->end(); }
    // set<TextQuery::line_no>::const_iterator cbegin() const { return lines->cbegin(); }
    // set<TextQuery::line_no>::const_iterator cend() const { return lines->cend(); }

    shared_ptr<StrBlob> get_file() { return file; }

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<StrBlob> file;
};

ostream &print(ostream &, const QueryResult &);

#endif