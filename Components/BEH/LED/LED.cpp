// ======================================================================
// \title  LED.cpp
// \author djwait
// \brief  cpp file for LED component implementation class
// ======================================================================

#include "Components/BEH/LED/LED.hpp"
#include "FpConfig.hpp"

namespace BEH {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  LED ::
    LED(const char* const compName) :
      LEDComponentBase(compName)
  {

  }

  LED ::
    ~LED()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void LED ::
    TODO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
