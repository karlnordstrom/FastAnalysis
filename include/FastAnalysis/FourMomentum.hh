#ifndef FourMomentum_HH
#define FourMomentum_HH

#include <FastAnalysis/Utils.hh>

using namespace std;

namespace FastAnalysis {

/// My own four momentum class to allow storage of
/// pdgid and status codes with the vector
/// (and other stuff in the future maybe)

class FourMomentum {

public:

    FourMomentum();
    FourMomentum(TLorentzVector& mom, int pdgid, int status);
    ~FourMomentum();
    TLorentzVector momentum() const;

    /// Setters
    void setMomentum(const TLorentzVector& vec);
    void setPdgId(const int pdgid);
    void setStatus(const int status);

    /// Accessers
    int pdgId() const;
    int status() const;
    float pt() const;
    float eta() const;
    float phi() const;
    float energy() const;
    float mass() const;

    float deltaR(FourMomentum other) const;
    float deltaPt(FourMomentum other) const;

    FourMomentum operator+ (const FourMomentum& other) const;
    void operator+= (const FourMomentum& other);
    FourMomentum operator- (const FourMomentum& other) const;
    void operator-= (const FourMomentum& other);


private:

    TLorentzVector _tvector;
    int _pdgId;
    int _status;

};

/// Helper functions for creating FourMomentum out of
/// vectors containing the pt, eta, phi, and E values

template <class N, class M, class R, class T>
FourMomentum makeVectorPtEtaPhiE(N pt, M eta, R phi, T E) {
    TLorentzVector vector;
    vector.SetPtEtaPhiE(pt, eta, phi, E);
    FourMomentum mom(vector, 0, 0);
    return mom;
}

template <class N, class M, class R, class T>
FourMomentum makeVectorPtEtaPhiE(N pt, M eta, R phi, T E, int pdgId, int status) {
    TLorentzVector vector;
    vector.SetPtEtaPhiE(pt, eta, phi, E);
    FourMomentum mom(vector, pdgId, status);
    return mom;
}

template <class N, class M, class R, class T>
vector<FourMomentum> makeVectorsPtEtaPhiE(vector<N> pt, vector<M> eta, vector<R> phi, vector<T> E, vector<int> pdgId, vector<int> status) {
    assert(pt.size() == eta.size() && eta.size() == phi.size() && phi.size() == E.size() && E.size() == pdgId.size() && pdgId.size() == status.size());//make sure input makes sense
    vector<FourMomentum> vectors;
    TLorentzVector vector;
    for(unsigned int it = 0; it < pt.size(); it++) {
        vector.SetPtEtaPhiE(pt[it], eta[it], phi[it], E[it]);
        FourMomentum mom(vector, pdgId[it], status[it]);
        vectors.push_back(mom);
    }
    return vectors;
}

template<class N, class M, class R, class T>
vector<FourMomentum> makeVectorsPtEtaPhiE(vector<N> pt, vector<M> eta, vector<R> phi, vector<T> E) {
    assert(pt.size() == eta.size() && eta.size() == phi.size() && phi.size() == E.size());//make sure input makes sense
    vector<FourMomentum> vectors;
    TLorentzVector vector;
    for(unsigned int it = 0; it < pt.size(); it++) {
        vector.SetPtEtaPhiE(pt[it], eta[it], phi[it], E[it]);
        FourMomentum mom(vector, 0, 0);
        vectors.push_back(mom);
    }
    return vectors;
}

/// Make four momenta from px, py, pz, E

template <class N, class M, class R, class T>
FourMomentum makeVectorPxPyPzE(N px, M py, R pz, T E) {
    TLorentzVector vector;
    vector.SetPxPyPzE(px, py, pz, E);
    FourMomentum mom(vector, 0, 0);
    return mom;
}

template <class N, class M, class R, class T>
FourMomentum makeVectorPxPyPzE(N px, M py, R pz, T E, int pdgId, int status) {
    TLorentzVector vector;
    vector.SetPxPyPzE(px, py, pz, E);
    FourMomentum mom(vector, pdgId, status);
    return mom;
}

template <class N, class M, class R, class T>
vector<FourMomentum> makeVectorsPxPyPzE(vector<N> px, vector<M> py, vector<R> pz, vector<T> E, vector<int> pdgId, vector<int> status) {
    assert(px.size() == py.size() && py.size() == pz.size() && pz.size() == E.size() && E.size() == pdgId.size() && pdgId.size() == status.size());//make sure input makes sense
    vector<FourMomentum> vectors;
    TLorentzVector vector;
    for(unsigned int it = 0; it < px.size(); it++) {
        vector.SetPxPyPzE(px[it], py[it], pz[it], E[it]);
        FourMomentum mom(vector, pdgId[it], status[it]);
        vectors.push_back(mom);
    }
    return vectors;
}

template<class N, class M, class R, class T>
vector<FourMomentum> makeVectorsPxPyPzE(vector<N> px, vector<M> py, vector<R> pz, vector<T> E) {
    assert(px.size() == py.size() && py.size() == pz.size() && pz.size() == E.size());//make sure input makes sense
    vector<FourMomentum> vectors;
    TLorentzVector vector;
    for(unsigned int it = 0; it < px.size(); it++) {
        vector.SetPxPyPzE(px[it], py[it], pz[it], E[it]);
        FourMomentum mom(vector, 0, 0);
        vectors.push_back(mom);
    }
    return vectors;
}



} // end namespace

#endif
