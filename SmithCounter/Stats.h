//
//  Stats.h
//  SmithCounter2
//
//  Created by Mike Ross on 5/1/19.
//  Copyright © 2019 Mike Ross. All rights reserved.
//

#ifndef STATS_H
#define STATS_H
#include <iostream>
#include <iomanip>

using namespace std;


class Stats {


public:
    Stats();
    void Data(bool actual, bool Correct);
    
    void reset();
    
    int  getTotal() const;
    
        
    
        int TotalAccepted() const;
            int AcceptedCorrect () const;
            int AcceptedIncorrect () const;
    
        int TotalRejected () const;
            int RejectedCorrect() const;
            int RejectedIncorrect() const;
    
    
    double Percentage();
    
    
    friend std::ostream& operator<< (std::ostream&, const Stats&);
    
protected:
    int Total;
    
        int AcceptedTotal;
        int AcceptedTotalCorrect;
    
        int RejectedTotal;
        int RejectedTotalCorrect;
    
    
};

#endif // STATS_H
