#include "FL/fl_ask.H"	// fl_alert(-)
#include "ptbl_returncode.h"
#include "pri.h"
#include "gts_gui.h"
#include "gts_master.h"

int gts_master::next_scan_and_save_( void )
{
	/* 01 次(始め)の位置を得る */
	int crnt_list_num = this->cl_file_number_list.get_crnt_list_num();
	int crnt_file_num = this->cl_file_number_list.get_crnt_file_num();
	int next_file_num = this->cl_file_number_list.get_next_file_num();
	if (crnt_list_num< 1 || crnt_file_num< 1) {
		pri_funct_err_bttvr(
   "Error : crnt_list_num=%d or crnt_file_num=%d"
			,crnt_list_num ,crnt_file_num );
		return NG;
	}

	/* 02 保存するファイルパスを得る
		DirPath/Level.Number.Ext-->例:"C:/users/public/A.0001.tif"
	*/
	char* filepath = const_cast<char*>(
		this->cl_bro_level.cp_filepath( crnt_file_num )
	);
	if (filepath == nullptr) {
		pri_funct_err_bttvr(
	"Error : this->cl_bro_level.cp_filepath(%d) returns nullptr."
			, crnt_file_num );
		return NG;
	}

	/* 03 フレーム番号(crnt_list_num)を表示するようリストをスクロール */
	cl_gts_gui.selbro_fnum_list->middleline(crnt_list_num);

	/* 04 スキャンを実行 */
	iip_canvas* clp_scan = this->_iipg_scan();
	if (nullptr == clp_scan) {
		pri_funct_err_bttvr(
		      "Error : this->_iipg_scan() returns nullptr" );
// std::string str("Error in scaning at next!";
// fl_alert(str.c_str());
		return NG;
	}

	/* 05 回転、2値化、ドットノイズ消去　処理 */
	if (this->rot_and_trace_and_enoise_(
		clp_scan ,cl_gts_gui.choice_rot90->value()
	) != OK) {
		return NG;
	}

	/* 06 画像を保存する
		BW/Grayscale/RGB/RGBTraceのどれか
	*/
	if (OK != this->_iipg_save(
		&(cl_gts_master.cl_iip_edot)/* Effectの最後Node画像を保存 */
		, filepath
		, cl_gts_gui.valinp_area_reso->value()
		/* 回転値後を正対として角度ゼロ(default)として保存する */
	) ) {
		pri_funct_err_bttvr(
	 "Error : this->_iipg_save(-) returns NG" );
		return NG;
	}

	/* 07 リストに保存済マーク付け "0000" --> "0000 S" */
	if (OK!=this->cl_file_number_list.marking_scan_file(crnt_list_num)){
		pri_funct_err_bttvr(
       "Error : this->cl_file_number_list.marking_scan_file(%d) returns NG",
			crnt_list_num
		);
		return NG;
	}

	/* 08 リストの選択解除 */
	this->cl_file_number_list.unselect(crnt_list_num);

	/* 09 level browser listの(保存したファイルも含めて)再表示 */
	this->cl_bro_level.cb_list_redisplay();

	/* 10 画像表示 */
	if (this->redraw_image_( clp_scan ,false ,false ) != OK) {
		return NG;
	}

	/* 11 切抜きはしないのでOFFにしておく */
	this->cl_ogl_view.set_crop_disp_sw(OFF);

	/* 12 次のフレーム番号があるなら、
	次の処理を促すwindowの設定をしておく */
	if (0 < this->cl_file_number_list.get_next_file_num()) {
		char	ca8_but[8];
		(void)sprintf( ca8_but ,"%d" ,crnt_file_num );
		cl_gts_gui.norout_crnt_scan_number->value(ca8_but);

		(void)sprintf( ca8_but ,"%d" ,next_file_num );
		cl_gts_gui.norout_next_scan_number->value(ca8_but);

		cl_gts_gui.norout_crnt_scan_level->value(
			this->cl_bro_level.cp_levelname()
		);
	}

	return OK;
}

/*--------------------------------------------------------*/

void gts_master::cb_scan_and_save_start( void )
{
	/* 先頭を得る */
	this->cl_file_number_list.counter_start(
		cl_gts_gui.choice_level_num_continue_type->value()
	);

	/* 最初に番号が選択がない/設定できない */
	if (this->cl_file_number_list.get_crnt_file_num() < 1) {
		if (cl_gts_gui.choice_level_num_continue_type->value()
		== cl_gts_master.cl_file_number_list.get_end_type_value()
		) {/*End*/
			fl_alert("Select number!");
		}
		else {/* Endless */
			fl_alert("Bad number in Start!");
		}
		return;
	}

	/* levelの名前を得る */
	if (nullptr == this->cl_bro_level.cp_filepath(
		this->cl_file_number_list.get_crnt_file_num()
	)) {
		pri_funct_err_bttvr(
	 "Error : this->cl_bro_level.cp_filepath(%d) returns nullptr.",
		this->cl_file_number_list.get_crnt_file_num()
		);
fl_alert("Input level name!");
		return;
	}

	/* 保存するタイプで画像を表示する */
	if ( cl_gts_gui.chkbtn_filter_rgb_color_trace_sw->value() ) {
		/* TracenImage画像のみ表示 */
		cl_gts_master.cb_change_wview_sub();

		/* 画像表示状態をメニューに設定 */
		cl_gts_gui.menite_wview_sub->setonly();
	}
	else {
		/* ScanImage(メイン)画像のみ表示 */
		cl_gts_master.cb_change_wview_main();

		/* 画像表示状態をメニューに設定 */
		cl_gts_gui.menite_wview_main->setonly();
	}
	
	/* カレントのスキャンと保存をして、次があるなら準備もする */
	if (this->next_scan_and_save_() != OK) {
		return;
	}

	/* 次のスキャンがあるなら */
	if (1 <= this->cl_file_number_list.get_next_file_num()) {
		/* Spaceに関しては常にここでfocus設定が必要2014-02-03 */
	this->cl_memo_short_cut_key.set_space_key_focus_in_next_scan();

		/* 次をどうするかwindowを表示して指示を仰ぐ */
		cl_gts_gui.window_next_scan->show();
	}
}
void gts_master::cb_scan_and_save_next( void )
{
	/* windowを消す */
	cl_gts_gui.window_next_scan->hide();

	/* 次の番号を得る */
	this->cl_file_number_list.counter_next(
		cl_gts_gui.choice_level_num_continue_type->value()
	);

	/* カレントのスキャンと保存をして、次があるなら準備もする */
	if (this->next_scan_and_save_() != OK) {
		return;
	}

	/* 次のスキャンがあるなら */
	if (1 <= this->cl_file_number_list.get_next_file_num()) {
		/* Spaceに関しては常にここでfocus設定が必要2014-02-03 */
	this->cl_memo_short_cut_key.set_space_key_focus_in_next_scan();

		/* 次をどうするかwindowを表示して指示を仰ぐ */
		cl_gts_gui.window_next_scan->show();
	}
}
void gts_master::cb_scan_and_save_prev( void )
{
	/* windowを消す */
	cl_gts_gui.window_next_scan->hide();

	/* カレントのスキャンと保存をして、次があるなら準備もする */
	if ( this->next_scan_and_save_() != OK ) {
		return;
	}

	/* 次のスキャンがあるなら */
	if (1 <= this->cl_file_number_list.get_next_file_num()) {
		/* Spaceに関しては常にここでfocus設定が必要2014-02-03 */
	this->cl_memo_short_cut_key.set_space_key_focus_in_next_scan();

		/* 次をどうするかwindowを表示して指示を仰ぐ */
		cl_gts_gui.window_next_scan->show();
	}
}
