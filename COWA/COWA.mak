# Microsoft Developer Studio Generated NMAKE File, Based on COWA.dsp
!IF "$(CFG)" == ""
CFG=COWA - Win32 Debug
!MESSAGE No configuration specified. Defaulting to COWA - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "COWA - Win32 Release" && "$(CFG)" != "COWA - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "COWA.mak" CFG="COWA - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "COWA - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "COWA - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "COWA - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\COWA.exe"


CLEAN :
	-@erase "$(INTDIR)\AttendanceDlg.obj"
	-@erase "$(INTDIR)\AttendanceRS.obj"
	-@erase "$(INTDIR)\BusTripDlg.obj"
	-@erase "$(INTDIR)\CounterRS.obj"
	-@erase "$(INTDIR)\COWA.obj"
	-@erase "$(INTDIR)\COWA.pch"
	-@erase "$(INTDIR)\COWA.res"
	-@erase "$(INTDIR)\COWADlg.obj"
	-@erase "$(INTDIR)\DepartmentRS.obj"
	-@erase "$(INTDIR)\Encryption.obj"
	-@erase "$(INTDIR)\ErrandRS.obj"
	-@erase "$(INTDIR)\LeaveDlg.obj"
	-@erase "$(INTDIR)\LeaveRS.obj"
	-@erase "$(INTDIR)\LoginDlg.obj"
	-@erase "$(INTDIR)\OvertimeDlg.obj"
	-@erase "$(INTDIR)\OvertimeRS.obj"
	-@erase "$(INTDIR)\PersonRS.obj"
	-@erase "$(INTDIR)\RecordDlg.obj"
	-@erase "$(INTDIR)\SetTimeDlg.obj"
	-@erase "$(INTDIR)\StatisticsDlg.obj"
	-@erase "$(INTDIR)\StatisticsRS.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\COWA.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\COWA.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\COWA.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COWA.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\COWA.pdb" /machine:I386 /out:"$(OUTDIR)\COWA.exe" 
LINK32_OBJS= \
	"$(INTDIR)\AttendanceDlg.obj" \
	"$(INTDIR)\AttendanceRS.obj" \
	"$(INTDIR)\BusTripDlg.obj" \
	"$(INTDIR)\CounterRS.obj" \
	"$(INTDIR)\COWA.obj" \
	"$(INTDIR)\COWADlg.obj" \
	"$(INTDIR)\DepartmentRS.obj" \
	"$(INTDIR)\Encryption.obj" \
	"$(INTDIR)\ErrandRS.obj" \
	"$(INTDIR)\LeaveDlg.obj" \
	"$(INTDIR)\LeaveRS.obj" \
	"$(INTDIR)\LoginDlg.obj" \
	"$(INTDIR)\OvertimeDlg.obj" \
	"$(INTDIR)\OvertimeRS.obj" \
	"$(INTDIR)\PersonRS.obj" \
	"$(INTDIR)\RecordDlg.obj" \
	"$(INTDIR)\SetTimeDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\COWA.res" \
	"$(INTDIR)\StatisticsDlg.obj" \
	"$(INTDIR)\StatisticsRS.obj"

"$(OUTDIR)\COWA.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\COWA.exe" "$(OUTDIR)\COWA.bsc"


CLEAN :
	-@erase "$(INTDIR)\AttendanceDlg.obj"
	-@erase "$(INTDIR)\AttendanceDlg.sbr"
	-@erase "$(INTDIR)\AttendanceRS.obj"
	-@erase "$(INTDIR)\AttendanceRS.sbr"
	-@erase "$(INTDIR)\BusTripDlg.obj"
	-@erase "$(INTDIR)\BusTripDlg.sbr"
	-@erase "$(INTDIR)\CounterRS.obj"
	-@erase "$(INTDIR)\CounterRS.sbr"
	-@erase "$(INTDIR)\COWA.obj"
	-@erase "$(INTDIR)\COWA.pch"
	-@erase "$(INTDIR)\COWA.res"
	-@erase "$(INTDIR)\COWA.sbr"
	-@erase "$(INTDIR)\COWADlg.obj"
	-@erase "$(INTDIR)\COWADlg.sbr"
	-@erase "$(INTDIR)\DepartmentRS.obj"
	-@erase "$(INTDIR)\DepartmentRS.sbr"
	-@erase "$(INTDIR)\Encryption.obj"
	-@erase "$(INTDIR)\Encryption.sbr"
	-@erase "$(INTDIR)\ErrandRS.obj"
	-@erase "$(INTDIR)\ErrandRS.sbr"
	-@erase "$(INTDIR)\LeaveDlg.obj"
	-@erase "$(INTDIR)\LeaveDlg.sbr"
	-@erase "$(INTDIR)\LeaveRS.obj"
	-@erase "$(INTDIR)\LeaveRS.sbr"
	-@erase "$(INTDIR)\LoginDlg.obj"
	-@erase "$(INTDIR)\LoginDlg.sbr"
	-@erase "$(INTDIR)\OvertimeDlg.obj"
	-@erase "$(INTDIR)\OvertimeDlg.sbr"
	-@erase "$(INTDIR)\OvertimeRS.obj"
	-@erase "$(INTDIR)\OvertimeRS.sbr"
	-@erase "$(INTDIR)\PersonRS.obj"
	-@erase "$(INTDIR)\PersonRS.sbr"
	-@erase "$(INTDIR)\RecordDlg.obj"
	-@erase "$(INTDIR)\RecordDlg.sbr"
	-@erase "$(INTDIR)\SetTimeDlg.obj"
	-@erase "$(INTDIR)\SetTimeDlg.sbr"
	-@erase "$(INTDIR)\StatisticsDlg.obj"
	-@erase "$(INTDIR)\StatisticsDlg.sbr"
	-@erase "$(INTDIR)\StatisticsRS.obj"
	-@erase "$(INTDIR)\StatisticsRS.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\COWA.bsc"
	-@erase "$(OUTDIR)\COWA.exe"
	-@erase "$(OUTDIR)\COWA.ilk"
	-@erase "$(OUTDIR)\COWA.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\COWA.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x804 /fo"$(INTDIR)\COWA.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\COWA.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\AttendanceDlg.sbr" \
	"$(INTDIR)\AttendanceRS.sbr" \
	"$(INTDIR)\BusTripDlg.sbr" \
	"$(INTDIR)\CounterRS.sbr" \
	"$(INTDIR)\COWA.sbr" \
	"$(INTDIR)\COWADlg.sbr" \
	"$(INTDIR)\DepartmentRS.sbr" \
	"$(INTDIR)\Encryption.sbr" \
	"$(INTDIR)\ErrandRS.sbr" \
	"$(INTDIR)\LeaveDlg.sbr" \
	"$(INTDIR)\LeaveRS.sbr" \
	"$(INTDIR)\LoginDlg.sbr" \
	"$(INTDIR)\OvertimeDlg.sbr" \
	"$(INTDIR)\OvertimeRS.sbr" \
	"$(INTDIR)\PersonRS.sbr" \
	"$(INTDIR)\RecordDlg.sbr" \
	"$(INTDIR)\SetTimeDlg.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\StatisticsDlg.sbr" \
	"$(INTDIR)\StatisticsRS.sbr"

"$(OUTDIR)\COWA.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\COWA.pdb" /debug /machine:I386 /out:"$(OUTDIR)\COWA.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\AttendanceDlg.obj" \
	"$(INTDIR)\AttendanceRS.obj" \
	"$(INTDIR)\BusTripDlg.obj" \
	"$(INTDIR)\CounterRS.obj" \
	"$(INTDIR)\COWA.obj" \
	"$(INTDIR)\COWADlg.obj" \
	"$(INTDIR)\DepartmentRS.obj" \
	"$(INTDIR)\Encryption.obj" \
	"$(INTDIR)\ErrandRS.obj" \
	"$(INTDIR)\LeaveDlg.obj" \
	"$(INTDIR)\LeaveRS.obj" \
	"$(INTDIR)\LoginDlg.obj" \
	"$(INTDIR)\OvertimeDlg.obj" \
	"$(INTDIR)\OvertimeRS.obj" \
	"$(INTDIR)\PersonRS.obj" \
	"$(INTDIR)\RecordDlg.obj" \
	"$(INTDIR)\SetTimeDlg.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\COWA.res" \
	"$(INTDIR)\StatisticsDlg.obj" \
	"$(INTDIR)\StatisticsRS.obj"

"$(OUTDIR)\COWA.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("COWA.dep")
!INCLUDE "COWA.dep"
!ELSE 
!MESSAGE Warning: cannot find "COWA.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "COWA - Win32 Release" || "$(CFG)" == "COWA - Win32 Debug"
SOURCE=.\AttendanceDlg.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\AttendanceDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\AttendanceDlg.obj"	"$(INTDIR)\AttendanceDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\AttendanceRS.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\AttendanceRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\AttendanceRS.obj"	"$(INTDIR)\AttendanceRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\BusTripDlg.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\BusTripDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\BusTripDlg.obj"	"$(INTDIR)\BusTripDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\CounterRS.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\CounterRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\CounterRS.obj"	"$(INTDIR)\CounterRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\COWA.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\COWA.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\COWA.obj"	"$(INTDIR)\COWA.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\COWA.rc

"$(INTDIR)\COWA.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\COWADlg.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\COWADlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\COWADlg.obj"	"$(INTDIR)\COWADlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\DepartmentRS.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\DepartmentRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\DepartmentRS.obj"	"$(INTDIR)\DepartmentRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\Encryption.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\Encryption.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\Encryption.obj"	"$(INTDIR)\Encryption.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\ErrandRS.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\ErrandRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\ErrandRS.obj"	"$(INTDIR)\ErrandRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\LeaveDlg.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\LeaveDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\LeaveDlg.obj"	"$(INTDIR)\LeaveDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\LeaveRS.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\LeaveRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\LeaveRS.obj"	"$(INTDIR)\LeaveRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\LoginDlg.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\LoginDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\LoginDlg.obj"	"$(INTDIR)\LoginDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\OvertimeDlg.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\OvertimeDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\OvertimeDlg.obj"	"$(INTDIR)\OvertimeDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\OvertimeRS.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\OvertimeRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\OvertimeRS.obj"	"$(INTDIR)\OvertimeRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\PersonRS.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\PersonRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\PersonRS.obj"	"$(INTDIR)\PersonRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\RecordDlg.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\RecordDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\RecordDlg.obj"	"$(INTDIR)\RecordDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\SetTimeDlg.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\SetTimeDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\SetTimeDlg.obj"	"$(INTDIR)\SetTimeDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\StatisticsDlg.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\StatisticsDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\StatisticsDlg.obj"	"$(INTDIR)\StatisticsDlg.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\StatisticsRS.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"


"$(INTDIR)\StatisticsRS.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"


"$(INTDIR)\StatisticsRS.obj"	"$(INTDIR)\StatisticsRS.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\COWA.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "COWA - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\COWA.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\COWA.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "COWA - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\COWA.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\COWA.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

