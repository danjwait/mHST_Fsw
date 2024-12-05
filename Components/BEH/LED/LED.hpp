// ======================================================================
// \title  LED.hpp
// \author djwait
// \brief  hpp file for LED component implementation class
// ======================================================================

#ifndef BEH_LED_HPP
#define BEH_LED_HPP

#include "Components/BEH/LED/LEDComponentAc.hpp"

namespace BEH {

  class LED :
    public LEDComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct LED object
      LED(
          const char* const compName //!< The component name
      );

      //! Destroy LED object
      ~LED();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command TODO
      //!
      //! TODO
      void TODO_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      ) override;

  };

}

#endif
