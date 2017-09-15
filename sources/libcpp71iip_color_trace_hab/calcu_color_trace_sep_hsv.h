#ifndef calcu_color_trace_sep_hsv_h
#define calcu_color_trace_sep_hsv_h

/*
HSV��Ω�Τ���ƿ����ʬ���򤷤���Ū�ο�������

��Hue
	R - Y - G - C - B - M - R
	��  ��  ��  ��  ��  ��  ��

��min,maxŪ�ͤ����顢�ƿ����ʬ����ˡ(���ޤޤ�)
	��
		hue min. max.	0...360 �ƶ��ο�����ϰ�
		saturation min.	������ɽ��
		saturation max.	1����
		value min.	�Ȥ�ʤ�
		value max.	1����
		smin,smax,vmin,vmax�Ƿ׻�����

	��(���Ȥ��ϰϷ׻���ˡ�ϰ㤦)
		hue min. max.	0��꾮(-1)�Ϲ��򰷤����Ȥ򼨤���
		saturation min.	�Ȥ�ʤ�(��̣�λĤ�Ǽ��)
		saturation max.	�Ȥ�ʤ�(��̣�λĤ�Ǽ��)
		value min.	0����
		value max.	������ɽ��

�����ȹ�����ڤ���ˡ(���줫��)

 1 HSVΩ�Τ�SV����
	S=0,V=0����S=1,V=1�ؤ�ľ����򤿤ɤ�ѥ�᡼����T�Ȥ���
		T=calcu_sep_hsv::threshold_to_black
	T�ΰ��֤���S=0,V=1���֤�ľ�������������ľ���Ǿ岼��ʬ���뤳�Ȥǡ�
	���ΰ褫���ΰ褫Ƚ�Ǥ�Ԥ�
		T=0	��̣�ʤ�
		T=1	���ƿ�̣

	0 |---- S --->| 1
      1 - +-----------+
	^ |          /  1
	| |        /
	V |  P   +
	| |    /   T
	| |  /
      0 - +
	     0
		�� T ��̣�ȹ�̣�����Ǥ��뤿��ΰ���
		�� P �ƥԥ�����

 2 ���������Τޤޡ�ľ�Ժ�ɸ�Ϥˤ��������

	T����	( T      , T )
	P����	( S * V  , V )

 3 ���帶����ɸ�Ϥ�(�岼ȿž)�����Ȥ��ΰ���

	0 |---- S --->| 1
      0 - +-----------+
	| | \        /  1
	| |    \   /
	V |  P   +
	| |    /   T
	v |  /
      1 - +
	     0

	T����	( T      , 1 - T )
	P����	( S * V  , 1 - V )

 4 ���帶����ɸ�Ϥˤơ�������T����ľ����P���֤Ȥδط��ǡ�
   ��̣����̣����Ƚ�Ǥ��롣
   ���Τ��ᡢT���P�����Ӥǰ��ִط��򸫤�

	T��	(1 - T) / T
	P��	(1 - V) / (S * V)

	T�� <  P��	��̣¦�Ǥ���
	T�� => P��	��̣¦�Ǥ���

	��äơ���̣¦�Ǥ��뤫��Ƚ�Ǥ�
	(1 - T) / T   <   (1 - V) / (S * V) 
*/

#include <vector>

class calcu_sep_black_and_color {
public:
	calcu_sep_black_and_color(const double s ,const double v)
		:one_minus_v_div_s_v_(0.)
	{
		if (s != 0. && v != 0.) {
		 this->one_minus_v_div_s_v_ = (1. - v) / (s * v);
		}
	}
	inline bool is_black_side(const double tt) {
		if ( tt == 0.) { /* threshold_to_black��0�ʤ����ƿ���ʬ */
			return false;
		}
		if ( ((1. - tt) / tt) < one_minus_v_div_s_v_ ) {
			return true;
		}
		return false;
	}
private:
	double one_minus_v_div_s_v_;
};
/*-------------------------------------------------------*/
class calcu_sep_hsv {
public:
	bool	enable_sw;	/* 2�Ͳ������¹� false=¾��2�Ͳ������� */

	double	 target_r	/* 0...1 ��̿� */
		,target_g
		,target_b;

	double	thickness;	/* 0...1 ��/��������(=���ٺǾ���) */

	double	hmin , hmax;	/* 0...360 �����٤������ϰ�
					0��꾮�����ʤ鿧�Ǥʤ������� */
	double	threshold_to_black;/* 0...1 SV�̾�����Ȥμ�礤���� */
	double	threshold_offset;/* 0...1 SV�̾�����Ȥ�
				��礤�������θ������֤Υ��ե��å� */
	bool	hsv_view_guide_sw;	/* hsv viewer���ϰϤ�ɽ������sw */
};
/*-------------------------------------------------------*/
/* ���ޤޤǤΥ��饹�ȶ�¸�����뤿��ΰ��Ū���� --> ��refactering */
class calcu_color_trace_base {
public:
	virtual bool exec(
		const double hh, const double ss, const double vv
		, double *rr, double *gg, double *bb
	){
		(void)hh; (void)ss; (void)vv; (void)rr; (void)gg; (void)bb;
		return false;
	}
};

class calcu_color_trace_sep_hsv : public calcu_color_trace_base {
public:
	calcu_color_trace_sep_hsv()
	:target_paper_r_(1.)
	,target_paper_g_(1.)
	,target_parer_b_(1.)
	{}

	std::vector<calcu_sep_hsv> cla_area_param;

	void setup_default_area_param(void) {
		this->cla_area_param = {
 { true  ,0.,0.,0. ,0.7 , -1 , -1  ,0.5,0.0 ,true } /* �� */
,{ true  ,1.,0.,0. ,0.7 ,300., 60. ,0.5,0.0 ,true } /* �� */
,{ true  ,0.,0.,1. ,0.7 ,180.,300. ,0.5,0.0 ,true } /* �� */
,{ true  ,0.,1.,0. ,0.7 , 60.,180. ,0.5,0.0 ,true } /* �� */
,{ false ,0.,1.,1. ,0.7 ,120.,240. ,0.5,0.0 ,false } /* �� */
,{ false ,1.,0.,1. ,0.7 ,240.,360. ,0.5,0.0 ,false } /* �� */
,{ false ,1.,1.,0. ,0.7   ,0.,120. ,0.5,0.0 ,false } /* ��(or �����) */
		};
	}

	/* hh = 0...360 , ss,vv,rr,gg,bb = 0...1 */
	bool exec(
		const double hh, const double ss, const double vv
		, double *rr, double *gg, double *bb
	);
private:
	double	 target_paper_r_
		,target_paper_g_
		,target_parer_b_;
};

#endif /* !calcu_color_trace_sep_hsv_h */
