#include "microwave.hpp"

void MicrowaveImpl::RegisterDoorOpenChangedCallBack(std::function<void(bool)> callback) {
    m_doorOpenChangedCallBack = std::move(callback);
}

void MicrowaveImpl::RegisterStartButtonPressedCallBack(std::function<void(void)> callback) {
    m_startButtonPressedCallBack = std::move(callback);
}

/// <summary>
/// Turns off the Microwave heater element
/// </summary>
void MicrowaveImpl::TurnOffHeater() {
    if (not m_startButtonPressedCallBack) {
        Error("callback was not provideed, aborting");
        return;
    }
    if (m_isDoorOpen) {
        Log("Doors were open, was not heating by default");
    }
    m_isHeatingActive = false;
    m_isLampActive = false;
    m_startButtonPressedCallBack();
    m_turnoffTimeout =
            std::chrono::steady_clock::now();  // resetting to currnet moment, for all actions it will be known as past
}

/// <summary>
/// Turns on the Microwave heater element
/// </summary>
void MicrowaveImpl::TurnOnHeater() {
    if (m_isDoorOpen) {
        Error("Doors opened, heating aborted");
        return;
    }
    if (not m_startButtonPressedCallBack) {
        Error("no callback for starting heating, aborting");
        return;
    }
    if (m_turnoffTimeout > std::chrono::steady_clock::now()) {
        Log("timer active, heating in progess");
        m_turnoffTimeout += std::chrono::minutes{1};
    } else {  // process was not running, calculating new timeout
        m_turnoffTimeout = std::chrono::steady_clock::now() + std::chrono::minutes{1};
        m_isHeatingActive = true;
        m_isLampActive = true;
    }
    m_startButtonPressedCallBack();
}
