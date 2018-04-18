#ifndef osapi_getusername_h
#define osapi_getusername_h

/*
���ߤΥ桼����̾������
���Ĥ���ʤ��Ȥ���nullʸ����(nullptr�ǤϤʤ�)���֤�
*/

#ifdef _WIN32
#include "osapi_mbs_wcs.h"
namespace osapi {
std::TSTRING getusername(void);
} // namespace osapi

#else	// unix
#include <string>
namespace osapi {
/* ��ա�login̾�ǤϤʤ���礢�ꡣCygwin�Ǥ�Admin... */
std::string getusername(void);
} // namespace osapi
#endif

#endif /* !osapi_getusername_h */
