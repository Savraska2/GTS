// generated by Fast Light User Interface Designer (fluid) version 1.0107

#include "gtsfbro_gui.h"
#include "gts_master.h"

void gts_gui::cb_window_opengl_i(Fl_Double_Window*, void*) {
  exit(0);
}
void gts_gui::cb_window_opengl(Fl_Double_Window* o, void* v) {
  ((gts_gui*)(o->user_data()))->cb_window_opengl_i(o,v);
}

void gts_gui::cb_menite_level_i(Fl_Menu_*, void*) {
  cl_gts_master.cl_bro_level.cb_wintgl();
}
void gts_gui::cb_menite_level(Fl_Menu_* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_menite_level_i(o,v);
}

void gts_gui::cb_menite_config_load_i(Fl_Menu_*, void*) {
  cl_gts_master.cl_bro_config.cb_load_wintgl();
}
void gts_gui::cb_menite_config_load(Fl_Menu_* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_menite_config_load_i(o,v);
}

void gts_gui::cb_menite_config_save_as_i(Fl_Menu_*, void*) {
  cl_gts_master.cl_bro_config.cb_save_as_wintgl();
}
void gts_gui::cb_menite_config_save_as(Fl_Menu_* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_menite_config_save_as_i(o,v);
}

void gts_gui::cb_Quit_i(Fl_Menu_*, void*) {
  exit(0);
}
void gts_gui::cb_Quit(Fl_Menu_* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_Quit_i(o,v);
}

void gts_gui::cb_menite_trace_batch_i(Fl_Menu_*, void*) {
  cl_gts_master.cl_bro_trace_batch.cb_wintgl();
}
void gts_gui::cb_menite_trace_batch(Fl_Menu_* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_menite_trace_batch_i(o,v);
}

Fl_Menu_Item gts_gui::menu_[] = {
 {"File", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Level...", 0xffbf,  (Fl_Callback*)gts_gui::cb_menite_level, 0, 130, FL_NORMAL_LABEL, 0, 14, 0},
 {"Load Config...", 0xffbe,  (Fl_Callback*)gts_gui::cb_menite_config_load, 0, 2, FL_NORMAL_LABEL, 0, 14, 0},
 {"Save As Config...", 0x50073,  (Fl_Callback*)gts_gui::cb_menite_config_save_as, 0, 130, FL_NORMAL_LABEL, 0, 14, 0},
 {"    Quit", 0x51,  (Fl_Callback*)gts_gui::cb_Quit, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Setup", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Color Trace Batch...", 0,  (Fl_Callback*)gts_gui::cb_menite_trace_batch, 0, 2, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};
Fl_Menu_Item* gts_gui::menite_level = gts_gui::menu_ + 1;
Fl_Menu_Item* gts_gui::menite_config_load = gts_gui::menu_ + 2;
Fl_Menu_Item* gts_gui::menite_config_save_as = gts_gui::menu_ + 3;
Fl_Menu_Item* gts_gui::menite_trace_batch = gts_gui::menu_ + 7;

void gts_gui::cb_window_config_load_i(Fl_Double_Window*, void*) {
  cl_gts_master.cl_bro_config.cb_load_cancel();
}
void gts_gui::cb_window_config_load(Fl_Double_Window* o, void* v) {
  ((gts_gui*)(o->user_data()))->cb_window_config_load_i(o,v);
}

void gts_gui::cb__i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_config.cb_load_dir_up();
}
void gts_gui::cb_(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb__i(o,v);
}

void gts_gui::cb_filinp_config_load_dir_i(Fl_File_Input*, void*) {
  cl_gts_master.cl_bro_config.cb_load_dir();
}
void gts_gui::cb_filinp_config_load_dir(Fl_File_Input* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_filinp_config_load_dir_i(o,v);
}

void gts_gui::cb_selbro_config_load_list_i(Fl_Browser*, void*) {
  cl_gts_master.cl_bro_config.cb_load_list();
}
void gts_gui::cb_selbro_config_load_list(Fl_Browser* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->parent()->user_data()))->cb_selbro_config_load_list_i(o,v);
}

void gts_gui::cb_Load_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_config.cb_load_ok();
}
void gts_gui::cb_Load(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_Load_i(o,v);
}

void gts_gui::cb_Cancel_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_config.cb_load_cancel();
}
void gts_gui::cb_Cancel(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_Cancel_i(o,v);
}

void gts_gui::cb_window_config_save_as_i(Fl_Double_Window*, void*) {
  cl_gts_master.cl_bro_config.cb_save_as_cancel();
}
void gts_gui::cb_window_config_save_as(Fl_Double_Window* o, void* v) {
  ((gts_gui*)(o->user_data()))->cb_window_config_save_as_i(o,v);
}

void gts_gui::cb_1_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_config.cb_save_as_dir_up();
}
void gts_gui::cb_1(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_1_i(o,v);
}

void gts_gui::cb_filinp_config_save_as_dir_i(Fl_File_Input*, void*) {
  cl_gts_master.cl_bro_config.cb_save_as_dir();
}
void gts_gui::cb_filinp_config_save_as_dir(Fl_File_Input* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_filinp_config_save_as_dir_i(o,v);
}

void gts_gui::cb_selbro_config_save_as_list_i(Fl_Browser*, void*) {
  cl_gts_master.cl_bro_config.cb_save_as_list();
}
void gts_gui::cb_selbro_config_save_as_list(Fl_Browser* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->parent()->user_data()))->cb_selbro_config_save_as_list_i(o,v);
}

void gts_gui::cb_Save_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_config.cb_save_as_ok();
}
void gts_gui::cb_Save(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_Save_i(o,v);
}

void gts_gui::cb_Cancel1_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_config.cb_save_as_cancel();
}
void gts_gui::cb_Cancel1(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_Cancel1_i(o,v);
}

void gts_gui::cb_window_level_i(Fl_Double_Window*, void*) {
  cl_gts_master.cl_bro_level.cb_cancel();
}
void gts_gui::cb_window_level(Fl_Double_Window* o, void* v) {
  ((gts_gui*)(o->user_data()))->cb_window_level_i(o,v);
}

void gts_gui::cb_2_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_dir_up();
}
void gts_gui::cb_2(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_2_i(o,v);
}

void gts_gui::cb_filinp_level_dir_i(Fl_File_Input*, void*) {
  cl_gts_master.cl_bro_level.cb_dir();
}
void gts_gui::cb_filinp_level_dir(Fl_File_Input* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_filinp_level_dir_i(o,v);
}

void gts_gui::cb_choice_level_list_form_i(Fl_Choice*, void*) {
  cl_gts_master.cl_bro_level.cb_file_or_level();
}
void gts_gui::cb_choice_level_list_form(Fl_Choice* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_choice_level_list_form_i(o,v);
}

Fl_Menu_Item gts_gui::menu_choice_level_list_form[] = {
 {"File.tif", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Level.tif", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0}
};

void gts_gui::cb_Makedir_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_mkdir();
}
void gts_gui::cb_Makedir(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_Makedir_i(o,v);
}

void gts_gui::cb_Rename_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_rename();
}
void gts_gui::cb_Rename(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_Rename_i(o,v);
}

void gts_gui::cb_button_level_shift_number_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_renumber();
}
void gts_gui::cb_button_level_shift_number(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_button_level_shift_number_i(o,v);
}

void gts_gui::cb_selbro_level_list_i(Fl_Browser*, void*) {
  cl_gts_master.cl_bro_level.cb_list();
}
void gts_gui::cb_selbro_level_list(Fl_Browser* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->parent()->user_data()))->cb_selbro_level_list_i(o,v);
}

void gts_gui::cb_scroll_level_info_number_i(Fl_Scrollbar*, void*) {
  cl_gts_gui.valinp_level_crnt->value(
cl_gts_gui.scroll_level_info_number->value()
);
cl_gts_master.cl_bro_level.cb_info_redisplay();
}
void gts_gui::cb_scroll_level_info_number(Fl_Scrollbar* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_scroll_level_info_number_i(o,v);
}

void gts_gui::cb_valinp_level_crnt_i(Fl_Value_Input*, void*) {
  ((Fl_Valuator *)(cl_gts_gui.scroll_level_info_number))->value(
(double)cl_gts_gui.valinp_level_crnt->value()
);
cl_gts_master.cl_bro_level.cb_info_redisplay();
}
void gts_gui::cb_valinp_level_crnt(Fl_Value_Input* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_valinp_level_crnt_i(o,v);
}

void gts_gui::cb_ligbut_level_image_x1_sw_i(Fl_Light_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_x1view_wintgl();
}
void gts_gui::cb_ligbut_level_image_x1_sw(Fl_Light_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_ligbut_level_image_x1_sw_i(o,v);
}

void gts_gui::cb_ligbut_level_view_sw_i(Fl_Light_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_info_redisplay();
}
void gts_gui::cb_ligbut_level_view_sw(Fl_Light_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_ligbut_level_view_sw_i(o,v);
}

void gts_gui::cb_filinp_level_rgb_scan_dir_i(Fl_File_Input*, void*) {
  cl_gts_master.cl_bro_level.cb_rgb_scan_dir();
}
void gts_gui::cb_filinp_level_rgb_scan_dir(Fl_File_Input* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_filinp_level_rgb_scan_dir_i(o,v);
}

void gts_gui::cb_ligbut_level_rgb_scan_browse_sw_i(Fl_Light_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_browse_sw();
}
void gts_gui::cb_ligbut_level_rgb_scan_browse_sw(Fl_Light_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_ligbut_level_rgb_scan_browse_sw_i(o,v);
}

void gts_gui::cb_ligbut_level_info_rgb_sub_sw_i(Fl_Light_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_info_redisplay();
}
void gts_gui::cb_ligbut_level_info_rgb_sub_sw(Fl_Light_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_ligbut_level_info_rgb_sub_sw_i(o,v);
}

void gts_gui::cb_OK_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_ok();
}
void gts_gui::cb_OK(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_OK_i(o,v);
}

void gts_gui::cb_Cancel2_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_level.cb_cancel();
}
void gts_gui::cb_Cancel2(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_Cancel2_i(o,v);
}

void gts_gui::cb_window_x1view_i(Fl_Double_Window*, void*) {
  cl_gts_master.cl_bro_level.cb_x1view_cancel();
}
void gts_gui::cb_window_x1view(Fl_Double_Window* o, void* v) {
  ((gts_gui*)(o->user_data()))->cb_window_x1view_i(o,v);
}

void gts_gui::cb_window_trace_batch_i(Fl_Double_Window*, void*) {
  cl_gts_master.cl_bro_trace_batch.cb_cancel();
}
void gts_gui::cb_window_trace_batch(Fl_Double_Window* o, void* v) {
  ((gts_gui*)(o->user_data()))->cb_window_trace_batch_i(o,v);
}

void gts_gui::cb_3_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_trace_batch.cb_dir_up();
}
void gts_gui::cb_3(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_3_i(o,v);
}

void gts_gui::cb_Add_i(Fl_Menu_*, void*) {
  cl_gts_master.cl_bro_trace_batch.cb_add();
}
void gts_gui::cb_Add(Fl_Menu_* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_Add_i(o,v);
}

void gts_gui::cb_All_i(Fl_Menu_*, void*) {
  cl_gts_master.cl_bro_trace_batch.cb_alladd();
}
void gts_gui::cb_All(Fl_Menu_* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_All_i(o,v);
}

void gts_gui::cb_Select_i(Fl_Menu_*, void*) {
  int     ii;
for (ii = 1; ii <= cl_gts_gui.selbro_trace_batch_run_list->size(); ++ii) {
                   cl_gts_gui.selbro_trace_batch_run_list->select(ii);
};
}
void gts_gui::cb_Select(Fl_Menu_* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_Select_i(o,v);
}

void gts_gui::cb_Delete_i(Fl_Menu_*, void*) {
  int     ii;
for (ii = 1; ii <= cl_gts_gui.selbro_trace_batch_run_list->size();) {
              if ( cl_gts_gui.selbro_trace_batch_run_list->selected(ii) ) {
                   cl_gts_gui.selbro_trace_batch_run_list->remove(ii);
              } else { ++ii; }
};
}
void gts_gui::cb_Delete(Fl_Menu_* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_Delete_i(o,v);
}

Fl_Menu_Item gts_gui::menu_1[] = {
 {"Edit", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Add", 0x40073,  (Fl_Callback*)gts_gui::cb_Add, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"All Add", 0x50073,  (Fl_Callback*)gts_gui::cb_All, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Select All", 0x40061,  (Fl_Callback*)gts_gui::cb_Select, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Delete", 0x40078,  (Fl_Callback*)gts_gui::cb_Delete, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};

void gts_gui::cb_filinp_trace_batch_dir_i(Fl_File_Input*, void*) {
  cl_gts_master.cl_bro_trace_batch.cb_dir();
}
void gts_gui::cb_filinp_trace_batch_dir(Fl_File_Input* o, void* v) {
  ((gts_gui*)(o->parent()->user_data()))->cb_filinp_trace_batch_dir_i(o,v);
}

void gts_gui::cb_selbro_trace_batch_list_i(Fl_Browser*, void*) {
  cl_gts_master.cl_bro_trace_batch.cb_list();
}
void gts_gui::cb_selbro_trace_batch_list(Fl_Browser* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->parent()->user_data()))->cb_selbro_trace_batch_list_i(o,v);
}

void gts_gui::cb_Run_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_trace_batch.cb_run();
}
void gts_gui::cb_Run(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_Run_i(o,v);
}

void gts_gui::cb_Cancel3_i(Fl_Button*, void*) {
  cl_gts_master.cl_bro_trace_batch.cb_cancel();
}
void gts_gui::cb_Cancel3(Fl_Button* o, void* v) {
  ((gts_gui*)(o->parent()->parent()->user_data()))->cb_Cancel3_i(o,v);
}

Fl_Double_Window* gts_gui::make_window() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o= window_opengl= new Fl_Double_Window(200,25,"GTS");
    w = o;
    o->callback((Fl_Callback*)cb_window_opengl, (void*)(this));
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 200, 25);
      o->menu(menu_);
    }
    o->end();
    o->resizable(o);
  }
  { Fl_Double_Window* o = window_config_load = new Fl_Double_Window(300, 390, "Load Config");
    w = o;
    o->callback((Fl_Callback*)cb_window_config_load, (void*)(this));
    { Fl_Button* o = new Fl_Button(0, 0, 0, 0);
      o->shortcut(0x40075);
      o->callback((Fl_Callback*)cb_);
    }
    { Fl_File_Input* o = filinp_config_load_dir = new Fl_File_Input(0, 20, 300, 35, "Directory");
      o->box(FL_BORDER_BOX);
      o->callback((Fl_Callback*)cb_filinp_config_load_dir);
      o->align(FL_ALIGN_TOP_LEFT);
      o->when(FL_WHEN_CHANGED);
    }
    { Fl_Tile* o = new Fl_Tile(0, 60, 300, 265);
      { Fl_Group* o = new Fl_Group(0, 60, 150, 265);
        { Fl_Browser* o = selbro_config_load_list = new Fl_Browser(0, 60, 150, 265);
          o->type(2);
          o->box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_selbro_config_load_list);
          o->align(FL_ALIGN_CENTER);
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(150, 60, 150, 265);
        { Fl_Text_Display* o = txtdis_config_load_text = new Fl_Text_Display(150, 60, 150, 265);
          o->box(FL_DOWN_BOX);
          o->color(FL_LIGHT1);
          o->align(FL_ALIGN_CENTER);
        }
        o->end();
      }
      o->end();
      Fl_Group::current()->resizable(o);
    }
    { Fl_Group* o = new Fl_Group(0, 330, 300, 25);
      new Fl_Box(0, 330, 30, 25);
      { Fl_Input* o = strinp_config_load_file = new Fl_Input(30, 330, 270, 25, "File");
        o->box(FL_BORDER_BOX);
        o->when(FL_WHEN_CHANGED);
        Fl_Group::current()->resizable(o);
      }
      o->end();
    }
    { Fl_Group* o = new Fl_Group(0, 360, 300, 25);
      { Fl_Button* o = new Fl_Button(10, 360, 80, 25, "Load");
        o->callback((Fl_Callback*)cb_Load);
      }
      { Fl_Box* o = new Fl_Box(90, 360, 120, 25);
        Fl_Group::current()->resizable(o);
      }
      { Fl_Button* o = new Fl_Button(210, 360, 80, 25, "Cancel");
        o->callback((Fl_Callback*)cb_Cancel);
      }
      o->end();
    }
    o->set_non_modal();
    o->size_range(180, 125);
    o->end();
  }
  { Fl_Double_Window* o = window_config_save_as = new Fl_Double_Window(300, 390, "Save As Config");
    w = o;
    o->callback((Fl_Callback*)cb_window_config_save_as, (void*)(this));
    { Fl_Button* o = new Fl_Button(0, 0, 0, 0);
      o->shortcut(0x40075);
      o->callback((Fl_Callback*)cb_1);
    }
    { Fl_File_Input* o = filinp_config_save_as_dir = new Fl_File_Input(0, 20, 300, 35, "Directory");
      o->box(FL_BORDER_BOX);
      o->callback((Fl_Callback*)cb_filinp_config_save_as_dir);
      o->align(FL_ALIGN_TOP_LEFT);
      o->when(FL_WHEN_CHANGED);
    }
    { Fl_Tile* o = new Fl_Tile(0, 60, 300, 265);
      { Fl_Group* o = new Fl_Group(0, 60, 150, 265);
        { Fl_Browser* o = selbro_config_save_as_list = new Fl_Browser(0, 60, 150, 265);
          o->type(2);
          o->box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_selbro_config_save_as_list);
          o->align(FL_ALIGN_CENTER);
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(150, 60, 150, 265);
        { Fl_Text_Display* o = txtdis_config_save_as_text = new Fl_Text_Display(150, 60, 150, 265);
          o->box(FL_DOWN_BOX);
          o->color(FL_LIGHT1);
          o->align(FL_ALIGN_CENTER);
        }
        o->end();
      }
      o->end();
      Fl_Group::current()->resizable(o);
    }
    { Fl_Group* o = new Fl_Group(0, 330, 300, 25);
      new Fl_Box(0, 330, 30, 25);
      { Fl_Input* o = strinp_config_save_as_file = new Fl_Input(30, 330, 270, 25, "File");
        o->box(FL_BORDER_BOX);
        o->when(FL_WHEN_CHANGED);
        Fl_Group::current()->resizable(o);
      }
      o->end();
    }
    { Fl_Group* o = new Fl_Group(0, 360, 300, 25);
      { Fl_Button* o = new Fl_Button(10, 360, 80, 25, "Save");
        o->callback((Fl_Callback*)cb_Save);
      }
      { Fl_Box* o = new Fl_Box(90, 360, 120, 25);
        Fl_Group::current()->resizable(o);
      }
      { Fl_Button* o = new Fl_Button(210, 360, 80, 25, "Cancel");
        o->callback((Fl_Callback*)cb_Cancel1);
      }
      o->end();
    }
    o->set_non_modal();
    o->size_range(180, 125);
    o->end();
  }
  { Fl_Double_Window* o = window_level = new Fl_Double_Window(350, 570, "Browse Level");
    w = o;
    o->callback((Fl_Callback*)cb_window_level, (void*)(this));
    { Fl_Button* o = new Fl_Button(0, 0, 0, 0);
      o->shortcut(0x40075);
      o->callback((Fl_Callback*)cb_2);
    }
    { Fl_File_Input* o = filinp_level_dir = new Fl_File_Input(0, 20, 350, 35, "Directory");
      o->box(FL_BORDER_BOX);
      o->callback((Fl_Callback*)cb_filinp_level_dir);
      o->align(FL_ALIGN_TOP_LEFT);
      o->when(FL_WHEN_CHANGED);
    }
    { Fl_Group* o = new Fl_Group(0, 60, 350, 25);
      { Fl_Choice* o = choice_level_list_form = new Fl_Choice(5, 60, 80, 25);
        o->down_box(FL_BORDER_BOX);
        o->callback((Fl_Callback*)cb_choice_level_list_form);
        o->menu(menu_choice_level_list_form);
      }
      { Fl_Button* o = new Fl_Button(90, 60, 60, 25, "Makedir");
        o->callback((Fl_Callback*)cb_Makedir);
      }
      { Fl_Button* o = new Fl_Button(155, 60, 60, 25, "Rename");
        o->callback((Fl_Callback*)cb_Rename);
      }
      { Fl_Button* o = button_level_shift_number = new Fl_Button(220, 60, 85, 25, "Shift number");
        o->callback((Fl_Callback*)cb_button_level_shift_number);
        o->hide();
      }
      { Fl_Box* o = new Fl_Box(305, 60, 45, 25);
        Fl_Group::current()->resizable(o);
      }
      o->end();
    }
    { Fl_Tile* o = new Fl_Tile(0, 90, 350, 330);
      o->align(FL_ALIGN_CENTER);
      { Fl_Group* o = new Fl_Group(0, 90, 150, 330);
        o->box(FL_DOWN_BOX);
        { Fl_Browser* o = selbro_level_list = new Fl_Browser(0, 90, 150, 330);
          o->type(2);
          o->callback((Fl_Callback*)cb_selbro_level_list);
          o->align(FL_ALIGN_CENTER);
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(150, 90, 200, 150);
        o->box(FL_DOWN_BOX);
        box_level_image = new Fl_Box(150, 90, 200, 150);
        o->end();
      }
      { Fl_Group* o = new Fl_Group(150, 240, 200, 180);
        o->box(FL_DOWN_BOX);
        { Fl_Text_Display* o = txtdis_level_info = new Fl_Text_Display(150, 240, 200, 155);
          o->color(FL_LIGHT1);
          o->align(FL_ALIGN_LEFT);
          Fl_Group::current()->resizable(o);
        }
        { Fl_Group* o = new Fl_Group(150, 395, 200, 25);
          { Fl_Scrollbar* o = scroll_level_info_number = new Fl_Scrollbar(150, 395, 160, 25);
            o->type(1);
            o->box(FL_BORDER_BOX);
            o->callback((Fl_Callback*)cb_scroll_level_info_number);
            o->when(FL_WHEN_RELEASE);
            Fl_Group::current()->resizable(o);
          }
          { Fl_Value_Input* o = valinp_level_crnt = new Fl_Value_Input(310, 395, 40, 25);
            o->minimum(1);
            o->maximum(9999);
            o->value(1);
            o->callback((Fl_Callback*)cb_valinp_level_crnt);
            o->when(FL_WHEN_ENTER_KEY);
          }
          o->end();
        }
        o->end();
      }
      o->end();
      Fl_Group::current()->resizable(o);
    }
    { Fl_Group* o = new Fl_Group(0, 425, 350, 25);
      new Fl_Box(0, 425, 40, 25);
      { Fl_Input* o = strinp_level_file = new Fl_Input(40, 425, 310, 25, "Level");
        o->box(FL_BORDER_BOX);
        Fl_Group::current()->resizable(o);
      }
      o->end();
    }
    { Fl_Group* o = new Fl_Group(0, 455, 350, 25);
      { Fl_Value_Input* o = valinp_level_start = new Fl_Value_Input(40, 455, 40, 25, "Start");
        o->box(FL_BORDER_BOX);
        o->minimum(1);
        o->maximum(9999);
        o->value(1);
      }
      { Fl_Value_Input* o = valinp_level_end = new Fl_Value_Input(110, 455, 40, 25, "End");
        o->box(FL_BORDER_BOX);
        o->minimum(1);
        o->maximum(9999);
        o->value(1);
      }
      { Fl_Box* o = new Fl_Box(150, 455, 60, 25);
        Fl_Group::current()->resizable(o);
      }
      { Fl_Light_Button* o = ligbut_level_image_x1_sw = new Fl_Light_Button(210, 455, 35, 25, "x1");
        o->callback((Fl_Callback*)cb_ligbut_level_image_x1_sw);
      }
      { Fl_Light_Button* o = ligbut_level_view_sw = new Fl_Light_Button(250, 455, 95, 25, "View image");
        o->callback((Fl_Callback*)cb_ligbut_level_view_sw);
      }
      o->end();
    }
    { Fl_Group* o = new Fl_Group(0, 485, 350, 50);
      { Fl_File_Input* o = filinp_level_rgb_scan_dir = new Fl_File_Input(0, 500, 165, 35, "RGB scan dir");
        o->callback((Fl_Callback*)cb_filinp_level_rgb_scan_dir);
        o->align(FL_ALIGN_TOP_LEFT);
        o->when(FL_WHEN_CHANGED);
        o->deactivate();
        Fl_Group::current()->resizable(o);
      }
      { Fl_Check_Button* o = chkbtn_level_rgb_trace_save_sw = new Fl_Check_Button(165, 515, 55, 20, "S.C.T.");
        o->tooltip("Save Color Trace level");
        o->down_box(FL_DOWN_BOX);
      }
      { Fl_Light_Button* o = ligbut_level_rgb_scan_browse_sw = new Fl_Light_Button(225, 510, 70, 25, "Browse");
        o->callback((Fl_Callback*)cb_ligbut_level_rgb_scan_browse_sw);
      }
      { Fl_Light_Button* o = ligbut_level_info_rgb_sub_sw = new Fl_Light_Button(300, 510, 45, 25, "Full");
        o->callback((Fl_Callback*)cb_ligbut_level_info_rgb_sub_sw);
        o->hide();
      }
      o->end();
    }
    { Fl_Group* o = new Fl_Group(0, 540, 350, 25);
      { Fl_Button* o = new Fl_Button(10, 540, 80, 25, "OK");
        o->callback((Fl_Callback*)cb_OK);
      }
      { Fl_Box* o = new Fl_Box(90, 540, 170, 25);
        Fl_Group::current()->resizable(o);
      }
      { Fl_Button* o = new Fl_Button(260, 540, 80, 25, "Cancel");
        o->callback((Fl_Callback*)cb_Cancel2);
      }
      o->end();
    }
    o->set_non_modal();
    o->size_range(310, 265);
    o->end();
  }
  { Fl_Double_Window* o = window_x1view = new Fl_Double_Window(300, 300, "x1");
    w = o;
    o->callback((Fl_Callback*)cb_window_x1view, (void*)(this));
    o->align(FL_ALIGN_CENTER);
    { Fl_Scroll* o = scroll_level_x1view = new Fl_Scroll(0, 0, 300, 300);
      o->align(FL_ALIGN_CENTER);
      box_level_x1view = new Fl_Box(0, 0, 300, 300);
      o->end();
      Fl_Group::current()->resizable(o);
    }
    o->set_non_modal();
    o->end();
  }
  { Fl_Double_Window* o = window_trace_batch = new Fl_Double_Window(300, 415, "Color Trace Batch");
    w = o;
    o->callback((Fl_Callback*)cb_window_trace_batch, (void*)(this));
    { Fl_Button* o = new Fl_Button(0, 0, 0, 0);
      o->shortcut(0x40075);
      o->callback((Fl_Callback*)cb_3);
    }
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 300, 25);
      o->menu(menu_1);
    }
    { Fl_File_Input* o = filinp_trace_batch_dir = new Fl_File_Input(0, 40, 300, 35, "Directory");
      o->box(FL_BORDER_BOX);
      o->callback((Fl_Callback*)cb_filinp_trace_batch_dir);
      o->align(FL_ALIGN_TOP_LEFT);
      o->when(FL_WHEN_CHANGED);
    }
    { Fl_Tile* o = new Fl_Tile(0, 80, 300, 300);
      { Fl_Group* o = new Fl_Group(0, 80, 150, 150);
        { Fl_Browser* o = selbro_trace_batch_list = new Fl_Browser(0, 80, 150, 150);
          o->type(2);
          o->box(FL_DOWN_BOX);
          o->callback((Fl_Callback*)cb_selbro_trace_batch_list);
          o->align(FL_ALIGN_CENTER);
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(150, 80, 150, 150);
        { Fl_Text_Display* o = txtdis_trace_batch_text = new Fl_Text_Display(150, 80, 150, 150);
          o->box(FL_DOWN_BOX);
          o->color(FL_LIGHT1);
          o->align(FL_ALIGN_CENTER);
        }
        o->end();
      }
      { Fl_Group* o = new Fl_Group(0, 230, 300, 150);
        { Fl_Browser* o = selbro_trace_batch_run_list = new Fl_Browser(0, 230, 300, 150);
          o->type(3);
          o->box(FL_DOWN_BOX);
        }
        o->end();
      }
      o->end();
      Fl_Group::current()->resizable(o);
    }
    { Fl_Group* o = new Fl_Group(0, 385, 300, 25);
      { Fl_Button* o = new Fl_Button(10, 385, 80, 25, "Run");
        o->callback((Fl_Callback*)cb_Run);
      }
      { Fl_Box* o = new Fl_Box(90, 385, 120, 25);
        Fl_Group::current()->resizable(o);
      }
      { Fl_Button* o = new Fl_Button(210, 385, 80, 25, "Cancel");
        o->callback((Fl_Callback*)cb_Cancel3);
      }
      o->end();
    }
    o->set_non_modal();
    o->size_range(180, 125);
    o->end();
  }
  return w;
}
gts_gui cl_gts_gui;
