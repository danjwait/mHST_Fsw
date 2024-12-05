module BEH {
    @ Component for signaling LED
    active component LED {

        ##############################################################################
        # Custom Channels, Events, Commands, Parameters  #
        ##############################################################################

        @ Command to turn on or off the blinking LED
        async command LED_BLINK_ON_OFF(
            onOff: Fw.On @< LED blink on-off State
            )

        @ LED state telemetry 
        telemetry Led_State: Fw.On

        @ Event reporting change LED blink state on-off
        event LedBlinkStateSet($state: Fw.On) \
        severity activity high \
        format "LED blink state set to {}"

        @ Event reporting change LED blink interval
        event LedBlinkIntervalSet(interval: U32) \
        severity activity high \
        format "LED blink interval set to {}"

        @ Event reporting change LED state
        event LedState(onOff: Fw.On) \
        severity activity low \
        format "LED is {}"

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

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