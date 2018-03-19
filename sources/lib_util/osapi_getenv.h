#ifndef osapi_getenv_h
#define osapi_getenv_h

/*
	�Ķ��ѿ�������
	�б������ѿ����ʤ����nullʸ����(nullptr�ǤϤʤ�)���֤�
*/

#ifdef _WIN32
#include "osapi_mbs_wcs.h"
namespace osapi {
std::TSTRING getenv(const std::TSTRING& name);
} // namespace osapi

#else	// unix
#include <string>
namespace osapi {
std::string getenv(const std::string& name);
} // namespace osapi
#endif


#endif /* !osapi_getenv_h */
