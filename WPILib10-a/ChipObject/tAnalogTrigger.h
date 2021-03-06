// Copyright (c) National Instruments 2008.  All Rights Reserved.
// Do Not Edit... this file is generated!

#ifndef __nAD9A5591CC64E4DF756D77D1B57A549E_AnalogTrigger_h__
#define __nAD9A5591CC64E4DF756D77D1B57A549E_AnalogTrigger_h__

#include "tScopedSystem.h"

namespace nFPGA
{
namespace nAD9A5591CC64E4DF756D77D1B57A549E
{

class tAnalogTrigger : public tScopedSystem
{
public:
   tAnalogTrigger(unsigned char sys_index, tRioStatusCode *status);
   ~tAnalogTrigger();

   inline unsigned char getSystemIndex()
   {
      return _SystemIndex;
   }

   typedef enum
   {
      kNumSystems = 8,
   } tConstants;

   typedef
   union{
      struct{
         unsigned InHysteresis : 1;
         unsigned OverLimit : 1;
         unsigned Rising : 1;
         unsigned Falling : 1;
      };
      struct{
         unsigned value : 4;
      };
   } tOutput;
   typedef
   union{
      struct{
         unsigned Channel : 3;
         unsigned Module : 1;
         unsigned Averaged : 1;
         unsigned Filter : 1;
         unsigned FloatingRollover : 1;
         signed RolloverLimit : 8;
      };
      struct{
         unsigned value : 15;
      };
   } tSourceSelect;


   typedef enum
   {
      kSourceSelect_RolloverLimit_FixedPointIntegerShift = 4,
      kAnalogTrigger0_SourceSelectAddress = 0x83B4,
      kAnalogTrigger1_SourceSelectAddress = 0x83A8,
      kAnalogTrigger2_SourceSelectAddress = 0x839C,
      kAnalogTrigger3_SourceSelectAddress = 0x8390,
      kAnalogTrigger4_SourceSelectAddress = 0x8384,
      kAnalogTrigger5_SourceSelectAddress = 0x8378,
      kAnalogTrigger6_SourceSelectAddress = 0x836C,
      kAnalogTrigger7_SourceSelectAddress = 0x8360,
   } tSourceSelect_Constants;
   static const unsigned int kSourceSelectAddresses [];

   void writeSourceSelect(tSourceSelect value, tRioStatusCode *status);
   void writeSourceSelect_Channel(unsigned char value, tRioStatusCode *status);
   void writeSourceSelect_Module(unsigned char value, tRioStatusCode *status);
   void writeSourceSelect_Averaged(bool value, tRioStatusCode *status);
   void writeSourceSelect_Filter(bool value, tRioStatusCode *status);
   void writeSourceSelect_FloatingRollover(bool value, tRioStatusCode *status);
   void writeSourceSelect_RolloverLimit(signed short value, tRioStatusCode *status);
   tSourceSelect readSourceSelect(tRioStatusCode *status);
   unsigned char readSourceSelect_Channel(tRioStatusCode *status);
   unsigned char readSourceSelect_Module(tRioStatusCode *status);
   bool readSourceSelect_Averaged(tRioStatusCode *status);
   bool readSourceSelect_Filter(tRioStatusCode *status);
   bool readSourceSelect_FloatingRollover(tRioStatusCode *status);
   signed short readSourceSelect_RolloverLimit(tRioStatusCode *status);


   typedef enum
   {
      kAnalogTrigger0_UpperLimitAddress = 0x83B0,
      kAnalogTrigger1_UpperLimitAddress = 0x83A4,
      kAnalogTrigger2_UpperLimitAddress = 0x8398,
      kAnalogTrigger3_UpperLimitAddress = 0x838C,
      kAnalogTrigger4_UpperLimitAddress = 0x8380,
      kAnalogTrigger5_UpperLimitAddress = 0x8368,
      kAnalogTrigger6_UpperLimitAddress = 0x8374,
      kAnalogTrigger7_UpperLimitAddress = 0x835C,
   } tUpperLimit_Constants;
   static const unsigned int kUpperLimitAddresses [];

   void writeUpperLimit(signed int value, tRioStatusCode *status);
   signed int readUpperLimit(tRioStatusCode *status);


   typedef enum
   {
      kAnalogTrigger0_LowerLimitAddress = 0x83AC,
      kAnalogTrigger1_LowerLimitAddress = 0x83A0,
      kAnalogTrigger2_LowerLimitAddress = 0x8394,
      kAnalogTrigger3_LowerLimitAddress = 0x8388,
      kAnalogTrigger4_LowerLimitAddress = 0x837C,
      kAnalogTrigger5_LowerLimitAddress = 0x8364,
      kAnalogTrigger6_LowerLimitAddress = 0x8370,
      kAnalogTrigger7_LowerLimitAddress = 0x8358,
   } tLowerLimit_Constants;
   static const unsigned int kLowerLimitAddresses [];

   void writeLowerLimit(signed int value, tRioStatusCode *status);
   signed int readLowerLimit(tRioStatusCode *status);



   typedef enum
   {
      kNumOutputElements = 8,
      kOutput_ElementSize = 4,
      kOutput_ElementMask = 0xF,
      kAnalogTrigger_OutputAddress = 0x83B8,
   } tOutput_Constants;

   tOutput readOutput(unsigned char bitfield_index, tRioStatusCode *status);
   bool readOutput_InHysteresis(unsigned char bitfield_index, tRioStatusCode *status);
   bool readOutput_OverLimit(unsigned char bitfield_index, tRioStatusCode *status);
   bool readOutput_Rising(unsigned char bitfield_index, tRioStatusCode *status);
   bool readOutput_Falling(unsigned char bitfield_index, tRioStatusCode *status);




private:
   unsigned char _SystemIndex;

};

}
}

#endif // __nAD9A5591CC64E4DF756D77D1B57A549E_AnalogTrigger_h__
