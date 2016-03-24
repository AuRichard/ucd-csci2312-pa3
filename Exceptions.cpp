#include "Exceptions.h"
#include <cassert>
#include <sstream>
#include "Cluster.h"



namespace Clustering {

//**************************************************
//      OutOfBoundsEX Class
//***************************************************

    OutOfBoundsEx::OutOfBoundsEx(unsigned int c, int r) {

    }

    // Current Getter
    unsigned int OutOfBoundsEx::getCurrent() const { return __current;}

    // Rhs Getter
    int OutOfBoundsEx::getRhs() const { return __rhs; }

    // Name getter
    string OutOfBoundsEx::getName() const { return __name; }


    ostream &Clustering::operator<<(ostream &os, const OutOfBoundsEx &ex) {
        
    }

//**************************************************
//      DimensionalityMismatchEx Class
//***************************************************

    DimensionalityMismatchEx::DimensionalityMismatchEx(unsigned int c, unsigned int r){
        
    }

    // Current Getter
    unsigned int DimensionalityMismatchEx::getCurrent() const { return __current; }

    // Rhs Getter
    unsigned int DimensionalityMismatchEx::getRhs() const{ return __rhs; }

    // Name Getter
    string DimensionalityMismatchEx::getName() const
    { return __name;}


    ostream &Clustering::operator<<(ostream &os, const DimensionalityMismatchEx &ex){

    }

//**************************************************
//      ZeroClusterEX Class
//***************************************************

    ZeroClustersEx::ZeroClustersEx(){

    }

    // Name Getter
    string ZeroClustersEx::getName() const{ return __name; }




    ostream &Clustering::operator<<(ostream &os, const ZeroClustersEx &ex){
        
    }

//**************************************************
//      DataFileOpenEx Class
//***************************************************

    DataFileOpenEx::DataFileOpenEx(string filename) {
        
    }

    // Filename Getter
    string DataFileOpenEx::getFilename() const{ return __filename; }

    // Name Getter
    string DataFileOpenEx::getName() const { return __name; }

    ostream &Clustering::operator<<(ostream &os, const DataFileOpenEx &ex){
        
        
    }

//**************************************************
//      ZeroDimensionsEx Class
//***************************************************

    ZeroDimensionsEx::ZeroDimensionsEx(){

    }

    // Name Getter
    string ZeroDimensionsEx::getName() const { return __name; }


    ostream &Clustering::operator<<(ostream &os, const ZeroDimensionsEx &ex){
        
    }

//**************************************************
//      EmptyClusterEx Class
//***************************************************


    EmptyClusterEx::EmptyClusterEx(){

    }

    // Name Getter
    string EmptyClusterEx::getName() const { return __name; }


    ostream &Clustering::operator<<(ostream &os, const EmptyClusterEx &ex){
        
    }
}