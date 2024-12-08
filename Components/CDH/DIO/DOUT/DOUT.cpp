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
    // report command success
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
