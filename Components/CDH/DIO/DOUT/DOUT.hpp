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

      //! Handler implementation for run
      //!
      //! Port receiving calls from rate group
      void run_handler(
          FwIndexType portNum, //!< The port number
          U32 context //!< The call order
      ) override;

      //! Emit parameter updated EVR
      void parameterUpdated(FwPrmIdType id  //!< The parameter ID
                            ) override;

      //! Private state variables
      Fw::On m_state = Fw::On::OFF; //! track digital out state
      U64 m_transitions = 0; //! number of digital out transitions from FSW boot
      U32 m_toggleCounter = 0; //! counter for number of ticks the digital out has been "on"
      bool m_cycling = false; //! Flag: if true then digital out will cycle, else no cycling

  };

}

#endif
