#ifndef LheReader_HH
#define LheReader_HH

#include <FastAnalysis/Utils.hh>
#include <FastAnalysis/FourMomentum.hh>
#include <fstream>
#include <sstream>

using namespace std;

namespace FastAnalysis {

class LheReader {

public:

    LheReader(string filename = "");
    ~LheReader();
    void addFile(string filename);
    pair<vector<FourMomentum>,vector<double> > nextEvent();

private:

    string _filename;
    bool _opened;
    ifstream _file;

};

} // end namespace
#endif
