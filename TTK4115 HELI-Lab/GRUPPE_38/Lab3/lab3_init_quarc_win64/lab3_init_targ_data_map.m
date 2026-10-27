  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (lab3_init_P)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% lab3_init_P.A_est
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_P.B_est
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 25;
	
	  ;% lab3_init_P.C_est
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 35;
	
	  ;% lab3_init_P.ELEV_OFFSET
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 60;
	
	  ;% lab3_init_P.F
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 61;
	
	  ;% lab3_init_P.Joystick_gain_x
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 65;
	
	  ;% lab3_init_P.Joystick_gain_y
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 66;
	
	  ;% lab3_init_P.K
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 67;
	
	  ;% lab3_init_P.L_est
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 77;
	
	  ;% lab3_init_P.V_s_0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 102;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_P.HILWriteAnalog_channels
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 51;
      section.data(51)  = dumData; %prealloc
      
	  ;% lab3_init_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab3_init_P.HILInitialize_OOStart
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab3_init_P.HILInitialize_OOEnter
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab3_init_P.HILInitialize_AOFinal
	  section.data(5).logicalSrcIdx = 15;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab3_init_P.HILInitialize_POFinal
	  section.data(6).logicalSrcIdx = 16;
	  section.data(6).dtTransOffset = 5;
	
	  ;% lab3_init_P.HILInitialize_AIHigh
	  section.data(7).logicalSrcIdx = 17;
	  section.data(7).dtTransOffset = 6;
	
	  ;% lab3_init_P.HILInitialize_AILow
	  section.data(8).logicalSrcIdx = 18;
	  section.data(8).dtTransOffset = 7;
	
	  ;% lab3_init_P.HILInitialize_AOHigh
	  section.data(9).logicalSrcIdx = 19;
	  section.data(9).dtTransOffset = 8;
	
	  ;% lab3_init_P.HILInitialize_AOLow
	  section.data(10).logicalSrcIdx = 20;
	  section.data(10).dtTransOffset = 9;
	
	  ;% lab3_init_P.HILInitialize_AOInitial
	  section.data(11).logicalSrcIdx = 21;
	  section.data(11).dtTransOffset = 10;
	
	  ;% lab3_init_P.HILInitialize_AOWatchdog
	  section.data(12).logicalSrcIdx = 22;
	  section.data(12).dtTransOffset = 11;
	
	  ;% lab3_init_P.HILInitialize_POFrequency
	  section.data(13).logicalSrcIdx = 23;
	  section.data(13).dtTransOffset = 12;
	
	  ;% lab3_init_P.HILInitialize_POLeading
	  section.data(14).logicalSrcIdx = 24;
	  section.data(14).dtTransOffset = 13;
	
	  ;% lab3_init_P.HILInitialize_POTrailing
	  section.data(15).logicalSrcIdx = 25;
	  section.data(15).dtTransOffset = 14;
	
	  ;% lab3_init_P.HILInitialize_POInitial
	  section.data(16).logicalSrcIdx = 26;
	  section.data(16).dtTransOffset = 15;
	
	  ;% lab3_init_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 27;
	  section.data(17).dtTransOffset = 16;
	
	  ;% lab3_init_P.Constant4_Value
	  section.data(18).logicalSrcIdx = 28;
	  section.data(18).dtTransOffset = 17;
	
	  ;% lab3_init_P.Gain1_Gain
	  section.data(19).logicalSrcIdx = 29;
	  section.data(19).dtTransOffset = 18;
	
	  ;% lab3_init_P.Gain2_Gain
	  section.data(20).logicalSrcIdx = 30;
	  section.data(20).dtTransOffset = 27;
	
	  ;% lab3_init_P.PitchCounttorad_Gain
	  section.data(21).logicalSrcIdx = 31;
	  section.data(21).dtTransOffset = 36;
	
	  ;% lab3_init_P.Integrator_IC
	  section.data(22).logicalSrcIdx = 32;
	  section.data(22).dtTransOffset = 37;
	
	  ;% lab3_init_P.PitchTransferFcn_A
	  section.data(23).logicalSrcIdx = 33;
	  section.data(23).dtTransOffset = 38;
	
	  ;% lab3_init_P.PitchTransferFcn_C
	  section.data(24).logicalSrcIdx = 34;
	  section.data(24).dtTransOffset = 39;
	
	  ;% lab3_init_P.PitchTransferFcn_D
	  section.data(25).logicalSrcIdx = 35;
	  section.data(25).dtTransOffset = 40;
	
	  ;% lab3_init_P.ElevationCounttorad_Gain
	  section.data(26).logicalSrcIdx = 36;
	  section.data(26).dtTransOffset = 41;
	
	  ;% lab3_init_P.ElevationTransferFcn_A
	  section.data(27).logicalSrcIdx = 37;
	  section.data(27).dtTransOffset = 42;
	
	  ;% lab3_init_P.ElevationTransferFcn_C
	  section.data(28).logicalSrcIdx = 38;
	  section.data(28).dtTransOffset = 43;
	
	  ;% lab3_init_P.ElevationTransferFcn_D
	  section.data(29).logicalSrcIdx = 39;
	  section.data(29).dtTransOffset = 44;
	
	  ;% lab3_init_P.Gain2_Gain_d
	  section.data(30).logicalSrcIdx = 40;
	  section.data(30).dtTransOffset = 45;
	
	  ;% lab3_init_P.TravelCounttorad_Gain
	  section.data(31).logicalSrcIdx = 41;
	  section.data(31).dtTransOffset = 46;
	
	  ;% lab3_init_P.TravelTransferFcn_A
	  section.data(32).logicalSrcIdx = 42;
	  section.data(32).dtTransOffset = 47;
	
	  ;% lab3_init_P.TravelTransferFcn_C
	  section.data(33).logicalSrcIdx = 43;
	  section.data(33).dtTransOffset = 48;
	
	  ;% lab3_init_P.TravelTransferFcn_D
	  section.data(34).logicalSrcIdx = 44;
	  section.data(34).dtTransOffset = 49;
	
	  ;% lab3_init_P.Constant2_Value
	  section.data(35).logicalSrcIdx = 45;
	  section.data(35).dtTransOffset = 50;
	
	  ;% lab3_init_P.RateTransitionx_InitialConditio
	  section.data(36).logicalSrcIdx = 46;
	  section.data(36).dtTransOffset = 51;
	
	  ;% lab3_init_P.DeadZonex_Start
	  section.data(37).logicalSrcIdx = 47;
	  section.data(37).dtTransOffset = 52;
	
	  ;% lab3_init_P.DeadZonex_End
	  section.data(38).logicalSrcIdx = 48;
	  section.data(38).dtTransOffset = 53;
	
	  ;% lab3_init_P.Gainx_Gain
	  section.data(39).logicalSrcIdx = 49;
	  section.data(39).dtTransOffset = 54;
	
	  ;% lab3_init_P.RateTransitiony_InitialConditio
	  section.data(40).logicalSrcIdx = 50;
	  section.data(40).dtTransOffset = 55;
	
	  ;% lab3_init_P.DeadZoney_Start
	  section.data(41).logicalSrcIdx = 51;
	  section.data(41).dtTransOffset = 56;
	
	  ;% lab3_init_P.DeadZoney_End
	  section.data(42).logicalSrcIdx = 52;
	  section.data(42).dtTransOffset = 57;
	
	  ;% lab3_init_P.Gainy_Gain
	  section.data(43).logicalSrcIdx = 53;
	  section.data(43).dtTransOffset = 58;
	
	  ;% lab3_init_P.Integrator_IC_a
	  section.data(44).logicalSrcIdx = 54;
	  section.data(44).dtTransOffset = 59;
	
	  ;% lab3_init_P.Integrator1_IC
	  section.data(45).logicalSrcIdx = 55;
	  section.data(45).dtTransOffset = 60;
	
	  ;% lab3_init_P.Backgain_Gain
	  section.data(46).logicalSrcIdx = 56;
	  section.data(46).dtTransOffset = 61;
	
	  ;% lab3_init_P.Frontgain_Gain
	  section.data(47).logicalSrcIdx = 57;
	  section.data(47).dtTransOffset = 62;
	
	  ;% lab3_init_P.FrontmotorSaturation_UpperSat
	  section.data(48).logicalSrcIdx = 58;
	  section.data(48).dtTransOffset = 63;
	
	  ;% lab3_init_P.FrontmotorSaturation_LowerSat
	  section.data(49).logicalSrcIdx = 59;
	  section.data(49).dtTransOffset = 64;
	
	  ;% lab3_init_P.BackmotorSaturation_UpperSat
	  section.data(50).logicalSrcIdx = 60;
	  section.data(50).dtTransOffset = 65;
	
	  ;% lab3_init_P.BackmotorSaturation_LowerSat
	  section.data(51).logicalSrcIdx = 61;
	  section.data(51).dtTransOffset = 66;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% lab3_init_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 63;
	  section.data(2).dtTransOffset = 3;
	
	  ;% lab3_init_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 64;
	  section.data(3).dtTransOffset = 4;
	
	  ;% lab3_init_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 65;
	  section.data(4).dtTransOffset = 5;
	
	  ;% lab3_init_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 66;
	  section.data(5).dtTransOffset = 6;
	
	  ;% lab3_init_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 67;
	  section.data(6).dtTransOffset = 7;
	
	  ;% lab3_init_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 68;
	  section.data(7).dtTransOffset = 8;
	
	  ;% lab3_init_P.HILReadEncoderTimebase_Clock
	  section.data(8).logicalSrcIdx = 69;
	  section.data(8).dtTransOffset = 9;
	
	  ;% lab3_init_P.StreamCall2_SendBufferSize
	  section.data(9).logicalSrcIdx = 70;
	  section.data(9).dtTransOffset = 10;
	
	  ;% lab3_init_P.StreamCall2_ReceiveBufferSize
	  section.data(10).logicalSrcIdx = 71;
	  section.data(10).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% lab3_init_P.UnitDelay_InitialCondition
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_P.UnitDelay_InitialCondition_l
	  section.data(2).logicalSrcIdx = 73;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab3_init_P.UnitDelay_InitialCondition_j
	  section.data(3).logicalSrcIdx = 74;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab3_init_P.UnitDelay_InitialCondition_m
	  section.data(4).logicalSrcIdx = 75;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab3_init_P.UnitDelay_InitialCondition_l1
	  section.data(5).logicalSrcIdx = 76;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab3_init_P.UnitDelay_InitialCondition_i
	  section.data(6).logicalSrcIdx = 77;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% lab3_init_P.StreamFormattedRead_MaxUnits
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_P.HILInitialize_AIChannels
	  section.data(2).logicalSrcIdx = 79;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab3_init_P.HILInitialize_AOChannels
	  section.data(3).logicalSrcIdx = 80;
	  section.data(3).dtTransOffset = 9;
	
	  ;% lab3_init_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 81;
	  section.data(4).dtTransOffset = 17;
	
	  ;% lab3_init_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 82;
	  section.data(5).dtTransOffset = 25;
	
	  ;% lab3_init_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 83;
	  section.data(6).dtTransOffset = 26;
	
	  ;% lab3_init_P.HILReadEncoderTimebase_Channels
	  section.data(7).logicalSrcIdx = 84;
	  section.data(7).dtTransOffset = 34;
	
	  ;% lab3_init_P.HILReadEncoderTimebase_SamplesI
	  section.data(8).logicalSrcIdx = 85;
	  section.data(8).dtTransOffset = 37;
	
	  ;% lab3_init_P.StreamFormattedRead1_MaxUnits
	  section.data(9).logicalSrcIdx = 86;
	  section.data(9).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 87;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% lab3_init_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 88;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 89;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab3_init_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 90;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab3_init_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 91;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab3_init_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 92;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab3_init_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 93;
	  section.data(6).dtTransOffset = 5;
	
	  ;% lab3_init_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 94;
	  section.data(7).dtTransOffset = 6;
	
	  ;% lab3_init_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 95;
	  section.data(8).dtTransOffset = 7;
	
	  ;% lab3_init_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 96;
	  section.data(9).dtTransOffset = 8;
	
	  ;% lab3_init_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 97;
	  section.data(10).dtTransOffset = 9;
	
	  ;% lab3_init_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 98;
	  section.data(11).dtTransOffset = 10;
	
	  ;% lab3_init_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 99;
	  section.data(12).dtTransOffset = 11;
	
	  ;% lab3_init_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 100;
	  section.data(13).dtTransOffset = 12;
	
	  ;% lab3_init_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 101;
	  section.data(14).dtTransOffset = 13;
	
	  ;% lab3_init_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 102;
	  section.data(15).dtTransOffset = 14;
	
	  ;% lab3_init_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 103;
	  section.data(16).dtTransOffset = 15;
	
	  ;% lab3_init_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 104;
	  section.data(17).dtTransOffset = 16;
	
	  ;% lab3_init_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 105;
	  section.data(18).dtTransOffset = 17;
	
	  ;% lab3_init_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 106;
	  section.data(19).dtTransOffset = 18;
	
	  ;% lab3_init_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 107;
	  section.data(20).dtTransOffset = 19;
	
	  ;% lab3_init_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 108;
	  section.data(21).dtTransOffset = 20;
	
	  ;% lab3_init_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 109;
	  section.data(22).dtTransOffset = 21;
	
	  ;% lab3_init_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 110;
	  section.data(23).dtTransOffset = 22;
	
	  ;% lab3_init_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 111;
	  section.data(24).dtTransOffset = 23;
	
	  ;% lab3_init_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 112;
	  section.data(25).dtTransOffset = 24;
	
	  ;% lab3_init_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 113;
	  section.data(26).dtTransOffset = 25;
	
	  ;% lab3_init_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 114;
	  section.data(27).dtTransOffset = 26;
	
	  ;% lab3_init_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 115;
	  section.data(28).dtTransOffset = 27;
	
	  ;% lab3_init_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 116;
	  section.data(29).dtTransOffset = 28;
	
	  ;% lab3_init_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 117;
	  section.data(30).dtTransOffset = 29;
	
	  ;% lab3_init_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 118;
	  section.data(31).dtTransOffset = 30;
	
	  ;% lab3_init_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 119;
	  section.data(32).dtTransOffset = 31;
	
	  ;% lab3_init_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 120;
	  section.data(33).dtTransOffset = 32;
	
	  ;% lab3_init_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 121;
	  section.data(34).dtTransOffset = 33;
	
	  ;% lab3_init_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 122;
	  section.data(35).dtTransOffset = 34;
	
	  ;% lab3_init_P.HILReadEncoderTimebase_Active
	  section.data(36).logicalSrcIdx = 123;
	  section.data(36).dtTransOffset = 35;
	
	  ;% lab3_init_P.StreamCall2_NonBlocking
	  section.data(37).logicalSrcIdx = 124;
	  section.data(37).dtTransOffset = 36;
	
	  ;% lab3_init_P.StreamCall2_Active
	  section.data(38).logicalSrcIdx = 125;
	  section.data(38).dtTransOffset = 37;
	
	  ;% lab3_init_P.HILWriteAnalog_Active
	  section.data(39).logicalSrcIdx = 126;
	  section.data(39).dtTransOffset = 38;
	
	  ;% lab3_init_P.GameController_AutoCenter
	  section.data(40).logicalSrcIdx = 127;
	  section.data(40).dtTransOffset = 39;
	
	  ;% lab3_init_P.GameController_Enabled
	  section.data(41).logicalSrcIdx = 128;
	  section.data(41).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% lab3_init_P.HILReadEncoderTimebase_Overflow
	  section.data(1).logicalSrcIdx = 129;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_P.StringConstant1_Value
	  section.data(2).logicalSrcIdx = 130;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab3_init_P.StreamCall2_URI
	  section.data(3).logicalSrcIdx = 131;
	  section.data(3).dtTransOffset = 256;
	
	  ;% lab3_init_P.StreamCall2_Endian
	  section.data(4).logicalSrcIdx = 132;
	  section.data(4).dtTransOffset = 257;
	
	  ;% lab3_init_P.GameController_ControllerNumber
	  section.data(5).logicalSrcIdx = 133;
	  section.data(5).dtTransOffset = 258;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (lab3_init_B)
    ;%
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% lab3_init_B.DataTypeConversion2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_B.Gain1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 3;
	
	  ;% lab3_init_B.DataTypeConversion1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% lab3_init_B.Gain2
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 9;
	
	  ;% lab3_init_B.PitchCounttorad
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 12;
	
	  ;% lab3_init_B.x_hat
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 13;
	
	  ;% lab3_init_B.PitchTransferFcn
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 18;
	
	  ;% lab3_init_B.Sum
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 19;
	
	  ;% lab3_init_B.ElevationTransferFcn
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
	  ;% lab3_init_B.Gain2_e
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 21;
	
	  ;% lab3_init_B.TravelCounttorad
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 22;
	
	  ;% lab3_init_B.TravelTransferFcn
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 23;
	
	  ;% lab3_init_B.RateTransitionx
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 24;
	
	  ;% lab3_init_B.Joystick_gain_x
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 25;
	
	  ;% lab3_init_B.RateTransitiony
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 26;
	
	  ;% lab3_init_B.Joystick_gain_y
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 27;
	
	  ;% lab3_init_B.Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 28;
	
	  ;% lab3_init_B.FrontmotorSaturation
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 30;
	
	  ;% lab3_init_B.BackmotorSaturation
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 31;
	
	  ;% lab3_init_B.Gain4
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 32;
	
	  ;% lab3_init_B.Gain2_c
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 37;
	
	  ;% lab3_init_B.Gain1_i
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 42;
	
	  ;% lab3_init_B.Gain_i
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 47;
	
	  ;% lab3_init_B.x_hat_dot
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 52;
	
	  ;% lab3_init_B.gamma_dot
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 57;
	
	  ;% lab3_init_B.zeta_dot
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 58;
	
	  ;% lab3_init_B.euler_angles
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 59;
	
	  ;% lab3_init_B.euler_rates
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 61;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% lab3_init_B.StreamFormattedRead1_o2
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_B.StreamFormattedRead1_o3
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab3_init_B.StreamFormattedRead1_o4
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab3_init_B.StreamFormattedRead1_o5
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab3_init_B.StreamFormattedRead1_o6
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab3_init_B.StreamFormattedRead1_o7
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 5;
	
	  ;% lab3_init_B.UnitDelay
	  section.data(7).logicalSrcIdx = 34;
	  section.data(7).dtTransOffset = 6;
	
	  ;% lab3_init_B.UnitDelay_k
	  section.data(8).logicalSrcIdx = 35;
	  section.data(8).dtTransOffset = 7;
	
	  ;% lab3_init_B.UnitDelay_g
	  section.data(9).logicalSrcIdx = 36;
	  section.data(9).dtTransOffset = 8;
	
	  ;% lab3_init_B.UnitDelay_n
	  section.data(10).logicalSrcIdx = 37;
	  section.data(10).dtTransOffset = 9;
	
	  ;% lab3_init_B.UnitDelay_m
	  section.data(11).logicalSrcIdx = 38;
	  section.data(11).dtTransOffset = 10;
	
	  ;% lab3_init_B.UnitDelay_i
	  section.data(12).logicalSrcIdx = 39;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_B.StreamCall2_o2
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% lab3_init_B.StreamFormattedRead1_o10
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_B.StreamFormattedRead1_o11
	  section.data(2).logicalSrcIdx = 42;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab3_init_B.RelationalOperator
	  section.data(3).logicalSrcIdx = 43;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab3_init_B.RelationalOperator_o
	  section.data(4).logicalSrcIdx = 44;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab3_init_B.RelationalOperator_g
	  section.data(5).logicalSrcIdx = 45;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab3_init_B.RelationalOperator_p
	  section.data(6).logicalSrcIdx = 46;
	  section.data(6).dtTransOffset = 5;
	
	  ;% lab3_init_B.RelationalOperator_a
	  section.data(7).logicalSrcIdx = 47;
	  section.data(7).dtTransOffset = 6;
	
	  ;% lab3_init_B.RelationalOperator_pg
	  section.data(8).logicalSrcIdx = 48;
	  section.data(8).dtTransOffset = 7;
	
	  ;% lab3_init_B.LogicalOperator1
	  section.data(9).logicalSrcIdx = 49;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 12;
    sectIdxOffset = 4;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (lab3_init_DW)
    ;%
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% lab3_init_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% lab3_init_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% lab3_init_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% lab3_init_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% lab3_init_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% lab3_init_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% lab3_init_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% lab3_init_DW.RateTransitionx_Buffer0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% lab3_init_DW.RateTransitiony_Buffer0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
	  ;% lab3_init_DW.HILWriteAnalog_Buffer
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 66;
	
	  ;% lab3_init_DW.p_last
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 68;
	
	  ;% lab3_init_DW.e_last
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 69;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_DW.StreamCall2_Stream
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% lab3_init_DW.Scope5_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_DW.Scope6_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 3;
	
	  ;% lab3_init_DW.ElevationScoperads_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 8;
	
	  ;% lab3_init_DW.ElevationScoperad_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 9;
	
	  ;% lab3_init_DW.PitchScoperad_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 10;
	
	  ;% lab3_init_DW.PtichrateScoperads_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 11;
	
	  ;% lab3_init_DW.TravelrateScoperads_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 12;
	
	  ;% lab3_init_DW.TravelScoperad_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 13;
	
	  ;% lab3_init_DW.HILWriteAnalog_PWORK
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 14;
	
	  ;% lab3_init_DW.Closed_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 15;
	
	  ;% lab3_init_DW.Connected2_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 16;
	
	  ;% lab3_init_DW.Scope_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 17;
	
	  ;% lab3_init_DW.ax_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 29;
	  section.data(13).dtTransOffset = 23;
	
	  ;% lab3_init_DW.ay_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 30;
	  section.data(14).dtTransOffset = 24;
	
	  ;% lab3_init_DW.az_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 31;
	  section.data(15).dtTransOffset = 25;
	
	  ;% lab3_init_DW.wx_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 32;
	  section.data(16).dtTransOffset = 26;
	
	  ;% lab3_init_DW.wy_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 33;
	  section.data(17).dtTransOffset = 27;
	
	  ;% lab3_init_DW.wz_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 34;
	  section.data(18).dtTransOffset = 28;
	
	  ;% lab3_init_DW.Scope_PWORK_f.LoggedData
	  section.data(19).logicalSrcIdx = 35;
	  section.data(19).dtTransOffset = 29;
	
	  ;% lab3_init_DW.Scope_PWORK_p.LoggedData
	  section.data(20).logicalSrcIdx = 36;
	  section.data(20).dtTransOffset = 31;
	
	  ;% lab3_init_DW.Scope_PWORK_k.LoggedData
	  section.data(21).logicalSrcIdx = 37;
	  section.data(21).dtTransOffset = 33;
	
	  ;% lab3_init_DW.Scope_PWORK_l.LoggedData
	  section.data(22).logicalSrcIdx = 38;
	  section.data(22).dtTransOffset = 35;
	
	  ;% lab3_init_DW.Scope_PWORK_b.LoggedData
	  section.data(23).logicalSrcIdx = 39;
	  section.data(23).dtTransOffset = 37;
	
	  ;% lab3_init_DW.Scope_PWORK_o.LoggedData
	  section.data(24).logicalSrcIdx = 40;
	  section.data(24).dtTransOffset = 39;
	
	  ;% lab3_init_DW.XScope_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 41;
	  section.data(25).dtTransOffset = 41;
	
	  ;% lab3_init_DW.YScope_PWORK.LoggedData
	  section.data(26).logicalSrcIdx = 42;
	  section.data(26).dtTransOffset = 42;
	
	  ;% lab3_init_DW.Scope_PWORK_e.LoggedData
	  section.data(27).logicalSrcIdx = 43;
	  section.data(27).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% lab3_init_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_DW.UnitDelay_DSTATE_d
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 1;
	
	  ;% lab3_init_DW.UnitDelay_DSTATE_p
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 2;
	
	  ;% lab3_init_DW.UnitDelay_DSTATE_l
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 3;
	
	  ;% lab3_init_DW.UnitDelay_DSTATE_n
	  section.data(5).logicalSrcIdx = 48;
	  section.data(5).dtTransOffset = 4;
	
	  ;% lab3_init_DW.UnitDelay_DSTATE_dn
	  section.data(6).logicalSrcIdx = 49;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% lab3_init_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 51;
	  section.data(2).dtTransOffset = 3;
	
	  ;% lab3_init_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 52;
	  section.data(3).dtTransOffset = 11;
	
	  ;% lab3_init_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 53;
	  section.data(4).dtTransOffset = 19;
	
	  ;% lab3_init_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 54;
	  section.data(5).dtTransOffset = 27;
	
	  ;% lab3_init_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 55;
	  section.data(6).dtTransOffset = 35;
	
	  ;% lab3_init_DW.HILReadEncoderTimebase_Buffer
	  section.data(7).logicalSrcIdx = 56;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_DW.Skiptonextline_SubsysRanBC
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% lab3_init_DW.StreamCall2_State
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% lab3_init_DW.p_last_not_empty
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% lab3_init_DW.e_last_not_empty
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3722332900;
  targMap.checksum1 = 1604340118;
  targMap.checksum2 = 2396975944;
  targMap.checksum3 = 2866133730;

