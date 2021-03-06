#include "calc_trace_by_hsv.h"

double calc::line_len_from_rad( const double rad )
{
/*
[直角二等辺三角形の直角点を中心とした回転角から、中心の対辺上の位置を得る]
以下、計算式を得るための解法

直線の方程式
	(x - x1) / (x2 - x1) = (y - y1) / (y2 - y1)

直線その1
	x1 = 0 ,y1 = 0 ,x2 = cos(rad) ,y2 = sin(rad)

直線その2
	x1 = 1 ,y1 = 0 ,x2 = 0 ,y2 = 1

直線の方程式に直線その1を当てはめる
	(x - 0) / (c - 0) = (y - 0) / (s - 0)
-->	x / c = y / s
-->	s * x = c * y ... (式1)

直線の方程式に直線その2を当てはめる
	(x - 1) / (0 - 1) = (y - 0) / (1 - 0)
-->	(x - 1) / -1 = y / 1
-->	- x + 1 = y
-->	y = 1 - x ... (式2)

(式1)に(式2)を代入
	s * x = c * (1 - x)
-->	s * x = c - c * x
-->	s * x + c * x = c
-->	(s + c) * x = c
-->	x = c / (s + c) ... (式3)

(式2)に(式3)を代入
	y = 1 - c / (s + c) ... (式4)

軸の意味
	x(式3) --> 0から1への距離を、1から0への距離に替える	--> x(式5)
	y(式4) --> 値そのまま使う				--> z

(式3)を左右1幅で反転する
	x = 1 - c / (s + c)
-->	x = (s + c) / (s + c) - c / (s + c)
-->	x = (s + c - c) / (s + c)
-->	x = s / (s + c) ... (式5)
*/
	const double si = sin(rad);
	const double co = cos(rad);
	const double x = si / (si+co);	/* (式5) */
	const double z = 1. - co / (si+co);	/* (式4) */
	return sqrt( x * x + z * z ) / sqrt(2.);
}

bool calc::trace_by_hsv_to_rgb(
	const double h, const double s, const double v
	,const std::vector<calc::trace_by_hsv_params>& hsv_params
	, double& r, double& g, double& b
)
{
	/* 高速化のための初期計算と、中間値の保持と、黒/色判断関数 */
 class check_black_and_color {
 public:
	check_black_and_color(const double s ,const double v)
		:one_minus_v_(1.-v) ,s_mul_v_(s*v)
	{}
	inline bool is_black_side(
		const double slope_line_len ,const double intercept
	) {
		if (this->s_mul_v_ == 0.) {/* 色味か明度がゼロなら黒部分 */
			return true;
		}
		if ( slope_line_len == 0.) { /* 0なら全て色部分 */
			return false;
		}
		if ( ((1. - slope_line_len) * this->s_mul_v_) <
		(this->one_minus_v_ - intercept) * slope_line_len) {
			return true;	/* 斜め切断して黒味側 */
		}
			return false; /* 上以外は色側 */
	}
 private:
	double one_minus_v_ ,s_mul_v_;
 }	chk_b_and_c(s,v);

	/* トレス(2値化)処理 */
	for (unsigned ii = 0; ii < hsv_params.size(); ++ii) {
		const trace_by_hsv_params& area = hsv_params.at(ii);

		/* 有効でない範囲は無視して他の範囲を探す */
		if (area.enable_sw == false) { continue; }

		/* 黒線 */
		if (area.hue_min < 0. || area.hue_max < 0.) {
			/* 太さ外のときは次ループへ */
			if (area.thickness < v) { continue; }

			/* 色味範囲のときは次ループへ */
			if ((0. < v) && (0. < s)
			&& (chk_b_and_c.is_black_side(
				area.slope_line_len ,area.intercept
			) == false)) {
				continue;
			}
			/* vがゼロあるいは、sがゼロのときは黒線 */
		}

		/* 色線 */
		else {
			/* 色相の範囲外の時は次ループへ */
			if (area.hue_min < area.hue_max) {
				if ((h < area.hue_min)
				||  (area.hue_max < h)) { continue; }
			} else
			if (area.hue_max < area.hue_min) {
				if ((area.hue_max < h)
				&&  (h < area.hue_min)) { continue; }
			} else
			if (area.hue_min == area.hue_max) {
				if (area.rotate360_sw==false) {
					if (area.hue_min != h) {
				/* 0回転でmin/max位置になければ範囲外 */
						continue;
					}
				}
				/* 1回転なら全て範囲内 */
			}

			/* 太さ外のときは次ループへ */
			if (area.thickness < (1. - s)) { continue; }

			/* 黒である(色味がない)ので次ループへ */
			if (v <= 0.) { continue; }

			/* 色味がないので次ループへ */
			if (s <= 0.) { continue; }

			/* 黒味範囲のときは次ループへ */
			if (chk_b_and_c.is_black_side(
				area.slope_line_len ,area.intercept
			)) {
				continue;
			}
		}

		/* 指定範囲の色で、トレススイッチONなら、
		トレス(指定の色に)して、抜ける
		範囲が重複していたらループで先の指定を優先する */
		r = area.target_r;
		g = area.target_g;
		b = area.target_b;
		return true;
	}

	/* 有効な範囲がなく2値化をしないなら
	白色(紙の地の色)(RGB=(1,1,1))にする */
	r = 1.;
	g = 1.;
	b = 1.;

	return false;
}
#if defined DEBUG_CALC_TRACE_BY_HSV
#include <iostream>
//#include "../lib_util/calc_rad_deg.h"
#include "../lib_util/calc_rad_deg.cpp"
int main(int argc ,const char* argv)
{
	argc; argv;
	for (int ii = 0 ;ii<=90 ; ii+=5) {
		double deg = static_cast<double>(ii);
		double rad = calc::rad_from_deg( deg );
		double lin = calc::line_len_from_rad( rad );
		std::cout
		<< "ii=" << ii
		<< " deg=" << deg
		<< " rad=" << rad
		<< " lin=" << lin
		<< std::endl;
	}

	std::vector<calc::trace_by_hsv_params> hsv_params(6);
	for (size_t ii = 0 ;ii<hsv_params.size() ; ++ii) {
		calc::trace_by_hsv_params& hsv_param = hsv_params.at(ii);
		std::cout
		<< "e_sw=" << hsv_param.enable_sw 
		<< " tgtr=" << hsv_param.target_r
		<< " tgtg=" << hsv_param.target_g
		<< " tgtb=" << hsv_param.target_b 
		<< " thic=" << hsv_param.thickness 
		<< " hmin=" << hsv_param.hue_min
		<< " hmax=" << hsv_param.hue_max
		<< " sl_l=" << hsv_param.slope_line_len
		<< " inte=" << hsv_param.intercept
		<< " d_sw=" << hsv_param.display_sw
		<< " 360sw=" << hsv_param.rotate360_sw
		<< std::endl
		;
	}

	return 0;
}
#endif // DEBUG_CALC_TRACE_BY_HSV
/*
rem glu32.lib advapi32.lib shlwapi.lib opengl32.lib comctl32.lib wsock32.lib user32.lib gdi32.lib shell32.lib ole32.lib comdlg32.lib 
rem :152,153 w! make_calc_trace_by_hsv.bat
cl /W4 /MD /EHa /O2 /wd4819 /DWIN32 /DDEBUG_CALC_TRACE_BY_HSV /I. /I../lib_util calc_trace_by_hsv.cpp /Fea
del calc_trace_by_hsv.obj
*/
