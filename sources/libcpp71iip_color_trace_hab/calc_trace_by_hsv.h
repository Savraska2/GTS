#ifndef calc_trace_by_hsv_h
#define calc_trace_by_hsv_h

#include <cmath>	// sin() ,cos() ,sqrt()
#include <vector>

namespace calc {

template <typename T>
T rad_from_deg( const T deg ) // T = float or double
{
	return 3.14159265358979323846264338327950288 * deg / 180.0;
}

template <typename T>
T line_len_from_rad( const T rad ) // T = float or double
{
/*
[ľ�������ջ��ѷ���ľ�������濴�Ȥ�����ž�Ѥ��顢�濴�����վ�ΰ��֤�����]
�ʲ����׻��������뤿��β�ˡ

ľ����������
	(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)

ľ������1
	x1 = 0 ,y1 = 0 ,x2 = cos(rad) ,y2 = sin(rad)

ľ������2
	x1 = 1 ,y1 = 0 ,x2 = 0 ,y2 = 1

ľ������������ľ������1�����ƤϤ��
	(x - 0) / (c - 0) = (y - 0) / (s - 0)
-->	x / c = y / s
-->	s * x = c * y ... (��1)

ľ������������ľ������2�����ƤϤ��
	(x - 1) / (0 - 1) = (y - 0) / (1 - 0)
-->	(x - 1) / -1 = y / 1
-->	- x + 1 = y
-->	y = 1 - x ... (��2)

(��1)��(��2)������
	s * x = c * (1 - x)
-->	s * x = c - c * x
-->	s * x + c * x = c
-->	(s + c) * x = c
-->	x = c / (s + c) ... (��3)

(��2)��(��3)������
	y = 1 - c / (s + c) ... (��4)

���ΰ�̣
	x(��3) --> 0����1�ؤε�Υ��1����0�ؤε�Υ���ؤ���	--> x(��5)
	y(��4) --> �ͤ��Τޤ޻Ȥ�				--> z

(��3)�򺸱�1����ȿž����
	x = 1 - c / (s + c)
-->	x = (s + c) / (s + c) - c / (s + c)
-->	x = (s + c - c) / (s + c)
-->	x = s / (s + c) ... (��5)
*/
	const T si = sin(rad);
	const T co = cos(rad);
	const T x = si / (si+co);	/* (��5) */
	const T z = 1. - co / (si+co);	/* (��4) */
	return sqrt( x * x + z * z ) / sqrt(2.);
}

/*
[HSV��Ω�Τ���ƿ����ʬ���򤷤���Ū�ο�������]

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
		T=calc::trace_by_hsv_params::slope_line_len
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


	Tľ����岼�˰�ư�����ѿ���Intercept�Ȥ����
	Point���֤�դ�Intercept�ݤ���
	T��	(1 - T) / T
	P��	(1 - V - Intercept) / (S * V)

	P����̣¦�Ǥ��뤫��Ƚ�Ǥ�
	(1 - T) / T   <   (1 - V - Intercept) / (S * V) 

	(0 <= T) && (0 <= S) && (0 <= V)�Ǥ�����ϡ�
	(1 - T) * (S * V)  <   (1 - V - Intercept) * T

	(��) T=slope_line_len
*/
class trace_by_hsv_params {
public:
	bool	enable_sw;	/* 2�Ͳ������¹�sw(false=¾��2�Ͳ�������) */

	double	 target_r	/* 0...1 ��̿� */
		,target_g
		,target_b;

	double	thickness;	/* 0...1 ��/�������� */

	double	hue_min
		,hue_max;	/* 0...360 �����٤������ϰ�
				   Minus�ξ��Ϲ����� */
	double	slope_line_len;	/* 0...1 =��...���ζ�������
	(sin,cos�Ի��Ѥ�)��®�����뤿�ᡢ���٤Ǥʤ����դΰ��֤�ɽ�� */
	double	intercept;	/* 0...1 =��...���ζ������� */
	bool	display_sw;	/* ��-���ζ�����ʬ��ɽ������sw */
	bool	rotate360_sw;	/* hue_min/hue_max��Ʊ�ͤξ���o/cȽ�� */
};

/*
h(=0...<360),s(=0...1),v(=0...1)�������ͤȤ��ơ�
hsv_params�ˤ�ä�Ƚ�Ǥ���
�ȥ쥹(2�Ͳ�)������r,g,b(=0...1)�˥ȥ쥹(2�Ͳ�)�ͤ������true���֤�
�ȥ쥹(2�Ͳ�)���ʤ��ä��� r,g,b(=1)(=���)�������false���֤� */
bool trace_by_hsv_to_rgb(
	const double h, const double s, const double v
	,const std::vector<calc::trace_by_hsv_params>& hsv_params
	, double& r, double& g, double& b
);

} // namespace calc

#endif /* !calc_trace_by_hsv_h */
