/*****************************************************************
*�ļ�����			TcpRadarComm.h
*����������	        -
*����������	        -
*��˾����			�п�Ժ������������ҵ�о�Ժ
*��ǰ�汾�ţ�	    v1.0
*
*Copyright? 2009, �п�Ժ������������ҵ�о�Ժ All rights reserved.
*
*����			ʱ��					��ע
*zhangyong		2010-2-1			
*
*˵��
	�����״�--ͨ�Ž�����--���ײ��״����ݽ����࣬SOCKET�����ڡ����Э���ʽ��ο�SPEC
******************************************************************/
// LeuzeSocketComm.h: interface for the CLeuzeSocketComm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LEUZESOCKETCOMM_H__58F35304_378B_4C07_BD9B_5E8BAEBEEF7F__INCLUDED_)
#define AFX_LEUZESOCKETCOMM_H__58F35304_378B_4C07_BD9B_5E8BAEBEEF7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RadarCommunicationBase.h"
#include <vector>
using std::vector;

class CLeuzeSocketComm : public CRadarCommunicationBase  
{
public:
	CLeuzeSocketComm();
	virtual ~CLeuzeSocketComm();
	virtual int  StartRadar(void);
	virtual int	 CloseRadar(void);
	virtual bool GetRawData(DataFrame * pData);
private:
	FILE * m_pFile;//�ļ�ָ��
	SOCKET  m_socket;
	vector<unsigned char> m_rawDataBuff;
	
	int angluarResolution;

	bool findStartTag;	//�Ƿ��ҵ���ʼ��־
	bool findStopTag;	//�Ƿ��ҵ�������־
	
	unsigned char tagBuffer[3];
	int tagBufferNumber;

protected:
	void ClearRawData();
	bool ProcessData(char * recvBuf,int size,DataFrame * pData);
	void ReSetTagBuffer();
	void SetTagBuffer(unsigned char tag);
	bool CheckStartTag();
	bool CheckStopTag();
	bool LoadData(DataFrame *pData);
	int  GetDistance(unsigned char highByte,unsigned char lowByte);

	int GetDataOffset();

	bool CheckSum();
	bool CheckOperation();
	int GetOptionByteNum();
	int GetAngularResolution();


};

#endif // !defined(AFX_LEUZESOCKETCOMM_H__58F35304_378B_4C07_BD9B_5E8BAEBEEF7F__INCLUDED_)