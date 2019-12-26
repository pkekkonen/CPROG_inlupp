
#ifndef MemberFunctionPair_h
#define MemberFunctionPair_h
#include "Sprite.h"
typedef void (Sprite::*MemberFunction) ();

class MemberFunctionPair {
public:
    static MemberFunctionPair* create(Sprite* spriteObj, MemberFunction memFun);
    ~MemberFunctionPair();
    Sprite* getSpriteObj() { return spriteObj; }
    MemberFunction getMemberFunction() {return memFun;}
    const MemberFunctionPair& operator=(const MemberFunctionPair& other);
    MemberFunctionPair(const MemberFunctionPair& other);
private:
    Sprite* spriteObj;
    MemberFunction memFun;
    MemberFunctionPair(Sprite* sprObj, MemberFunction memFun): spriteObj(sprObj), memFun(memFun) {}


};

#endif /* MemberFunctionPair_h */
