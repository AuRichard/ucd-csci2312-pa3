//
// Created by Richard Au on 3/20/2016.
//

#include <string>
#include <sstream>
#include <algorithm>
#include "Cluster.h"
#include <iostream>
using namespace std;
using namespace Clustering;
namespace Clustering
{
    LNode::LNode(const Point & newPoint, LNodePtr nextPtr):point(newPoint)
    {
        point=newPoint;
        next=nextPtr;
    }
    Clustering::Cluster::Cluster()
    {
        __size = 0;
        __points = nullptr;
    }
    int Clustering::Cluster::getSize() const
    { return __size; }
    Clustering::Cluster::Cluster(const Cluster & rhs):Cluster()
    {
        for (int count = 0;
             count < rhs.__size;
             count++)
            add(rhs[count]);
    }
    Cluster &Clustering::Cluster::operator=(const Cluster &rhs)
    {
        LNodePtr curr;
        if(this==&rhs)
            return *this;
        else
        {
            while (__points != nullptr)
            {
                curr = __points;
                __points = __points->next;
                delete curr;
                __size--;
            }
            for (int count = 0;
                 count < rhs.__size;
                 count++)
                add(rhs[count]);
        }
        return *this;
    }
    const Point &Cluster::operator[](unsigned int index) const
    {
        LNodePtr cursor=__points;
        for(int count =0;
            (count < index) && (cursor->next != nullptr);
            count++)
            cursor=cursor->next;
        return cursor->point;
    }
    Clustering::Cluster::~Cluster()
    {
        if(__points!=nullptr)
        {
            LNodePtr prev=__points;
            LNodePtr curr=nullptr;
            while (prev != nullptr)
            {
                curr = prev->next;
                delete prev;
                prev = curr;
            }
        }
    }
//**************************************************
//                  add
//
// task:    This adds a point to linked list in
//          lexographical (alphabetical) order
// Postcondition: a point is added to the linked list,
//                retaining the lexigraphical order
//
//***************************************************
    void Clustering::Cluster::add(const Point &point)
    {
        LNodePtr insertPtr=new LNode(point, nullptr);
        LNodePtr curr=__points;
        LNodePtr prev=__points;
        if(__points==nullptr)
        {
            __points = insertPtr;
            __size++;
            return;
        }
        else if(__points->next==nullptr)
        {
            if(point<__points->point)
            {
                __points=insertPtr;
                insertPtr->next=prev;
                __size++;
                return;
            }
            else
            {
                __points->next=insertPtr;
                __size++;
                return;
            }
        }
        else
        {
            curr=curr->next;
            if(point < prev->point)
            {
                __points = insertPtr;
                insertPtr->next=prev;
                __size++;
                return;
            }
            while(curr!=nullptr)
            {
                if(point < curr->point)
                {
                    prev->next=insertPtr;
                    insertPtr->next=curr;
                    __size++;
                    return;
                }
                curr = curr->next;
                prev = prev->next;
            }
            prev->next=insertPtr;
            __size++;
        }
    }
//**************************************************
//                  remove
//
// task:    This removes a point from the cluster
// Postcondition: Takes in an point as an parameter
//
//***************************************************
    const Point &Clustering::Cluster::remove(const Point &point)
    {
        LNodePtr curr=__points;
        LNodePtr prev=__points;
        if(__points==nullptr)
            return point;
        else if(__points->point == point)
        {
            curr=__points;
            __points=__points->next;
            delete curr;
            __size--;
        }
        else
        {
            curr=curr->next;
            while (curr!= nullptr)
            {
                if (curr->point == point)
                {
                    prev->next=curr->next;
                    delete curr;
                    __size--;
                    break;
                }
                curr = curr->next;
                prev = prev->next;
            }
        }
        return point;
    }
//**************************************************
//                  Contains
//
// task:    Checks if a point is in the cluster
// Postcondition: Takes in an point as an parameter
//
//***************************************************
    bool Clustering::Cluster::contains(const Point &point)
    {
        for (LNodePtr Cursor = this->__points;
             Cursor != nullptr;
             Cursor = Cursor->next)
        {
            if (Cursor->point == point)
            {
                return true;
            }
        }
        return false;
    }
//**************************************************
//                  == Operator
//
// task:    Check if cluster are the same size
// Postcondition: Takes in 2 clusters as parameters
//
//***************************************************
    bool operator==(const Cluster &clust1, const Cluster &clust2)
    {
        LNodePtr clustObject1= clust1.__points;
        LNodePtr clustObject2=clust2.__points;
        bool equal=true;
        if (clust1.__size != clust2.__size)
            equal=false;
        while(clustObject1!=nullptr && clustObject2!=nullptr)
        {
            if(clustObject1->point!=clustObject2->point)
                equal=false;
            clustObject1=clustObject1->next;
            clustObject2=clustObject2->next;
        }
        return equal;
    }
//**************************************************
//                  != Operator
//
// task:    Check if cluster are not the same size
// Postcondition: Takes in 2 clusters as parameters
//
//***************************************************
    bool operator!=(const Cluster &clust1, const Cluster &clust2)
    { return (!(clust1==clust2)); }
    Cluster &Clustering::Cluster::operator+=(const Point &point)
    {
        add(point);
        return *this;
    }
//**************************************************
//                  -= Operator
//
// task:    Removes a point from cluster
// Postcondition: Takes in a point as a parameter
//
//***************************************************
    Cluster &Clustering::Cluster::operator-=(const Point &point)
    {
        remove(point);
        return *this;
    }
//**************************************************
//                  + Operator
//
// task:    Adds a new point to create a new cluster
// Postcondition: Takes in a cluster and a point as
// parameters
//
//***************************************************
    const Cluster operator+(const Cluster & clust1, const Point &point)
    {
        Cluster clust2(clust1);
        clust2+= point;
        return clust2;
    }
//**************************************************
//                  - Operator
//
// task:    Removes a point to create a new cluster
// Postcondition: Takes in a cluster and a point as
// parameters
//
//***************************************************
    const Cluster operator-(const Cluster & clust1, const Point &point)
    {
        Cluster clust2(clust1);
        clust2-= point;
        return clust2;
    }
//**************************************************
//                  += Operator
//
// task:    Combines two cluster
// Postcondition: takes in a cluster as a parameter
//
//***************************************************
    Cluster &Clustering::Cluster::operator+=(const Cluster & clust1)
    {
        for (int count = 0;
             count < clust1.__size;
             count++)
        {
            if (!contains(clust1[count]))
                add(clust1[count]);
        }
        return *this;
    }
//**************************************************
//                  -= Operator
//
// task:    create a new cluster by using differences
//          between 2 existing clusters
//
// Postcondition: takes in a cluster as a parameter
//
//***************************************************
    Cluster &Clustering::Cluster::operator-=(const Cluster &clust1)
    {
        for (int count = 0;
             count < clust1.__size;
             count++)
            if (contains(clust1[count]))
                remove(clust1[count]);
        return *this;
    }
//**************************************************
//                  + Operator
//
// task:    Combines 2 clusters
// Postcondition: Takes in 2 clusters as parameters
//
//***************************************************
    const Cluster operator+(const Cluster &clust1, const Cluster &clust2)
    {
        Cluster clustObject1(clust1);
        clustObject1+=clust2;
        return clustObject1;
    }
//**************************************************
//                  - Operator
//
// task:    Asymetrical differences between 2 clusters
// Postcondition: Takes in 2 clusters as parameters
//
//***************************************************
    const Cluster operator-(const Cluster &clust1, const Cluster &clust2)
    {
        Cluster clustObject1(clust1);
        clustObject1-=clust2;
        return clustObject1;
    }
//**************************************************
//                  << Operator
//
// task:    streams out cluster
// Postcondition: Takes in cluster as parameter
//
//***************************************************
    std::ostream &operator<<(std::ostream &os, const Cluster &clust1)
    {
        LNodePtr cursor=clust1.__points;
        for(int count = 0;
            count < clust1.__size;
            count++)
        {
            os << cursor->point << std::endl;
            cursor = cursor->next;
        }
        return os;
    }
//**************************************************
//                  >> Operator
//
// task:    streams in cluster
// Postcondition: Takes in cluster as parameter
//
//***************************************************
    std::istream &operator>>(std::istream &input, Cluster &clust1)
    {
        std::string holder;
        while (getline(input,holder))
        {
            if (holder.empty())
            {
                return input;
            }
            int count = std::count(holder.begin(), holder.end(), ',');
            Point ptr(count + 1);
            std::istringstream ss(holder);
            ss >> ptr;
            clust1.add(ptr);
        }
        return input;
    }
} 