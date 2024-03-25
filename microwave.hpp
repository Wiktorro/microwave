#include <iostream>
#include <functional>

#include <chrono>
#include <mutex>

//  considered interface-specific enums for handling the object states
// enum class MicrowaveStates: unit8_t {};

// remark : personally I would arrange interface differently about callbacks and more items
// as it would be more convenient if these functionals were given by class, not taken as input
//  but I treat it as client's requirement

class IMicrowaveInterface {
  public:
    virtual ~IMicrowaveInterface() = default;
    /// <summary>
    /// Turns on the Microwave heater element
    /// </summary>
    virtual void TurnOnHeater() = 0;
    /// <summary>
    /// Turns off the Microwave heater element
    /// </summary>
    virtual void TurnOffHeater() = 0;
    /// <summary>
    /// Indicates if the door to the Microwave oven is open or closed
    /// </summary>
    virtual bool IsDoorOpen() const = 0;
    /// <summary>
    /// Signal if the Door is opened or closed,
    /// </summary>
    virtual void RegisterDoorOpenChangedCallBack(std::function<void(bool)>) = 0;
    /// <summary>
    /// Signals that the Start button is pressed
    /// </summary>
    virtual void RegisterStartButtonPressedCallBack(std::function<void(void)>) = 0;
};

class MicrowaveImpl : public IMicrowaveInterface {
  public:
    MicrowaveImpl() = default;

    // assuming copy/move ctors have no logical point here, removing for safety
    MicrowaveImpl(const MicrowaveImpl&) = delete;
    MicrowaveImpl& operator=(const MicrowaveImpl&) = delete;
    MicrowaveImpl(MicrowaveImpl&&) = delete;
    MicrowaveImpl& operator=(MicrowaveImpl&&) = delete;

    ~MicrowaveImpl() override{};

    // considered to merge DoorsOpen /DoorsClose into singe DoorsToggle() or sth similar
    void DoorsOpen() {
        m_isDoorOpen = true;
        if (not m_doorOpenChangedCallBack) {
            Error("Doors callback not set! Aborting callback");
        } else {
            m_doorOpenChangedCallBack(true);
        }
    }

    void DoorsClose() {
        m_isDoorOpen = false;
        if (not m_doorOpenChangedCallBack) {
            Error("Doors callback not set! Aborting callback");
        } else {
            m_doorOpenChangedCallBack(false);
        }
    }

    /// <summary>
    /// Turns on the Microwave heater element
    /// </summary>
    void TurnOnHeater() override;
    /// <summary>
    /// Turns off the Microwave heater element
    /// </summary>
    void TurnOffHeater() override;
    /// <summary>
    /// Indicates if the door to the Microwave oven is open or closed
    /// </summary>
    bool IsDoorOpen() const override {
        return m_isDoorOpen;
    }
    /// <summary>
    /// Signal if the Door is opened or closed,
    /// </summary>
    void RegisterDoorOpenChangedCallBack(std::function<void(bool)> callback) override;
    /// <summary>
    /// Signals that the Start button is pressed
    /// </summary>
    void RegisterStartButtonPressedCallBack(std::function<void(void)> callback) override;

    // a getter necessary for diagnosics
    bool IsLampActive() const {
        return m_isLampActive;
    };

    // logging wrappers with intention of simple refactor to other systems
    static void Log(const std::string& msg) {
        ::std::cout << msg << ::std::endl;
    }

    static void Error(const std::string& msg) {
        ::std::cerr << msg << ::std::endl;
    }

    // #ifndef UNITTEST // enabling member access for tests only, sometimes used approach
    // sometimes preferred over declaring test classes as friends
  private:
    // #endif

    std::function<void(bool)> m_doorOpenChangedCallBack{nullptr};
    std::function<void(void)> m_startButtonPressedCallBack{nullptr};
    bool m_isHeatingActive{false};
    bool m_isLampActive{false};
    bool m_isDoorOpen{false};

    // timestapm initiated with value from construction moment will always be the valid past moment
    std::chrono::_V2::steady_clock::time_point m_turnoffTimeout{std::chrono::steady_clock::now()};

    std::mutex m_mutex;  // considerable if that stage required concurrency
};
