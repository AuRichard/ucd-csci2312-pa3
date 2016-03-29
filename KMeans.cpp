#include <iostream>

using namespace std;

namespace Clustering {
    
    // Constructor:
    KMeans::KMeans(unsigned int dim, unsigned int k, std::string filename, unsigned int maxIter){

        __dimensionality = dim;
        __k = k;
        __iFileName = filename;
        __maxIter = maxIter;
        __numNonempty = 1
        __clusters = new Cluster *[k];
        
        // If __k is zero, throw an exception:
        if(__k == 0)
            throw ZeroClustersEx();

    }
    
    // Destructor:
    KMeans::~KMeans(){
        delete [] __clusters;
        delete [] __initCentroids;
    }

    
    
}


