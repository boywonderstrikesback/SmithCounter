//
//  Stats.cpp
//  SmithCounter2
//
//  Created by Mike Ross on 5/1/19.
//  Copyright © 2019 Mike Ross. All rights reserved.
//

#include "Stats.h"

#include <fstream>
#include <string>


using namespace std;

Stats::Stats() {
    
    int Total= 0;
    
    int AcceptedTotal=0;
    int AcceptedTotalCorrect=0;
    
    int RejectedTotal=0;
    int RejectedTotalCorrect=0;
}

void Stats::Data(bool actual, bool Correct) {
    
    if (actual == true) {
        AcceptedTotal++;
        
        if (Correct == true) {
            AcceptedTotalCorrect++;
        }
    }
    
    else if (actual == false) {
        RejectedTotal++;
        
        if (Correct == false) {
            RejectedTotalCorrect++;
        }
    }
    Total = AcceptedTotal + RejectedTotal;
}



    int Stats::getTotal() const {
        return Total;
    }

    int Stats::TotalAccepted() const {
        return AcceptedTotal;
    }

    int Stats::AcceptedCorrect() const {
        return AcceptedTotalCorrect;
    }


    int Stats::AcceptedIncorrect () const {
        return AcceptedTotal - AcceptedTotalCorrect;
    }

int Stats::TotalRejected () const {
        return RejectedTotal;
    }

    int Stats::RejectedCorrect () const {
        return RejectedTotalCorrect;
    }

    int Stats::RejectedIncorrect() const {
        return RejectedTotal - RejectedTotalCorrect;

    }

    

    
double Stats::Percentage() {

    double denominator = ((double)getTotal());
    double numerator = ((double)RejectedCorrect()) + ((double)AcceptedCorrect());

    return (numerator/denominator)*100;

}
