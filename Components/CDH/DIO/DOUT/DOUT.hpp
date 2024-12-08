// ======================================================================
// \title  DOUT.hpp
// \author djwait
// \brief  hpp file for DOUT component implementation class
// ======================================================================

#ifndef DIO_DOUT_HPP
#define DIO_DOUT_HPP

#include "Components/CDH/DIO/DOUT/DOUTComponentAc.hpp"

namespace DIO {

  class DOUT :
    public DOUTComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct DOUT object
      DOUT(
          const char* const compName //!< The component name
      );

      //! Destroy DOUT object
      ~DOUT();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command DOUT_ON_OFF
      //!
      //! Set the digital out state to on or off
      void DOUT_ON_OFF_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Fw::On onOff //!< Sets the ditial out as on or off
      ) override;

  };

}

#endif
