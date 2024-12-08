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
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
