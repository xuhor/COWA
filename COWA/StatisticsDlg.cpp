// StatisticsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "COWA.h"
#include "StatisticsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatisticsDlg dialog
extern CDatabase Db;

CTime StrToTime(CString str)
{// ʱ�䴮��ʽ "%Y-%m-%d %H:%M:%S",��"1999-01-01 11:11:11"
	int nYear,nMonth,nDay,nHour,nMinute,nSecond;
	sscanf(str.Left(4), "%d", &nYear); // �õ���
	sscanf(str.Mid(5,2), "%d", &nMonth); // �õ���
	sscanf(str.Mid(8,2), "%d", &nDay); // �õ���
	sscanf(str.Mid(11,2), "%d", &nHour); // �õ�ʱ
	sscanf(str.Mid(14,2), "%d", &nMinute); // �õ���
	sscanf(str.Mid(17,2), "%d", &nSecond); // �õ���
	// ����CTime����
	CTime result(nYear,nMonth,nDay,nHour,nMinute,nSecond);
	return result;
}

CStatisticsDlg::CStatisticsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStatisticsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStatisticsDlg)
	m_SCCheck = FALSE;
	m_SYMCheck = FALSE;
	m_strTime = _T("");
	m_ETime = 0;
	m_STime = 0;
	//}}AFX_DATA_INIT
}


void CStatisticsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatisticsDlg)
	DDX_Control(pDX, IDC_S_LIST, m_S_List);
	DDX_Check(pDX, IDC_S_C_CHECK, m_SCCheck);
	DDX_Check(pDX, IDC_S_Y_M_CHECK, m_SYMCheck);
	DDX_Text(pDX, IDC_STAT_EDT_TIME, m_strTime);
	DDX_DateTimeCtrl(pDX, IDC_ENDTIME, m_ETime);
	DDX_DateTimeCtrl(pDX, IDC_STARTTIME, m_STime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatisticsDlg, CDialog)
	//{{AFX_MSG_MAP(CStatisticsDlg)
	ON_BN_CLICKED(IDC_S_CHECK, OnSCheck)
	ON_EN_CHANGE(IDC_S_CLERK_ID, OnChangeSClerkId)
	ON_BN_CLICKED(IDC_BeginToStat, OnBeginToStat)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatisticsDlg message handlers

void CStatisticsDlg::OnSCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	//���º�Ա������������Ϊ��
	if (m_SYMCheck==FALSE && m_SCCheck==FALSE)
	{
		MessageBox("��ѡ���������","��ʾ",MB_OK | MB_ICONINFORMATION);
		return;
	}
    //
	CStatisticsRS StatRS(&Db);
	//get YearMongth time case 
	CString YearMonth,Person;
	GetDlgItem(IDC_YEAR_MONTH)->GetWindowText(YearMonth);
	GetDlgItem(IDC_S_CLERK_ID)->GetWindowText(Person);
	//���º�Ա������������Ϊ��
	if (m_SYMCheck==TRUE && m_SCCheck==TRUE)
	{
		StatRS.m_strFilter="PERSON = '" + Person + "' and YEAR_MONTH = '" + YearMonth + "'";  
	}
	//���¼�������Ϊ�棬Ա����������Ϊ��
	else if (m_SYMCheck==TRUE && m_SCCheck==FALSE)
	{
		StatRS.m_strFilter="YEAR_MONTH = '" + YearMonth + "'";
	}
	//���¼�������Ϊ�٣�Ա����������Ϊ��
	else
	{
			StatRS.m_strFilter = "PERSON = '" + Person + "'";
	}

	//������ʾ�б� 
	int i=0;
	CString Str;
    StatRS.Open();
	m_S_List.DeleteAllItems();
	while (!StatRS.IsEOF())
	{
		CString Str;
		m_S_List.InsertItem(i," ");
		//
		Str.Format("%d",StatRS.m_ID);
		m_S_List.SetItemText(i,0,Str);
		//
		m_S_List.SetItemText(i,1,StatRS.m_YEAR_MONTH);
		//
		m_S_List.SetItemText(i,2,StatRS.m_PERSON);
		//
		Str.Format("%d",StatRS.m_WORK_HOUR);
		m_S_List.SetItemText(i,3,Str);
		//
		Str.Format("%d",StatRS.m_OVER_HOUR);
        m_S_List.SetItemText(i,4,Str);
		//
		Str.Format("%d",StatRS.m_LEAVE_HDAY);
        m_S_List.SetItemText(i,5,Str);
		//
		Str.Format("%d",StatRS.m_ERRAND_HDAY);
        m_S_List.SetItemText(i,6,Str);
		//
		Str.Format("%d",StatRS.m_LATE_TIMES);
        m_S_List.SetItemText(i,7,Str);
		//
		Str.Format("%d",StatRS.m_EARLY_TIMES);
        m_S_List.SetItemText(i,8,Str);
		//
		Str.Format("%d",StatRS.m_ABSENT_TIMES);
        m_S_List.SetItemText(i,9,Str);
		//
		StatRS.MoveNext();
		i++;
	}
	StatRS.Close();
}

BOOL CStatisticsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//set list
	m_S_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_S_List.InsertColumn(0,"ID",LVCFMT_LEFT,50);
	m_S_List.InsertColumn(1,"YEAR_MONTH",LVCFMT_LEFT,80);
	m_S_List.InsertColumn(2,"PERSON",LVCFMT_LEFT,70);
	m_S_List.InsertColumn(3,"WORK_HOUR",LVCFMT_LEFT,80);
	m_S_List.InsertColumn(4,"OVER_HOUR",LVCFMT_LEFT,80);
	m_S_List.InsertColumn(5,"LEAVE_HDAY",LVCFMT_LEFT,80);
	m_S_List.InsertColumn(6,"ERRAND_HDAY",LVCFMT_LEFT,80);
	m_S_List.InsertColumn(7,"LATE_TIMES",LVCFMT_LEFT,80);
	m_S_List.InsertColumn(8,"EARLY_TIMES",LVCFMT_LEFT,80);
	m_S_List.InsertColumn(9,"ABSENT_TIMES",LVCFMT_LEFT,90);
	//�������±༭��ؼ���ʼ����ʾʱ��
    CTime CurTime=CTime::GetCurrentTime();
	CString Temp=CurTime.Format("%Y-%m");
	SetDlgItemText(IDC_STAT_EDT_TIME,Temp);
    //show list
    ShowSRecord();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CStatisticsDlg::ShowSRecord()
{
	int i=0;
	CStatisticsRS StatRS(&Db);
	StatRS.Open();
	m_S_List.DeleteAllItems();
	while (!StatRS.IsEOF())
	{
		CString Str;
		m_S_List.InsertItem(i," ");
		//
		Str.Format("%d",StatRS.m_ID);
		m_S_List.SetItemText(i,0,Str);
		//
		m_S_List.SetItemText(i,1,StatRS.m_YEAR_MONTH);
		//
		m_S_List.SetItemText(i,2,StatRS.m_PERSON);
		//
		Str.Format("%d",StatRS.m_WORK_HOUR);
		m_S_List.SetItemText(i,3,Str);
		//
		Str.Format("%d",StatRS.m_OVER_HOUR);
        m_S_List.SetItemText(i,4,Str);
		//
		Str.Format("%d",StatRS.m_LEAVE_HDAY);
        m_S_List.SetItemText(i,5,Str);
		//
		Str.Format("%d",StatRS.m_ERRAND_HDAY);
        m_S_List.SetItemText(i,6,Str);
		//
		Str.Format("%d",StatRS.m_LATE_TIMES);
        m_S_List.SetItemText(i,7,Str);
		//
		Str.Format("%d",StatRS.m_EARLY_TIMES);
        m_S_List.SetItemText(i,8,Str);
		//
		Str.Format("%d",StatRS.m_ABSENT_TIMES);
        m_S_List.SetItemText(i,9,Str);
		//
		StatRS.MoveNext();
		i++;
	}
	StatRS.Close();
}

void CStatisticsDlg::OnChangeSClerkId() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	CString PersonD;
	CPersonRS PersonRS(&Db);
	GetDlgItemText(IDC_S_CLERK_ID,PersonD);
	PersonRS.m_strFilter="ID = '"+PersonD + "'";
	PersonRS.Open();
	if (PersonRS.GetRecordCount()==1)
	{
		SetDlgItemText(IDC_S_CLERK_NAME,PersonRS.m_NAME);
	}
	else
	{
		SetDlgItemText(IDC_S_CLERK_NAME,"");
	}
	PersonRS.Close();
	// TODO: Add your control notification handler code here
	
}

void CStatisticsDlg::OnBeginToStat() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_PROCRSS,"");
	SetDlgItemText(IDC_PROCRSS,"ͳ�ƿ�ʼ�����Եȡ���");
	CRecordset rs_Q_attend(&Db); // ����Q_attend��¼��
	CRecordset rs_Q_leave(&Db);  // ����Q_leave��¼��
	CRecordset rs_Q_errand(&Db);  // ����Q_errand��¼��
	CTimeSpan tp_1(1,0,0,0); // ����һ��1���CTimeSpan
	CTimeSpan tp_02(0,2,0,0); // ����һ��2Сʱ��CTimeSpan
	CTimeSpan TimeSpan[4]; // �������°�ʱ��
	int nHours[2]; // ���������繤��ʱ��
	CString strSTime,strETime; // ����ʼĩʱ��
	CTime TimeStamp, LateTime, EarlyTime,WorkStart,WorkEnd; // �����м��ж�ʱ��
	int nWorkHour,nOverHour,nLeaveHDay,nErrandHDay; // ����ʱ��������
	BOOL bLate,bEarly,bAbsent,bLeave,bErrand; // �����жϽ��
	int nLateTimes,nEarlyTimes,nAbsentTimes; // �������
	CString cstr[4]; // �ݴ���ʼʱ��
	char str[4][9]; // �ݴ���ʼʱ��
	int i,j,/*n,*/counter; // ����ѭ���ͼ���
	CString strTmp,strTmp1,strTmp2; // ��ʱ����
	// ��ʱ����,��,��,��,ʱ,��,��
	int nHour,nMinute,nSecond;
	CString strFileName=".\\workplan.ini"; // INI�ļ���
	UpdateData(); // ��������
	// ��ȡINI�ļ�
	GetPrivateProfileString("WorkPlan", "Time1", "08:00:00", str[0], 9, strFileName);
	GetPrivateProfileString("WorkPlan", "Time2", "12:00:00", str[1], 9, strFileName);
	GetPrivateProfileString("WorkPlan", "Time3", "14:00:00", str[2], 9, strFileName);
	GetPrivateProfileString("WorkPlan", "Time4", "18:00:00", str[3], 9, strFileName);
	for(i=0; i<4; i++) cstr[i]=str[i];

	// �����ĸ�ʱ������������ʼ��ΪINI�ļ��е�ֵ
	CTimeSpan *pTS;
	for(i=0; i<4; i++)
	{
		sscanf(cstr[i].Left(2), "%d", &nHour);		// �õ�ʱ
		sscanf(cstr[i].Mid(3,2), "%d", &nMinute);	// �õ���
		sscanf(cstr[i].Mid(6,2), "%d", &nSecond);	// �õ���
		// ����һ��ʱ��������
		pTS=new CTimeSpan(0,nHour,nMinute,nSecond);
		TimeSpan[i]=*pTS; // ��ֵ
		delete pTS;
	}
	nHours[0]=(TimeSpan[1]-TimeSpan[0]).GetTotalHours(); // �������繤��ʱ��
	if((TimeSpan[1]-TimeSpan[0]).GetMinutes()>30) nHours[0]++; // ��������
	nHours[1]=(TimeSpan[3]-TimeSpan[2]).GetTotalHours(); // �������繤��ʱ��
	if((TimeSpan[3]-TimeSpan[2]).GetMinutes()>30) nHours[1]++; // ��������
	// ת��ͳ�ƿ�ʼʱ��
	strSTime="#"+m_STime.Format("%Y-%m-%d")+"#";
	// ת��ͳ�ƽ���ʱ�䣬��������1
	strETime="#"+(m_ETime+tp_1).Format("%Y-%m-%d")+"#";
	// ��ȡԱ���б�
	CPersonRS rs_person(&Db); // ����Ա����
	rs_person.m_strFilter="STATE='T'"; // ���ù���������ȡԱ���б�
	rs_person.Open(); // ��Ա����
// 	n=rs_person.GetRecordCount(); // ��¼Ա������                    //?????????????????????????n��ֵ����ȷ��������
// 	i=0; // ��ʼ���Ѵ���Ա������
// 	m_cProgress.SetRange(0,n); // ���ý�����
// 	m_cProgress.SetPos(0); // ��ʼ��������
	//���ѭ������PERSON���ҵ�����Ա�������ֱ��ÿ��Ա������ͳ��

	while(!rs_person.IsEOF()) // ���ζ�ÿ��Ա������ͳ��
	{
		//��ȡ���ڼ�¼
		// ִ�в�ѯ
		rs_Q_attend.Open(CRecordset::forwardOnly,
			"select IN_OUT,IO_TIME from ATTENDANCE\
			where PERSON='" + rs_person.m_ID
			+ "' and IO_TIME>" + strSTime
			+ " and IO_TIME<" +strETime
			+ " order by IO_TIME");
		strTmp1.Empty(); // ���strTmp1
		// ��ʼ��
		nWorkHour=nOverHour=0;
		nLeaveHDay=nErrandHDay=0;
		nLateTimes=nEarlyTimes=nAbsentTimes=0;
		TimeStamp=m_STime; // ��ʼ��ʱ���Ϊͳ�ƿ�ʼʱ��
		//ѭ�����ֱ���ڶ���ÿһ�����ͳ��

		while(TimeStamp < m_ETime+tp_02) // �ж��Ƿ񳬳�ͳ�ƽ���ʱ�� //?????
		{
			if(TimeStamp.GetDayOfWeek()!=1 &&
			   TimeStamp.GetDayOfWeek()!=7) // �ж��Ƿ�����
			{
				for(j=0;j<=1;j++) // �������
				{
					LateTime=TimeStamp+TimeSpan[2*j]; // ���óٵ�ʱ��
					EarlyTime=TimeStamp+TimeSpan[2*j+1]; // ��������ʱ��

					// �ж��Ƿ����
					rs_Q_leave.Open(CRecordset::forwardOnly,
						"select ID from LEAVE where\
						PERSON='" + rs_person.m_ID
						+ "' and START_TIME<#"
						+ LateTime.Format("%Y-%m-%d %H:%M:%S")
						+ "# and END_TIME>#"
						+ EarlyTime.Format("%Y-%m-%d %H:%M:%S")
						+ "#");
					bLeave=(rs_Q_leave.GetRecordCount()>0);	// �ж��Ƿ�����ټ�¼
					rs_Q_leave.Close(); // �رռ�¼��
					// �ж��Ƿ����
					rs_Q_errand.Open(CRecordset::forwardOnly,
						"select ID from ERRAND where\
						PERSON='" + rs_person.m_ID
						+ "' and START_TIME<#"
						+ LateTime.Format("%Y-%m-%d %H:%M:%S")
						+ "# and END_TIME>#"
						+ EarlyTime.Format("%Y-%m-%d %H:%M:%S")
						+ "#");
					bErrand=(rs_Q_errand.GetRecordCount()>0); // �ж��Ƿ��г����¼
					rs_Q_errand.Close(); // �رռ�¼��
					if(bLeave) // �������ټ�¼
						nLeaveHDay++; // ��ټ�¼��1
					else if(bErrand) // ����г����¼
					{
						nErrandHDay++; // ���������1
						nWorkHour+=nHours[j]; // ���������ۼӹ���ʱ��
					}
					else // �����ϰ�
					{
						WorkStart=LateTime; // ���ù�����ʼʱ��
						WorkEnd=EarlyTime; // ���ù�������ʱ��
						bLate=TRUE; // ��ʼ���ٵ��ж�
						bAbsent=FALSE; // ��ʼ�������ж�
						// �ж��Ƿ�ٵ�
						if(!rs_Q_attend.IsEOF() && // ��¼������
							strTmp1.IsEmpty()) // ��,��һ��GetFieldValue
							rs_Q_attend.GetFieldValue("IO_TIME",strTmp1); // �õ�IO_TIME
						while(!rs_Q_attend.IsEOF()
							&& StrToTime(strTmp1)<=LateTime)
						{// ����ʱ��˳���ж��Ƿ�ٵ�
							// �õ�IN_OUT
							rs_Q_attend.GetFieldValue("IN_OUT",strTmp2);
							bLate=(strTmp2=="O"); // �ж��ϰ�ʱ��ǰ�Ƿ񱨵�
							rs_Q_attend.MoveNext(); // ������һ�����ڼ�¼
							// �õ�IO_TIME
							if(!rs_Q_attend.IsEOF())
								rs_Q_attend.GetFieldValue("IO_TIME",strTmp1);
						}
						// �ж��Ƿ����
						if(bLate) // �ж��Ƿ�ٵ�
						{
							if(!rs_Q_attend.IsEOF() && StrToTime(strTmp1)<EarlyTime)
								WorkStart=StrToTime(strTmp1); // ��¼�ٵ�ʱ��
							else bAbsent=TRUE; // ����°�ǰ��δ������Ϊ����
						}
						bEarly=FALSE;
						// �ж��Ƿ�����
						while(!rs_Q_attend.IsEOF() && StrToTime(strTmp1)<EarlyTime)
						{
							// �õ�IN_OUT
							rs_Q_attend.GetFieldValue("IN_OUT",strTmp2);
							bEarly=(strTmp2=="O"); // �ж��Ƿ�������
							if(bEarly)
							{
								// ������ʱ���¼Ϊ��������ʱ��
								WorkEnd=StrToTime(strTmp1);
							}
							else WorkEnd=EarlyTime; // ���°�ʱ���¼Ϊ��������ʱ��
							rs_Q_attend.MoveNext(); // ������һ�����ڼ�¼
							// �õ�IO_TIME
							if(!rs_Q_attend.IsEOF())
								rs_Q_attend.GetFieldValue("IO_TIME",strTmp1);
						}
						// ������������ӿ���������¼
						if(bAbsent) nAbsentTimes++;
						else
						{
							// ����ٵ������ӳٵ�������¼
							if(bLate) nLateTimes++;
							// ������ˣ��������˴�����¼
							if(bEarly) nEarlyTimes++;
							// ����ʵ�ʹ���ʱ��
							nWorkHour+=(WorkEnd-WorkStart).GetTotalHours();
							if((WorkEnd-WorkStart).GetMinutes()>30)
								nWorkHour++; // ��������
						}

					}
				} // End of �������
			} // End of �Ƿ�����
			TimeStamp+=tp_1; // �ƽ�һ��
		}// �ж��Ƿ񳬳�ͳ�ƽ���ʱ�� ����
		rs_Q_attend.Close(); // �ر�Q_attend��¼��

		// ͳ�ƼӰ�ʱ��
		CRecordset rs_Q_overtime(&Db); // ����Q_overtime��¼��
		rs_Q_overtime.Open(CRecordset::forwardOnly,
			"select sum(WORK_HOURS) as SUM from OVERTIME\
			where PERSON='" + rs_person.m_ID
			+ "' and WORK_DATE>#"
			+ m_STime.Format("%Y-%m-%d %H:%M:%S")
			+ "# and WORK_DATE<#"
			+ m_ETime.Format("%Y-%m-%d %H:%M:%S")
			+ "#");
		if(rs_Q_overtime.GetRecordCount()>0) // �м�¼
		{
			// ��ȡ�Ӱ�ʱ��
			rs_Q_overtime.GetFieldValue("SUM",strTmp);
			sscanf(strTmp,"%d",&nOverHour);
		}
		else nOverHour=0; // �޼�¼
		rs_Q_overtime.Close();
		// �ж��Ƿ����и��¿��ڼ�¼
		CStatisticsRS rs_stat(&Db); // ����ͳ�����ݱ�
		// ���ù��˴�
		rs_stat.m_strFilter="PERSON='" + rs_person.m_ID
			+ "' and YEAR_MONTH='" + m_strTime + "'";
		rs_stat.Open(); // �����ݱ�
		if(rs_stat.GetRecordCount()==0) // �ж��Ƿ��и��·ݿ��ڼ�¼
		{
			// ��ȡ����
			CcounterRS rs_counter(&Db); // �����������
			rs_counter.m_strFilter = "ID='S'"; // ���ù���������ȡ����ֵ
			rs_counter.Open(); // �򿪼�������¼��
			counter=rs_counter.m_COUNTER_VALUE; // ��ȡ����ֵ
			counter++; // ����ֵ��1
			rs_counter.Edit(); // �༭������
			rs_counter.m_COUNTER_VALUE=counter; // ���浱ǰ����
			rs_counter.Update(); // �ύ�޸�
			rs_counter.Close(); // �رռ�������¼��
			// ׷��ͳ�Ƽ�¼
			rs_stat.AddNew();
			rs_stat.m_ID=counter;
			rs_stat.m_YEAR_MONTH=m_strTime;
			rs_stat.m_PERSON=rs_person.m_ID;
			rs_stat.m_WORK_HOUR=nWorkHour;
			rs_stat.m_OVER_HOUR=nOverHour;
			rs_stat.m_LEAVE_HDAY=nLeaveHDay;
			rs_stat.m_ERRAND_HDAY=nErrandHDay;
			rs_stat.m_LATE_TIMES=nLateTimes;
			rs_stat.m_EARLY_TIMES=nEarlyTimes;
			rs_stat.m_ABSENT_TIMES=nAbsentTimes;
			rs_stat.Update(); // �ύ�޸�
		}
		else
		{
			// ��¼�Ѵ����޸�����
			rs_stat.Edit();
			rs_stat.m_WORK_HOUR=nWorkHour;
			rs_stat.m_OVER_HOUR=nOverHour;
			rs_stat.m_LEAVE_HDAY=nLeaveHDay;
			rs_stat.m_ERRAND_HDAY=nErrandHDay;
			rs_stat.m_LATE_TIMES=nLateTimes;
			rs_stat.m_EARLY_TIMES=nEarlyTimes;
			rs_stat.m_ABSENT_TIMES=nAbsentTimes;
			rs_stat.Update(); // �ύ�޸�
		}
		rs_stat.Close(); // �ر����ݱ�
		i++; // ��ͳ��Ա������1
		/*m_cProgress.SetPos(i); // ��ʾͳ�ƽ���*/
		rs_person.MoveNext(); // ������һ��Ա����¼
	}//// ���ζ�ÿ��Ա������ͳ�ƽ���
	rs_person.Close(); // �ر�Ա����
// 	CStatRS rs_stat(&Db); // ����ͳ�����ݱ�
// 	UpdateList(rs_stat); // �����б��
	SetDlgItemText(IDC_PROCRSS,"ͳ�����");
	ShowSRecord();
}
