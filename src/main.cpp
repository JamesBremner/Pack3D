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

void gen1()
{
    int count = 2;
    int max = 10;
    int min = 1;

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

class cGUI : public cStarterGUI
{
public:
    cGUI()
        : cStarterGUI(
              "Starter",
              {50, 50, 1000, 500}),
          lb(wex::maker::make<wex::label>(fm))
    {
        lb.move(50, 50, 100, 30);
        lb.text("Hello World");

        show();
        run();
    }

private:
    wex::label &lb;
};

main()
{
    theEngine.test();
    gen1();
    theEngine.setSize(100,100,100);
    theEngine.pack( theBoxes[0] );
    //cGUI theGUI;
    return 0;
}
