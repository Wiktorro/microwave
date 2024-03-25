#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "microwave.hpp"

using namespace testing;

class CallbackMock {
  public:
    MOCK_METHOD1(onDoorChange, void(bool));
    MOCK_METHOD0(onStartButton, void());
};
class MicrowaveTest : public Test {
  public:
    MicrowaveTest() {
        auto callbackDoor = [this](bool val) { m_mock.onDoorChange(val); };
        auto callbackButton = [this]() { m_mock.onStartButton(); };
        m_sut->RegisterDoorOpenChangedCallBack(std::move(callbackDoor));
        m_sut->RegisterStartButtonPressedCallBack(std::move(callbackButton));
    }

  protected:
    std::unique_ptr<MicrowaveImpl> m_sut = std::make_unique<MicrowaveImpl>();
    CallbackMock m_mock;
};

TEST_F(MicrowaveTest, BasicConstruction_ShouldBeInactive) {
    EXPECT_FALSE(m_sut->IsDoorOpen());
    EXPECT_FALSE(m_sut->IsLampActive());
}

TEST_F(MicrowaveTest, DoorsOpenAndClose_ShouldSetLampOffOnOff) {
    EXPECT_FALSE(m_sut->IsDoorOpen());
    EXPECT_FALSE(m_sut->IsLampActive());

    ASSERT_NO_THROW(m_sut->TurnOnHeater());  // additional safety for no exceptions during call

    EXPECT_TRUE(m_sut->IsLampActive());
}

TEST_F(MicrowaveTest, PressButtonOnDoorsClosed_ShouldKeepInactive) {
    EXPECT_FALSE(m_sut->IsDoorOpen());
    m_sut->TurnOnHeater();

    EXPECT_TRUE(m_sut->IsLampActive());
}

TEST_F(MicrowaveTest, DeviceTurnOff_ShouldBeInactive) {
    EXPECT_FALSE(m_sut->IsDoorOpen());

    EXPECT_CALL(m_mock, onStartButton()).Times(1);

    m_sut->TurnOffHeater();
}
