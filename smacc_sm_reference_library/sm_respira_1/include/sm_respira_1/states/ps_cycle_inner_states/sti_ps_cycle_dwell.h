namespace sm_respira_1
{
namespace ps_cycle_inner_states
{
// STATE DECLARATION
struct StiPSCycleDwell : smacc::SmaccState<StiPSCycleDwell, SsPSCycle>
{
  using SmaccState::SmaccState;

  // DECLARE CUSTOM OBJECT TAGS
  struct TIMEOUT : ABORT
  {
  };
  struct NEXT : SUCCESS
  {
  };
  struct PREVIOUS : ABORT
  {
  };

  // TRANSITION TABLE
  typedef mpl::list<

    Transition<EvTimer<CbTimerCountdownOnce, OrTimer>, StiPSCycleLoop, TIMEOUT>,
    Transition<EvKeyPressP<CbDefaultKeyboardBehavior, OrKeyboard>, StiPSCycleExpire, PREVIOUS>,
    Transition<EvKeyPressN<CbDefaultKeyboardBehavior, OrKeyboard>, StiPSCycleLoop, NEXT>,

    Transition<EvKeyPressX<CbDefaultKeyboardBehavior, OrKeyboard>, MsLeakyLung, ABORT>,
    Transition<EvKeyPressZ<CbDefaultKeyboardBehavior, OrKeyboard>, MsPatientObstruction, ABORT>

    >
    reactions;

  // STATE FUNCTIONS
  static void staticConfigure()
  {
    configure_orthogonal<OrTimer, CbTimerCountdownOnce>(10);
    configure_orthogonal<OrSubscriber, CbWatchdogSubscriberBehavior>();
    configure_orthogonal<OrUpdatablePublisher, CbDefaultPublishLoop>();
    configure_orthogonal<OrKeyboard, CbDefaultKeyboardBehavior>();
  }

  void runtimeConfigure() {}

  void onEntry() { RCLCPP_INFO(getLogger(), "On Entry!"); }

  void onExit() { RCLCPP_INFO(getLogger(), "On Exit!"); }
};
}  // namespace ps_cycle_inner_states
}  // namespace sm_respira_1
