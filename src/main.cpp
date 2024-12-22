#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <wex.h>
#include "cStarterGUI.h"

#include "PackEngine.h"

typedef raven::pack::cItem box_t;

raven::pack::cEngine theEngine;

std::vector<box_t> theBoxes;

void gen1( int count )
{
    int max = 100;
    int min = 10;

    srand(77);
    theBoxes.clear();
    for (int k = 0; k < count; k++)
    {
        double x = rand() % (max - min) + min;
        double y = rand() % (max - min) + min;
        double z = rand() % (max - min) + min;
        theBoxes.emplace_back(x, y, z);

        // std::cout << "( " << x << " " << y << "),";
    }
}

void cGUI::draw(wex::shapes &S)
{
    double Z = 0;
    double scale = 10;
    for (auto &box : theEngine.getPack())
    {
        if (box.loc.z <= Z && box.loc.z + box.wlh.z >= Z)
            S.rectangle(
                cxy(
                    scale * box.loc.x,
                    scale * box.loc.y),
                cxy(
                    scale * (box.wlh.x),
                    scale * (box.wlh.y)));
    }
}

main()
{
    //theEngine.test();
    gen1(5);
    theEngine.setSize(100, 100, 100);
    for( auto& box : theBoxes)
        theEngine.pack(box);
    cGUI theGUI;
    return 0;
}
