//
// Created by Darwin Yuan on 2020/6/16.
//

#ifndef TRANS_DSL_2_VOIDHELPER_H
#define TRANS_DSL_2_VOIDHELPER_H

#include <trans-dsl/sched/action/SchedVoid.h>
#include <trans-dsl/sched/concepts/SchedActionConcept.h>
#include <trans-dsl/sched/concepts/ConceptHelper.h>

TSL_NS_BEGIN

namespace details {
   template<typename T_ACTION VOID_CONCEPT>
   struct Void_;

   template<CONCEPT_C(SchedActionConcept, T_ACTION)>
   struct Void_<T_ACTION ENABLE_C(SchedActionConcept, T_ACTION)> : SchedVoid {
   private:
      IMPL_ROLE_WITH_VAR(SchedAction, action);
      T_ACTION action;
   };
}

TSL_NS_END

#define __void(...) TSL_NS::details::Void_<__VA_ARGS__>

#endif //TRANS_DSL_2_VOIDHELPER_H
