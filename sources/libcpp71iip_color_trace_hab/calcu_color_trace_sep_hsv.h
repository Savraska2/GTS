#ifndef calcu_color_trace_sep_hsv_h
#define calcu_color_trace_sep_hsv_h

/*
  HSV��Ω�Τ���ƿ����ʬ���򤷤���Ū�ο�������

    ��Hue
	R - Y - G - C - B - M - R
	��  ��  ��  ��  ��  ��  ��

    ��min,maxŪ�ͤ����顢�ƿ����ʬ����ˡ
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

    �����ȹ��Ȥ�ʬΥ��ˡ (T = calcu_sep_hsv::src_threshold_to_black)

	  0 ----- S ----->1
	1 +---------------+
	^ |             /
	| |           /
	| |         /
	V |       /  T
	| |     /
	| |   /
	  | /
	0 +

	S=0,V=0����S=1,V=1�ؤ�ľ����򤿤ɤ�ѥ�᡼����T�Ȥ���
	T�ΰ��֤���S=0,V=1���֤�ľ�������������ľ���Ǿ岼��ʬ���뤳�Ȥǡ�
	���ΰ褫���ΰ褫Ƚ�Ǥ�Ԥ�
		T�ˤĤ���
			T=0	��̣�ʤ�
			T=1	���ƿ�̣
			�嵭�ͤ�ȿž���ƥѥ�᡼�����Ȥ��ƻȤ�
		Pixel����
			p=( S * T , V )	�� "S * T"��������ɸ���Ѵ�
		Ƚ�ǰ���
			t=( T     , T )
		�岼ȿž���ƺ�������ˤ���
			p=( S*T , 1-V )
			t=( T   , 1-T )
		��ǰ��֤�Ƚ��
			1<=V	--> ����� --> ��
			1<=T	--> ��
			pd= (1-V) / S*T
			td= (1-T) / T    
			pd < td	--> ��¦ --> ��
			td < pd	--> ��¦ --> ��
		�׻����ͻ� --> �ޥ��ʥ�������Ȥ��ᤫ?!
			(1-T) / T     <  (1-V) / S*T
			(1-T) * S * T <  (1-V) * T
*/

#include <vector>

class calcu_sep_hsv {
public:
	double	src_hmin , src_hmax;	/* 0...360 �����٤������ϰ�
					0��꾮�����ʤ鿧�Ǥʤ������� */
	double	src_threshold_to_black;/* 0...1 SV�̾�����Ȥμ�礤���� */
	double	src_threshold_offset;/* 0...1 SV�̾�����Ȥ�
				��礤�������θ������֤Υ��ե��å� */

	double	src_thickness;		/* 0...1 ��/��������(=���ٺǾ���) */
	double	 tgt_line_color_red	/* 0...1 ��̿� */
		,tgt_line_color_green
		,tgt_line_color_blue;
	bool	tgt_line_color_sw;	/* ��̿��ˤ���(false=�طʿ�(bg)) */
};

/*-------------------------------------------------------*/
/* ���ޤޤǤΥ��饹�ȶ�¸�����뤿��ΰ��Ū���� --> ��refactering */
class calcu_color_trace_base {
public:
	virtual void exec(
	double hh, double ss, double vv, double *rr, double *gg, double *bb
	){}
};

class calcu_color_trace_sep_hsv : public calcu_color_trace_base {
public:
	calcu_color_trace_sep_hsv()
	:tgt_bg_red_(1.)
	,tgt_bg_green_(1.)
	,tgt_bg_blue_(1.)
	{}

	std::vector<calcu_sep_hsv> cla_area_param;

	void setup_default_area_param(void) {
		this->cla_area_param = {
	 {300., 60. ,0.1 ,0.8,1.,0.,0. ,true }	/* �� */
	,{ 60.,180. ,0.1 ,0.8,0.,1.,0. ,true }	/* �� */
	,{180.,300. ,0.1 ,0.8,0.,0.,1. ,true }	/* �� */
	,{ -1 , -1  ,0.1 ,0.6,0.,0.,0. ,true }	/* ��(ɬ���Ǹ�ˤ���) */
		};
	}

	/* hh = 0...360 , ss,vv,rr,gg,bb = 0...1 */
	void exec(
	double hh, double ss, double vv, double *rr, double *gg, double *bb
	);
private:
	double	tgt_bg_red_
		,tgt_bg_green_
		,tgt_bg_blue_;
};

#endif /* !calcu_color_trace_sep_hsv_h */
