// ---------------------------------------------------------------------------
// Name: Christelle Mbemba
// Course-Section: CS255-02
// Assignment: Project 8
// Date due: 04/09/2023
// Description:  implementation of an address class with overloaded operators for comparison and output.
// ---------------------------------------------------------------------------
#include <iostream>
#include <fstream>

#include "addressType.h"
#include "linkedList.h"
using namespace std;

int main()
{
    int count = 0;
    ifstream inFile;
    inFile.open("addresses.txt");
    linkedListType<addressType> atLL;
    addressType atTemp;
    string temp, f, l, sA, c, s, zst;
    int z;
    while(getline(inFile, temp))
    {
        switch(count)
        {
            case 0:
                f = temp;
                break;
            case 1:
                l = temp;
                break;
            case 2:
                sA = temp;
                break;
            case 3:
                c = temp;
                break;
            case 4:
                s = temp;
                break;
            case 5:
                zst = temp;
                z = stoi(zst);
                atTemp.setAll(f, l, sA, c, s, z);
                atLL.insert(atTemp);
                break;
        }
        count = (count+1) % 6;
    }

    atLL.print();
    atLL.sort();
    cout<<endl<<endl;
    cout<<"SORTED LIST"<<endl;
    atLL.print();

    addressType atDel;
    atDel.setAll("Daniel", "Ray", "1234 Woodlow Dr SE", "Huntsville", "AL", 32523);
    atLL.deleteNode(atDel);
    cout<<endl<<endl;
    cout<<"UPDATED LIST"<<endl;
    atLL.print();
    return 0;
}
