// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <smacc/smacc.hpp>

namespace sm_atomic_performance_test
{
using namespace smacc::default_transition_tags;

// STATE DECLARATION
struct State1 : smacc::SmaccState<State1, SmAtomicPerformanceTest>
{
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  typedef mpl::list<Transition<EvStateRequestFinish<State1>, State2>> reactions;

  // STATE FUNCTIONS
  static void staticConfigure() {}

  void runtimeConfigure() {}

  void onEntry() { this->postEvent<EvStateRequestFinish<State1>>(); }

  void onExit() {}
};
}  // namespace sm_atomic_performance_test
