//
//  SmithCounter.h
//  SmithCounter2
//
//  Created by Mike Ross on 5/1/19.
//  Copyright © 2019 Mike Ross. All rights reserved.
//

#ifndef SmithCounter_h
#define SmithCounter_h

class SmithCounter{

public:
    SmithCounter(int bits=2, int Value=0);
   
    void BranchRecord(bool Accepted);
        void BranchRecord_Accepted();
        void BranchRecord_Rejected();
    
    int  GetState() const;
    bool GetGuess() const;
   
    


private:
    
    int State;
    int Bits;
    int mask_Value;    
    int guess;
};

#endif // SMITHCOUNTER_H#endif /* SmithCounter_h */
