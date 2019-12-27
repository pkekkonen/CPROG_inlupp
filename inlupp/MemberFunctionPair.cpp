//
//#include <stdio.h>
//#include "MemberFunctionPair.h"
//
//MemberFunctionPair* MemberFunctionPair::create(Sprite* spriteObj, MemberFunction memFun) {
//    return new MemberFunctionPair(spriteObj, memFun);
//}
//
//const MemberFunctionPair& MemberFunctionPair::operator=(const MemberFunctionPair& other) {
//    if(this != &other) {
//        delete spriteObj;
//        //delete memFun; måste deleta funcPoint?
//        spriteObj = other.spriteObj;
//        memFun = other.memFun;
//    }
//    return *this;
//}
//
//
//MemberFunctionPair::MemberFunctionPair(const MemberFunctionPair& other) {
//    spriteObj = other.spriteObj;
//    memFun = other.memFun;
//}
//
//MemberFunctionPair::~MemberFunctionPair() {
//    delete spriteObj;
//    //måste städa bort funcpointer?
//}
//
