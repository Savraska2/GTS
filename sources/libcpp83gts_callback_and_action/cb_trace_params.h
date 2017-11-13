#ifndef cb_trace_params_h
#define cb_trace_params_h

#include <vector>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Scrollbar.H>

#include "calcu_color_trace_sep_hsv.h"	// calcu_sep_hsv
//#include "gts_gui.h"

class cb_trace_params {
public:
	cb_trace_params()
		:number_(0)
		,r_(0)
		,g_(0)
		,b_(0)
		,hmin_(0.)
		,hmax_(0.)
	{}

	/* ����� */
	void init_color(void);

	/* target rgb color editor */
	void cb_target_rgb_color_open_editor(
		Fl_Double_Window* flwin
		,Fl_Button* flbut
		,const int number
	);
	void cb_target_rgb_color_change(void);
	void cb_target_rgb_color_cancel(void);

	/* hue min max editor */
	void cb_hue_min_or_max_open_editor(
		Fl_Double_Window* flwin
		,Fl_Button* flbut
		,const int number
	);
	void cb_hue_min_or_max_cancel(void);

	/* trace����Ū�������� */
	void get_target_rgb(
		const int number
		, unsigned char& r , unsigned char& g , unsigned char& b
	);
	void set_target_rgb(
		const int number
		, unsigned char r , unsigned char g , unsigned char b
	);

	/* trace param�γƹ��ܤ�����Ȥ��ư�������ν���
		"�岼�����ؤ�"���ȡ�"memory_config save&load"��������
	*/
	class widget_set {
	public:
		Fl_Check_Button*	chebut_enable_sw;
		Fl_Group*		group_trace;
		Fl_Button*		button_target_rgb;
		Fl_Value_Input*		valinp_thickness;
		Fl_Scrollbar*		scrbar_thickness;
		Fl_Value_Input*		valinp_hue_min;
		Fl_Value_Input*		valinp_hue_max;
		Fl_Button*		button_hue_min_max;
		Fl_Value_Input*		valinp_slope_deg;
		Fl_Value_Input*		valinp_intercept;
		Fl_Check_Button*	chebut_display_sw;
		Fl_Check_Button*	chebut_rotate360_sw;
	};
	std::vector<widget_set> widget_sets;
	void init_widget_set(void) { this->init_widget_set_(); }
	void set_params_for_speedup(
		std::vector<calcu_sep_hsv>& param_sets
	);
	void cb_swap_widget_set( const unsigned num1 ,const unsigned num2 );
	int cb_get_window_height_active( void );
private:
	int number_;
	uchar r_ ,g_ ,b_;
	double hmin_ ,hmax_ ,rotate360_sw_;

	void init_widget_set_(void);
};

//--------------------

class fltk_button_trace_params : public Fl_Button {
public:
	fltk_button_trace_params(
	int x,int y,int w,int h,const char *l=0)
	: Fl_Button(x,y,w,h,l)
	{}
private:
	void draw();    
	int handle(int);
};

#endif /* !cb_trace_params_h */
