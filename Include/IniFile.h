#ifndef _INI_FILE_H_
#define _INI_FILE_H_
/*
ini文件操作
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
	函数描述：写整形数据到ini文件中
	参数：
		szItemName项的名称
		szKeyName项下面的键的名称
		nValues要设置的值
	返回值：成功返回TRUE,失败返回FALSE
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
	函数描述：写字符串数据到ini文件中
	参数：
		szItemName项的名称
		szKeyName项下面的键的名称
		szValues要设置的值,为NULL则设置空值
	返回值：成功返回TRUE,失败返回FALSE
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
	函数描述：获取指定项，指定键的数据
	参数：
		szItemName项的名称
		szKeyName项下面的键的名称
	返回值：如果键存在则返回键的值，不存则返回空字符串
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
	函数描述：获取指定项，指定键的数据
	参数：
		szItemName项的名称
		szKeyName项下面的键的名称
	返回值：如果键存在则返回键的值，不存则返回空字符串
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
	函数描述：设置INI文件名，该文件名必须是文件的全路径
	参数：szFileName文件名
	返回值：无
	*/
	void  SetFileName( LPCTSTR szFileName)
	{
		if (szFileName)
		{
			lstrcpyn(m_szFileName, szFileName, sizeof(m_szFileName));
		}
	}

	/*
	函数描述：获取函数出错时候的错误码
	参数：无
	返回值：函数的错误码
	*/
	DWORD  GetLastError()
	{
		return m_dwLastError;
	}
private:
	TCHAR	m_szFileName[MAX_PATH];//ini文件名称
	TCHAR	m_szValues[MAX_PATH];//用来存放从INI中获取到的数据
	DWORD	m_dwLastError;//错误码
};

#endif