
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "SmithCounter.h"
#include "Stats.h"
using namespace std;

int main()
{
    SmithCounter  c;
    Stats    stats;
    
    for (int i=0; i < 45; i++)
    {
        cout << setw(5) << i << "  Initally: " << c.GetState() << " predicing: "
        << c.GetGuess() << " then after ";
        if (rand() & 1)
        {
            c.BranchRecord_Accepted();
            stats.Data(true, c.GetGuess());
            cout << setw(10) << "TAKEN";
        }
        else
        {
            c.BranchRecord_Rejected();
            stats.Data(false, c.GetGuess());
            cout << setw(10) << "NOT TAKEN";
        }
        
        cout << " State is: " << c.GetState() << endl;
    }
    
    cout << "\n\nStats:\n" << stats << endl;
    
    return 0;
}
