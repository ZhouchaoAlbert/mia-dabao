#ifndef __EVENT_H__
#define __EVENT_H__

#include <set>
#include <list>
#include <map>
#include <windows.h>

namespace event{


/***********************************互斥对象**************************************/
class  mutex  
{
public:
	mutex(){ ::InitializeCriticalSection(&m_CritSec); }
	virtual ~mutex(){ ::DeleteCriticalSection(&m_CritSec); }
public:
	void lock(){ EnterCriticalSection(&m_CritSec); }
	void unlock(){ LeaveCriticalSection(&m_CritSec); }
protected:
    CRITICAL_SECTION m_CritSec;
};
//end

/***********************************连接参数*************************************/
class conn_base0 //0个参数
{
public:
	virtual ~conn_base0(){}
	virtual void * get_object() const = 0;
	virtual void run() = 0;
	virtual void release() = 0;
};

template<class type>
class conn_base1 //1个参数
{
public:
	virtual ~conn_base1(){}
	virtual void * get_object() const = 0;
	virtual void run(type a1) = 0;
	virtual void release() = 0;
};

template<class type1, class type2>
class conn_base2 //2个参数
{
public:
	virtual ~conn_base2(){}
	virtual void * get_object() const = 0;
	virtual void run(type1 a1, type2 a2) = 0;
	virtual void release() = 0;
};

template<class type1, class type2, class type3>
class conn_base3 //3个参数
{
public:
	virtual ~conn_base3(){}
	virtual void * get_object() const = 0;
	virtual void run(type1 a1, type2 a2, type3 a3) = 0;
	virtual void release() = 0;
};

template<class type1, class type2, class type3, class type4>
class conn_base4 //4个参数
{
public:
	virtual ~conn_base4(){}
	virtual void * get_object() const = 0;
	virtual void run(type1 a1, type2 a2, type3 a3, type4 a4) = 0;
	virtual void release() = 0;
};

template<class type1, class type2, class type3, class type4, class type5>
class conn_base5 //5个参数
{
public:
	virtual ~conn_base5(){}
	virtual void * get_object() const = 0;
	virtual void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5) = 0;
	virtual void release() = 0;
};

template<class type1, class type2, class type3, class type4, class type5, class type6>
class conn_base6 //6个参数
{
public:
	virtual ~conn_base6(){}
	virtual void * get_object() const = 0;
	virtual void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6) = 0;
	virtual void release() = 0;
};

template<class type1, class type2, class type3, class type4, class type5, class type6, class type7>
class conn_base7 //7个参数
{
public:
	virtual ~conn_base7(){}
	virtual void * get_object() const = 0;
	virtual void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6, type7 a7) = 0;
	virtual void release() = 0;
};
//end

/***********************************连接参数具体实现*************************************/
template<class class_type>
class connect0 : public conn_base0 //0个参数
{
public:
	connect0(class_type* pobject, void (class_type::*pmemfun)()) { m_pobject = pobject; m_pmemfun = pmemfun; }
	virtual void run(){ (m_pobject->*m_pmemfun)(); }
	virtual void * get_object() const{ return m_pobject; }
	virtual void release() { delete this; }
private:
	class_type* m_pobject;
	void (class_type::* m_pmemfun)();
};

template<class class_type, class type>
class connect1 : public conn_base1<type>//1个参数
{
public:
	connect1(class_type* pobject, void (class_type::*pmemfun)(type)) { m_pobject = pobject; m_pmemfun = pmemfun; }
	virtual void run(type a1){ (m_pobject->*m_pmemfun)(a1); }
	virtual void * get_object() const{ return m_pobject; }
	virtual void release() { delete this; }
private:
	class_type* m_pobject;
	void (class_type::* m_pmemfun)(type);
};

template<class class_type, class type1, class type2>
class connect2 : public conn_base2<type1, type2>//2个参数
{
public:
	connect2(class_type* pobject, void (class_type::*pmemfun)(type1, type2)) { m_pobject = pobject; m_pmemfun = pmemfun; }
	virtual void run(type1 a1, type2 a2){ (m_pobject->*m_pmemfun)(a1, a2); }
	virtual void * get_object() const{ return m_pobject; }
	virtual void release() { delete this; }
private:
	class_type* m_pobject;
	void (class_type::* m_pmemfun)(type1, type2);
};

template<class class_type, class type1, class type2, class type3>
class connect3 : public conn_base3<type1, type2, type3>//3个参数
{
public:
	connect3(class_type* pobject, void (class_type::*pmemfun)(type1, type2, type3)) { m_pobject = pobject; m_pmemfun = pmemfun; }
	virtual void run(type1 a1, type2 a2, type3 a3){ (m_pobject->*m_pmemfun)(a1, a2, a3); }
	virtual void * get_object() const{ return m_pobject; }
	virtual void release() { delete this; }
private:
	class_type* m_pobject;
	void (class_type::* m_pmemfun)(type1, type2, type3);
};

template<class class_type, class type1, class type2, class type3, class type4>
class connect4 : public conn_base4<type1, type2, type3, type4>//4个参数
{
public:
	connect4(class_type* pobject, void (class_type::*pmemfun)(type1, type2, type3, type4)) { m_pobject = pobject; m_pmemfun = pmemfun; }
	virtual void run(type1 a1, type2 a2, type3 a3, type4 a4){ (m_pobject->*m_pmemfun)(a1, a2, a3, a4); }
	virtual void * get_object() const{ return m_pobject; }
	virtual void release() { delete this; }
private:
	class_type* m_pobject;
	void (class_type::* m_pmemfun)(type1, type2, type3, type4);
};

template<class class_type, class type1, class type2, class type3, class type4, class type5>
class connect5 : public conn_base5<type1, type2, type3, type4, type5>//5个参数
{
public:
	connect5(class_type* pobject, void (class_type::*pmemfun)(type1, type2, type3, type4, type5)) { m_pobject = pobject; m_pmemfun = pmemfun; }
	virtual void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5){ (m_pobject->*m_pmemfun)(a1, a2, a3, a4, a5); }
	virtual void * get_object() const{ return m_pobject; }
	virtual void release() { delete this; }
private:
	class_type* m_pobject;
	void (class_type::* m_pmemfun)(type1, type2, type3, type4, type5);
};

template<class class_type, class type1, class type2, class type3, class type4, class type5, class type6>
class connect6 : public conn_base6<type1, type2, type3, type4, type5, type6>//6个参数
{
public:
	connect6(class_type* pobject, void (class_type::*pmemfun)(type1, type2, type3, type4, type5, type6)) { m_pobject = pobject; m_pmemfun = pmemfun; }
	virtual void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6){ (m_pobject->*m_pmemfun)(a1, a2, a3, a4, a5, a6); }
	virtual void * get_object() const{ return m_pobject; }
	virtual void release() { delete this; }
private:
	class_type* m_pobject;
	void (class_type::* m_pmemfun)(type1, type2, type3, type4, type5, type6);
};

template<class class_type, class type1, class type2, class type3, class type4, class type5, class type6, class type7>
class connect7 : public conn_base7<type1, type2, type3, type4, type5, type6, type7>//7个参数
{
public:
	connect7(class_type* pobject, void (class_type::*pmemfun)(type1, type2, type3, type4, type5, type6, type7)) { m_pobject = pobject; m_pmemfun = pmemfun; }
	virtual void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6, type7 a7){ (m_pobject->*m_pmemfun)(a1, a2, a3, a4, a5, a6, a7); }
	virtual void * get_object() const{ return m_pobject; }
	virtual void release() { delete this; }
private:
	class_type* m_pobject;
	void (class_type::* m_pmemfun)(type1, type2, type3, type4, type5, type6, type7);
};

/***********************************连接参数具体实现*************************************/
class common_signal0 //普通0个参数
{
public:
	common_signal0()
	{

	}

	~common_signal0()
	{
		disconnect_all();
	}

	template<class class_type>
	void connect(class_type* pclass, void (class_type::*pmemfun)())
	{
		m_mutex.lock();
		connect0<class_type>* conn =
			new connect0<class_type>(pclass, pmemfun);
		m_connected_slots.push_back(conn);
		m_mutex.unlock();
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if ((*it)->get_object() == pclass)
			{
				(*it)->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			(*it)->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run()
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			(*it)->run();
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()()
	{
		run();
	}
protected:
	common_signal0(const common_signal0 & s){}
	void operator =(const common_signal0 & s){}
protected:
	typedef std::list<conn_base0 *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type>
class common_signal1 //普通1个参数
{
public:
	common_signal1()
	{

	}

	~common_signal1()
	{
		disconnect_all();
	}

	template<class class_type>
	void connect(class_type* pclass, void (class_type::*pmemfun)(type))
	{
		m_mutex.lock();
		connect1<class_type, type>* conn =
			new connect1<class_type, type>(pclass, pmemfun);
		m_connected_slots.push_back(conn);
		m_mutex.unlock();
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if ((*it)->get_object() == pclass)
			{
				(*it)->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			(*it)->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type a1)
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			(*it)->run(a1);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type a1)
	{
		run(a1);
	}
protected:
	common_signal1(const common_signal1<type>& s){}
	void operator =(const common_signal1<type>& s){}
protected:
	typedef std::list<conn_base1<type> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2>
class common_signal2 //普通2个参数
{
public:
	common_signal2()
	{

	}

	~common_signal2()
	{
		disconnect_all();
	}

	template<class class_type>
	void connect(class_type* pclass, void (class_type::*pmemfun)(type1, type2))
	{
		m_mutex.lock();
		connect2<class_type, type1, type2>* conn =
			new connect2<class_type, type1, type2>(pclass, pmemfun);
		m_connected_slots.push_back(conn);
		m_mutex.unlock();
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if ((*it)->get_object() == pclass)
			{
				(*it)->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			(*it)->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2)
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			(*it)->run(a1, a2);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2)
	{
		run(a1, a2);
	}
protected:
	common_signal2(const common_signal2<type1, type2>& s){}
	void operator =(const common_signal2<type1, type2>& s){}
protected:
	typedef std::list<conn_base2<type1, type2> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3>
class common_signal3 //普通3个参数
{
public:
	common_signal3()
	{

	}

	~common_signal3()
	{
		disconnect_all();
	}

	template<class class_type>
	void connect(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3))
	{
		m_mutex.lock();
		connect3<class_type, type1, type2, type3> *conn =
			new connect3<class_type, type1, type2, type3>(pclass, pmemfun);
		m_connected_slots.push_back(conn);
		m_mutex.unlock();
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if ((*it)->get_object() == pclass)
			{
				(*it)->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			(*it)->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3)
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			(*it)->run(a1, a2, a3);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3)
	{
		run(a1, a2, a3);
	}
protected:
	common_signal3(const common_signal3<type1, type2, type3>& s){}
	void operator =(const common_signal3<type1, type2, type3>& s){}
protected:
	typedef std::list<conn_base3<type1, type2, type3> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4>
class common_signal4 //普通4个参数
{
public:
	common_signal4()
	{

	}

	~common_signal4()
	{
		disconnect_all();
	}

	template<class class_type>
	void connect(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4))
	{
		m_mutex.lock();
		connect4<class_type, type1, type2, type3, type4> *conn =
			new connect4<class_type, type1, type2, type3, type4>(pclass, pmemfun);
		m_connected_slots.push_back(conn);
		m_mutex.unlock();
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if ((*it)->get_object() == pclass)
			{
				(*it)->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			(*it)->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4)
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			(*it)->run(a1, a2, a3, a4);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4)
	{
		run(a1, a2, a3, a4);
	}
protected:
	common_signal4(const common_signal4<type1, type2, type3, type4>& s){}
	void operator =(const common_signal4<type1, type2, type3, type4>& s){}
protected:
	typedef std::list<conn_base4<type1, type2, type3, type4> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4, class type5>
class common_signal5 //普通5个参数
{
public:
	common_signal5()
	{

	}

	~common_signal5()
	{
		disconnect_all();
	}

	template<class class_type>
	void connect(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4, type5))
	{
		m_mutex.lock();
		connect5<class_type, type1, type2, type3, type4, type5> *conn =
			new connect5<class_type, type1, type2, type3, type4, type5>(pclass, pmemfun);
		m_connected_slots.push_back(conn);
		m_mutex.unlock();
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if ((*it)->get_object() == pclass)
			{
				(*it)->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			(*it)->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5)
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			(*it)->run(a1, a2, a3, a4, a5);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5)
	{
		run(a1, a2, a3, a4, a5);
	}
protected:
	common_signal5(const common_signal5<type1, type2, type3, type4, type5>& s){}
	void operator =(const common_signal5<type1, type2, type3, type4, type5>& s){}
protected:
	typedef std::list<conn_base5<type1, type2, type3, type4, type5> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4, class type5, class type6>
class common_signal6 //普通6个参数
{
public:
	common_signal6()
	{

	}

	~common_signal6()
	{
		disconnect_all();
	}

	template<class class_type>
	void connect(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4, type5, type6))
	{
		m_mutex.lock();
		connect6<class_type, type1, type2, type3, type4, type5, type6> *conn =
			new connect6<class_type, type1, type2, type3, type4, type5, type6>(pclass, pmemfun);
		m_connected_slots.push_back(conn);
		m_mutex.unlock();
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if ((*it)->get_object() == pclass)
			{
				(*it)->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			(*it)->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6)
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			(*it)->run(a1, a2, a3, a4, a5, a6);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6)
	{
		run(a1, a2, a3, a4, a5, a6);
	}
protected:
	common_signal6(const common_signal6<type1, type2, type3, type4, type5, type6>& s){}
	void operator =(const common_signal6<type1, type2, type3, type4, type5, type6>& s){}
protected:
	typedef std::list<conn_base6<type1, type2, type3, type4, type5, type6> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4, class type5, class type6, class type7>
class common_signal7 //普通7个参数
{
public:
	common_signal7()
	{

	}

	~common_signal7()
	{
		disconnect_all();
	}

	template<class class_type>
	void connect(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4, type5, type6, type7))
	{
		m_mutex.lock();
		connect7<class_type, type1, type2, type3, type4, type5, type6, type7> *conn =
			new connect7<class_type, type1, type2, type3, type4, type5, type6, type7>(pclass, pmemfun);
		m_connected_slots.push_back(conn);
		m_mutex.unlock();
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if ((*it)->get_object() == pclass)
			{
				(*it)->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			(*it)->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6, type7 a7)
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			(*it)->run(a1, a2, a3, a4, a5, a6, a7);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6, type7 a7)
	{
		run(a1, a2, a3, a4, a5, a6, a7);
	}
protected:
	common_signal7(const common_signal7<type1, type2, type3, type4, type5, type6, type7>& s){}
	void operator =(const common_signal7<type1, type2, type3, type4, type5, type6, type7>& s){}
protected:
	typedef std::list<conn_base7<type1, type2, type3, type4, type5, type6, type7> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

//有顺序
class order_signal0 //顺序0个参数
{
public:
	order_signal0()
	{

	}

	~order_signal0()
	{
		disconnect_all();
	}

	template<class class_type>
	bool connect(int nOrder, class_type* pclass, void (class_type::*pmemfun)())
	{
		bool bRet = false;
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.find(nOrder);
		if (it == m_connected_slots.end())
		{
			connect0<class_type>* conn =
				new connect0<class_type>(pclass, pmemfun);
			m_connected_slots[nOrder] = conn;
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if (it->second->get_object() == pclass)
			{
				it->second->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			it->second->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run()
	{
		m_mutex.lock();
        connect_list::const_iterator itNext, it = m_connected_slots.begin();
        connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			it->second->run();
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()()
	{
		run();
	}
protected:
	order_signal0(const order_signal0 & s){}
	void operator =(const order_signal0 & s){}
protected:
	typedef std::map<int, conn_base0 *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type>
class order_signal1 //顺序1个参数
{
public:
	order_signal1()
	{

	}

	~order_signal1()
	{
		disconnect_all();
	}

	template<class class_type>
	bool connect(int nOrder, class_type* pclass, void (class_type::*pmemfun)(type))
	{
		bool bRet = false;
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.find(nOrder);
		if (it == m_connected_slots.end())
		{
			connect1<class_type, type>* conn =
				new connect1<class_type, type>(pclass, pmemfun);
			m_connected_slots[nOrder] = conn;
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if (it->second->get_object() == pclass)
			{
				it->second->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			it->second->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type a1)
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while(it != itEnd)
		{
			itNext = it;
			++itNext;
			it->second->run(a1);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type a1)
	{
		run(a1);
	}
protected:
	order_signal1(const order_signal1<type>& s){}
	void operator =(const order_signal1<type>& s){}
protected:
	typedef std::map<int, conn_base1<type> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2>
class order_signal2 //顺序2个参数
{
public:
	order_signal2()
	{

	}

	~order_signal2()
	{
		disconnect_all();
	}

	template<class class_type>
	bool connect(int nOrder, class_type* pclass, void (class_type::*pmemfun)(type1, type2))
	{
		bool bRet = false;
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.find(nOrder);
		if (it == m_connected_slots.end())
		{
			connect2<class_type, type1, type2>* conn =
				new connect2<class_type, type1, type2>(pclass, pmemfun);
			m_connected_slots[nOrder] = conn;
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if (it->second->get_object() == pclass)
			{
				it->second->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			it->second->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2)
	{
		m_mutex.lock();
        connect_list::const_iterator itNext, it = m_connected_slots.begin();
        connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			it->second->run(a1, a2);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2)
	{
		run(a1, a2);
	}
protected:
	order_signal2(const order_signal2<type1, type2>& s){}
	void operator =(const order_signal2<type1, type2>& s){}
protected:
	typedef std::map<int, conn_base2<type1, type2> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3>
class order_signal3 //顺序3个参数
{
public:
	order_signal3()
	{

	}

	~order_signal3()
	{
		disconnect_all();
	}

	template<class class_type>
	bool connect(int nOrder, class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3))
	{
		bool bRet = false;
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.find(nOrder);
		if (it == m_connected_slots.end())
		{
			connect3<class_type, type1, type2, type3>* conn =
				new connect3<class_type, type1, type2, type3>(pclass, pmemfun);
			m_connected_slots[nOrder] = conn;
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if (it->second->get_object() == pclass)
			{
				it->second->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			it->second->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3)
	{
		m_mutex.lock();
        connect_list::const_iterator itNext, it = m_connected_slots.begin();
        connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			it->second->run(a1, a2, a3);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3)
	{
		run(a1, a2, a3);
	}
protected:
	order_signal3(const order_signal3<type1, type2, type3>& s){}
	void operator =(const order_signal3<type1, type2, type3>& s){}
protected:
	typedef std::map<int, conn_base3<type1, type2, type3> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4>
class order_signal4 //顺序4个参数
{
public:
	order_signal4()
	{

	}

	~order_signal4()
	{
		disconnect_all();
	}

	template<class class_type>
	bool connect(int nOrder, class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4))
	{
		bool bRet = false;
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.find(nOrder);
		if (it == m_connected_slots.end())
		{
			connect4<class_type, type1, type2, type3, type4>* conn =
				new connect4<class_type, type1, type2, type3, type4>(pclass, pmemfun);
			m_connected_slots[nOrder] = conn;
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if (it->second->get_object() == pclass)
			{
				it->second->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			it->second->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4)
	{
		m_mutex.lock();
        connect_list::const_iterator itNext, it = m_connected_slots.begin();
        connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			it->second->run(a1, a2, a3, a4);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4)
	{
		run(a1, a2, a3, a4);
	}
protected:
	order_signal4(const order_signal4<type1, type2, type3, type4>& s){}
	void operator =(const order_signal4<type1, type2, type3, type4>& s){}
protected:
	typedef std::map<int, conn_base4<type1, type2, type3, type4> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4, class type5>
class order_signal5 //顺序5个参数
{
public:
	order_signal5()
	{

	}

	~order_signal5()
	{
		disconnect_all();
	}

	template<class class_type>
	bool connect(int nOrder, class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4, type5))
	{
		bool bRet = false;
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.find(nOrder);
		if (it == m_connected_slots.end())
		{
			connect5<class_type, type1, type2, type3, type4, type5>* conn =
				new connect5<class_type, type1, type2, type3, type4, type5>(pclass, pmemfun);
			m_connected_slots[nOrder] = conn;
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if (it->second->get_object() == pclass)
			{
				it->second->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			it->second->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5)
	{
		m_mutex.lock();
        connect_list::const_iterator itNext, it = m_connected_slots.begin();
        connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			it->second->run(a1, a2, a3, a4, a5);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5)
	{
		run(a1, a2, a3, a4, a5);
	}
protected:
	order_signal5(const order_signal5<type1, type2, type3, type4, type5>& s){}
	void operator =(const order_signal5<type1, type2, type3, type4, type5>& s){}
protected:
	typedef std::map<int, conn_base5<type1, type2, type3, type4, type5> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4, class type5, class type6>
class order_signal6 //顺序6个参数
{
public:
	order_signal6()
	{

	}

	~order_signal6()
	{
		disconnect_all();
	}

	template<class class_type>
	bool connect(int nOrder, class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4, type5, type6))
	{
		bool bRet = false;
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.find(nOrder);
		if (it == m_connected_slots.end())
		{
			connect6<class_type, type1, type2, type3, type4, type5, type6>* conn =
				new connect6<class_type, type1, type2, type3, type4, type5, type6>(pclass, pmemfun);
			m_connected_slots[nOrder] = conn;
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if (it->second->get_object() == pclass)
			{
				it->second->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			it->second->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6)
	{
		m_mutex.lock();
        connect_list::const_iterator itNext, it = m_connected_slots.begin();
        connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			it->second->run(a1, a2, a3, a4, a5, a6);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6)
	{
		run(a1, a2, a3, a4, a5, a6);
	}
protected:
	order_signal6(const order_signal6<type1, type2, type3, type4, type5, type6>& s){}
	void operator =(const order_signal6<type1, type2, type3, type4, type5, type6>& s){}
protected:
	typedef std::map<int, conn_base6<type1, type2, type3, type4, type5, type6> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4, class type5, class type6, class type7>
class order_signal7 //顺序7个参数
{
public:
	order_signal7()
	{

	}

	~order_signal7()
	{
		disconnect_all();
	}

	template<class class_type>
	bool connect(int nOrder, class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4, type5, type6, type7))
	{
		bool bRet = false;
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.find(nOrder);
		if (it == m_connected_slots.end())
		{
			connect7<class_type, type1, type2, type3, type4, type5, type6, type7>* conn =
				new connect7<class_type, type1, type2, type3, type4, type5, type6, type7>(pclass, pmemfun);
			m_connected_slots[nOrder] = conn;
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void disconnect(class_type* pclass)
	{
		m_mutex.lock();
		connect_list::iterator it = m_connected_slots.begin();
		connect_list::iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			if (it->second->get_object() == pclass)
			{
				it->second->release();
				m_connected_slots.erase(it);
				return;
			}
			++it;
		}
		m_mutex.unlock();
	}

	void disconnect_all()
	{
		m_mutex.lock();
		connect_list::const_iterator it = m_connected_slots.begin();
		connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			it->second->release();
			++it;
		}
		m_connected_slots.erase(m_connected_slots.begin(), m_connected_slots.end());
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6, type7 a7)
	{
		m_mutex.lock();
		connect_list::const_iterator itNext, it = m_connected_slots.begin();
        connect_list::const_iterator itEnd = m_connected_slots.end();
		while (it != itEnd)
		{
			itNext = it;
			++itNext;
			it->second->run(a1, a2, a3, a4, a5, a6, a7);
			it = itNext;
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6, type7 a7)
	{
		run(a1, a2, a3, a4, a5, a6);
	}
protected:
	order_signal7(const order_signal7<type1, type2, type3, type4, type5, type6, type7>& s){}
	void operator =(const order_signal7<type1, type2, type3, type4, type5, type6, type7>& s){}
protected:
	typedef std::map<int, conn_base7<type1, type2, type3, type4, type5, type6, type7> *>  connect_list;
	connect_list m_connected_slots;
	mutex m_mutex;
};

//单对单
class alone_signal0 //单对单0个参数
{
public:
	alone_signal0()
	{
		m_conn = NULL;
	}

	~alone_signal0()
	{
		if (m_conn)
		{
			m_conn->release();
			m_conn = NULL;
		}
	}

	template<class class_type>
	bool bind(class_type* pclass, void (class_type::*pmemfun)())
	{
		bool bRet = false;
		m_mutex.lock();
		if (m_conn == NULL)
		{
			m_conn = new connect0<class_type>(pclass, pmemfun);
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void unbind(class_type* pclass)
	{
		m_mutex.lock();
		if (m_conn &&m_conn->get_object() == pclass)
		{
			m_conn->release();
			m_conn = NULL;
		}
		m_mutex.unlock();
	}

	void run()
	{
		m_mutex.lock();
		if (m_conn)
		{
			m_conn->run();
		}
		m_mutex.unlock();
	}

	void operator()()
	{
		run();
	}
protected:
	alone_signal0(const alone_signal0 & s){}
	void operator =(const alone_signal0 & s){}
protected:
	conn_base0 * m_conn;
	mutex m_mutex;
};

template<class type>
class alone_signal1 //单对单1个参数
{
public:
	alone_signal1()
	{
		m_conn = NULL;
	}

	~alone_signal1()
	{
		if (m_conn)
		{
			m_conn->release();
			m_conn = NULL;
		}
	}

	template<class class_type>
	bool bind(class_type* pclass, void (class_type::*pmemfun)(type))
	{
		bool bRet = false;
		m_mutex.lock();
		if (m_conn == NULL)
		{
			m_conn = new connect1<class_type, type>(pclass, pmemfun);
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void unbind(class_type* pclass)
	{
		m_mutex.lock();
		if (m_conn &&m_conn->get_object() == pclass)
		{
			m_conn->release();
			m_conn = NULL;
		}
		m_mutex.unlock();
	}

	void run(type a)
	{
		m_mutex.lock();
		if (m_conn)
		{
			m_conn->run(a);
		}
		m_mutex.unlock();
	}

	void operator()(type a)
	{
		run(a);
	}
protected:
	alone_signal1(const alone_signal1 & s){}
	void operator =(const alone_signal1 & s){}
protected:
	conn_base1<type> * m_conn;
	mutex m_mutex;
};

template<class type1, class type2>
class alone_signal2 //单对单2个参数
{
public:
	alone_signal2()
	{
		m_conn = NULL;
	}

	~alone_signal2()
	{
		if (m_conn)
		{
			m_conn->release();
			m_conn = NULL;
		}
	}

	template<class class_type>
	bool bind(class_type* pclass, void (class_type::*pmemfun)(type1, type2))
	{
		bool bRet = false;
		m_mutex.lock();
		if (m_conn == NULL)
		{
			m_conn = new connect2<class_type, type1, type2>(pclass, pmemfun);
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void unbind(class_type* pclass)
	{
		m_mutex.lock();
		if (m_conn &&m_conn->get_object() == pclass)
		{
			m_conn->release();
			m_conn = NULL;
		}
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2)
	{
		m_mutex.lock();
		if (m_conn)
		{
			m_conn->run(a1, a2);
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2)
	{
		run(a1, a2);
	}
protected:
	alone_signal2(const alone_signal2 & s){}
	void operator =(const alone_signal2 & s){}
protected:
	conn_base2<type1, type2> * m_conn;
	mutex m_mutex;
};

template<class type1, class type2, class type3>
class alone_signal3 //单对单3个参数
{
public:
	alone_signal3()
	{
		m_conn = NULL;
	}

	~alone_signal3()
	{
		if (m_conn)
		{
			m_conn->release();
			m_conn = NULL;
		}
	}

	template<class class_type>
	bool bind(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3))
	{
		bool bRet = false;
		m_mutex.lock();
		if (m_conn == NULL)
		{
			m_conn = new connect3<class_type, type1, type2, type3>(pclass, pmemfun);
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void unbind(class_type* pclass)
	{
		m_mutex.lock();
		if (m_conn &&m_conn->get_object() == pclass)
		{
			m_conn->release();
			m_conn = NULL;
		}
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3)
	{
		m_mutex.lock();
		if (m_conn)
		{
			m_conn->run(a1, a2, a3);
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3)
	{
		run(a1, a2, a3);
	}
protected:
	alone_signal3(const alone_signal3 & s){}
	void operator =(const alone_signal3 & s){}
protected:
	conn_base3<type1, type2, type3> * m_conn;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4>
class alone_signal4 //单对单4个参数
{
public:
	alone_signal4()
	{
		m_conn = NULL;
	}

	~alone_signal4()
	{
		if (m_conn)
		{
			m_conn->release();
			m_conn = NULL;
		}
	}

	template<class class_type>
	bool bind(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4))
	{
		bool bRet = false;
		m_mutex.lock();
		if (m_conn == NULL)
		{
			m_conn = new connect4<class_type, type1, type2, type3, type4>(pclass, pmemfun);
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void unbind(class_type* pclass)
	{
		m_mutex.lock();
		if (m_conn &&m_conn->get_object() == pclass)
		{
			m_conn->release();
			m_conn = NULL;
		}
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4)
	{
		m_mutex.lock();
		if (m_conn)
		{
			m_conn->run(a1, a2, a3, a4);
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4)
	{
		run(a1, a2, a3, a4);
	}
protected:
	alone_signal4(const alone_signal4 & s){}
	void operator =(const alone_signal4 & s){}
protected:
	conn_base4<type1, type2, type3, type4>  * m_conn;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4, class type5>
class alone_signal5 //单对单5个参数
{
public:
	alone_signal5()
	{
		m_conn = NULL;
	}

	~alone_signal5()
	{
		if (m_conn)
		{
			m_conn->release();
			m_conn = NULL;
		}
	}

	template<class class_type>
	bool bind(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4, type5))
	{
		bool bRet = false;
		m_mutex.lock();
		if (m_conn == NULL)
		{
			m_conn = new connect5<class_type, type1, type2, type3, type4, type5>(pclass, pmemfun);
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void unbind(class_type* pclass)
	{
		m_mutex.lock();
		if (m_conn &&m_conn->get_object() == pclass)
		{
			m_conn->release();
			m_conn = NULL;
		}
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5)
	{
		m_mutex.lock();
		if (m_conn)
		{
			m_conn->run(a1, a2, a3, a4, a5);
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5)
	{
		run(a1, a2, a3, a4, a5);
	}
protected:
	alone_signal5(const alone_signal5 & s){}
	void operator =(const alone_signal5 & s){}
protected:
	conn_base5<type1, type2, type3, type4, type5> * m_conn;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4, class type5, class type6>
class alone_signal6 //单对单6个参数
{
public:
	alone_signal6()
	{
		m_conn = NULL;
	}

	~alone_signal6()
	{
		if (m_conn)
		{
			m_conn->release();
			m_conn = NULL;
		}
	}

	template<class class_type>
	bool bind(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4, type5, type6))
	{
		bool bRet = false;
		m_mutex.lock();
		if (m_conn == NULL)
		{
			m_conn = new connect6<class_type, type1, type2, type3, type4, type5, type6>(pclass, pmemfun);
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void unbind(class_type* pclass)
	{
		m_mutex.lock();
		if (m_conn &&m_conn->get_object() == pclass)
		{
			m_conn->release();
			m_conn = NULL;
		}
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6)
	{
		m_mutex.lock();
		if (m_conn)
		{
			m_conn->run(a1, a2, a3, a4, a5, a6);
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6)
	{
		run(a1, a2, a3, a4, a5, a6);
	}
protected:
	alone_signal6(const alone_signal6 & s){}
	void operator =(const alone_signal6 & s){}
protected:
	conn_base6<type1, type2, type3, type4, type5, type6> * m_conn;
	mutex m_mutex;
};

template<class type1, class type2, class type3, class type4, class type5, class type6, class type7>
class alone_signal7 //单对单7个参数
{
public:
	alone_signal7()
	{
		m_conn = NULL;
	}

	~alone_signal7()
	{
		if (m_conn)
		{
			m_conn->release();
			m_conn = NULL;
		}
	}

	template<class class_type>
	bool bind(class_type* pclass, void (class_type::*pmemfun)(type1, type2, type3, type4, type5, type6, type7))
	{
		bool bRet = false;
		m_mutex.lock();
		if (m_conn == NULL)
		{
			m_conn = new connect7<class_type, type1, type2, type3, type4, type5, type6, type7>(pclass, pmemfun);
			bRet = true;
		}
		m_mutex.unlock();
		return bRet;
	}

	template<class class_type>
	void unbind(class_type* pclass)
	{
		m_mutex.lock();
		if (m_conn &&m_conn->get_object() == pclass)
		{
			m_conn->release();
			m_conn = NULL;
		}
		m_mutex.unlock();
	}

	void run(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6, type7 a7)
	{
		m_mutex.lock();
		if (m_conn)
		{
			m_conn->run(a1, a2, a3, a4, a5, a6, a7);
		}
		m_mutex.unlock();
	}

	void operator()(type1 a1, type2 a2, type3 a3, type4 a4, type5 a5, type6 a6, type7 a7)
	{
		run(a1, a2, a3, a4, a5, a6, a7);
	}
protected:
	alone_signal7(const alone_signal7 & s){}
	void operator =(const alone_signal7 & s){}
protected:
	conn_base7<type1, type2, type3, type4, type5, type6, type7>  * m_conn;
	mutex m_mutex;
};

}

#endif