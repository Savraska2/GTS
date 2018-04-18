#ifndef osapi_gethostname_h
#define osapi_gethostname_h

/*
�ۥ���̾������
���Ĥ���ʤ��Ȥ���nullʸ����(nullptr�ǤϤʤ�)���֤�
*/

#ifdef _WIN32
#include "osapi_mbs_wcs.h"
namespace osapi {
std::TSTRING gethostname(void);
} // namespace osapi

#else	// unix
#include <string>
namespace osapi {
std::string gethostname(void);
} // namespace osapi
#endif

#endif /* !osapi_gethostname_h */
