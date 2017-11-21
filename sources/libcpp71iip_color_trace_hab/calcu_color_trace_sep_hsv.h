#ifndef calcu_color_trace_sep_hsv_h
#define calcu_color_trace_sep_hsv_h

/*
HSV��Ω�Τ���ƿ����ʬ���򤷤���Ū�ο�������

��Hue
	R - Y - G - C - B - M - R
	��  ��  ��  ��  ��  ��  ��

��min,maxŪ�ͤ����顢�ƿ����ʬ��
	��
		hue min.	0...360 ����Υ�������å��ϰϤκǾ���
		hue max.	0...360 ����Υ�������å��ϰϤκ�����
		saturation min.	������ɽ��
		saturation max.	1����
		value min.	Ĵ����(0.5��)
		value max.	1����

	��(���Ȥ��ϰϷ׻���ˡ�ϰ㤦)
		hue min.	0
		hue max.	360
		saturation min.	0����
		saturation max.	Ĵ����(0.3��)
		value min.	0����
		value max.	������ɽ��

�����ȹ�����ڤ�Τ�"��value min."��saturation max." ���� �ʤʤ�����
  �ˤ�����ˡ

 1 HSVΩ�Τ�SV����
	S=0,V=0����S=1,V=1�ؤ�ľ����򤿤ɤ�ѥ�᡼����T�Ȥ���
		T=calcu_sep_hsv::slope_deg
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


	Tľ����岼�˰�ư�����ѿ���Offset�Ȥ����
	Point���֤�դ�Offset�ݤ���
	T��	(1 - T) / T
	P��	(1 - V - Offset) / (S * V)

	P����̣¦�Ǥ��뤫��Ƚ�Ǥ�
	(1 - T) / T   <   (1 - V - Offset) / (S * V) 
*/

#include <vector>

class calcu_sep_black_and_color {
public:
	calcu_sep_black_and_color(const double s ,const double v)
		:one_minus_v_(0.)
		,s_mul_v_(0.)
	{
		this->one_minus_v_ = (1. - v);
		this->s_mul_v_ = (s * v);
	}
	inline bool is_black_side(
		const double slope_line ,const double intercept
	) {
		if ( slope_line == 0.) { /* slope_deg��0�ʤ����ƿ���ʬ */
			return false;
		}
		if (this->s_mul_v_ == 0.) {/* ��̣�����٤�����ʤ����ʬ */
			return true;
		}
		if ( ((1. - slope_line) / slope_line) <
		(this->one_minus_v_ - (1. - intercept)) / this->s_mul_v_ ) {
			return true;	/* �Ф����Ǥ��ƹ�̣¦ */
		}
		return false; /* ��ʳ��Ͽ�¦ */
	}
private:
	double one_minus_v_ ,s_mul_v_;
};
/*-------------------------------------------------------*/
class calcu_sep_hsv {
public:
	bool	enable_sw;	/* 2�Ͳ������¹�sw(false=¾��2�Ͳ�������) */

	double	 target_r	/* 0...1 ��̿� */
		,target_g
		,target_b;

	double	thickness;	/* 0...1 ��/�������� */

	double	hue_min
		,hue_max;	/* 0...360 �����٤������ϰ�
				   Minus�ξ��Ϲ����� */
	double	slope_deg;	/* 0...90 ��-���ζ������� */
	double	intercept;	/* 0... 1 ��-���ζ������� */
	bool	display_sw;	/* ��-���ζ�����ɽ������sw */
	bool	rotate360_sw;	/* hue_min/hue_max��Ʊ�ͤξ���Ƚ�� */
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
	,cla_area_param(
{{ true  ,0.,0.,0. ,0.7 , -1 , -1  ,45.,1. ,true  ,false } /* 0 �� */
,{ true  ,1.,0.,0. ,0.7 ,300., 60. ,45.,1. ,true  ,false } /* 1 �� */
,{ true  ,0.,0.,1. ,0.7 ,180.,300. ,45.,1. ,true  ,false } /* 2 �� */
,{ true  ,0.,1.,0. ,0.7 , 60.,180. ,45.,1. ,true  ,false } /* 3 �� */
,{ false ,0.,1.,1. ,0.7 ,120.,240. ,45.,1. ,false ,false } /* 4 �� */
,{ false ,1.,0.,1. ,0.7 ,240.,360. ,45.,1. ,false ,false } /* 5 �� */
}
	)
	{}

	std::vector<calcu_sep_hsv> cla_area_param;

	/* hh = 0...360 , ss,vv,rr,gg,bb = 0...1 */
	bool exec(
		const double hh, const double ss, const double vv
		, double* rr, double* gg, double* bb
	);
private:
	double	 target_paper_r_
		,target_paper_g_
		,target_parer_b_;
};

#endif /* !calcu_color_trace_sep_hsv_h */
