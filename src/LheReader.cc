#include <FastAnalysis/LheReader.hh>

using namespace std;

namespace FastAnalysis {

LheReader::LheReader(string filename)
    :  _filename(filename), _opened(false)
      {}

LheReader::~LheReader() {}

void LheReader::addFile(string filename) {
    _filename = filename;
    _opened = false;
}

pair<vector<FourMomentum>,vector<double> > LheReader::nextEvent() {
    assert(_filename != "");
    if(_opened == false) { _file.open(_filename.c_str()); _opened = true; }
    vector<FourMomentum> particles;
    double px, py, pz, E, weight, scale;
    int pdg, status, dump;
    string line;
    while(true) {
      getline(_file, line);
      if (!_file) return make_pair(particles,0.);// end of file
      if (line == "<event>") {
        getline(_file, line);
        istringstream iss(line);
        iss >> dump >> dump >> weight >> scale;
        while (true) {
          getline(_file, line);
          if (line == "</event>") break;
          istringstream iss(line);
          iss >> pdg >> status >> dump >> dump >> dump >> dump >> px >> py >> pz >> E;
          particles.push_back(makeVectorPxPyPzE(px,py,pz,E,pdg,status));
        }
      break;
      }
    }
    vector<double> tmp;
    tmp.push_back(weight);
    tmp.push_back(scale);
    return make_pair(particles, tmp);
}

} // end namespace
