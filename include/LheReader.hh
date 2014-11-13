#ifndef LheReader_HH
#define LheReader_HH

#include <Utils.hh>
#include <FourMomentum.hh>
#include <fstream>
#include <sstream>

using namespace std;

namespace Analysis {

class LheReader {

public:

    LheReader(string filename);
    ~LheReader();
    void addFile(string filename);
    vector<FourMomentum> nextEvent();

private:

    string _filename;
    bool _opened;
    ifstream _file;

};

} // end namespace
#endif
