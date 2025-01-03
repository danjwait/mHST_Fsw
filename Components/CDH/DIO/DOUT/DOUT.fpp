module DIO {
    @ Digital signal out- high-low or duty cycled
    active component DOUT {

        ##############################################################################
        # Custom commands, telemetry, parameters, events #
        ##############################################################################

        @ Set the digital out state to on or off
        async command DOUT_ON_OFF(
            onOff: Fw.On @< Sets the ditial out as on or off
        )

        @ Report digital out commanded on or off
        event SetDigitalOutOnOff($state: Fw.On) \
            severity activity high \ 
            format "Digital out set to {}"

        @ Report digital out interval parameter set
        event SetDigitalOutInterval(interval: U32) \
            severity activity high \ 
            format "Digital out interval set to {}"
    
        @ Report digital out state change due to interval
        event DigitalOutState(onOff: Fw.On) \
            severity activity low \
            format "Digital out is {}"
        
        @ Telemeter digital out state
        telemetry DOUT_STATE: Fw.On

        @ Telemeter number of cycles of digital out state
        telemetry DOUT_TRANSITION_COUNT: U64

        @ Parameter digital out cycle interval in rate group ticks
        param DOUT_INTERVAL_TICKS: U32 default 1

        @ Port receiving calls from rate group
        async input port run: Svc.Sched

        @ Port sending calls to the GPIO driver 
        output port gpioSet: Drv.GpioWrite
        
        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}