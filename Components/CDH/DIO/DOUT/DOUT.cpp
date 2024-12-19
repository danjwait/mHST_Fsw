// ======================================================================
// \title  DOUT.cpp
// \author djwait
// \brief  cpp file for DOUT component implementation class
// ======================================================================

#include "Components/CDH/DIO/DOUT/DOUT.hpp"
#include "FpConfig.hpp"

namespace DIO {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  DOUT ::
    DOUT(const char* const compName) :
      DOUTComponentBase(compName)
  {

  }

  DOUT ::
    ~DOUT()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void DOUT ::
    DOUT_ON_OFF_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::On onOff
    )
  {
    // Set states
    this->m_toggleCounter = 0; // reset toggle count on any sucessful on/off command
    this->m_cycling = Fw::On::ON == onOff;
    // report state change
    this->log_ACTIVITY_HI_SetDigitalOutOnOff(onOff);
    // telemeter the digital out state (onOff) on channel BlinkingState.
    this->tlmWrite_DOUT_STATE(onOff);
    // report command success
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

  void DOUT ::
    parameterUpdated(FwPrmIdType id) 
  {
    Fw::ParamValid isValid = Fw::ParamValid::INVALID;
    switch (id)
    {
    case PARAMID_DOUT_INTERVAL_TICKS: {
      // Read back the parameter value
      const U32 interval = this->paramGet_DOUT_INTERVAL_TICKS(isValid);
      // Note: isValid is always VALID in parameterUpdated as it was just properly set
      FW_ASSERT(isValid == Fw::ParamValid::VALID, static_cast<FwAssertArgType>(isValid));
      // Report the interval set event
      this->log_ACTIVITY_HI_SetDigitalOutInterval(interval);
      break;
    }
    default:
      FW_ASSERT(0, static_cast<FwAssertArgType>(id));
      break;
    }
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void DOUT ::
    run_handler(
        FwIndexType portNum,
        U32 context
    )
  {
    // Read back the on/off toggle tick parameter value and check
    Fw::ParamValid isValid = Fw::ParamValid::INVALID;
    U32 interval = this->paramGet_DOUT_INTERVAL_TICKS(isValid);
    FW_ASSERT((isValid != Fw::ParamValid::INVALID) && (isValid != Fw::ParamValid::UNINIT),static_cast<FwAssertArgType>(isValid));

    // Only cycle when enabled and within interval
    if (this->m_cycling && (interval !=0)) {
      // if within interval
      if(this->m_toggleCounter == 0) {
        // toggle to On
        this->m_state = (this->m_state == Fw::On::ON) ? Fw::On::OFF : Fw::On::ON;
        this->m_transitions++;
        // telemeter transition count
        this->tlmWrite_DOUT_TRANSITION_COUNT(this->m_transitions);
        // write to GPIO; check port connection first
        if (this->isConnected_gpioSet_OutputPort(0)) {
          this->gpioSet_out(0, (Fw::On::ON == this->m_state) ? Fw::Logic::HIGH : Fw::Logic::LOW);
        } 
        // report state change
        this->log_ACTIVITY_LO_DigitalOutState(this->m_state);
      }

      this->m_toggleCounter = (this->m_toggleCounter +1) % interval;
    }
    // not within interval 
    else {
      if (this->m_state == Fw::On::ON) {
        // write to GPIO; check port connection first
        if (this->isConnected_gpioSet_OutputPort(0)) {
          this->gpioSet_out(0, Fw::Logic::LOW);
        }

      this->m_state = Fw::On::OFF;
      // report state change
      this->log_ACTIVITY_LO_DigitalOutState(this->m_state);
      }
    }
  }
}
