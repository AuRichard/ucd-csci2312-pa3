#include "Exceptions.h"
#include <cassert>
#include <sstream>
#include "Cluster.h"



namespace Clustering {

//**************************************************
//      OutOfBoundsEX Class
//***************************************************

    OutOfBoundsEx::OutOfBoundsEx(unsigned int c, int r) {
        
        this -> __current = c;
        this -> __rhs = r;

    }

    // Current Getter
    unsigned int OutOfBoundsEx::getCurrent() const{return this -> __current;}

    // Rhs Getter
    int OutOfBoundsEx::getRhs() const{return this -> __rhs;}

    // Name getter
    string OutOfBoundsEx::getName() const{return this -> __name;}


    ostream &Clustering::operator<<(ostream &os, const OutOfBoundsEx &ex) {
        
        os << ex << endl;
        
    }

//**************************************************
//      DimensionalityMismatchEx Class
//***************************************************

    DimensionalityMismatchEx::DimensionalityMismatchEx(unsigned int c, unsigned int r){
        
        this -> __current = c;
        this -> __rhs = r;
        
    }

    // Current Getter
    unsigned int DimensionalityMismatchEx::getCurrent() const{return this -> __current;}

    // Rhs Getter
    unsigned int DimensionalityMismatchEx::getRhs() const{return this -> __rhs;}

    // Name Getter
    string DimensionalityMismatchEx::getName() const{return this -> __name;}


    ostream &Clustering::operator<<(ostream &os, const DimensionalityMismatchEx &ex){
        
        os << ex << endl;

    }

//**************************************************
//      ZeroClusterEX Class
//***************************************************

    ZeroClustersEx::ZeroClustersEx(){__name.clear()}

    // Name Getter
    string ZeroClustersEx::getName() const{return this -> __name;}

    ostream &Clustering::operator<<(ostream &os, const ZeroClustersEx &ex){
        
        os << ex << endl;
        
    }

//**************************************************
//      DataFileOpenEx Class
//***************************************************

    DataFileOpenEx::DataFileOpenEx(string filename) {this-> __filename = filename;}

    // Filename Getter
    string DataFileOpenEx::getFilename() const{return this -> __filename;}

    // Name Getter
    string DataFileOpenEx::getName() const {return this -> __name;}

    ostream &Clustering::operator<<(ostream &os, const DataFileOpenEx &ex){
        
        os << ex << endl;
        
    }

//**************************************************
//      ZeroDimensionsEx Class
//***************************************************

    ZeroDimensionsEx::ZeroDimensionsEx(){__name.clear()}

    // Name Getter
    string ZeroDimensionsEx::getName() const {return this -> __name;}


    ostream &Clustering::operator<<(ostream &os, const ZeroDimensionsEx &ex){
        
        os << ex << endl;
        
    }

//**************************************************
//      EmptyClusterEx Class
//***************************************************


    EmptyClusterEx::EmptyClusterEx(){__name.clear()}

    // Name Getter
    string EmptyClusterEx::getName() const {return this -> __name;}


    ostream &Clustering::operator<<(ostream &os, const EmptyClusterEx &ex){
        
        os << ex << endl;
        
    }
}