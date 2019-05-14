
//  Smith.cpp
//  SmithCounter2
//
//  Created by Mike Ross on 5/1/19.
//  Copyright © 2019 Mike Ross. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include <string>
#include "SmithCounter.cpp"
#include "Stats.cpp"


using namespace std;
#include "SmithCounter.h"
#include "Stats.h"
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void read_file(char *file, SmithCounter counter[], Stats &stats);

int main(int argc, char* argv[]) {
    
    SmithCounter c[128];
    Stats   stats;
    
    read_file(" branch_trace.dat ", c, stats);
    
    cout << "stats: " <<"\n";
    cout << "Total: " << stats.getTotal() << "\n";
    cout << "Total Taken: "<< stats.TotalAccepted() << "\n";
    cout << "Taken Correct: "<< stats.AcceptedCorrect ()<< "\n";
    cout << "Taken Incorrect "<< stats.AcceptedIncorrect ()<< "\n";
    cout << "Total Not Taken "<< stats.TotalRejected() << "\n";
    cout << "Not Taken Correct "<< stats.RejectedCorrect() << "\n";
    cout << "Not Taken Incorrect "<< stats.RejectedIncorrect() << "\n";
    cout << "Percentage correct: " << stats.Percentage() << "%" << endl;
    return 0;
    
}

void read_file(char *file, SmithCounter counter[], Stats &stats) {
    
    string line;
     string state;
    int address;
    bool Accepted;
    
    
    ifstream infile(file);
    
    while(getline(infile, line, ' ')) {
        
        getline(infile, state, '\n');
        address = atoi(line.c_str());
        
        if(state == "T") Accepted = true;
        else Accepted = false;
        
        stats.Data(Accepted,counter[address%128].GetGuess());
        counter[address%128].BranchRecord(Accepted);
        
    }
    
    infile.close();

    }
    

