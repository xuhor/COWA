; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAttendanceDlg
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "COWA.h"

ClassCount=21
Class1=CCOWAApp
Class2=CCOWADlg
Class3=CAboutDlg

ResourceCount=12
Resource1=IDD_LEAVE_PAGE3
Resource2=IDR_MAINFRAME
Resource3=IDD_BUS_TRIP_PAGE4
Class4=CLoginDlg
Class5=CEncryption
Class6=CPersonRS
Resource4=IDD_RECORD_DIG
Class7=CSetTimeDlg
Resource5=IDD_ABOUTBOX
Resource6=IDD_PROPPAGE_MEDIUM (English (U.S.))
Resource7=IDD_LOGIN_DIALOG
Resource8=IDD_SET_DIALOG
Resource9=IDD_ATTANDENCE_PAGE1
Resource10=IDD_COWA_DIALOG
Class8=CAttendanceDlg
Class9=COvertimeDlg
Class10=CLeaveDlg
Class11=CBusTripDlg
Class12=CRecordDlg
Class13=CAttendanceRS
Class14=CDepartmentRS
Class15=CCounterRS
Class16=CcounterRS
Class17=COvertimeRS
Class18=CLeaveRS
Class19=CErrandRS
Resource11=IDD_OVERTIME_PAGE2
Class20=CStatisticsDlg
Class21=CStatisticsRS
Resource12=IDD_STATISTICS

[CLS:CCOWAApp]
Type=0
HeaderFile=COWA.h
ImplementationFile=COWA.cpp
Filter=N

[CLS:CCOWADlg]
Type=0
HeaderFile=COWADlg.h
ImplementationFile=COWADlg.cpp
Filter=D
LastObject=CCOWADlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=COWADlg.h
ImplementationFile=COWADlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COWA_DIALOG]
Type=1
Class=CCOWADlg
ControlCount=8
Control1=IDC_BITMAP,static,1342177294
Control2=IDCANCEL,button,1342242816
Control3=IDC_COWA_STATIC,static,1342308352
Control4=IDC_SetTime,button,1342242816
Control5=IDC_C_O_W_A,button,1342242816
Control6=IDC_STATISTICS,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_RELOGIN,button,1342242817

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO1
VirtualFilter=dWC

[CLS:CEncryption]
Type=0
HeaderFile=Encryption.h
ImplementationFile=Encryption.cpp
BaseClass=CButton
Filter=W

[CLS:CPersonRS]
Type=0
HeaderFile=PersonRS.h
ImplementationFile=PersonRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CPersonRS]
DB=1
DBType=ODBC
ColumnCount=15
Column1=[ID], 12, 12
Column2=[PASSWD], 12, 40
Column3=[AUTHORITY], 12, 2
Column4=[NAME], 12, 20
Column5=[SEX], 12, 2
Column6=[BIRTHDAY], 11, 16
Column7=[DEPARTMENT], 12, 6
Column8=[JOB], 12, 6
Column9=[EDU_LEVEL], 12, 2
Column10=[SPECIALTY], 12, 40
Column11=[ADDRESS], 12, 100
Column12=[TEL], 12, 40
Column13=[EMAIL], 12, 100
Column14=[STATE], 12, 2
Column15=[REMARK], -1, 2147483646

[DLG:IDD_SET_DIALOG]
Type=1
Class=CSetTimeDlg
ControlCount=11
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_AM_ON,SysDateTimePick32,1342242857
Control6=IDC_AM_OFF,SysDateTimePick32,1342242857
Control7=IDC_PM_ON,SysDateTimePick32,1342242857
Control8=IDC_PM_OFF,SysDateTimePick32,1342242857
Control9=IDC_STATIC,button,1342177287
Control10=IDC_CHANGE,button,1342242816
Control11=IDC_RESET,button,1342242816

[CLS:CSetTimeDlg]
Type=0
HeaderFile=SetTimeDlg.h
ImplementationFile=SetTimeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSetTimeDlg
VirtualFilter=dWC

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLoginDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LOGIN_STATIC,static,1342177280
Control4=IDC_STATIC,static,1342308352
Control5=IDC_COMBO1,combobox,1344340226
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_NAME_EDIT,edit,1350631552
Control9=IDC_PASSWORD_EDIT,edit,1350631584

[DLG:IDD_RECORD_DIG]
Type=1
Class=CRecordDlg
ControlCount=11
Control1=IDC_CHECK_TIME,button,1342242819
Control2=IDC_CHECK_CLERK,button,1342242819
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_START_TIME,SysDateTimePick32,1342242848
Control6=IDC_END_TIME,SysDateTimePick32,1342242848
Control7=IDC_CLERK_ID,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_CLERKNAME,edit,1350633600
Control11=IDC_STATIC,button,1342177287

[DLG:IDD_PROPPAGE_MEDIUM (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_ATTANDENCE_PAGE1]
Type=1
Class=CAttendanceDlg
ControlCount=21
Control1=IDC_STATIC,static,1342308352
Control2=IDC_IN_OUT_TIME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_DEPART_ID,edit,1350631552
Control5=IDC_DEPART_NAME,edit,1350633600
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_CLERK_NUM,edit,1350631552
Control9=IDC_CLERK_NAME,edit,1350633600
Control10=IDC_IN_OUT,button,1342308359
Control11=IDC_OUT,button,1342308361
Control12=IDC_IN,button,1342177289
Control13=IDC_ALL_CLERK,button,1342308361
Control14=IDC_DEPART_CLERK,button,1342177289
Control15=IDC_SINGLE_CLERK,button,1342177289
Control16=IDC_ADD_RECORD,button,1342242816
Control17=IDC_SELECT_E,button,1342308359
Control18=IDC_LIST1,SysListView32,1350631425
Control19=IDC_CHECK_BY_C,button,1342242816
Control20=IDC_DELETE_RECORD,button,1342242816
Control21=IDC_STATIC,static,1342308352

[DLG:IDD_LEAVE_PAGE3]
Type=1
Class=CLeaveDlg
ControlCount=16
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_L_START_TIME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_L_END_TIME,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_L_CLERK_ID,edit,1350631552
Control9=IDC_L_CLERK_NAME,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_LEAVE_REASON,edit,1350631552
Control12=IDC_ADD_L_RECORD,button,1342242816
Control13=IDC_LEAVE_LIST,SysListView32,1350631425
Control14=IDC_DELETE_L_RECORD,button,1342242816
Control15=IDC_LEAVE_CHECK,button,1342242816
Control16=IDC_STATIC,static,1342308352

[DLG:IDD_OVERTIME_PAGE2]
Type=1
Class=COvertimeDlg
ControlCount=15
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CUR_TIME,SysDateTimePick32,1342242848
Control6=IDC_CLERK_ID,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_OVERTIME_HOURS,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_CLERK_NAME,edit,1350633600
Control11=IDC_ADD_OVERTIME_R,button,1342242816
Control12=IDC_OVERTIME_LIST,SysListView32,1350631425
Control13=IDC_DELETE_OVERTIM_R,button,1342242816
Control14=IDC_OVERTIMR_SEARCH,button,1342242816
Control15=IDC_STATIC,static,1342308352

[DLG:IDD_BUS_TRIP_PAGE4]
Type=1
Class=CBusTripDlg
ControlCount=16
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_B_T_START_TIME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_B_T_END_TIME,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_B_T_CLERK_ID,edit,1350631552
Control9=IDC_B_T_CLERK_NAME,edit,1350633600
Control10=IDC_B_T_DESCRIPTION,edit,1350631552
Control11=IDC_ADD_B_T_RECORD,button,1342242816
Control12=IDC_STATIC,static,1342308352
Control13=IDC_DELETE_B_T_RECORD,button,1342242816
Control14=IDC_B_T_CHECK,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_B_T_LIST,SysListView32,1350631425

[CLS:CAttendanceDlg]
Type=0
HeaderFile=AttendanceDlg.h
ImplementationFile=AttendanceDlg.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=IDC_OUT
VirtualFilter=idWC

[CLS:COvertimeDlg]
Type=0
HeaderFile=OvertimeDlg.h
ImplementationFile=OvertimeDlg.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=COvertimeDlg
VirtualFilter=idWC

[CLS:CLeaveDlg]
Type=0
HeaderFile=LeaveDlg.h
ImplementationFile=LeaveDlg.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CLeaveDlg
VirtualFilter=idWC

[CLS:CBusTripDlg]
Type=0
HeaderFile=BusTripDlg.h
ImplementationFile=BusTripDlg.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CBusTripDlg
VirtualFilter=idWC

[CLS:CRecordDlg]
Type=0
HeaderFile=RecordDlg.h
ImplementationFile=RecordDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CLERK_NAME
VirtualFilter=dWC

[CLS:CAttendanceRS]
Type=0
HeaderFile=AttendanceRS.h
ImplementationFile=AttendanceRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CAttendanceRS

[DB:CAttendanceRS]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[ID], 5, 2
Column2=[PERSON], 12, 12
Column3=[IN_OUT], 12, 2
Column4=[IO_TIME], 11, 16

[CLS:CDepartmentRS]
Type=0
HeaderFile=DepartmentRS.h
ImplementationFile=DepartmentRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CDepartmentRS

[DB:CDepartmentRS]
DB=1
DBType=ODBC
ColumnCount=8
Column1=[ATTENDANCE].[ID], 5, 2
Column2=[PERSON], 12, 12
Column3=[IN_OUT], 12, 2
Column4=[IO_TIME], 11, 16
Column5=[DEPARTMENT].[ID], 12, 6
Column6=[NAME], 12, 40
Column7=[MANAGER], 12, 12
Column8=[INTRO], -1, 2147483646

[CLS:CCounterRS]
Type=0
HeaderFile=CounterRS.h
ImplementationFile=CounterRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CCounterRS]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 12, 2
Column2=[COUNTER_VALUE], 5, 2
Column3=[DESCRIPTION], 12, 20

[CLS:CcounterRS]
Type=0
HeaderFile=counterRS.h
ImplementationFile=counterRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CcounterRS

[DB:CcounterRS]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[ID], 12, 2
Column2=[COUNTER_VALUE], 5, 2
Column3=[DESCRIPTION], 12, 20

[CLS:COvertimeRS]
Type=0
HeaderFile=OvertimeRS.h
ImplementationFile=OvertimeRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:COvertimeRS]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[ID], 5, 2
Column2=[PERSON], 12, 12
Column3=[WORK_HOURS], -6, 1
Column4=[WORK_DATE], 11, 16

[CLS:CLeaveRS]
Type=0
HeaderFile=LeaveRS.h
ImplementationFile=LeaveRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CLeaveRS

[DB:CLeaveRS]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[ID], 5, 2
Column2=[PERSON], 12, 12
Column3=[START_TIME], 11, 16
Column4=[END_TIME], 11, 16
Column5=[REASON], 12, 20

[CLS:CErrandRS]
Type=0
HeaderFile=ErrandRS.h
ImplementationFile=ErrandRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CErrandRS

[DB:CErrandRS]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[ID], 5, 2
Column2=[PERSON], 12, 12
Column3=[START_TIME], 11, 16
Column4=[END_TIME], 11, 16
Column5=[DESCRIPTION], 12, 20

[DLG:IDD_STATISTICS]
Type=1
Class=CStatisticsDlg
ControlCount=20
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_S_Y_M_CHECK,button,1342242819
Control4=IDC_S_C_CHECK,button,1342242819
Control5=IDC_S_CLERK_ID,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_S_CLERK_NAME,edit,1350633600
Control9=IDC_YEAR_MONTH,edit,1350631552
Control10=IDC_S_CHECK,button,1342242816
Control11=IDC_S_LIST,SysListView32,1350631425
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STAT_EDT_TIME,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STARTTIME,SysDateTimePick32,1342242848
Control18=IDC_ENDTIME,SysDateTimePick32,1342242848
Control19=IDC_BeginToStat,button,1342242816
Control20=IDC_PROCRSS,static,1342308352

[CLS:CStatisticsDlg]
Type=0
HeaderFile=StatisticsDlg.h
ImplementationFile=StatisticsDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_STAT_EDT_TIME
VirtualFilter=dWC

[CLS:CStatisticsRS]
Type=0
HeaderFile=StatisticsRS.h
ImplementationFile=StatisticsRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CStatisticsRS

[DB:CStatisticsRS]
DB=1
DBType=ODBC
ColumnCount=10
Column1=[ID], 5, 2
Column2=[YEAR_MONTH], 12, 14
Column3=[PERSON], 12, 12
Column4=[WORK_HOUR], 5, 2
Column5=[OVER_HOUR], 4, 4
Column6=[LEAVE_HDAY], 5, 2
Column7=[ERRAND_HDAY], 5, 2
Column8=[LATE_TIMES], -6, 1
Column9=[EARLY_TIMES], -6, 1
Column10=[ABSENT_TIMES], -6, 1

