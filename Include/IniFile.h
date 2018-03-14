#ifndef _INI_FILE_H_
#define _INI_FILE_H_
/*
ini�ļ�����
*/
#include <Windows.h>
#include <tchar.h>

class CIniFile
{
public:
	CIniFile(void){}
	virtual ~CIniFile(void){}
public:
	/*
	����������д�������ݵ�ini�ļ���
	������
		szItemName�������
		szKeyName������ļ�������
		nValuesҪ���õ�ֵ
	����ֵ���ɹ�����TRUE,ʧ�ܷ���FALSE
	*/
	BOOL  WriteInt(LPCTSTR szItemName,  LPCTSTR szKeyName,  int nValues)
	{
		BOOL	bRet = FALSE;

		do 
		{
			m_dwLastError = ERROR_INVALID_PARAMETER;

			if (NULL == szItemName)
			{
				break;
			}
			if (NULL == szKeyName)
			{
				break;
			}

			TCHAR	szValues[16] = {0};
			::wsprintf(szValues, _T("%d"), nValues);
			bRet = ::WritePrivateProfileString(szItemName, szKeyName, szValues, m_szFileName);
			if (!bRet)
			{
				m_dwLastError = ::GetLastError();
			}
		} while (0);

		return bRet;
	}

	/*
	����������д�ַ������ݵ�ini�ļ���
	������
		szItemName�������
		szKeyName������ļ�������
		szValuesҪ���õ�ֵ,ΪNULL�����ÿ�ֵ
	����ֵ���ɹ�����TRUE,ʧ�ܷ���FALSE
	*/
	BOOL  WriteStr( LPCTSTR szItemName,  LPCTSTR szKeyName,  LPCTSTR szValues)
	{
		BOOL	bRet = FALSE;

		do 
		{
			m_dwLastError = ERROR_INVALID_PARAMETER;

			if (NULL == szItemName)
			{
				break;
			}
			if (NULL == szKeyName)
			{
				break;
			}

			bRet = ::WritePrivateProfileString(szItemName, szKeyName, szValues, m_szFileName);
			if (!bRet)
			{
				m_dwLastError = ::GetLastError();
			}
		} while (0);

		return bRet;
	}

	/*
	������������ȡָ���ָ����������
	������
		szItemName�������
		szKeyName������ļ�������
	����ֵ������������򷵻ؼ���ֵ�������򷵻ؿ��ַ���
	*/
	LPCTSTR  GetStr( LPCTSTR szItemName,  LPCTSTR szKeyName)
	{
		do 
		{
			m_dwLastError = ERROR_INVALID_PARAMETER;

			if (NULL == szItemName)
			{
				break;
			}
			if (NULL == szKeyName)
			{
			}
		} while (0);

		GetPrivateProfileString(szItemName, szKeyName, _T(""), m_szValues, sizeof(m_szValues), m_szFileName);

		return m_szValues;
	}

	/*
	������������ȡָ���ָ����������
	������
		szItemName�������
		szKeyName������ļ�������
	����ֵ������������򷵻ؼ���ֵ�������򷵻ؿ��ַ���
	*/
	int  GetInt( LPCTSTR szItemName,  LPCTSTR szKeyName)
	{
		int		nRet = 0;

		do 
		{
			if (NULL == szItemName)
			{
				break;
			}
			if (NULL == szKeyName)
			{
				break;
			}

			nRet = GetPrivateProfileInt(szItemName, szKeyName, 0, m_szFileName);

		} while (0);

		return nRet;
	}

	/*
	��������������INI�ļ��������ļ����������ļ���ȫ·��
	������szFileName�ļ���
	����ֵ����
	*/
	void  SetFileName( LPCTSTR szFileName)
	{
		if (szFileName)
		{
			lstrcpyn(m_szFileName, szFileName, sizeof(m_szFileName));
		}
	}

	/*
	������������ȡ��������ʱ��Ĵ�����
	��������
	����ֵ�������Ĵ�����
	*/
	DWORD  GetLastError()
	{
		return m_dwLastError;
	}
private:
	TCHAR	m_szFileName[MAX_PATH];//ini�ļ�����
	TCHAR	m_szValues[MAX_PATH];//������Ŵ�INI�л�ȡ��������
	DWORD	m_dwLastError;//������
};

#endif