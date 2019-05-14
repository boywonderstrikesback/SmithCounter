
#include <fstream>
#include <string>
#include "SmithCounter.h"
#include <cmath>


using namespace std;



SmithCounter::SmithCounter(int bits, int Value) {
    
    Value = State;
    Bits = bits;
    mask_Value = (pow(2,Bits)) - 1;
    
}
void SmithCounter::BranchRecord(bool Accepted){
    
    if( Accepted ) BranchRecord_Accepted();
    else BranchRecord_Rejected();
    
}
void SmithCounter::BranchRecord_Accepted() {
    
    State ++;
    if(State > 3) State = 3;
    
}
void SmithCounter::BranchRecord_Rejected() {
    
    State --;
    if(State < 0) State = 0;
    
}
bool SmithCounter::GetGuess() const {
    
    if(State > 1) return true;
    else return false;
    
}
int SmithCounter::GetState() const {
    
    return State;
    
}
