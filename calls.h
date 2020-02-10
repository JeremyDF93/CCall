#ifndef _INCLUDE_CALLS_H_
#define _INCLUDE_CALLS_H_

#include "extension.h"

#define CALL_DECL(name, ret, args) \
  class name##Class { \
  public: \
    static ret (name##Class::*p##name)args; \
  }; \
  ret (name##Class::*p##name)args = nullptr
#define CALL_INVOKE(obj, name) (reinterpret_cast<name##Class *>(obj)->*p##name)

#define CALL_DECL_STATIC(name, ret, args) ret (*p##name)args = nullptr
#define CALL_INVOKE_STATIC(name) (p##name)

#define CALL_JOIN(name, signame) (*((void **)&p##name) = CCallManager::GetAddress(signame))

class CCallManager {
  public:
    static void Init(IGameConfig *gameconf);
    static void *GetAddress(const char *signame);
  private:
    static IGameConfig *gameconf;
};

#endif // _INCLUDE_CALLS_H_
