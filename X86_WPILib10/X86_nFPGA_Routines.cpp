/*
 * X86_nFPGA_Routines.cpp
 *
 *  Created on: Feb 9, 2010
 *      Author: chris
 */

#include "ChipObject.h"

//W:/workspace/WPILib10/DigitalInput.cpp:55: undefined reference to `nFPGA::tInterruptManager::~tInterruptManager()'
//W:/workspace/WPILib10/DigitalInput.cpp:56: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tInterrupt::~tInterrupt()'
tInterruptManager::~tInterruptManager() {};

using namespace nAD9A5591CC64E4DF756D77D1B57A549E;
tInterrupt::~tInterrupt(){};

void tInterrupt::writeConfig_WaitForAck(bool, int*) {}
void tInterrupt::writeConfig_Source_AnalogTrigger(bool, int*){}
void tInterrupt::writeConfig_Source_Channel(unsigned char, int*){}
void tInterrupt::writeConfig_Source_Module(unsigned char, int*){}
void tInterrupt::writeConfig_RisingEdge(bool, int*){}
void tInterrupt::writeConfig_FallingEdge(bool, int*){}
//void tGlobal::tGlobal(int*){}
UINT16 tGlobal::readVersion(int*){return 0;}
tGlobal::~tGlobal(){}
//void tGlobal::readLocalTime(int*){}
void tGlobal::writeFPGA_LED(bool, int*){}
//void Global::readFPGA_LED(int*){}
//void tDIO::tDIO(unsigned char, int*){}
//void tDIO::readLoopTiming(int*){}
void tDIO::writePWMConfig_Period(unsigned short, int*){}
void tDIO::writePWMConfig_MinHigh(unsigned short, int*){}
void tDIO::writeSlowValue_RelayFwd(unsigned char, int*){}
void tDIO::writeSlowValue_RelayRev(unsigned char, int*){}
tDIO::~tDIO(){}
void tDIO::writePWMValue(unsigned char, unsigned char, int*){}
/*W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule6GetPWMEj':
W:/workspace/WPILib10/DigitalModule.cpp:110: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readPWMValue(unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule17SetPWMPeriodScaleEjj':
W:/workspace/WPILib10/DigitalModule.cpp:122: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writePWMPeriodScale(unsigned char, unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule15SetRelayForwardEjb':
W:/workspace/WPILib10/DigitalModule.cpp:136: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readSlowValue_RelayFwd(int*)'
W:/workspace/WPILib10/DigitalModule.cpp:141: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeSlowValue_RelayFwd(unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule15SetRelayReverseEjb':
W:/workspace/WPILib10/DigitalModule.cpp:157: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readSlowValue_RelayRev(int*)'
W:/workspace/WPILib10/DigitalModule.cpp:162: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeSlowValue_RelayRev(unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule15GetRelayForwardEj':
W:/workspace/WPILib10/DigitalModule.cpp:173: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readSlowValue_RelayFwd(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule15GetRelayForwardEv':
W:/workspace/WPILib10/DigitalModule.cpp:183: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readSlowValue_RelayFwd(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule15GetRelayReverseEj':
W:/workspace/WPILib10/DigitalModule.cpp:192: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readSlowValue_RelayRev(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule15GetRelayReverseEv':
W:/workspace/WPILib10/DigitalModule.cpp:203: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readSlowValue_RelayRev(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule11AllocateDIOEjb':
W:/workspace/WPILib10/DigitalModule.cpp:216: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readOutputEnable(int*)'
W:/workspace/WPILib10/DigitalModule.cpp:227: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeOutputEnable(unsigned short, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule6SetDIOEjs':
W:/workspace/WPILib10/DigitalModule.cpp:253: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readDO(int*)'
W:/workspace/WPILib10/DigitalModule.cpp:262: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeDO(unsigned short, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule6GetDIOEj':
W:/workspace/WPILib10/DigitalModule.cpp:273: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readDI(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule6GetDIOEv':
W:/workspace/WPILib10/DigitalModule.cpp:290: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readDI(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule15GetDIODirectionEj':
W:/workspace/WPILib10/DigitalModule.cpp:300: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readOutputEnable(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule15GetDIODirectionEv':
W:/workspace/WPILib10/DigitalModule.cpp:318: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readOutputEnable(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule5PulseEjf':
W:/workspace/WPILib10/DigitalModule.cpp:328: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readLoopTiming(int*)'
W:/workspace/WPILib10/DigitalModule.cpp:328: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writePulseLength(unsigned char, int*)'
W:/workspace/WPILib10/DigitalModule.cpp:329: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writePulse(unsigned short, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule9IsPulsingEj':
W:/workspace/WPILib10/DigitalModule.cpp:339: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readPulse(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DigitalModule.o): In function `ZN13DigitalModule9IsPulsingEv':
W:/workspace/WPILib10/DigitalModule.cpp:349: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readPulse(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModuleC2Ej':
W:/workspace/WPILib10/AnalogModule.cpp:65: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::tAI(unsigned char, int*)'
W:/workspace/WPILib10/AnalogModule.cpp:71: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::writeScanList(unsigned char, unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModuleC1Ej':
W:/workspace/WPILib10/AnalogModule.cpp:65: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::tAI(unsigned char, int*)'
W:/workspace/WPILib10/AnalogModule.cpp:71: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::writeScanList(unsigned char, unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModuleD2Ev':
W:/workspace/WPILib10/AnalogModule.cpp:90: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::~tAI()'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModuleD1Ev':
W:/workspace/WPILib10/AnalogModule.cpp:90: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::~tAI()'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModuleD0Ev':
W:/workspace/WPILib10/AnalogModule.cpp:90: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::~tAI()'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule13SetSampleRateEf':
W:/workspace/WPILib10/AnalogModule.cpp:122: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::writeConfig(nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::tConfig, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule13GetSampleRateEv':
W:/workspace/WPILib10/AnalogModule.cpp:140: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::readLoopTiming(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule20GetNumActiveChannelsEv':
W:/workspace/WPILib10/AnalogModule.cpp:154: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::readConfig_ScanSize(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule14SetAverageBitsEjj':
W:/workspace/WPILib10/AnalogModule.cpp:203: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::writeAverageBits(unsigned char, unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule14GetAverageBitsEj':
W:/workspace/WPILib10/AnalogModule.cpp:218: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::readAverageBits(unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule17SetOversampleBitsEjj':
W:/workspace/WPILib10/AnalogModule.cpp:235: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::writeOversampleBits(unsigned char, unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule17GetOversampleBitsEj':
W:/workspace/WPILib10/AnalogModule.cpp:250: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::readOversampleBits(unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule8GetValueEj':
W:/workspace/WPILib10/AnalogModule.cpp:275: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::writeReadSelect(nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::tReadSelect, int*)'
W:/workspace/WPILib10/AnalogModule.cpp:276: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::strobeLatchOutput(int*)'
W:/workspace/WPILib10/AnalogModule.cpp:277: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::readOutput(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule15GetAverageValueEj':
W:/workspace/WPILib10/AnalogModule.cpp:308: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::writeReadSelect(nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::tReadSelect, int*)'
W:/workspace/WPILib10/AnalogModule.cpp:309: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::strobeLatchOutput(int*)'
W:/workspace/WPILib10/AnalogModule.cpp:310: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAI::readOutput(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule12GetLSBWeightEj':
W:/workspace/WPILib10/AnalogModule.cpp:401: undefined reference to `FRC_NetworkCommunication_nAICalibration_getLSBWeight'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogModule.o): In function `ZN12AnalogModule9GetOffsetEj':
W:/workspace/WPILib10/AnalogModule.cpp:420: undefined reference to `FRC_NetworkCommunication_nAICalibration_getOffset'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DriverStation.o): In function `ZN9Dashboard15GetUpdateNumberEv':
W:/workspace/WPILib10/DriverStation.cpp:(.text+0x160): undefined reference to `setNewDataSem'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DriverStation.o): In function `ZN13DriverStationC1Ev':
W:/workspace/WPILib10/DriverStation.cpp:40: undefined reference to `setNewDataSem'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DriverStation.o): In function `ZN13DriverStationD2Ev':
W:/workspace/WPILib10/DriverStation.cpp:87: undefined reference to `setNewDataSem'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DriverStation.o): In function `ZN13DriverStationD1Ev':
W:/workspace/WPILib10/DriverStation.cpp:87: undefined reference to `setNewDataSem'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DriverStation.o): In function `ZN13DriverStationD0Ev':
W:/workspace/WPILib10/DriverStation.cpp:87: undefined reference to `setNewDataSem'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DriverStation.o): In function `ZN13DriverStation7GetDataEv':
W:/workspace/WPILib10/DriverStation.cpp:126: undefined reference to `getCommonControlData'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DriverStation.o): In function `ZN13DriverStation7SetDataEv':
W:/workspace/WPILib10/DriverStation.cpp:147: undefined reference to `setStatusData'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ImageBase.o): In function `ZN9ImageBaseC2E14ImageType_enum':
W:/workspace/WPILib10/Vision/ImageBase.cpp:18: undefined reference to `imaqCreateImage'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ImageBase.o): In function `ZN9ImageBaseC1E14ImageType_enum':
W:/workspace/WPILib10/Vision/ImageBase.cpp:18: undefined reference to `imaqCreateImage'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ImageBase.o): In function `ZN9ImageBaseD2Ev':
W:/workspace/WPILib10/Vision/ImageBase.cpp:28: undefined reference to `imaqDispose'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ImageBase.o): In function `ZN9ImageBaseD1Ev':
W:/workspace/WPILib10/Vision/ImageBase.cpp:28: undefined reference to `imaqDispose'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ImageBase.o): In function `ZN9ImageBase5writeEPKc':
W:/workspace/WPILib10/Vision/ImageBase.cpp:38: undefined reference to `Priv_SetWriteFileAllowed'
W:/workspace/WPILib10/Vision/ImageBase.cpp:39: undefined reference to `imaqWriteFile'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ImageBase.o): In function `ZN9ImageBase9getHeightEv':
W:/workspace/WPILib10/Vision/ImageBase.cpp:50: undefined reference to `imaqGetImageSize'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ImageBase.o): In function `ZN9ImageBase8getWidthEv':
W:/workspace/WPILib10/Vision/ImageBase.cpp:61: undefined reference to `imaqGetImageSize'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8WatchdogC2Ev':
W:/workspace/WPILib10/Watchdog.cpp:17: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::tWatchdog(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8WatchdogC1Ev':
W:/workspace/WPILib10/Watchdog.cpp:17: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::tWatchdog(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8WatchdogD2Ev':
W:/workspace/WPILib10/Watchdog.cpp:29: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::~tWatchdog()'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8WatchdogD1Ev':
W:/workspace/WPILib10/Watchdog.cpp:29: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::~tWatchdog()'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8WatchdogD0Ev':
W:/workspace/WPILib10/Watchdog.cpp:29: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::~tWatchdog()'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8Watchdog4FeedEv':
W:/workspace/WPILib10/Watchdog.cpp:48: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::strobeFeed(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8Watchdog4KillEv':
W:/workspace/WPILib10/Watchdog.cpp:61: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::strobeKill(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8Watchdog8GetTimerEv':
W:/workspace/WPILib10/Watchdog.cpp:72: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::readTimer(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8Watchdog13GetExpirationEv':
W:/workspace/WPILib10/Watchdog.cpp:84: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::readExpiration(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8Watchdog13SetExpirationEd':
W:/workspace/WPILib10/Watchdog.cpp:96: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::writeExpiration(unsigned int, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8Watchdog10GetEnabledEv':
W:/workspace/WPILib10/Watchdog.cpp:107: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::readImmortal(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8Watchdog10SetEnabledEb':
W:/workspace/WPILib10/Watchdog.cpp:126: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::writeImmortal(bool, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8Watchdog7IsAliveEv':
W:/workspace/WPILib10/Watchdog.cpp:144: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::readStatus_Alive(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(Watchdog.o): In function `ZN8Watchdog14IsSystemActiveEv':
W:/workspace/WPILib10/Watchdog.cpp:156: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tWatchdog::readStatus_SystemActive(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera2010.o): In function `ZN10AxisCamera8GetImageEP12Image_struct':
W:/workspace/WPILib10/Vision/AxisCamera2010.cpp:31: undefined reference to `Priv_ReadJPEGString_C'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera2010.o): In function `ZN10AxisCamera8GetImageEv':
W:/workspace/WPILib10/Vision/AxisCamera2010.cpp:48: undefined reference to `Priv_ReadJPEGString_C'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera2010.o): In function `ZN10AxisCamera11mjpegStreamEPc':
W:/workspace/WPILib10/Vision/AxisCamera2010.cpp:113: undefined reference to `socket(int, int, int)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera2010.o): In function `ZN10AxisCamera14updateCamParamEPKc':
W:/workspace/WPILib10/Vision/AxisCamera2010.cpp:399: undefined reference to `socket(int, int, int)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera2010.o): In function `ZN10AxisCamera13readCamParamsEv':
W:/workspace/WPILib10/Vision/AxisCamera2010.cpp:448: undefined reference to `socket(int, int, int)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera2010.o): In function `ZN10AxisCamera14searchForParamEPcPKciS0_':
W:/workspace/WPILib10/Vision/AxisCamera2010.cpp:573: undefined reference to `pcre_compile'
W:/workspace/WPILib10/Vision/AxisCamera2010.cpp:575: undefined reference to `pcre_exec'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z14frcCreateImage14ImageType_enum':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:40: undefined reference to `imaqCreateImage'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z10frcDisposePv':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:48: undefined reference to `imaqDispose'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z10frcDisposePKcz':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:67: undefined reference to `imaqDispose'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z12frcCopyImageP12Image_structPKS_':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:84: undefined reference to `imaqDuplicate'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z7frcCropP12Image_structPKS_11Rect_struct':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:98: undefined reference to `imaqScale'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z8frcScaleP12Image_structPKS_ii16ScalingMode_enum':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:116: undefined reference to `imaqMakeRect'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:117: undefined reference to `imaqScale'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z12frcReadImageP12Image_structPKc':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:132: undefined reference to `imaqReadFile'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z13frcWriteImagePK12Image_structPKc':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:166: undefined reference to `imaqWriteFile'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z12frcHistogramPK12Image_structiff':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:202: undefined reference to `imaqMakeRect'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z12frcHistogramPK12Image_structiff11Rect_struct':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:211: undefined reference to `imaqCreateROI'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:212: undefined reference to `imaqAddRectContour'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:217: undefined reference to `imaqROIToMask'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:226: undefined reference to `imaqHistogram'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z17frcColorHistogramPK12Image_structi14ColorMode_enumPS_':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:260: undefined reference to `imaqColorHistogram2'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z16frcGetPixelValuePK12Image_struct12Point_structP16PixelValue_union':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:277: undefined reference to `imaqGetPixel'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z17frcParticleFilterP12Image_structS0_PK30ParticleFilterCriteria2_structiPK28ParticleFilterOptions_structPi':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:300: undefined reference to `imaqMakeRect'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z17frcParticleFilterP12Image_structS0_PK30ParticleFilterCriteria2_structiPK28ParticleFilterOptions_struct11Rect_structPi':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:307: undefined reference to `imaqCreateROI'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:308: undefined reference to `imaqAddRectContour'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:309: undefined reference to `imaqParticleFilter3'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z13frcMorphologyP12Image_structS0_21MorphologyMethod_enum':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:329: undefined reference to `imaqMorphology'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z13frcMorphologyP12Image_structS0_21MorphologyMethod_enumPK25StructuringElement_struct':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:334: undefined reference to `imaqMorphology'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z15frcRejectBorderP12Image_structS0_':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:351: undefined reference to `imaqRejectBorder'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z15frcRejectBorderP12Image_structS0_i':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:355: undefined reference to `imaqRejectBorder'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z17frcCountParticlesP12Image_structPi':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:368: undefined reference to `imaqCountParticles'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z19frcParticleAnalysisP12Image_structiP29ParticleAnalysisReport_struct':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:388: undefined reference to `imaqGetImageSize'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:395: undefined reference to `imaqMeasureParticle'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:399: undefined reference to `imaqMeasureParticle'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:404: undefined reference to `imaqMeasureParticle'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:408: undefined reference to `imaqMeasureParticle'
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:412: undefined reference to `imaqMeasureParticle'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o):W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:416: more undefined references to `imaqMeasureParticle' follow
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z11frcEqualizeP12Image_structPKS_ffS2_':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:462: undefined reference to `imaqEqualize'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z16frcColorEqualizeP12Image_structPKS_':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:477: undefined reference to `imaqColorEqualize'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z16frcColorEqualizeP12Image_structPKS_i':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:482: undefined reference to `imaqColorEqualize'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z17frcSmartThresholdP12Image_structPKS_jj25LocalThresholdMethod_enumd15ObjectType_enum':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:515: undefined reference to `imaqLocalThreshold'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z17frcSmartThresholdP12Image_structPKS_jj25LocalThresholdMethod_enumd15ObjectType_enumf':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:523: undefined reference to `imaqLocalThreshold'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z18frcSimpleThresholdP12Image_structPKS_fff':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:564: undefined reference to `imaqThreshold'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z17frcColorThresholdP12Image_structPKS_14ColorMode_enumPK12Range_structS6_S6_':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:586: undefined reference to `imaqColorThreshold'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z17frcColorThresholdP12Image_structPKS_i14ColorMode_enumPK12Range_structS6_S6_':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:607: undefined reference to `imaqColorThreshold'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z15frcHueThresholdP12Image_structPKS_PK12Range_structi':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:632: undefined reference to `imaqColorThreshold'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(VisionAPI.o): In function `Z21frcExtractColorPlanesPK12Image_struct14ColorMode_enumPS_S3_S3_':
W:/workspace/WPILib10/Vision2009/VisionAPI.cpp:649: undefined reference to `imaqExtractColorPlanes'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(FrcError.o): In function `Z18GetLastVisionErrorv':
W:/workspace/WPILib10/Vision2009/FrcError.cpp:27: undefined reference to `imaqGetLastError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogChannel.o): In function `ZN10SensorBase22GetDefaultAnalogModuleEv':
W:/workspace/WPILib10/AnalogChannel.cpp:(.text+0xf4): undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAccumulator::tAccumulator(unsigned char, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogChannel.o): In function `ZN13AnalogChannel16ResetAccumulatorEv':
W:/workspace/WPILib10/AnalogChannel.cpp:267: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAccumulator::strobeReset(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogChannel.o): In function `ZN13AnalogChannel20SetAccumulatorCenterEi':
W:/workspace/WPILib10/AnalogChannel.cpp:288: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAccumulator::writeCenter(int, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogChannel.o): In function `ZN13AnalogChannel22SetAccumulatorDeadbandEi':
W:/workspace/WPILib10/AnalogChannel.cpp:302: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAccumulator::writeDeadband(int, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogChannel.o): In function `ZN13AnalogChannel19GetAccumulatorValueEv':
W:/workspace/WPILib10/AnalogChannel.cpp:321: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAccumulator::readOutput_Value(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogChannel.o): In function `ZN13AnalogChannel19GetAccumulatorCountEv':
W:/workspace/WPILib10/AnalogChannel.cpp:341: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAccumulator::readOutput_Count(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AnalogChannel.o): In function `ZN13AnalogChannel20GetAccumulatorOutputEPxPj':
W:/workspace/WPILib10/AnalogChannel.cpp:370: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tAccumulator::readOutput(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(MonoImage.o): In function `ZN9MonoImage14DetectEllipsesEP24EllipseDescriptor_structP19CurveOptions_structP28ShapeDetectionOptions_structP10ROI_struct':
W:/workspace/WPILib10/Vision/MonoImage.cpp:23: undefined reference to `imaqDetectEllipses'
W:/workspace/WPILib10/Vision/MonoImage.cpp:33: undefined reference to `imaqDispose'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ColorImage.o): In function `ZN10ColorImage9thresholdE14ColorMode_enumiiiiii':
W:/workspace/WPILib10/Vision/ColorImage.cpp:24: undefined reference to `imaqColorThreshold'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ColorImage.o): In function `ZN10ColorImage17extractColorPlaneE14ColorMode_enumi':
W:/workspace/WPILib10/Vision/ColorImage.cpp:150: undefined reference to `imaqExtractColorPlanes'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ColorImage.o): In function `ZN10ColorImage12replacePlaneE14ColorMode_enumP9MonoImagei':
W:/workspace/WPILib10/Vision/ColorImage.cpp:279: undefined reference to `imaqReplaceColorPlanes'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(ColorImage.o): In function `ZN10ColorImage8equalizeEb':
W:/workspace/WPILib10/Vision/ColorImage.cpp:438: undefined reference to `imaqColorEqualize'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `GetImageBlocking':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:93: undefined reference to `imaqSetError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `Z17CameraInitializedv':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:112: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:120: undefined reference to `imaqSetError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `GetImage':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:153: undefined reference to `imaqDuplicate'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:177: undefined reference to `imaqSetError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `GetImageDataBlocking':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:262: undefined reference to `imaqSetError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `Z14CameraReadLineiPcib':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:306: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:314: undefined reference to `read(int, char*, unsigned int)'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:315: undefined reference to `imaqSetError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `Z41CameraOpenSocketAndIssueAuthorizedRequestPKcS0_':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:420: undefined reference to `socket(int, int, int)'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:421: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:432: undefined reference to `hostGetByName(char*)'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:435: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:441: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:447: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:468: undefined reference to `imaqSetError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `ConfigureCamera':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:505: undefined reference to `imaqSetError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o):W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:654: more undefined references to `imaqSetError' follow
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `Z16cameraJPEGServerii9ImageSize13ImageRotation':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:666: undefined reference to `socket(int, int, int)'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:667: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:680: undefined reference to `hostGetByName(char*)'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:689: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:754: undefined reference to `read(int, char*, unsigned int)'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:811: undefined reference to `fioRead(int, char*, int)'
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:830: undefined reference to `Priv_ReadJPEGString_C'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `Z10initCameraii9ImageSize13ImageRotation':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:928: undefined reference to `Priv_SetWriteFileAllowed'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(AxisCamera.o): In function `StartCameraTask':
W:/workspace/WPILib10/Vision2009/AxisCamera.cpp:977: undefined reference to `imaqSetError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(TrackAPI.o): In function `Z6InAreaP12Image_structi11Rect_struct':
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:37: undefined reference to `imaqMeasureParticle'
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:41: undefined reference to `imaqMeasureParticle'
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:45: undefined reference to `imaqMeasureParticle'
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:49: undefined reference to `imaqMeasureParticle'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(TrackAPI.o): In function `Z18GetLargestParticleP12Image_structPi':
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:66: undefined reference to `imaqMakeRect'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(TrackAPI.o): In function `Z18GetLargestParticleP12Image_structPi11Rect_struct':
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:84: undefined reference to `imaqMeasureParticle'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(TrackAPI.o): In function `Z9FindColor11FrcHue_enumP29ParticleAnalysisReport_struct':
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:122: undefined reference to `imaqSetError'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(TrackAPI.o): In function `Z9FindColor14ColorMode_enumPK12Range_structS2_S2_P29ParticleAnalysisReport_structP18ColorReport_struct':
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:185: undefined reference to `imaqMakeRect'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(TrackAPI.o): In function `Z9FindColor14ColorMode_enumPK12Range_structS2_S2_P29ParticleAnalysisReport_structP18ColorReport_struct11Rect_struct':
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:220: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:249: undefined reference to `imaqSetError'
W:/workspace/WPILib10/Vision2009/TrackAPI.cpp:282: undefined reference to `imaqColorHistogram2'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(InterruptableSensorBase.o): In function `ZN23InterruptableSensorBase18AllocateInterruptsEb':
W:/workspace/WPILib10/InterruptableSensorBase.cpp:26: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tInterrupt::tInterrupt(unsigned char, int*)'
W:/workspace/WPILib10/InterruptableSensorBase.cpp:27: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tInterrupt::writeConfig_WaitForAck(bool, int*)'
W:/workspace/WPILib10/InterruptableSensorBase.cpp:28: undefined reference to `nFPGA::tInterruptManager::tInterruptManager(unsigned int, bool, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(InterruptableSensorBase.o): In function `ZN23InterruptableSensorBase16CancelInterruptsEv':
W:/workspace/WPILib10/InterruptableSensorBase.cpp:39: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tInterrupt::~tInterrupt()'
W:/workspace/WPILib10/InterruptableSensorBase.cpp:40: undefined reference to `nFPGA::tInterruptManager::~tInterruptManager()'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(InterruptableSensorBase.o): In function `ZN23InterruptableSensorBase16WaitForInterruptEf':
W:/workspace/WPILib10/InterruptableSensorBase.cpp:53: undefined reference to `nFPGA::tInterruptManager::watch(int, int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(InterruptableSensorBase.o): In function `ZN23InterruptableSensorBase16EnableInterruptsEv':
W:/workspace/WPILib10/InterruptableSensorBase.cpp:66: undefined reference to `nFPGA::tInterruptManager::enable(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(InterruptableSensorBase.o): In function `ZN23InterruptableSensorBase17DisableInterruptsEv':
W:/workspace/WPILib10/InterruptableSensorBase.cpp:77: undefined reference to `nFPGA::tInterruptManager::disable(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(InterruptableSensorBase.o): In function `ZN23InterruptableSensorBase22ReadInterruptTimestampEv':
W:/workspace/WPILib10/InterruptableSensorBase.cpp:89: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tInterrupt::readTimeStamp(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(I2C.o): In function `ZN3I2C5WriteEhh':
W:/workspace/WPILib10/I2C.cpp:51: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeI2CConfig_Address(unsigned char, int*)'
W:/workspace/WPILib10/I2C.cpp:52: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeI2CConfig_BytesToWrite(unsigned char, int*)'
W:/workspace/WPILib10/I2C.cpp:53: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeI2CConfig_BytesToRead(unsigned char, int*)'
W:/workspace/WPILib10/I2C.cpp:54: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeI2CDataToSend(unsigned int, int*)'
W:/workspace/WPILib10/I2C.cpp:55: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readI2CStatus_Transaction(int*)'
W:/workspace/WPILib10/I2C.cpp:56: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::strobeI2CStart(int*)'
W:/workspace/WPILib10/I2C.cpp:57: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readI2CStatus_Transaction(int*)'
W:/workspace/WPILib10/I2C.cpp:58: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readI2CStatus_Done(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(I2C.o): In function `ZN3I2C4ReadEhhPh':
W:/workspace/WPILib10/I2C.cpp:89: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeI2CConfig_Address(unsigned char, int*)'
W:/workspace/WPILib10/I2C.cpp:90: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeI2CConfig_BytesToWrite(unsigned char, int*)'
W:/workspace/WPILib10/I2C.cpp:91: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeI2CConfig_BytesToRead(unsigned char, int*)'
W:/workspace/WPILib10/I2C.cpp:92: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::writeI2CDataToSend(unsigned int, int*)'
W:/workspace/WPILib10/I2C.cpp:93: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readI2CStatus_Transaction(int*)'
W:/workspace/WPILib10/I2C.cpp:94: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::strobeI2CStart(int*)'
W:/workspace/WPILib10/I2C.cpp:95: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readI2CStatus_Transaction(int*)'
W:/workspace/WPILib10/I2C.cpp:96: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readI2CStatus_Done(int*)'
W:/workspace/WPILib10/I2C.cpp:97: undefined reference to `nFPGA::nAD9A5591CC64E4DF756D77D1B57A549E::tDIO::readI2CDataReceived(int*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(DriverStationEnhancedIO.o): In function `ZN23DriverStationEnhancedIO10UpdateDataEv':
W:/workspace/WPILib10/DriverStationEnhancedIO.cpp:75: undefined reference to `overrideIOConfig'
W:/workspace/WPILib10/DriverStationEnhancedIO.cpp:77: undefined reference to `getDynamicControlData'
W:/workspace/WPILib10/DriverStationEnhancedIO.cpp:117: undefined reference to `getDynamicControlData'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(PCVideoServer.o): In function `ZN13PCVideoServerD2Ev':
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:102: undefined reference to `socket(int, int, int)'
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:113: undefined reference to `hostGetByName(char*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(PCVideoServer.o): In function `ZN13PCVideoServerD1Ev':
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:102: undefined reference to `socket(int, int, int)'
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:113: undefined reference to `hostGetByName(char*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(PCVideoServer.o): In function `ZN13PCVideoServerD0Ev':
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:102: undefined reference to `socket(int, int, int)'
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:113: undefined reference to `hostGetByName(char*)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(PCVideoServer.o): In function `Z15ImageToPCServerv':
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:204: undefined reference to `taskSafe()'
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:206: undefined reference to `socket(int, int, int)'
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:212: undefined reference to `setsockopt(int, int, int, char*, int)'
W:/workspace/WPILib10/Vision/PCVideoServer.cpp:215: undefined reference to `bind(int, sockaddr*, int)'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(BinaryImage.o): In function `ZN11BinaryImage18GetNumberParticlesEv':
W:/workspace/WPILib10/Vision/BinaryImage.cpp:21: undefined reference to `imaqCountParticles'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(BinaryImage.o): In function `ZN11BinaryImage5writeEPKc':
W:/workspace/WPILib10/Vision/BinaryImage.cpp:79: undefined reference to `Priv_SetWriteFileAllowed'
W:/workspace/WPILib10/Vision/BinaryImage.cpp:86: undefined reference to `imaqWriteFile'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(BinaryImage.o): In function `Z19particleMeasurementP12Image_structi20MeasurementType_enum':
W:/workspace/WPILib10/Vision/BinaryImage.cpp:103: undefined reference to `imaqMeasureParticle'
W:/workspace/X86_WPILib10/Windows-gnu-native-3.x-4.x/X86_WPILib10/Debug/X86_WPILib10.a(BinaryImage.o): In function `ZN11BinaryImage16ParticleAnalysisEP12Image_structiP29ParticleAnalysisReport_struct':
W:/workspace/WPILib10/Vision/BinaryImage.cpp:122: undefined reference to `imaqGetImageSize'
W:/workspace/WPILib10/Vision/BinaryImage.cpp:127: undefined reference to `imaqCountParticles'
C:/MinGW/bin/../lib/gcc/mingw32/3.4.5/../../../libmingw32.a(main.o):main.c:(.text+0xd2): undefined reference to `WinMain@16'
collect2: ld returned 1 exit status
C:\windriver\workbench-3.0\x86-win32\bin\make.exe: *** [X86_chopshop10/Debug/X86_chopshop10.exe] Error 1
*/


