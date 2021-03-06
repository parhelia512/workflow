#include "instance_unit_info.h"
#include "wfApp.h"
#include <wx/choicdlg.h>
#include <wx/textdlg.h>
#include "pugixml.hpp"
#include <wx/textfile.h>
#include <wx/progdlg.h>
#include <wx/tokenzr.h>
#include "wf_stdafx.h"
#include "mydatepicker.h"
#include "ins_proc_log.h"
#include "ins_nonstd_proc_log.h"
#include "nstd_mat_task_list.h"
#include "search_case.h"
#include <wx/utils.h>
#include "review_remarks_dlg.h"
#include "datepickerdlg.h"
#include <wx/filefn.h>
#include <wx/dir.h>
#include "unit_info_attach_dlg.h"
#include "contract_label_print.h"
#include "contractbook_br_dlg.h"

//(*InternalHeaders(instance_unit_info)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(instance_unit_info)
const long instance_unit_info::ID_LISTCTRL_PROJECT = wxNewId();
const long instance_unit_info::ID_BUTTON_START_REVIEW = wxNewId();
const long instance_unit_info::ID_BUTTON_START_CONFIGURE = wxNewId();
const long instance_unit_info::ID_BUTTON_RESTART = wxNewId();
const long instance_unit_info::ID_BUTTON_CANCEL_RESTART = wxNewId();
const long instance_unit_info::ID_BUTTON_CANCEL_PROJECT = wxNewId();
const long instance_unit_info::ID_BUTTON_RESTORE_PROJECT = wxNewId();
const long instance_unit_info::ID_BUTTON_DEL_PROJECT = wxNewId();
const long instance_unit_info::ID_BUTTON_IMPORT = wxNewId();
const long instance_unit_info::ID_BUTTON_PRE_PRODUCTION = wxNewId();
const long instance_unit_info::ID_BUTTON_CANCEL_PRODUCTION = wxNewId();
const long instance_unit_info::ID_BUTTON_SAP_BY_WBS = wxNewId();
const long instance_unit_info::ID_BUTTON_BY_INTERNAL_DATE = wxNewId();
const long instance_unit_info::ID_BUTTON_NSTD_SAP_UPDATE = wxNewId();
const long instance_unit_info::ID_BUTTON_BASIC_INFO = wxNewId();
const long instance_unit_info::ID_BUTTON_SYC_TO_DIN = wxNewId();
const long instance_unit_info::ID_BUTTON1 = wxNewId();
const long instance_unit_info::ID_GRID_UNIT_INFO = wxNewId();
const long instance_unit_info::idMenu_SelAll = wxNewId();
const long instance_unit_info::idMenu_UnSel = wxNewId();
const long instance_unit_info::idMenu_MC2_H = wxNewId();
const long instance_unit_info::idMenu_export_xls = wxNewId();
const long instance_unit_info::idMenu_print_label = wxNewId();
const long instance_unit_info::idMenu_ReviewFlow = wxNewId();
const long instance_unit_info::idMenu_ProcFlow = wxNewId();
const long instance_unit_info::idMenu_Nstd_workflow = wxNewId();
const long instance_unit_info::idMenu_nstd_mat_maintain = wxNewId();
const long instance_unit_info::idMenu_nstd_design = wxNewId();
const long instance_unit_info::idMenu_nonstd_item = wxNewId();
const long instance_unit_info::idMenu_Weight = wxNewId();
const long instance_unit_info::idMenu_in_contract = wxNewId();
const long instance_unit_info::idMenu_hex = wxNewId();
const long instance_unit_info::idMenu_ReqDelv = wxNewId();
const long instance_unit_info::idMenu_ReqFin = wxNewId();
const long instance_unit_info::idMenu_PrjCata = wxNewId();
const long instance_unit_info::idMenu_Urgent = wxNewId();
const long instance_unit_info::idMenu_NonStd = wxNewId();
const long instance_unit_info::idMenu_special_Info = wxNewId();
const long instance_unit_info::idMenu_Update = wxNewId();
const long instance_unit_info::idMenu_unFreezed = wxNewId();
const long instance_unit_info::idMenu_CANRESTART = wxNewId();
const long instance_unit_info::idMenu_generate_contract = wxNewId();
const long instance_unit_info::idMenu_Search_contract = wxNewId();
const long instance_unit_info::idMenu_Contract_id = wxNewId();
const long instance_unit_info::idMenu_contract_br_search = wxNewId();
const long instance_unit_info::idMenu_ContractBook_Search = wxNewId();
const long instance_unit_info::idMenu_Change_Lender = wxNewId();
const long instance_unit_info::idMenu_create_folder = wxNewId();
const long instance_unit_info::idMenu_All = wxNewId();
const long instance_unit_info::idMenu_NSTD_LEVEL = wxNewId();
const long instance_unit_info::idMenu_UnSt = wxNewId();
const long instance_unit_info::idMenu_Motion = wxNewId();
const long instance_unit_info::idMenu_Finish = wxNewId();
const long instance_unit_info::idMenu_Pre_production = wxNewId();
const long instance_unit_info::idMenu_Closed = wxNewId();
const long instance_unit_info::idMenu_InDoc = wxNewId();
const long instance_unit_info::idMenu_Freeze = wxNewId();
const long instance_unit_info::idMenu_Cancel = wxNewId();
const long instance_unit_info::idMenu_contract_id = wxNewId();
const long instance_unit_info::idMenu_Prj = wxNewId();
const long instance_unit_info::idMenu_Wbs = wxNewId();
const long instance_unit_info::idMenu_Project_name = wxNewId();
const long instance_unit_info::idMenu_delivery_date = wxNewId();
const long instance_unit_info::idMenu_delv_mc2_h = wxNewId();
const long instance_unit_info::idMenu_Filt_basic_info = wxNewId();
const long instance_unit_info::idMenu_syc_din_units = wxNewId();
//*)

BEGIN_EVENT_TABLE(instance_unit_info, wxPanel)
    //(*EventTable(instance_unit_info)
    //*)
END_EVENT_TABLE()

instance_unit_info::instance_unit_info(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
{
    //(*Initialize(instance_unit_info)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;

    Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL|wxNO_FULL_REPAINT_ON_RESIZE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("项目信息"));
    lc_project = new wxListCtrl(this, ID_LISTCTRL_PROJECT, wxDefaultPosition, wxSize(533,165), wxLC_REPORT|wxLC_HRULES|wxLC_VRULES, wxDefaultValidator, _T("ID_LISTCTRL_PROJECT"));
    StaticBoxSizer1->Add(lc_project, 3, wxALL|wxEXPAND, 0);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    Button2 = new wxButton(this, ID_BUTTON_START_REVIEW, _("启动评审"), wxDefaultPosition, wxSize(100,23), 0, wxDefaultValidator, _T("ID_BUTTON_START_REVIEW"));
    Button2->SetToolTip(_("启动评审"));
    BoxSizer3->Add(Button2, 1, wxALL|wxEXPAND, 0);
    Button3 = new wxButton(this, ID_BUTTON_START_CONFIGURE, _("启动配置"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_START_CONFIGURE"));
    Button3->SetToolTip(_("启动配置的前提条件：项目评审完成，同时确定配置完成日期。"));
    BoxSizer3->Add(Button3, 1, wxALL|wxEXPAND, 0);
    Button4 = new wxButton(this, ID_BUTTON_RESTART, _("重排产"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RESTART"));
    Button4->SetToolTip(_("重排产的条件是项目配置必须已经完成。"));
    BoxSizer3->Add(Button4, 1, wxALL|wxEXPAND, 0);
    button_cancel_restart = new wxButton(this, ID_BUTTON_CANCEL_RESTART, _("取消重排产"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL_RESTART"));
    BoxSizer3->Add(button_cancel_restart, 1, wxALL|wxEXPAND, 0);
    Button_Cancel_project = new wxButton(this, ID_BUTTON_CANCEL_PROJECT, _("取消排产"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL_PROJECT"));
    Button_Cancel_project->SetToolTip(_("启动的项目,流程数据存储在log中，项目打‘CANCEL\'标识。"));
    BoxSizer3->Add(Button_Cancel_project, 1, wxALL|wxEXPAND, 0);
    Button_Restore_project = new wxButton(this, ID_BUTTON_RESTORE_PROJECT, _("恢复排产"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_RESTORE_PROJECT"));
    Button_Restore_project->SetToolTip(_("\'CANCEL\'的项目恢复排产，从项目授权启动"));
    BoxSizer3->Add(Button_Restore_project, 1, wxALL|wxEXPAND, 0);
    Button_DEL_project = new wxButton(this, ID_BUTTON_DEL_PROJECT, _("项目删除"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_DEL_PROJECT"));
    Button_DEL_project->SetToolTip(_("彻底删除项目和项目流程数据"));
    BoxSizer3->Add(Button_DEL_project, 1, wxALL|wxEXPAND, 0);
    StaticBoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 0);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    Button1 = new wxButton(this, ID_BUTTON_IMPORT, _("导入项目"), wxDefaultPosition, wxSize(83,23), 0, wxDefaultValidator, _T("ID_BUTTON_IMPORT"));
    Button1->SetToolTip(_("从外部文件或SAP导入项目信息"));
    BoxSizer2->Add(Button1, 1, wxALL|wxEXPAND, 0);
    Button_Pre_Production = new wxButton(this, ID_BUTTON_PRE_PRODUCTION, _("排产计划"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_PRE_PRODUCTION"));
    BoxSizer2->Add(Button_Pre_Production, 1, wxALL|wxEXPAND, 0);
    Button_cancel_production = new wxButton(this, ID_BUTTON_CANCEL_PRODUCTION, _("取消排产计划"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_CANCEL_PRODUCTION"));
    BoxSizer2->Add(Button_cancel_production, 1, wxALL|wxEXPAND, 0);
    button_sap_by_wbs = new wxButton(this, ID_BUTTON_SAP_BY_WBS, _("按WBS NO从SAP导入"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SAP_BY_WBS"));
    BoxSizer2->Add(button_sap_by_wbs, 1, wxALL|wxEXPAND, 0);
    button_sap_by_internal = new wxButton(this, ID_BUTTON_BY_INTERNAL_DATE, _("根据启动日期从SAP导入"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_BY_INTERNAL_DATE"));
    BoxSizer2->Add(button_sap_by_internal, 1, wxALL|wxEXPAND, 0);
    Button_NSTD_SAP_UPDATE = new wxButton(this, ID_BUTTON_NSTD_SAP_UPDATE, _("SAP中非标等级确认已更新"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_NSTD_SAP_UPDATE"));
    BoxSizer2->Add(Button_NSTD_SAP_UPDATE, 1, wxALL|wxEXPAND, 0);
    Button_Cal_Basic_Info = new wxButton(this, ID_BUTTON_BASIC_INFO, _("同步计算项目基本信息"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_BASIC_INFO"));
    BoxSizer2->Add(Button_Cal_Basic_Info, 1, wxALL|wxEXPAND, 0);
    Button_syc_to_din = new wxButton(this, ID_BUTTON_SYC_TO_DIN, _("同步信息到DIN"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON_SYC_TO_DIN"));
    BoxSizer2->Add(Button_syc_to_din, 1, wxALL|wxEXPAND, 0);
    Button5 = new wxButton(this, ID_BUTTON1, _("项目release"), wxDefaultPosition, wxSize(178,24), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button5->Hide();
    Button5->SetToolTip(_("项目归档是将已经发运完成的项目从流程状态排除，加快系统处理速度"));
    BoxSizer2->Add(Button5, 1, wxALL|wxEXPAND, 0);
    StaticBoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_TOP, 0);
    BoxSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 0);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Unit信息"));
    gd_unit_info = new sqlResultGrid(this, ID_GRID_UNIT_INFO, wxDefaultPosition, wxDefaultSize);
    StaticBoxSizer2->Add(gd_unit_info, 1, wxALL|wxEXPAND, 0);
    BoxSizer1->Add(StaticBoxSizer2, 5, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    MenuItem1 = new wxMenuItem((&menu_unit_info_renew), idMenu_SelAll, _("全选(&A)\tA"), _("选择所有列"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem1);
    MenuItem2 = new wxMenuItem((&menu_unit_info_renew), idMenu_UnSel, _("取消选择(&C)\tC"), _("取消选择"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem2);
    menu_unit_info_renew.AppendSeparator();
    mi_mc2_h = new wxMenuItem((&menu_unit_info_renew), idMenu_MC2_H, _("导出MC2-H项目(同一项目1台）"), _("导出MC2-H项目"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(mi_mc2_h);
    mi_Excel_export = new wxMenuItem((&menu_unit_info_renew), idMenu_export_xls, _("导出EXCEL(&X)\tX"), _("导出EXCEL"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(mi_Excel_export);
    mi_print_label = new wxMenuItem((&menu_unit_info_renew), idMenu_print_label, _("打印标签(&L)\tL"), _("打印标签"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(mi_print_label);
    menu_unit_info_renew.AppendSeparator();
    menu_unit_info_renew.Break();
    menu_unit_info_renew.Break();
    menu_unit_info_renew.AppendSeparator();
    MenuItem_Review = new wxMenuItem((&menu_unit_info_renew), idMenu_ReviewFlow, _("项目评审流程信息(&V)"), _("项目评审流程信息"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem_Review);
    MenuItem18 = new wxMenuItem((&menu_unit_info_renew), idMenu_ProcFlow, _("项目配置流程信息(&W)"), _("项目流程信息"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem18);
    MenuItem21 = new wxMenuItem((&menu_unit_info_renew), idMenu_Nstd_workflow, _("非标申请工作流(&T)"), _("非标申请工作流"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem21);
    MenuItem22 = new wxMenuItem((&menu_unit_info_renew), idMenu_nstd_mat_maintain, _("非标物料维护工作流(&M)"), _("非标物料维护工作流"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem22);
    MenuItem23 = new wxMenuItem((&menu_unit_info_renew), idMenu_nstd_design, _("非标设计工作流(&S)"), _("非标设计工作流"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem23);
    MenuItem24 = new wxMenuItem((&menu_unit_info_renew), idMenu_nonstd_item, _("显示非标选项(&H)"), _("显示非标选项"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem24);
    MenuItem_Weight = new wxMenuItem((&menu_unit_info_renew), idMenu_Weight, _("显示轿厢空重和装潢重量(&D)"), _("显示轿厢空重和装潢重量"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem_Weight);
    mi_unit_in_contract = new wxMenuItem((&menu_unit_info_renew), idMenu_in_contract, _("unit资料文档信息(&I)"), _("unit资料文档信息"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(mi_unit_in_contract);
    mi_hex = new wxMenuItem((&menu_unit_info_renew), idMenu_hex, _("获取项目随行电缆|钢丝绳|补偿链单重HEX数值(&E)"), _("获取项目随行电缆|钢丝绳|补偿链单重HEX数值"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(mi_hex);
    menu_unit_info_renew.AppendSeparator();
    MenuItem3 = new wxMenuItem((&menu_unit_info_renew), idMenu_ReqDelv, _("变更发货期(&D)"), _("变更发货期"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem3);
    MenuItem3->Enable(false);
    MenuItem4 = new wxMenuItem((&menu_unit_info_renew), idMenu_ReqFin, _("变更配置完成日期(&F)"), _("变更配置完成日期"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem4);
    MenuItem4->Enable(false);
    MenuItem5 = new wxMenuItem((&menu_unit_info_renew), idMenu_PrjCata, _("变更项目类型(&P)"), _("变革项目类型"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem5);
    MenuItem5->Enable(false);
    mi_urgent = new wxMenuItem((&menu_unit_info_renew), idMenu_Urgent, _("紧急项目(&R)"), _("是否紧急项目切换"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(mi_urgent);
    mi_urgent->Enable(false);
    MenuItem7 = new wxMenuItem((&menu_unit_info_renew), idMenu_NonStd, _("非标等级切换(&N)"), _("非标等级选择"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem7);
    MenuItem7->Enable(false);
    mi_special_info = new wxMenuItem((&menu_unit_info_renew), idMenu_special_Info, _("增加特殊标识(&X)"), _("增加特殊标识"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(mi_special_info);
    MenuItem8 = new wxMenuItem((&menu_unit_info_renew), idMenu_Update, _("暂停项目(&Z)"), _("暂停项目"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem8);
    MenuItem8->Enable(false);
    MenuItem19 = new wxMenuItem((&menu_unit_info_renew), idMenu_unFreezed, _("恢复项目(&U)"), _("恢复项目"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem19);
    MenuItem19->Enable(false);
    MenuItem20 = new wxMenuItem((&menu_unit_info_renew), idMenu_CANRESTART, _("取消重排产(&Q)"), _("取消重排产"), wxITEM_NORMAL);
    menu_unit_info_renew.Append(MenuItem20);
    MenuItem20->Enable(false);
    mi_generate_contract = new wxMenuItem((&menu_project_filter), idMenu_generate_contract, _("生成合同文档(&G)"), _("生成合同文档"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_generate_contract);
    mi_search_contract = new wxMenuItem((&menu_project_filter), idMenu_Search_contract, _("查询合同文档(&S)"), _("查询和处理合同文档"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_search_contract);
    mi_add_contract_id = new wxMenuItem((&menu_project_filter), idMenu_Contract_id, _("补全项目合同号(&F)"), _("补全项目合同号"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_add_contract_id);
    menu_project_filter.AppendSeparator();
    mi_contract_br_search = new wxMenuItem((&menu_project_filter), idMenu_contract_br_search, _("项目合同借阅查询"), _("项目合同借阅查询"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_contract_br_search);
    mi_cb_search = new wxMenuItem((&menu_project_filter), idMenu_ContractBook_Search, _("列表中选择合同借阅查询"), _("列表中选择项目合同借阅查询"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_cb_search);
    mi_cb_lender = new wxMenuItem((&menu_project_filter), idMenu_Change_Lender, _("项目合同借阅人转借"), _("项目合同借阅人转借"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_cb_lender);
    menu_project_filter.AppendSeparator();
    mi_folder = new wxMenuItem((&menu_project_filter), idMenu_create_folder, _("创建文件夹"), _("创建文件夹"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_folder);
    menu_project_filter.AppendSeparator();
    MenuItem9 = new wxMenuItem((&menu_project_filter), idMenu_All, _("全部项目(&A)"), _("显示全部项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem9);
    MenuItem9->Enable(false);
    MenuItem26 = new wxMenuItem((&menu_project_filter), idMenu_NSTD_LEVEL, _("SAP中非标等级待更新的项目(&T)"), _("非标等级变更的项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem26);
    MenuItem10 = new wxMenuItem((&menu_project_filter), idMenu_UnSt, _("未启动项目(&U)"), _("未启动项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem10);
    MenuItem12 = new wxMenuItem((&menu_project_filter), idMenu_Motion, _("活动状态的项目(&M)"), _("正在走流程的项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem12);
    MenuItem11 = new wxMenuItem((&menu_project_filter), idMenu_Finish, _("评审完成的项目(&R)"), _("已经完成的项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem11);
    mi_pre_production = new wxMenuItem((&menu_project_filter), idMenu_Pre_production, _("启动排产项目"), _("启动排产项目"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_pre_production);
    MenuItem15 = new wxMenuItem((&menu_project_filter), idMenu_Closed, _("配置完成的项目(&C)"), _("配置完成的项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem15);
    MenuItem16 = new wxMenuItem((&menu_project_filter), idMenu_InDoc, _("Released的项目(&D)"), _("归档的项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem16);
    MenuItem17 = new wxMenuItem((&menu_project_filter), idMenu_Freeze, _("暂停的项目(&F)"), _("暂停的项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem17);
    MenuItem25 = new wxMenuItem((&menu_project_filter), idMenu_Cancel, _("取消排产的项目(&N)"), _("取消排产的项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem25);
    mi_contract = new wxMenuItem((&menu_project_filter), idMenu_contract_id, _("按合同号筛选(&O)"), _("按合同号筛选"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_contract);
    MenuItem13 = new wxMenuItem((&menu_project_filter), idMenu_Prj, _("按Project筛选(&P)"), _("按项目筛选"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem13);
    MenuItem14 = new wxMenuItem((&menu_project_filter), idMenu_Wbs, _("按WBS NO筛选(&W)"), _("按WBS NO筛选"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem14);
    mi_proj_name = new wxMenuItem((&menu_project_filter), idMenu_Project_name, _("按项目名称筛选(&E)"), _("按项目名称筛选"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_proj_name);
    mi_delivery_date = new wxMenuItem((&menu_project_filter), idMenu_delivery_date, _("按发运日期筛选(&T)"), _("按发运日期筛选"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_delivery_date);
    mi_delv_mc2_h = new wxMenuItem((&menu_project_filter), idMenu_delv_mc2_h, _("按发运日期筛选MC2-H项目"), _("按发运日期筛选MC2-H项目"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_delv_mc2_h);
    MenuItem_Basic_Info = new wxMenuItem((&menu_project_filter), idMenu_Filt_basic_info, _("需同步基本信息的项目(&B)"), _("列出所有需同步基本信息的项目"), wxITEM_NORMAL);
    menu_project_filter.Append(MenuItem_Basic_Info);
    mi_syc_din = new wxMenuItem((&menu_project_filter), idMenu_syc_din_units, _("需同步DIN系统的项目(&Y)"), _("需同步DIN系统的项目"), wxITEM_NORMAL);
    menu_project_filter.Append(mi_syc_din);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_LISTCTRL_PROJECT,wxEVT_COMMAND_LIST_ITEM_ACTIVATED,(wxObjectEventFunction)&instance_unit_info::Onlc_projectItemActivated);
    Connect(ID_LISTCTRL_PROJECT,wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK,(wxObjectEventFunction)&instance_unit_info::Onlc_projectItemRClick);
    Connect(ID_LISTCTRL_PROJECT,wxEVT_COMMAND_LIST_COL_RIGHT_CLICK,(wxObjectEventFunction)&instance_unit_info::Onlc_projectItemRClick);
    Connect(ID_BUTTON_START_REVIEW,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton2Click);
    Connect(ID_BUTTON_START_CONFIGURE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton3Click);
    Connect(ID_BUTTON_RESTART,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton4Click);
    Connect(ID_BUTTON_CANCEL_RESTART,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::Onbutton_cancel_restartClick);
    Connect(ID_BUTTON_CANCEL_PROJECT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton_Cancel_projectClick);
    Connect(ID_BUTTON_RESTORE_PROJECT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton_Restore_projectClick);
    Connect(ID_BUTTON_DEL_PROJECT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton_DEL_projectClick);
    Connect(ID_BUTTON_IMPORT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton1Click);
    Connect(ID_BUTTON_PRE_PRODUCTION,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton_Pre_ProductionClick);
    Connect(ID_BUTTON_CANCEL_PRODUCTION,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton_cancel_productionClick);
    Connect(ID_BUTTON_SAP_BY_WBS,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::Onbutton_sap_by_wbsClick);
    Connect(ID_BUTTON_BY_INTERNAL_DATE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::Onbutton_sap_by_internalClick);
    Connect(ID_BUTTON_NSTD_SAP_UPDATE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton_NSTD_SAP_UPDATEClick);
    Connect(ID_BUTTON_BASIC_INFO,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton_Cal_Basic_InfoClick);
    Connect(ID_BUTTON_SYC_TO_DIN,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton_syc_to_dinClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&instance_unit_info::OnButton5Click);
    Connect(ID_GRID_UNIT_INFO,wxEVT_GRID_CELL_RIGHT_CLICK,(wxObjectEventFunction)&instance_unit_info::Ongd_unit_infoCellRightClick);
    Connect(ID_GRID_UNIT_INFO,wxEVT_GRID_LABEL_RIGHT_CLICK,(wxObjectEventFunction)&instance_unit_info::Ongd_unit_infoCellRightClick);
    Connect(idMenu_SelAll,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem1Selected);
    Connect(idMenu_UnSel,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem2Selected);
    Connect(idMenu_MC2_H,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_mc2_hSelected);
    Connect(idMenu_export_xls,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_Excel_exportSelected);
    Connect(idMenu_print_label,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_print_labelSelected);
    Connect(idMenu_ReviewFlow,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem_ReviewSelected);
    Connect(idMenu_ProcFlow,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem18Selected);
    Connect(idMenu_Nstd_workflow,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem21Selected);
    Connect(idMenu_nstd_mat_maintain,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem22Selected);
    Connect(idMenu_nstd_design,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem23Selected);
    Connect(idMenu_nonstd_item,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem24Selected);
    Connect(idMenu_Weight,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem_WeightSelected);
    Connect(idMenu_in_contract,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_unit_in_contractSelected);
    Connect(idMenu_hex,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_hexSelected);
    Connect(idMenu_ReqDelv,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem3Selected);
    Connect(idMenu_ReqFin,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem4Selected);
    Connect(idMenu_PrjCata,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem5Selected);
    Connect(idMenu_Urgent,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem6Selected);
    Connect(idMenu_NonStd,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem7Selected);
    Connect(idMenu_special_Info,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_special_infoSelected);
    Connect(idMenu_Update,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem8Selected);
    Connect(idMenu_unFreezed,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem19Selected);
    Connect(idMenu_CANRESTART,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem20Selected);
    Connect(idMenu_generate_contract,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_generate_contractSelected);
    Connect(idMenu_Search_contract,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_search_contractSelected);
    Connect(idMenu_Contract_id,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_add_contract_idSelected);
    Connect(idMenu_contract_br_search,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_contract_br_searchSelected);
    Connect(idMenu_ContractBook_Search,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_contractbook_searchSelected);
    Connect(idMenu_Change_Lender,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_change_lenderSelected);
    Connect(idMenu_create_folder,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_folderSelected);
    Connect(idMenu_All,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem9Selected);
    Connect(idMenu_NSTD_LEVEL,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem26Selected);
    Connect(idMenu_UnSt,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem10Selected);
    Connect(idMenu_Motion,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem12Selected);
    Connect(idMenu_Finish,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem11Selected);
    Connect(idMenu_Pre_production,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_pre_productionSelected);
    Connect(idMenu_Closed,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem15Selected);
    Connect(idMenu_InDoc,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem16Selected);
    Connect(idMenu_Freeze,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem17Selected);
    Connect(idMenu_Cancel,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem25Selected);
    Connect(idMenu_contract_id,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_contractSelected);
    Connect(idMenu_Prj,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem13Selected);
    Connect(idMenu_Wbs,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem14Selected);
    Connect(idMenu_Project_name,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_proj_nameSelected);
    Connect(idMenu_delivery_date,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_delivery_dateSelected);
    Connect(idMenu_delv_mc2_h,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_delv_mc2_hSelected);
    Connect(idMenu_Filt_basic_info,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::OnMenuItem_Basic_InfoSelected);
    Connect(idMenu_syc_din_units,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&instance_unit_info::Onmi_syc_dinSelected);
    //*)

    wxSize page_size(60, 30);

    g_printData->SetPaperId(wxPaperSize(0));

    g_printData->SetPaperSize(page_size);

    Show_control();
    b_refresh = false;
    b_refresh_project = true;
    init_list_header();
    refresh_list();

}

instance_unit_info::~instance_unit_info()
{
    //(*Destroy(instance_unit_info)
    //*)
}


void instance_unit_info::init_list_header()
{
    //Unit info.
    gd_unit_info->CreateGrid(0, 18);
    gd_unit_info->SetRowLabelSize(30);
    gd_unit_info->SetColLabelValue(0, _("项目号"));
    gd_unit_info->SetColSize(0, 80);
    gd_unit_info->SetColLabelValue(1, _("Unit WBS NO."));
    gd_unit_info->SetColSize(1, 100);
    gd_unit_info->SetColLabelValue(2, _("梯型编号"));
    gd_unit_info->SetColSize(2, 80);
    gd_unit_info->SetColLabelValue(3, _("梯型"));
    gd_unit_info->SetColSize(3, 80);
    gd_unit_info->SetColLabelValue(4, _("项目名称"));
    gd_unit_info->SetColSize(4, 200);
    gd_unit_info->SetColLabelValue(5, _("梯号"));
    gd_unit_info->SetColSize(5, 50);
    gd_unit_info->SetColLabelValue(6, _("Unit状态"));
    gd_unit_info->SetColSize(6, 60);
    gd_unit_info->SetColLabelValue(7, _("Unit\n流程状态"));
    gd_unit_info->SetColSize(7, 60);
    gd_unit_info->SetColLabelValue(8, _("是否紧急"));
    gd_unit_info->SetColSize(8, 60);
    gd_unit_info->SetColLabelValue(9, _("项目类别"));
    gd_unit_info->SetColSize(9, 100);
    gd_unit_info->SetColLabelValue(10, _("非标\n等级"));
    gd_unit_info->SetColSize(10, 80);
    gd_unit_info->SetColLabelValue(11, _("发货期"));
    gd_unit_info->SetColSize(11, 80);
    gd_unit_info->SetColLabelValue(12, _("配置完成日期"));
    gd_unit_info->SetColSize(12, 80);
    gd_unit_info->SetColLabelValue(13, _("特殊标识"));
    gd_unit_info->SetColSize(13, 100);
    gd_unit_info->SetColLabelValue(14, _("版本ID"));
    gd_unit_info->SetColSize(14, 80);
    gd_unit_info->SetColLabelValue(15, _("备注"));
    gd_unit_info->SetColSize(15, 100);
    gd_unit_info->SetColLabelValue(16, _("先行排产"));
    gd_unit_info->SetColSize(16, 0);

    gd_unit_info->SetColLabelValue(17, _("非标安装资料"));
    gd_unit_info->SetColSize(17, 0);

    for (int i = 0; i < 18; i++)
    {
        str_unit_header = str_unit_header + gd_unit_info->GetColLabelValue(i) + wxT(";");
    }
//PROJECT INFO.
    wxListItem itemCol;
    itemCol.SetText(_("项目号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(100);
    lc_project->InsertColumn(0, itemCol);
    itemCol.SetText(_("合同号"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(80);
    lc_project->InsertColumn(1, itemCol);
    itemCol.SetText(_("项目名称"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(300);
    lc_project->InsertColumn(2, itemCol);
    itemCol.SetText(_("工厂"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(50);
    lc_project->InsertColumn(3, itemCol);
    itemCol.SetText(_("分公司"));
    itemCol.SetImage(-1);
    itemCol.SetWidth(300);
    lc_project->InsertColumn(4, itemCol);
}

void instance_unit_info::OnButton1Click(wxCommandEvent& event)
{
    pugi::xml_document ldoc;
    pugi::xml_node lnode;
    pugi::xml_parse_result result;
    wxString import_file, s_split;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能向系统内导入任何信息!"));
        return;
    }
    if (!wxGetApp().conn->IsAlive())
    {
        if (wxGetApp().conn->GetStatus() == PGCONN_BROKEN)
            wxLogMessage(_("服务器连接断开,不能向系统内导入任何信息!"));
        return;
    }
    result = ldoc.load_file("config.xml");
    if (result)
    {
        lnode = ldoc.child("import");
 //       import_file = wxString(lnode.child_value("path"), wxConvUTF8);
        s_split = wxString(lnode.child_value("split"), wxConvUTF8);
    }
    else
    {
        wxLogMessage(_("config.xml配置文件不存在,无法继续操作!"));
        return;
    }
 //   if (import_file.IsEmpty())
  //  {
        wxFileDialog dlg(this, _("Open txt file"), "", "",
                         "txt files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
        if (dlg.ShowModal() == wxID_CANCEL)
            return;
        import_file  = dlg.GetPath();/*
        if (result)
        {
            lnode = ldoc.child("import").child("path");
            lnode.text().set(import_file.mbc_str());
            ldoc.save_file("config.xml");
        }
        else
        {
            wxLogMessage(_("config.xml配置文件不存在,无法继续操作!"));
            return;
        }*/
  //  }
    if (s_split.IsEmpty())
    {
        wxTextEntryDialog tdlg(this, _("请输入字段分割符"), _("分隔符录入"), wxT(","), wxTextEntryDialogStyle, wxDefaultPosition);
        if (tdlg.ShowModal() == wxID_CANCEL)
            return;
        s_split  = tdlg.GetValue();
        if (result)
        {
            lnode = ldoc.child("import").child("split");
            lnode.text().set(s_split.mbc_str());
            ldoc.save_file("config.xml");
        }
        else
        {
            wxLogMessage(_("config.xml配置文件不存在,无法继续操作!"));
            return;
        }
    }/*
    wxString _choice[2] =
    {
        _("SAP系统导入"),
        _("文本格式导入"),
    };
    wxSingleChoiceDialog cdlg(this, _("选择是从文本导入,还是从SAP系统导入?"), _("导入选择"), 2, _choice);
    if (cdlg.ShowModal() == wxID_CANCEL)
        return;
    int i_choice = cdlg.GetSelection();*/
    int i_choice = 1;
    wxTextFile txt_file(import_file);
    txt_file.Open(wxConvAuto());
    wxArrayString stra_header, stra_temp;
    int i_row = txt_file.GetLineCount();
    if (i_row <= 1)
    {
        wxLogMessage("导入文件内容为空!");
        return;
    }
    wxString s_header = txt_file.GetFirstLine();
    if (s_split == "\\t")
        s_split = wxT("\t");
    stra_header = wxStringTokenize(s_header, s_split, wxTOKEN_DEFAULT);
//   int icol = stra_header.GetCount();
//   wxPostgreSQLresult *l_res;
    wxString str_check, str_item, str_query, str_temp, str_doc, str_doc_id; //用于检查项目是否已经存在的中间值,存在则,不用check.
    int i_pregress = 0;
    int i_success_info = 0;
    int i_fail_info = 0;
    int i_success_para = 0;
    int i_fail_para = 0;
    wxProgressDialog dlg_progress(_("导入进度"), _("导入中......"), i_row - 1, this, wxPD_APP_MODAL | wxPD_AUTO_HIDE);
    switch (i_choice)
    {
    case 1:
        for (str_item = txt_file.GetLastLine(); txt_file.GetCurrentLine() > 0; str_item = txt_file.GetPrevLine())
        {
            if (str_item.IsEmpty())
            {
                dlg_progress.Update(i_pregress, _("导入中..."), NULL);
                continue;
            }
            stra_temp = wxStringTokenize(str_item, s_split, wxTOKEN_RET_EMPTY);
//          int i_test = stra_temp.GetCount();
            str_temp = get_str_val(wxT("wbs_no"), stra_header, stra_temp).Trim();
            if (str_check != str_temp.Left(10))
                str_check = str_temp.Left(10);
            str_query = wxT("SELECT * FROM s_project_info WHERE project_id = '") + str_temp.Left(10) + wxT("';");
            wxString s_branch_name = get_str_val("branch_name", stra_header, stra_temp).Trim();
            s_branch_name.Replace(wxT("'"),wxT(" "));
            if (!wxGetApp().is_have(str_query))
            {
                str_query = wxT("INSERT INTO s_project_info (project_id, contract_id, project_name, plant, branch_name, res_emp_id, modify_date, modify_emp_id, create_date, create_emp_id, branch_id) VALUES ('") + str_temp.Left(10) + wxT("','") + get_str_val("contract_id", stra_header, stra_temp).Trim() + wxT("','") +
                            get_str_val("project_name", stra_header, stra_temp).Trim() + wxT("','") +
                            gr_para.plant + wxT("','") +s_branch_name+ wxT("','") +
                            get_str_val("res_emp_id", stra_header, stra_temp).Trim() + wxT("','") +
                            wxDateTime::Now().Format("%Y-%m-%d %H:%M:%S") + wxT("','") +
                            gr_para.login_user + wxT("','") + wxDateTime::Now().Format("%Y-%m-%d %H:%M:%S") + wxT("','") +
                            gr_para.login_user+ wxT("','")+get_str_val("branch_id",stra_header,stra_temp).Trim() +wxT("');");
                str_query.Replace(wxT("''"), wxT("NULL"));
                wxGetApp().app_sql_update(str_query);
//                   wxLogMessage(_("项目:")+str_temp+_("导入成功"));
            }
            str_doc = get_str_val(wxT("doc_desc"), stra_header, stra_temp);
            if (!str_doc.IsEmpty())
            {
                wxString _table_str, _para_str;
                _table_str = wxT("s_doc");
                _para_str = wxT("doc_id");
                str_doc_id = wxGetApp().get_ser_no(_table_str, _para_str);
                str_query = wxT("INSERT INTO s_doc(doc_id, doc_desc) VALUES ('") + str_doc_id + wxT("','") + str_doc + wxT("');");
                wxGetApp().app_sql_update(str_query);
            }
            else str_doc_id.Empty();

            wxString str_req_delivery, str_req_finish;
            if (!get_str_val("req_delivery_date", stra_header, stra_temp).Trim().IsEmpty())
                str_req_delivery = get_str_val("req_delivery_date", stra_header, stra_temp).Trim() + wxT(" 23:00:00");
            else  str_req_delivery.Empty();

            if (!get_str_val("req_configure_finish", stra_header, stra_temp).Trim().IsEmpty())
                str_req_finish = get_str_val("req_configure_finish", stra_header, stra_temp).Trim() + wxT(" 23:00:00");
            else str_req_finish.Empty();

            wxString is_through = get_str_val("is_through", stra_header, stra_temp);
            if (is_through.IsEmpty())
                is_through = wxT("false");
            else is_through = wxT("true");

            wxString is_urgent = get_str_val("review_is_urgent",stra_header,stra_temp);
            if(is_urgent.IsEmpty())
                 is_urgent = wxT("false");
            else is_urgent = wxT("true");
            str_query = wxT("SELECT * FROM s_unit_info WHERE wbs_no = '") + str_temp + wxT("'");
            if (!wxGetApp().is_have(str_query))
            {
                str_query = wxT("INSERT INTO s_unit_info ( wbs_no, project_id, elevator_id, lift_no, status,  req_delivery_date, req_configure_finish, conf_batch_id, unit_doc_id, modify_date, modify_emp_id, create_date, create_emp_id, review_is_urgent) VALUES ('") +
                            str_temp + wxT("','") +
                            str_temp.Left(10) + wxT("','") +
                            get_str_val("elevator_id", stra_header, stra_temp).Trim() + wxT("','") +
                            get_str_val("lift_no", stra_header, stra_temp).Trim() + wxT("','") +
                            get_str_val("status", stra_header, stra_temp).Trim() + wxT("','") +
                            str_req_delivery + wxT("','") + str_req_finish + wxT("','") +
                            get_str_val("conf_batch_id", stra_header, stra_temp).Trim() + wxT("','") +
                            str_doc_id + wxT("','") +
                            wxDateTime::Now().Format("%Y-%m-%d %H:%M:%S") + wxT("','") +
                            gr_para.login_user + wxT("','") + wxDateTime::Now().Format("%Y-%m-%d %H:%M:%S") + wxT("','") +
                            gr_para.login_user + wxT("',")+is_urgent+ wxT(" )");
                i_success_info++;
            }
            else
            {
                /*
                   str_query = wxT("UPDATE s_unit_info SET elevator_id = '")+get_str_val("elevator_id",stra_header,stra_temp).Trim()+
                               wxT("',lift_no = '")+get_str_val("lift_no",stra_header,stra_temp).Trim()+wxT("',status = '")+get_str_val("status",stra_header,stra_temp).Trim()+
                               wxT("',req_delivery_date = '")+str_req_delivery+
                               wxT("',req_configure_finish = '")+str_req_finish+
                               wxT("',conf_batch_id = '")+get_str_val("batch_id",stra_header,stra_temp).Trim()+
                               wxT("',unit_doc_id = '")+str_doc_id+
                               wxT("',modify_date = '")+wxDateTime::Now().Format("%Y-%m-%d %H:%M:%S")+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE wbs_no ='")+
                               get_str_val("wbs_no",stra_header,stra_temp).Trim()+wxT("';");*/
                wxLogMessage(str_temp + _("项目信息已经存在，请手动更新!"));
                i_fail_info++;
            }
            str_query.Replace(wxT("''"), wxT("NULL"));
            wxGetApp().app_sql_update(str_query);
            str_query = wxT("SELECT * FROM s_unit_parameter WHERE wbs_no = '") + str_temp + wxT("'");
            if (!wxGetApp().is_have(str_query))
            {
                str_query =  wxT("INSERT INTO s_unit_parameter(\
                   wbs_no, project_id, load, speed, control_sys, car_width, car_depth, \
                   car_height, open_type, car_door_type, landing_door_type, is_through, \
                   door_width, door_height, travel_height, floors, stops,  \
                    modify_date, modify_emp_id, create_date, create_emp_id)\
                    VALUES ('") + get_str_val("wbs_no", stra_header, stra_temp).Trim() + wxT("','") +
                             get_str_val("wbs_no", stra_header, stra_temp).Trim().Left(10) + wxT("','") + get_str_val("load", stra_header, stra_temp).Trim() + wxT("','") +
                             get_str_val("speed", stra_header, stra_temp).Trim() + wxT("','") + get_str_val("control_sys", stra_header, stra_temp).Trim() + wxT("','") +
                             get_str_val("car_width", stra_header, stra_temp).Trim() + wxT("','") + get_str_val("car_depth", stra_header, stra_temp).Trim() + wxT("','") +
                             get_str_val("car_height", stra_header, stra_temp).Trim() + wxT("','") + get_str_val("open_type", stra_header, stra_temp).Trim() + wxT("','") +
                             get_str_val("car_door_type", stra_header, stra_temp).Trim() + wxT("','") + get_str_val("landing_door_type", stra_header, stra_temp).Trim() + wxT("','") +
                             is_through + wxT("','") + get_str_val("door_width", stra_header, stra_temp).Trim() + wxT("','") +
                             get_str_val("door_height", stra_header, stra_temp).Trim() + wxT("','") + get_str_val("travel_height", stra_header, stra_temp).Trim() + wxT("','") +
                             get_str_val("floors", stra_header, stra_temp).Trim() + wxT("','") + get_str_val("stops", stra_header, stra_temp).Trim() + wxT("','") +
                             wxDateTime::Now().Format("%Y-%m-%d %H:%M:%S") + wxT("','") + gr_para.login_user + wxT("','") + wxDateTime::Now().Format("%Y-%m-%d %H:%M:%S") + wxT("','") +
                             gr_para.login_user + wxT("' )");
                i_success_para++;
            }
            else
            {
                /*
                   str_query = wxT("UPDATE s_unit_parameter SET load='")+get_str_val("load",stra_header,stra_temp).Trim()+wxT("',speed = '")+
                               get_str_val("speed",stra_header,stra_temp).Trim()+wxT("',control_sys='")+get_str_val("control_sys",stra_header,stra_temp).Trim()+wxT("',car_width='")+
                               get_str_val("car_width",stra_header,stra_temp).Trim()+wxT("',car_depth='")+ get_str_val("car_depth",stra_header,stra_temp).Trim()+wxT("',car_height='")+
                               get_str_val("car_height",stra_header,stra_temp).Trim()+wxT("',open_type='")+ get_str_val("open_type",stra_header,stra_temp).Trim()+wxT("',car_door_type='")+
                               get_str_val("car_door_type",stra_header,stra_temp).Trim()+wxT("',is_through='")+is_through+wxT("',door_width='")+get_str_val("door_width",stra_header,stra_temp).Trim()+wxT("',door_height='")+
                               get_str_val("door_height",stra_header,stra_temp).Trim()+wxT("',travel_height='")+get_str_val("travel_height",stra_header,stra_temp).Trim()+wxT("',floors='")+
                               get_str_val("floors",stra_header,stra_temp).Trim()+wxT("', stops='")+get_str_val("stops",stra_header,stra_temp).Trim()+
                               wxT("',modify_date = '")+wxDateTime::Now().Format("%Y-%m-%d %H:%M:%S")+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE wbs_no ='")+
                               get_str_val("wbs_no",stra_header,stra_temp).Trim()+wxT("';");*/
                wxLogMessage(str_temp + _("项目参数已经存在，请手动更新!"));
                i_fail_para++;
            }
            str_query.Replace(wxT("''"), wxT("NULL"));
//           wxLogMessage(str_query);//测试query是否写错。
            wxGetApp().app_sql_update(str_query);
            //              wxLogMessage(_("unit:")+get_str_val("wbs_no",stra_header,stra_temp).Trim()+_("项目参数更新成功"));
            dlg_progress.Update(i_pregress, _("导入中..."), NULL);
            i_pregress++;
        }
        break;
    default:
        break;
    }
    wxLogMessage("总计%d台，其中导入成功：%d项目信息，%d项目参数; \n失败:%d项目信息，%d项目参数!", i_pregress,
                 i_success_info, i_success_para, i_fail_info, i_fail_para);
}

int instance_unit_info::check_same_lift_no(wxString s_project_id,wxString s_lift_no)
{
    wxString s_sql = wxT(" select wbs_no from s_unit_info where project_id='")+s_project_id+wxT("' and lift_no ='")+s_lift_no+wxT("' and status>=0;");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return -1;
    }

    int i_count = _res->GetRowsNumber();
    wxString str;

    for(int i=0;i<i_count;i++)
    {
        str=str+wxT("\n")+_res->GetVal(wxT("wbs_no"));
        _res->MoveNext();
    }

    _res->Clear();

    if(i_count >=2)
    {
        wxMessageBox(_("如下")+NumToStr(i_count)+_("台梯,同一项目下多个UNIT梯号相同:\n")+str,_("梯号错误:")+s_lift_no);
    }

    return i_count;

}

void instance_unit_info::OnButton2Click(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();

    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxString str_instance, str_wbs_no;
    wxLongLong mils_used, start_mils;
    wxArrayString array_wbs, array_head;
    int i_old_status;
    wxArrayInt array_old_status;
    int i_task = 0;

    v_wf_action * t_template = get_template_action(wf_str_review);
    wf_operator * wf_review = 0;

    int i_status;
    wxString s_wf_status;
    wxArrayString array_task_units;
    wxString s_project_id=wxEmptyString;

    bool b_notice=false;
    wxString s_branch_id;

    for (int i = 0; i < i_count; i++)
    {
        str_wbs_no = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);

        i_old_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6));
/*配置工作流与评审工作流状态分离修改 20150710
        if (i_old_status  == 1 || i_old_status == 3)
        {
            wxLogMessage(str_wbs_no + _("-正处于活动状态，无法启动评审!"));
            continue;
        }

        if (i_old_status  == 4)
        {
            wxLogMessage(str_wbs_no + _("-已经冻结，无法启动评审!"));
            continue;
        }*/

        if (i_old_status  == 8)
        {
            wxLogMessage(str_wbs_no + _("-已经发运，无法启动评审!"));
            b_notice=false;
            continue;
        }
//配置工作流与评审工作流状态分离修改 20150710
        int i_review_status = get_review_status(str_wbs_no);

        if(i_review_status==1 or i_review_status==3)
        {
            wxLogMessage(str_wbs_no+_("-评审流程正处于激活状态，无法重启评审!"));
            b_notice=false;
            continue;
        }
 //配置工作流与评审工作流状态分离修改 20150710
/*
        if (i_old_status  == 6)
        {
            wxLogMessage(str_wbs_no + _("-已经RELEASE，无法启动评审!"));
            continue;
        }*/

        if (i_old_status  <0)
        {
            wxLogMessage(str_wbs_no + _("-已经取消或者删除，无法启动评审!"));
            continue;
        }

        wxString s_project = str_wbs_no.Left(10);
        if(array_head.Index(s_project)==wxNOT_FOUND)
        {
            i_task++;
            array_head.Add(s_project);
        }

        array_old_status.Add(i_old_status);
        array_wbs.Add(str_wbs_no);
        /*
                start_mils = wxGetLocalTimeMillis();
                wf_review = new wf_operator(str_wbs_no, wf_str_review, t_template);
                wf_review->start_proc(str_desc, true, true);
                if(wf_review->update_instance(1))
                {
                    i_status = wf_review->get_instance_status(s_wf_status);

                    update_review_status(array_task_units,i_status,s_wf_status);
                }
                delete wf_review;
                mils_used = wxGetLocalTimeMillis() - start_mils;
                wxLogMessage(str_wbs_no + _("评审流程创建成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));*/
    }

    for(int i=0; i<i_task; i++)
    {

        review_remarks_dlg tdlg;
        wxString str_desc;
        wxString str_drawing_qty;
        wxString str_res_cm;
        int i_urgent_level;

        wxString s_prj_res_cm = get_prj_res_person(array_head.Item(i));

        int i_qty = get_same_project_count(array_head.Item(i),array_wbs);

        tdlg.refresh_control(i_qty, s_prj_res_cm );
        tdlg.show_control();

        if (tdlg.ShowModal() == wxID_OK)
        {
            str_desc = tdlg.m_remarks;
            str_drawing_qty = tdlg.m_qty;
            str_res_cm = tdlg.m_res_cm;
            i_urgent_level = tdlg.m_urgent_level;

        }
        else continue;


        int i_pos = str_res_cm.Find(wxT("-"));
        str_res_cm = str_res_cm.Left(i_pos);
        //wxMessageBox("test","test");

        wxString str_task_id = create_review_struct( array_head.Item(i),str_res_cm, array_wbs,array_task_units, array_old_status,i_urgent_level,str_desc,str_drawing_qty);

        //wxMessageBox("test","test");
        int i_units = array_task_units.GetCount();

        for(int i=0; i<i_units; i++)
        {
            start_mils = wxGetLocalTimeMillis();
            int i_restart_times=0;
            str_wbs_no = array_task_units.Item(i);
            start_mils = wxGetLocalTimeMillis();
            wf_review = new wf_operator(str_wbs_no, wf_str_review, t_template);

            i_old_status = array_old_status.Item(array_wbs.Index(str_wbs_no));

            i_restart_times= get_restart_times(str_wbs_no);

            if(check_review_restart_status(str_wbs_no))
            {
                wf_review->restart_instance(wxT("AT00000002"),i_restart_times-1);
                i_status = 3;
            }
            else
            {
                wf_review->start_proc(str_desc, true, true);
                if(i_old_status >0)
                   i_status = 3;
                else i_status =1;
            }


            if(s_project_id!=str_wbs_no.Left(10))
            {
                s_project_id = str_wbs_no.Left(10);
                s_branch_id = wxGetApp().get_branch_id(s_project_id);
            }

            wxString s_operator=wxEmptyString;
            if(!s_branch_id.IsEmpty())
            {
               s_operator= wxGetApp().get_operator_from_branch( s_branch_id, "G0002");
               if(!s_operator.IsEmpty())
               {
                   if(wf_review->Pass_proc(s_operator, "G0002", wxEmptyString, false))
                   {
                       s_wf_status=_("项目评审");
                       update_operator(str_task_id, s_operator);
                   }
               }else
               {
                   s_wf_status=_("评审授权");
               }

            }else
            {
                s_wf_status=_("评审授权");

            }
//配置工作流与评审工作流状态分离修改 20150710            if(wf_review->update_instance(i_status,s_wf_status))
            if(update_review_units_status(str_task_id, str_wbs_no,i_status,i_old_status,s_wf_status, i_restart_times))   //配置工作流与评审工作流状态分离修改 20150710
            {
                b_notice=true;

 //               update_review_status(s_wbs,i_status,s_wf_status);
 //               update_review_units_status(str_task_id, str_wbs_no,i_status,i_old_status,s_wf_status, i_restart_times);
                //update_operator(str_task_id, str_res_cm);
                mils_used = wxGetLocalTimeMillis() - start_mils;
                wxLogMessage(_("项目:")+array_task_units.Item(i)+_("创建评审任务成功,耗时:")+NumToStr(mils_used)+wxT("ms!"));
            }


            delete wf_review;
        }


        array_task_units.Clear();
    }


    array_old_status.Clear();
    /*    mils_used = wxGetLocalTimeMillis() - start_mils;

        if (t_template)
            delete [] t_template;

        wxLogMessage(_("创建:")+NumToStr(i_task)+_("个评审任务,耗时:")+NumToStr(mils_used)+_("毫秒."));*/

    if(b_notice)
      wxMessageBox(_("请到合同评审-合同信息界面刷新任务!"),_("提示"), wxOK);
    else
        return;

    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

int instance_unit_info::get_review_status(wxString s_wbs)
{
    wxString s_sql = wxT("SELECT *  FROM s_review_units where wbs_no='")+s_wbs+wxT("' and unit_status<>-2 and unit_status<>-1 and is_del=false and is_latest=true;");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return -1;
    }

    int i_count =_res->GetRowsNumber();

    if(i_count==0)
    {
        _res->Clear();
        return 0;
    }

    int i_status = _res->GetInt(wxT("unit_status"));

    _res->Clear();

    return i_status;

}

int instance_unit_info::get_restart_times(wxString s_wbs)
{
    wxString s_sql = wxT("SELECT count(*) as count  FROM s_review_units where wbs_no='")+s_wbs+wxT("' and unit_status<>-2 and unit_status<>-1 and is_del=false;");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return 0;
    }

    int i_rel = _res->GetInt(wxT("count"));

    _res->Clear();

    return i_rel;
}

bool instance_unit_info::update_operator(wxString s_task_id, wxString s_operator_id)
{
    /*wxString s_sql = wxT("UPDATE l_proc_act SET operator_id='")+s_operator_id+wxT("' where instance_id = '")+s_instance_id+wxT("' and \
                    action_id = 'AT00000001' and workflow_id ='")+wf_str_review+wxT("';");*/
   wxString str_sql = wxT(" UPDATE s_review_info SET review_engineer='")+s_operator_id+wxT("' , modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("' \
                            where review_task_id ='")+s_task_id+wxT("' and active_status>=1;");
    return wxGetApp().app_sql_update(str_sql);
    //return wxGetApp().app_sql_update(s_sql);
}



wxString instance_unit_info::get_prj_res_person(wxString s_proj_id)
{
    wxString str_sql = wxT("select concat(res_emp_id,'-',name) as res_emp_person from v_project_info where project_id='")+s_proj_id+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    int i_count = _res->GetRowsNumber();

    wxString str;

    if(i_count > 0)
        str=_res->GetVal(wxT("res_emp_person"));

    _res->Clear();

    return str;
}

int instance_unit_info::get_same_project_count(wxString s_project, const wxArrayString s_unit_list)
{
    int i_count = s_unit_list.GetCount();

    int i_return=0;

    for(int i=0;i<i_count;i++)
    {
        if(s_unit_list.Item(i).Left(10)==s_project)
            i_return++;
    }

    return i_return;
}

/*
bool instance_unit_info::update_review_status(const wxString s_wbs_no, int i_status, wxString s_wf_status)
{
     wxString str_sql = wxT("UPDATE s_review_units SET unit_status =")+NumToStr(i_status)+wxT(",unit_wf_status='")+s_wf_status+wxT("',modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE review_task_id ='")+ s_task_id+wxT("' and wbs_no='")+s_wbs_no+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}*/

bool instance_unit_info::check_review_restart_status(wxString s_instance)
{
    bool b_active=false;

    wxString str_sql = wxT("select count(*) as count from l_proc_act where instance_id = '")+s_instance+wxT("' and workflow_id='")+wf_str_review+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);
    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetInt(wxT("count"));

    if(i_count==0)
        b_active=false;
    else
        b_active=true;


    return b_active;
}

//更改评审逻辑，以unit为单位,无需instance_status更新。

bool instance_unit_info::update_review_units_status(wxString s_task_id, wxString s_unit, int i_status, int i_old_status, wxString s_wf_status,int i_restart_times)
{
    wxString str_sql = wxT("UPDATE s_review_units SET   unit_status =")+NumToStr(i_status)+wxT(",unit_wf_status='")+s_wf_status+wxT("',unit_old_status='")+NumToStr(i_old_status)+wxT("',restart_times=")+NumToStr(i_restart_times)+wxT(", modify_date = '")+DateToAnsiStr(wxDateTime::Now())+
                               wxT("',modify_emp_id = '")+gr_para.login_user+wxT("' WHERE wbs_no ='")+s_unit+wxT("' and review_task_id='")+s_task_id+wxT("';");

    return wxGetApp().app_sql_update(str_sql);
}

wxString instance_unit_info::create_review_struct(wxString s_project,wxString s_res_cm, const wxArrayString &array_wbs, wxArrayString &array_task_units, wxArrayInt array_old_status, int i_urgent_level, wxString s_remarks, wxString s_qty)
{
      wxString s_task_id;
      int i_count = array_wbs.GetCount();

      if(i_count==0)
      {
          return s_task_id;
      }

      s_task_id = wxGetApp().get_ser_id(wxT("s_review_info"),wxT("review_task_id"));

      wxString str_sql = wxT("INSERT INTO s_review_info(review_task_id, res_cm, modify_date, modify_emp_id, create_date, create_emp_id, review_remarks, review_drawing_qty ) \
               VALUES ('")+s_task_id+wxT("','")+s_res_cm+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
               DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+s_remarks+wxT("',")+s_qty+wxT(");");

      if(wxGetApp().app_sql_update(str_sql))
      {
           str_sql = wxT("INSERT INTO s_review_units ( review_task_id, wbs_no, modify_date, modify_emp_id, create_date, create_emp_id, unit_old_status, unit_status, unit_wf_status, urgent_level ) VALUES ");
           int i_old_unit_status;
           for(int i=0;i<i_count;i++)
           {
               if(array_wbs.Item(i).Left(10)==s_project)
               {
                   array_task_units.Add(array_wbs.Item(i));

                   update_review_units_latest(array_task_units.Item(i));//将is_latest置false

                   //if(i==i_count-1)
                   //{

                     //str_sql = str_sql + wxT("('")+s_task_id+wxT("','")+array_wbs.Item(i)+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
                    //         DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+NumToStr(i_old_unit_status)+wxT("',1, '评审授权',")+NumToStr(i_urgent_level)+wxT(") ");                   }else
                  // {
                     str_sql = str_sql + wxT("('")+s_task_id+wxT("','")+array_wbs.Item(i)+wxT("','")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
                             DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+NumToStr(i_old_unit_status)+wxT("',1, '评审授权',")+NumToStr(i_urgent_level)+wxT("), ");
                   //}

               }
           }

           if(str_sql.Trim().Right(1)==",")
                str_sql.RemoveLast(1);

           str_sql = str_sql+";";

           str_sql.Replace(wxT("''"),wxT("NULL"));
     //      wxMessageBox(str_sql);
           if(array_task_units.IsEmpty())
               return wxEmptyString;


           wxGetApp().app_sql_update(str_sql);

      }

      return s_task_id;
}

bool instance_unit_info::check_g4_group(wxString s_wbs)
{
     wxString s_sql = wxT(" select elevator_type, load from v_unit_info_parameter where wbs_no = '")+s_wbs+wxT("';");

    wxPostgreSQLresult * res=wxGetApp().app_sql_select(s_sql);
    if(res->Status()!= PGRES_TUPLES_OK)
    {
        res->Clear();
        return false;
    }

    int i_count = res->GetRowsNumber();
    if(i_count==0)
    {
        res->Clear();
        return false;
    }

    if(res->GetInt(wxT("load"))<=1000 && res->GetVal(wxT("elevator_type"))=="RF1")
    {
        res->Clear();
        return true;
    }

    return false;
}

void instance_unit_info::OnButton3Click(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    bool b_log_pass = false;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    wxTextEntryDialog tdlg(this, _("配置提示输入"), _("备注"), wxT(""), wxOK | wxCANCEL | wxTE_MULTILINE, wxDefaultPosition);
    wxString str_desc;
    if (tdlg.ShowModal() == wxID_OK)
    {
        b_log_pass = false;
        str_desc = tdlg.GetValue();
    }
    else
    {
        b_log_pass = true;
    }
    int i_count = array_sel_line.GetCount();
    v_wf_action * t_template = get_template_action(wf_str_configure);
    v_wf_action * t_new_template = get_template_action(wf_str_new_config);
    wf_operator * wf_configure;
    wf_operator_ex * wf_new_conf;
    wxString str_instance;
    wxLongLong mils_used, start_mils;
    int i_status;
    bool b_can_psn;
    wxString s_project, s_lift_no, s_lift_type;

    wxArrayString array_wbs, array_group, array_flag;
    int i_ways, i_catalog;
    for (int i = 0; i < i_count; i++)
    {
        str_instance = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        i_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6));
        b_can_psn = StrToBool(gd_unit_info->GetCellValue(array_sel_line.Item(i), 16));
        s_project = gd_unit_info->GetCellValue(array_sel_line.Item(i),0).Trim();
        s_lift_no = gd_unit_info->GetCellValue(array_sel_line.Item(i),5).Trim();
        s_lift_type = gd_unit_info->GetCellValue(array_sel_line.Item(i),2).Trim();
        i_catalog=  prj_str_to_catalog(gd_unit_info->GetCellValue(array_sel_line.Item(i), 9).Trim());

        check_same_lift_no(s_project,s_lift_no);

        if (b_log_pass)
        {
            str_desc = gd_unit_info->GetCellValue(array_sel_line.Item(i), 15);
        }
        if (i_status== 1 ||i_status == 3 || i_status==0)
        {
            if(!b_can_psn)
            {
               wxLogMessage(str_instance + _("-评审流程尚未结束，无法启动配置流程!"));
               continue;
            }else
            {
                wxLogMessage(str_instance + _("正在线上PO确认,特批排产，正在启动配置工作流......"));
            }

        }
/*
        if(i_status == 0)
        {
             wxLogMessage(str_instance + _("-刚刚创建，尚未评审，无法启动配置"));
             continue;
        }*/

        if(i_status<0)
        {
             wxLogMessage(str_instance + _("-已经删除，请恢复后在操作!"));
             continue;
        }

        if(i_status==4)
        {
             wxLogMessage(str_instance + _("-已经冻结，请先解除冻结后再操作!"));
             continue;
        }

        if(i_status == 2)
        {
            wxLogMessage(str_instance + _("-未启动排产计划，请先启动排产!"));
             continue;
        }
/*
        if(i_status == 5 )
        {
            wxLogMessage(str_instance + _("-配置已经完成!"));
               continue;
        }

        if(i_status == 6 )
        {
            wxLogMessage(str_instance + _("-已经release!"));
               continue;
        }*/

        if(i_status == 8)
        {
            wxLogMessage(str_instance + _("-已经发运!"));
               continue;
        }



        int i_restart;

        start_mils = wxGetLocalTimeMillis();
        wxString s_case;
        bool b_new_config=false;

        if(!wxGetApp().check_new_config(array_group, array_flag, i_ways, s_lift_type, s_case))
            b_new_config=false;
        else
        {
            if(!s_case.IsEmpty())
            {
              if(!wxGetApp().check_is_highspeed(str_instance))
                   b_new_config=false;
              else
                  b_new_config=true;
            }else
                b_new_config=true;
        }

        if(!b_new_config)//新的配置工作流，由非标负责
        {
            i_restart = check_is_start_flow(str_instance, wf_str_configure);

            if(i_restart == 1)
            {
                wxLogMessage(str_instance+_("配置工作流已经激活状态，无法重复启动!"));
                return;
            }
            if(i_restart ==0)
            {

                wf_configure = new wf_operator(str_instance, wf_str_configure, t_template);
               // if (i_catalog!=6&&!check_g4_group(str_instance))
                    wf_configure->start_proc(str_desc, false, b_log_pass);
               /* else
                {
                    wxString s_operator = wxGetApp().get_leader(wxT("G0004"));
                    wxString s_group = wxT("G0004");
                    wf_configure->start_proc(s_operator, s_group);
                }*/

                update_contract_book_status(str_instance, 1);
                wf_configure->update_instance(1);
                if (wf_configure)
                    delete wf_configure;
                mils_used = wxGetLocalTimeMillis() - start_mils;
                wxLogMessage(str_instance + _("配置流程创建成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));
            }

            if(i_restart>=2)
            {
                update_basic_finish_status(str_instance);
                int i_times = update_restart_status(str_instance, true);
                wf_configure = new wf_operator(str_instance, wf_str_configure, t_template);
                wf_configure->restart_instance(i_times);
                wf_configure->update_instance(3);
                if (wf_configure)
                    delete wf_configure;
                mils_used = wxGetLocalTimeMillis() - start_mils;
                wxLogMessage(str_instance + _("重排产流程创建成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));
            }
        }else
        {
            i_restart = check_is_start_flow(str_instance, wf_str_new_config);

            if(i_restart == 1)
            {
                wxLogMessage(str_instance+_("配置工作流已经激活状态，无法重复启动!"));
                return;
            }

            if(i_restart ==0)
            {
                for(int j=0; j<i_ways;j++)
                {

                    wf_new_conf = new wf_operator_ex(str_instance, wf_str_new_config, t_new_template,array_flag.Item(j));
                    wf_new_conf->start_proc(array_group.Item(j), str_desc, b_log_pass);
                    wf_new_conf->update_instance(1);
                    if (wf_new_conf)
                        delete wf_new_conf;

                }

                mils_used = wxGetLocalTimeMillis() - start_mils;
                wxLogMessage(str_instance + _("配置流程创建成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));
            }

            if(i_restart>=2)
            {
                int i_times = update_restart_status(str_instance, true);

                for(int k=0; k<i_ways; k++)
                {

                    wf_new_conf = new wf_operator_ex(str_instance, wf_str_new_config, t_new_template, array_flag.Item(k));
                    wf_new_conf->restart_instance(i_times);
                    wf_new_conf->update_instance(3);
                    if (wf_new_conf)
                        delete wf_new_conf;

                }
                mils_used = wxGetLocalTimeMillis() - start_mils;
                wxLogMessage(str_instance + _("重排产流程创建成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));
            }
        }

        if(i_restart ==0)
        {
            array_wbs.Add(str_instance);
        }

    }

    if(!array_wbs.IsEmpty())
         Create_proj_Folder(array_wbs);

    if (t_template)
        delete [] t_template;

    if(t_new_template)
        delete [] t_new_template;
    b_refresh = true;
    refresh_list();
    b_refresh = false;


}

bool instance_unit_info::update_contract_book_status(wxString s_wbs, int i_status)
{
    wxString s_sql = wxT("select * from s_contract_book_header where contract_doc_id in (select contract_doc_id from s_contract_book_include where wbs_no='")+s_wbs+wxT("');");

    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(s_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count == 0)
    {
        _res->Clear();
        return false;
    }

     _res->MoveFirst();

    int i_old_status = _res->GetInt(wxT("status"));
    wxString s_doc = _res->GetVal(wxT("contract_doc_id"));

    if (i_old_status==i_status)
    {
        _res->Clear();
        return false;
    }

    _res->Clear();

    s_sql = wxT("UPDATE s_contract_book_header SET status =")+NumToStr(i_status)+wxT(" , modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where contract_doc_id='")+s_doc+wxT("';");

   return  wxGetApp().app_sql_update(s_sql);
}

void instance_unit_info::Create_proj_Folder(wxArrayString a_wbs)
{
    wxArrayString a_project,a_folder;


    int i_count = a_wbs.GetCount();
    int i_proj=0;
    wxString s_project=wxEmptyString;
    for(int j=0;j<i_count;j++)
    {
        if(s_project != a_wbs.Item(j).Left(10))
        {
            i_proj+=1;
            s_project=a_wbs.Item(j).Left(10);
            a_project.Add(s_project);
        }

    }
    wxString str_folder,str, str_path;

    for(int i=0; i<i_proj; i++)
    {
        s_project = a_project.Item(i);

        str_folder = get_full_prj_info(s_project);

        str_folder = a_project.Item(i)+str_folder;

        str_folder.Replace(wxT("/"),wxT(""));

        a_folder.Add(str_folder);
    }

    wxArrayString a_sub_folder;


    pugi::xml_document ldoc;
    pugi::xml_node lnode,litem;
    pugi::xml_parse_result result;

    result = ldoc.load_file("para.xml");

    if(result)
    {
        lnode = ldoc.child("StartFolder");
        for(litem = lnode.first_child(); litem; litem = litem.next_sibling())
        {
            str = wxString(litem.text().as_string());
            a_sub_folder.Add(str);
        }

        lnode = ldoc.child("StartPath");
        str_path = wxString(lnode.child_value("item"));
    }
    else
        return;

    wxDir ldir;
    wxString s_folder, s_sub_folder;

    for(int m=0; m<i_proj; m++)
    {
        ldir.Open(str_path);

        if(ldir.IsOpened())
        {
            s_folder = str_path+wxT("\\")+a_folder.Item(m);

            if(!ldir.Exists(s_folder))
            {
                if(ldir.Make(s_folder))
                {
                    wxLogMessage(_("成功-主资源文件夹。")+s_folder);
                }else
                {
                    wxLogMessage(_("失败:")+s_folder);
                    continue;
                }
            }


            if(ldir.Open(s_folder))
            {
                int i_folder_num = a_sub_folder.GetCount();
                for(int k=0; k<i_folder_num; k++)
                {
                                                                                                              s_sub_folder = s_folder+wxT("\\")+a_sub_folder.Item(k);
                    if(!ldir.Exists(s_sub_folder))
                    {

                        if(ldir.Make(s_sub_folder))
                        {
                            wxLogMessage(_("成功-子文件夹")+s_sub_folder);
                            if(a_sub_folder.Item(k)=="0700 SPEC&GAD")
                            {
                                ldir.Make(s_sub_folder+wxT("\\旧版清单"));
                            }
                        }
                        else
                        {
                            wxLogMessage(_("失败-子文件夹")+s_sub_folder);
                            continue;
                        }
                    }
                }
            }
        }
    }

   // wxLogMessage(_("资源文件夹创建成功:"));
}

void instance_unit_info::Create_Folder(wxArrayString a_wbs)
{
    //    a_wbs.Sort(wbs_sort);
//   a_wbs.Sort(true);
    wxArrayString a_project,a_folder;
    a_project = combine_str(a_wbs, wxT(";"),wxT("-"),wxT(","),true, false);
    /*  测试排序
        int i_wbs= a_wbs.GetCount();
        wxString s_wbs;
        for(int k=0;k<i_wbs;k++)
        {
               s_wbs=s_wbs+a_wbs.Item(k)+wxT("\n");

        }
        wxMessageBox(s_wbs, _(""));*/

    int i_count = a_project.GetCount();
    wxString str_folder,str, str_path;

    for(int i=0; i<i_count; i++)
    {
        wxString s_project = a_project.Item(i).Left(10);

        str_folder = get_full_prj_info(s_project);

        str_folder = a_project.Item(i)+str_folder;

        str_folder.Replace(wxT("/"),wxT(""));

        a_folder.Add(str_folder);
    }

    wxArrayString a_sub_folder;


    pugi::xml_document ldoc;
    pugi::xml_node lnode,litem;
    pugi::xml_parse_result result;

    result = ldoc.load_file("para.xml");

    if(result)
    {
        lnode = ldoc.child("StartFolder");
        for(litem = lnode.first_child(); litem; litem = litem.next_sibling())
        {
            str = wxString(litem.text().as_string());
            a_sub_folder.Add(str);
        }

        lnode = ldoc.child("StartPath");
        str_path = wxString(lnode.child_value("item"));
    }
    else
        return;

    wxDir ldir;
    wxString s_folder, s_sub_folder;

    for(int j=0; j<i_count; j++)
    {
        ldir.Open(str_path);

        if(ldir.IsOpened())
        {
            s_folder = str_path+wxT("\\")+a_folder.Item(j);

            if(!ldir.Exists(s_folder))
            {
                if(ldir.Make(s_folder))
                {
                    wxLogMessage(_("成功-主资源文件夹。")+s_folder);
                }else
                {
                    wxLogMessage(_("失败:")+s_folder);
                    continue;
                }
            }


            if(ldir.Open(s_folder))
            {
                int i_folder_num = a_sub_folder.GetCount();
                for(int k=0; k<i_folder_num; k++)
                {
                    s_sub_folder = s_folder+wxT("\\")+a_sub_folder.Item(k);
                    if(!ldir.Exists(s_sub_folder))
                    {

                        if(ldir.Make(s_sub_folder))
                        {
                            wxLogMessage(_("成功-子文件夹")+s_sub_folder);
                            if(a_sub_folder.Item(k)=="0700 SPEC&GAD")
                            {
                                ldir.Make(s_sub_folder+wxT("\\旧版清单"));
                            }
                        }
                        else
                        {
                            wxLogMessage(_("失败-子文件夹")+s_sub_folder);
                            continue;
                        }
                    }
                }
            }
        }
    }

   // wxLogMessage(_("资源文件夹创建成功:"));

}

wxString instance_unit_info::get_full_prj_info(wxString s_prj)
{
    wxString str_sql = wxT("select concat(project_name,contract_id) as prj_info from s_project_info where project_id ='")+s_prj+wxT("';");

    wxPostgreSQLresult* _res =wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return wxEmptyString;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count ==0)
        return wxEmptyString;

    wxString str= _res->GetVal(wxT("prj_info"));

    _res->Clear();

    return str;
}


void instance_unit_info::refresh_list(bool b_attach)
{
    if (!gr_para.login_status)
    {
        if (b_refresh)
            wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }
    if (!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }
    if (!b_refresh)
    {
        Set_Where_clause(wxT(" WHERE res_emp_id = '") + gr_para.login_user + wxT("' AND status='0' "));
    }
//   col_type.Clear();
//   col_name.Clear();
    wxPostgreSQLresult* _res;
    if(!b_attach)
        m_query = wxT("SELECT project_id, wbs_no, elevator_id, elevator_type, project_name, lift_no, status, wf_status, \
                is_urgent, project_catalog, nonstd_level, req_delivery_date, req_configure_finish, special_info, \
                version_id,(select doc_desc from s_doc where doc_id = unit_doc_id) as doc_desc,can_psn, has_nonstd_inst_info FROM v_unit_info ") + whereClause + wxT(" ORDER BY wbs_no ASC; ");
    else
                m_query = wxT("SELECT project_id, wbs_no, elevator_id, elevator_type, project_name, lift_no, status, wf_status, \
                is_urgent, project_catalog, nonstd_level, req_delivery_date, req_configure_finish, special_info, \
                version_id,(select doc_desc from s_doc where doc_id = unit_doc_id) as doc_desc,can_psn, has_nonstd_inst_info FROM v_unit_info_attach1 ") + whereClause + wxT(" ORDER BY wbs_no ASC; ");
    _res = wxGetApp().app_sql_select(m_query);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }
    m_rows = _res->GetRowsNumber();
    gd_unit_info->ClearGrid();
    int i_rows = gd_unit_info->GetNumberRows();
    /*
        if(m_rows > i_rows)
            gd_unit_info->AppendRows(m_rows-i_rows);

        if(m_rows<i_rows)
            gd_unit_info->DeleteRows(i_rows-m_rows);*/
    /* sqlResultTable 已更新appendrows,故此段不需要。
        int i_rows = gd_unit_info->GetNumberRows();

        if(i_rows>m_rows)
        {
    //        gd_unit_info->BeginBatch();
            wxGridUpdateLocker locker(gd_unit_info);
            wxGridTableMessage *msg;
            sqlResultTable *table = (sqlResultTable *)gd_unit_info->GetTable();
            msg = new wxGridTableMessage(table, wxGRIDTABLE_NOTIFY_ROWS_DELETED, 0, i_rows-m_rows);
            gd_unit_info->ProcessTableMessage(*msg);
            delete msg;

            gd_unit_info->ForceRefresh();
         //   gd_unit_info->EndBatch();
        }else if(i_rows<m_rows)
        {
      //      gd_unit_info->BeginBatch();
              wxGridUpdateLocker locker(gd_unit_info);
            wxGridTableMessage *msg;
            sqlResultTable *table = (sqlResultTable *)gd_unit_info->GetTable();
            msg = new wxGridTableMessage(table, wxGRIDTABLE_NOTIFY_ROWS_APPENDED, 0, m_rows-i_rows);
            gd_unit_info->ProcessTableMessage(*msg);
            delete msg;

            gd_unit_info->ForceRefresh();
         //   gd_unit_info->EndBatch();
        }

    */
//   if(m_rows == 0)
//         return;
//    gd_unit_info->BeginBatch();
    wxGridUpdateLocker locker(gd_unit_info);
    wxString str_table = wxT("s_unit_info");
    gd_unit_info->SetTable(new sqlResultTable(_res, str_table, str_unit_header, 0), true);
    gd_unit_info->SetSelectionMode(wxGrid::wxGridSelectRows);
    gd_unit_info->Fit();
//   gd_unit_info->EndBatch();
    gd_unit_info->SetColSize(15, 300);
    gd_unit_info->SetColSize(16,0);
    gd_unit_info->SetColSize(17,0);
    Layout();
    _res->Clear();
    if (!b_refresh_project)
    {
        b_refresh_project = true;
        return;
    }

    if(!b_attach)
         m_query = wxT("SELECT DISTINCT project_id , contract_id, project_name, plant, branch_name, res_emp_id from v_unit_info ") + whereClause + wxT(" Order by project_id;");
    else
        m_query = wxT("SELECT DISTINCT project_id , contract_id, project_name, plant, branch_name, res_emp_id from v_unit_info_attach1 ") + whereClause + wxT(" Order by project_id;");
    _res = wxGetApp().app_sql_select(m_query);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        return;
    }
    refresh_project_list(_res);
}

bool instance_unit_info::update_review_units_latest(wxString s_units, bool b_latest)
{
    bool b_sel= (b_latest)?false:true;
    wxString str_sql = wxT("UPDATE s_review_units SET  modify_date='")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id='")+gr_para.login_user+wxT("',is_latest=")+BoolToStr(b_latest)+wxT(" WHERE \
                        wbs_no='")+s_units+wxT("' and is_latest = ")+BoolToStr(b_sel)+wxT(";");
    return wxGetApp().app_sql_update(str_sql);
}

bool instance_unit_info::update_basic_finish_status(wxString s_wbs, bool _status)
{
    wxString s_sql = wxT("UPDATE s_unit_info_attach SET is_basic_finish=")+BoolToStr(_status)+wxT(" where wbs_no ='")+s_wbs+wxT("';");
    return wxGetApp().app_sql_update(s_sql);
}

void instance_unit_info::refresh_project_list(wxPostgreSQLresult *_res)
{
    if (b_refresh)
        lc_project->DeleteAllItems();
    int irow = _res->GetRowsNumber();
    _res->MoveFirst();
    for (int i = 0; i < irow; i++)
    {
        wxString str = _res->GetVal(wxT("project_id"));
        long tmp = lc_project->InsertItem(i, str);
        lc_project->SetItemData(tmp, i);
        str = _res->GetVal(wxT("contract_id"));
        lc_project->SetItem(tmp, 1, str);
        str = _res->GetVal(wxT("project_name"));
        lc_project->SetItem(tmp, 2, str);
        str = _res->GetVal(wxT("plant"));
        lc_project->SetItem(tmp, 3, str);
        str = _res->GetVal(wxT("branch_name"));
        lc_project->SetItem(tmp, 4, str);
        _res->MoveNext();
    }
    _res->Clear();
//   b_refresh = true;
}

void instance_unit_info::Onlc_projectItemRClick(wxListEvent& event)
{
    PopupMenu(&menu_project_filter, event.GetPoint());
}

void instance_unit_info::Ongd_unit_infoCellRightClick(wxGridEvent& event)
{
    PopupMenu(&menu_unit_info_renew, ScreenToClient(wxGetMousePosition()));
}

void instance_unit_info::OnMenuItem1Selected(wxCommandEvent& event)
{
    if (m_rows == 0)
        return;
    gd_unit_info->SelectAll();
    /*
    for(int i = 0;i<m_rows;i++)
    {
        gd_unit_info->SelectRow(i,true);
    }*/
    event.Skip();
}

void instance_unit_info::OnMenuItem2Selected(wxCommandEvent& event)
{
    if (gd_unit_info->GetSelectedRows().GetCount() == 0)
        return;
    gd_unit_info->ClearSelection();
}

void instance_unit_info::OnMenuItem10Selected(wxCommandEvent& event)//新项目
{
//    Set_Where_clause(wxT(" WHERE res_emp_id = '")+gr_para.login_user+wxT("' AND status='0' "));
    Set_Where_clause(wxT(" WHERE  status='0' and wbs_no not in (select wbs_no from s_review_units where is_latest = true and is_del=false and  unit_status>=0) "));
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem9Selected(wxCommandEvent& event) //全部项目
{
    /*
       Set_Where_clause(wxT("  WHERE res_emp_id = '")+gr_para.login_user+wxT("'  "));
       b_refresh = true;
       refresh_list();
       b_refresh = false;*/
}


void instance_unit_info::OnMenuItem11Selected(wxCommandEvent& event) //评审完成项目
{
//    Set_Where_clause(wxT(" WHERE res_emp_id = '")+gr_para.login_user+wxT("' AND status='2' "));
    Set_Where_clause(wxT(" WHERE  status='2' "));
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem17Selected(wxCommandEvent& event)//暂停项目
{
//    Set_Where_clause(wxT(" WHERE res_emp_id = '")+gr_para.login_user+wxT("' AND status='4' "));
    Set_Where_clause(wxT(" WHERE status='4' "));
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem12Selected(wxCommandEvent& event)//正在走流程项目
{
//    Set_Where_clause(wxT(" WHERE res_emp_id = '")+gr_para.login_user+wxT("' AND status='1' "));
    Set_Where_clause(wxT(" WHERE status='1' or status = '3' "));
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}


void instance_unit_info::OnMenuItem15Selected(wxCommandEvent& event)//配置完成
{
//    Set_Where_clause(wxT(" WHERE res_emp_id = '")+gr_para.login_user+wxT("' AND status='6' "));
    Set_Where_clause(wxT(" WHERE  status = '5' "));
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem16Selected(wxCommandEvent& event)//归档项目
{
    Set_Where_clause(wxT(" WHERE  status = '6' "));
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}



void instance_unit_info::OnMenuItem13Selected(wxCommandEvent& event)//filter by project_ID
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    search_case tdlg;
    wxString s_sql;
    wxArrayString array_project_id;
    if (tdlg.ShowModal() == wxID_OK)
    {
        array_project_id = tdlg.GetValue();
    }
    else return;
//   event.Skip();
    int i_count  = array_project_id.GetCount();
    for (int i = 0; i < i_count; i++)
    {
        if (i == 0)
//          s_sql = wxT(" WHERE res_emp_id = '")+gr_para.login_user+wxT("' AND (project_id LIKE '%")+array_project_id.Item(i)+wxT("%' ");
            s_sql = wxT(" WHERE  (project_id LIKE '%") + array_project_id.Item(i) + wxT("%' ");
        else
            s_sql = s_sql + wxT(" OR project_id LIKE '%") + array_project_id.Item(i) + wxT("%' ");
    }
    s_sql  = s_sql + wxT(") and status >=0 ");
    Set_Where_clause(s_sql);
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem14Selected(wxCommandEvent& event)//filter by wbs_no
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    search_case tdlg;
    wxString s_sql;
    wxArrayString array_wbsno;
    if (tdlg.ShowModal() == wxID_OK)
    {
        array_wbsno = tdlg.GetValue();
    }
    else return;
//   event.Skip();
    int i_count  = array_wbsno.GetCount();
    for (int i = 0; i < i_count; i++)
    {
        if (i == 0)
//         s_sql = wxT(" WHERE res_emp_id = '")+gr_para.login_user+wxT("' AND (wbs_no LIKE '%")+array_wbsno.Item(i)+wxT("%' ");
            s_sql = wxT(" WHERE  (wbs_no LIKE '%") + array_wbsno.Item(i) + wxT("%' ");
        else
            s_sql = s_sql + wxT(" OR wbs_no LIKE '%") + array_wbsno.Item(i) + wxT("%' ");
    }
    s_sql  = s_sql + wxT(") ");
    Set_Where_clause(s_sql);
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}


void instance_unit_info::OnMenuItem3Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    wxString str_date, str_wbsno, str_sql, s_date;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    mydatepicker ddlg;
    if (ddlg.ShowModal() == wxID_OK)
    {
        str_date = ddlg.GetString();
        s_date = str_date + wxT(" 23:00:00");
    }
    else return;
//    wxString str_batch = wxDateTime::Now().Format("%Y-%m-%d-%H-%M-%S");
//    str_batch.Replace("-",wxEmptyString);
    int i_count = array_sel_line.GetCount();
    if (!str_date.IsEmpty())
    {
        for (int i = 0; i < i_count; i++)
        {
            str_wbsno = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
            str_sql = wxT("UPDATE s_unit_info SET req_delivery_date ='") + s_date +/*wxT("',conf_batch_id='")+str_batch+*/wxT("' WHERE wbs_no='") + str_wbsno + wxT("';");
            if (wxGetApp().app_sql_update(str_sql))
            {
                wxLogMessage(_("unit:") + str_wbsno + _("更新发运日期为") + str_date + _("成功"));
                wxString s_source = gd_unit_info->GetCellValue(array_sel_line.Item(i), 11);
                wxGetApp().change_log(wxT("s_unit_info"), str_wbsno, wxT("req_delivery_date"), s_source, str_date, wxT("hand"));
            }
        }
    }
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem18Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    wxArrayString array_sel_wbs;
    wxString str_temp;
    int i_status;
    for (int i = 0; i < i_count; i++)
    {
        str_temp = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1).Upper().Trim();
        i_status= prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6));
        if(i_status ==2 || i_status ==0)
        {
            continue;
        }
        array_sel_wbs.Add(str_temp);
    }
    ins_proc_log ipl_dlg;
    ipl_dlg.init_conf_list_header();
    ipl_dlg.Refresh_list_view(array_sel_wbs);
    ipl_dlg.ShowModal();
    //  event.Skip();
}

void instance_unit_info::OnMenuItem4Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    wxString str_date, str_wbsno, str_sql, s_date;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    mydatepicker ddlg;
    if (ddlg.ShowModal() == wxID_OK)
    {
        str_date = ddlg.GetString();
        s_date = str_date + wxT(" 23:00:00");
    }
    else return;


    int i_count = array_sel_line.GetCount();
    if (!str_date.IsEmpty())
    {
        for (int i = 0; i < i_count; i++)
        {
            str_wbsno = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
            str_sql = wxT("UPDATE s_unit_info SET req_configure_finish ='") + s_date + wxT("' WHERE wbs_no='") + str_wbsno + wxT("';");
            if (wxGetApp().app_sql_update(str_sql))
            {
                wxLogMessage(_("unit:") + str_wbsno + _("更新配置完成日期为") + str_date + _("成功"));
                wxString s_source = gd_unit_info->GetCellValue(array_sel_line.Item(i), 12);
                wxGetApp().change_log(wxT("s_unit_info"), str_wbsno, wxT("req_configure_finish"), s_source, str_date, wxT("hand"));


                //update_nonstd_conf_date(str_wbsno,StrToDateTime(s_date));
                get_nonstd_array(str_wbsno);
            }
        }
        update_nonstd_conf_date();
        array_update_conf.Clear();
        array_links.Clear();
        array_now.Clear();

    }
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

bool instance_unit_info::get_nonstd_array(wxString s_wbs)
{
    wxString str_sql = wxT("SELECT * FROM l_nonstd_app_header where link_list like '%")+s_wbs+wxT("%' and (status >= 0 and status < 10)  ;");


    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }


    int i_count = _res->GetRowsNumber();

    if(i_count == 0)
    {
        _res->Clear();
        return false;
    }

    wxString s_app_id, s_link, s_now;

    _res->MoveFirst();

    for(int i=0;i<i_count;i++)
    {
        s_app_id = _res->GetVal(wxT("nonstd_id"));
        s_link = _res->GetVal(wxT("link_list"));
        s_now = DateToAnsiStr(_res->GetDateTime(wxT("drawing_req_date")));
        if(array_update_conf.Index(s_app_id)!=wxNOT_FOUND)
        {
            _res->MoveNext();
            continue;
        }

        //array_update_conf.Add(s_app_id);

        if(array_update_conf.Index(s_app_id)!=wxNOT_FOUND)
        {
            _res->MoveNext();
            continue;
        }

        array_update_conf.Add(s_app_id);
        array_links.Add(s_link);
        array_now.Add(s_now);

        _res->MoveNext();

    }

    _res->Clear();
}

bool instance_unit_info::update_nonstd_conf_date()
{
    wxString str_sql;
    wxString s_list, s_nstd;
    wxPostgreSQLresult * _res;
    int icount = array_update_conf.GetCount();
    wxDateTime dt_aim;

    for(int i=0;i<icount;i++)
    {
        s_nstd = array_update_conf.Item(i);
        s_list = array_links.Item(i);
        if(s_list.Right(1)==";")
            s_list.RemoveLast();
        s_list.Replace(";","','");
        str_sql = wxT("select req_configure_finish from s_unit_info where wbs_no in ('")+s_list+wxT("') and status>=0;");
        _res = wxGetApp().app_sql_select(str_sql);

        int i_qty = _res->GetRowsNumber();

        if(i_qty==0)
        {
            _res->Clear();
            continue;
        }

        dt_aim = _res->GetDateTime(wxT("req_configure_finish"));

        for(int j=1;j<i_qty;j++)
        {
            _res->MoveNext();

            if(dt_aim.IsLaterThan(_res->GetDateTime(wxT("req_configure_finish"))))
            {
                dt_aim = _res->GetDateTime(wxT("req_configure_finish"));
            }

        }

        _res->Clear();

        str_sql = wxT("UPDATE l_nonstd_app_header SET drawing_req_date='")+DateToAnsiStr(dt_aim)+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                wxT("', modify_emp_id='")+gr_para.login_user+wxT("' where nonstd_id ='")+s_nstd+wxT("';");

        if (wxGetApp().app_sql_update(str_sql))
        {
                wxLogMessage(_("非标：") + s_nstd + _("图纸要求日期变更为:") + DateToStrFormat(dt_aim) + _("成功!"));
                wxGetApp().change_log(wxT("l_nonstd_app_header"), s_nstd, wxT("drawing_req_date"), array_now.Item(i), DateToAnsiStr(dt_aim), wxT("hand"));
        }


    }


}

void instance_unit_info::OnMenuItem5Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    wxString str_wbsno, str_sql;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    wxString _choice[6] =
    {
        _("Common Project"),
        _("High-Speed Project"),
        _("Special Project"),
        _("Major Project"),
        _("Pre-engineering"),
        _("Lean Project")
    };
    wxSingleChoiceDialog cdlg(this, _("请选择项目类型？"), _("项目类型选择"), 6, _choice);
    if (cdlg.ShowModal() == wxID_CANCEL)
        return;
    int i_choice = cdlg.GetSelection();
    wxString s_result = cdlg.GetStringSelection();
    int i_count = array_sel_line.GetCount();
    for (int i = 0; i < i_count; i++)
    {
        str_wbsno = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        str_sql = wxT("UPDATE s_unit_info SET project_catalog ='") + NumToStr(i_choice + 1) + wxT("' WHERE wbs_no='") + str_wbsno + wxT("';");
        if (wxGetApp().app_sql_update(str_sql))
        {
            wxLogMessage(_("unit:") + str_wbsno + _("更新项目类型成功"));
            wxString s_source = gd_unit_info->GetCellValue(array_sel_line.Item(i), 9);
            wxGetApp().change_log(wxT("s_unit_info"), str_wbsno, wxT("project_catalog"), s_source, s_result, wxT("hand"));
        }
    }
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem6Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    wxString s_choice, s_wbsno, str_sql;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    if (wxMessageBox(_("确认切换当前项目的是否紧急状态标识？"), _("是否切换:"), wxOK | wxCANCEL, this) == wxOK)
    {
        int i_count = array_sel_line.GetCount();
        wxString s_source;
        for (int i = 0; i < i_count; i++)
        {
            s_wbsno = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
            s_choice = gd_unit_info->GetCellValue(array_sel_line.Item(i), 8);
            if (s_choice == wxT("Y"))
            {
                s_source = wxT("true");
                s_choice = wxT("false");
            }
            else
            {
                s_source = wxT("false");
                s_choice = wxT("true");
            }
            str_sql = wxT("UPDATE s_unit_info SET is_urgent =") + s_choice + wxT(" WHERE wbs_no='") + s_wbsno + wxT("';");
            if (wxGetApp().app_sql_update(str_sql))
            {
                wxLogMessage(_("unit:") + s_wbsno + _("是否紧急项目切换成功!"));
                wxGetApp().change_log(wxT("s_unit_info"), s_wbsno, wxT("is_urgent"), s_source, s_choice, wxT("hand"));
            }
        }
        b_refresh_project = false;
        b_refresh = true;
        refresh_list();
        b_refresh = false;
    }
}

void instance_unit_info::Onlc_projectItemActivated(wxListEvent& event)
{
    wxListItem li_item = event.GetItem();
    li_item.m_col = 0;
    wxString s_project = li_item.GetText();
//   Set_Where_clause(wxT(" WHERE res_emp_id = '")+gr_para.login_user+wxT("' AND project_id = '")+s_project+wxT("' "));
    Set_Where_clause(wxT(" WHERE project_id = '") + s_project + wxT("' and status>=0 "));
    b_refresh = true;
    b_refresh_project = false;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem7Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    wxString str_wbsno, str_sql;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    wxString _choice[4] =
    {
 //       _("Target STD"),
        _("Option STD"),
        _("Simple Non-STD"),
        _("Complex Non-STD"),
        _("Comp-Standard")//,
  //      _("Comp-Measurement"),
   //     _("Comp-Configurable")
    };
    wxSingleChoiceDialog cdlg(this, _("请选择非标等级?"), _("非标等级选择:"), 4, _choice);
    if (cdlg.ShowModal() == wxID_CANCEL)
        return;
    int i_nstd_level = nstd_str_to_level(cdlg.GetStringSelection());
    int i_old_nstd_level;
    wxString s_result = cdlg.GetStringSelection();
    int i_count = array_sel_line.GetCount();
    for (int i = 0; i < i_count; i++)
    {
        str_wbsno = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        i_old_nstd_level = nstd_str_to_level(gd_unit_info->GetCellValue(array_sel_line.Item(i),10));

        if(i_nstd_level == i_old_nstd_level)
        {
               wxLogMessage(str_wbsno+_("非标等级本来就是:")+nstd_level_to_str(i_nstd_level)+_("，无需更新!"));
               continue;
        }

        if(update_nstd_level(str_wbsno,i_old_nstd_level,i_nstd_level))
        {
            gd_unit_info->SetCellValue(array_sel_line.Item(i), 10, nstd_level_to_str(i_nstd_level));

            wxLogMessage(str_wbsno+_("非标等级更新为:")+nstd_level_to_str(i_nstd_level)+_(", 成功!"));
        }

    }

}

void instance_unit_info::Onlc_projectBeginDrag(wxListEvent& event)
{
}

void instance_unit_info::OnMenuItem8Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    wxString s_wbsno, str_sql;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    if (wxMessageBox(_("确认暂停当前项目？"), _("暂停项目:"), wxOK | wxCANCEL, this) == wxOK)
    {
        int i_count = array_sel_line.GetCount();
        for (int i = 0; i < i_count; i++)
        {
            s_wbsno = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
            str_sql = wxT("UPDATE s_unit_info SET status = '4' WHERE wbs_no='") + s_wbsno + wxT("';");
            if (wxGetApp().app_sql_update(str_sql))
            {
                wxLogMessage(_("unit暂停成功"));
                wxString s_source = gd_unit_info->GetCellValue(array_sel_line.Item(i), 6);
                wxGetApp().change_log(wxT("s_unit_info"), s_wbsno, wxT("status "), s_source, wxT("FREEZED"), wxT("hand"));
            }
        }
        b_refresh_project = false;
        b_refresh = true;
        refresh_list();
        b_refresh = false;
    }
}

void instance_unit_info::OnMenuItem19Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    wxString s_wbsno, str_sql;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    if (wxMessageBox(_("确认恢复当前项目？"), _("恢复项目:"), wxOK | wxCANCEL, this) == wxOK)
    {
        int i_count = array_sel_line.GetCount();
        for (int i = 0; i < i_count; i++)
        {
            s_wbsno = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
            wxString s_str = gd_unit_info->GetCellValue(array_sel_line.Item(i), 6);
            if (s_str != wxT("FREEZED"))
                continue;
            str_sql = wxT("UPDATE s_unit_info SET status = '1' WHERE wbs_no='") + s_wbsno + wxT("';");
            if (wxGetApp().app_sql_update(str_sql))
            {
                wxLogMessage(s_wbsno + _("unit恢复成功"));
                wxGetApp().change_log(wxT("s_unit_info"), s_wbsno, wxT("status "), s_str, wxT("ACTIVE"), wxT("hand"));
            }
        }
        b_refresh_project = false;
        b_refresh = true;
        refresh_list();
        b_refresh = false;
    }
}

void instance_unit_info::OnMenuItem20Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    wxString s_wbsno, str_sql;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    if (wxMessageBox(_("确认取消重排产？"), _("重排产项目:"), wxOK | wxCANCEL, this) == wxOK)
    {
        int i_count = array_sel_line.GetCount();
        for (int i = 0; i < i_count; i++)
        {
            s_wbsno = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
            wxString s_str = gd_unit_info->GetCellValue(array_sel_line.Item(i), 6);
            if (s_str != wxT("RESTART"))
                continue;
            str_sql = wxT("UPDATE s_unit_info SET status = '5' WHERE wbs_no='") + s_wbsno + wxT("';");
            if (wxGetApp().app_sql_update(str_sql))
            {
                wxGetApp().change_log(wxT("s_unit_info"), s_wbsno, wxT("status "), s_str, wxT("CLOSED"), wxT("hand"));
            }
            str_sql = wxT("UPDATE l_proc_act SET is_active= false WHERE wbs_no ='") + s_wbsno + wxT("';");
            if (wxGetApp().app_sql_update(str_sql))
            {
                wxLogMessage(s_wbsno + _("重排产取消成功"));
            }
        }
        b_refresh_project = false;
        b_refresh = true;
        refresh_list();
        b_refresh = false;
    }
}

void instance_unit_info::Show_control()
{
    wxArrayString array_group = wxGetApp().get_group();

    if(array_group.Index(wxT("G0001"))!=wxNOT_FOUND)
    {
        Button_NSTD_SAP_UPDATE->Show(true);
        Button1->Show(true);
        Button2->Show(true);
        Button3->Show(false);
        Button4->Show(false);
        Button5->Show(true);
        mi_folder->Enable(false);

        button_cancel_restart->Show(false);
        Button_Cancel_project->Show(false);
        Button_Restore_project->Show(false);
        Button_DEL_project->Show(false);
        Button_Pre_Production->Show(true);
        mi_pre_production->Enable(true);
        Button_cancel_production->Show(true);

        MenuItem3->Enable(false);
        MenuItem4->Enable(false);
        MenuItem5->Enable(false);
        //MenuItem6->Enable(false);
        MenuItem7->Enable(false);
        MenuItem8->Enable(false);
        MenuItem19->Enable(false);
       MenuItem20->Enable(false);

        mi_generate_contract->Enable(false);
        mi_search_contract->Enable(false);
        mi_unit_in_contract->Enable(true);
         mi_add_contract_id->Enable(false);
         mi_special_info->Enable(false);

        button_sap_by_internal->Show(true);
        button_sap_by_wbs->Show(true);
        Button_Cal_Basic_Info->Show(false);
        Button_syc_to_din->Show(false);
        mi_syc_din->Enable(false);
        mi_print_label->Enable(false);
    }else if(array_group.Index(wxT("G0011"))!=wxNOT_FOUND||array_group.Index(wxT("G0015"))!=wxNOT_FOUND)
    {
        Button_NSTD_SAP_UPDATE->Show(false);
        Button1->Show(false);
        Button2->Show(false);
        Button3->Show(true);
        Button4->Show(true);
        Button5->Show(false);
        mi_folder->Enable(true);

        Button_Pre_Production->Show(false);
        Button_cancel_production->Show(false);
        mi_pre_production->Enable(true);

        button_cancel_restart->Show(true);
        Button_Cancel_project->Show(true);
        Button_Restore_project->Show(true);
        Button_DEL_project->Show(true);
        button_sap_by_internal->Show(true);
        button_sap_by_wbs->Show(true);
        mi_special_info-Enable(true);

        MenuItem3->Enable(true);
        MenuItem4->Enable(true);
        MenuItem5->Enable(true);
        //MenuItem6->Enable(true);
        MenuItem7->Enable(true);
        MenuItem8->Enable(true);
        MenuItem19->Enable(true);
        MenuItem20->Enable(true);

         mi_add_contract_id->Enable(true);

        Button_Cal_Basic_Info->Show(true);
        button_sap_by_internal->Show(true);
        button_sap_by_wbs->Show(true);

        mi_generate_contract->Enable(false);
        mi_search_contract->Enable(false);
        mi_unit_in_contract->Enable(true);
        Button_syc_to_din->Show(true);
        mi_syc_din->Enable(true);
        mi_print_label->Enable(true);

   //         Button_Cal_Basic_Info->Enable(b_sys_basic_info_mode);
    }else if(array_group.Index(wxT("G0017"))!=wxNOT_FOUND)
    {
       Button_NSTD_SAP_UPDATE->Show(true);
        Button1->Show(true);
        Button2->Show(true);
        Button3->Show(false);
        Button4->Show(false);
        Button5->Show(true);
        mi_folder->Enable(false);
        Button_Pre_Production->Show(true);
        Button_cancel_production->Show(true);

        button_cancel_restart->Show(false);
        Button_Cancel_project->Show(false);
        Button_Restore_project->Show(false);
        Button_DEL_project->Show(false);
        mi_pre_production->Enable(true);

        MenuItem3->Enable(false);
        MenuItem4->Enable(false);
        MenuItem5->Enable(false);
        //MenuItem6->Enable(false);
        MenuItem7->Enable(false);
        MenuItem8->Enable(false);
        MenuItem19->Enable(false);
        MenuItem20->Enable(false);

        mi_generate_contract->Enable(true);
        mi_search_contract->Enable(true);
        mi_unit_in_contract->Enable(true);
        mi_add_contract_id->Enable(true);
        mi_special_info->Enable(true);

        button_sap_by_internal->Show(true);
        button_sap_by_wbs->Show(true);
        Button_Cal_Basic_Info->Show(false);
        Button_syc_to_din->Show(false);
        mi_syc_din->Enable(false);
        mi_print_label->Enable(false);

    }else
    {
        Button_NSTD_SAP_UPDATE->Show(false);
        Button1->Show(false);
        Button2->Show(false);
        Button3->Show(false);
        Button4->Show(false);
        Button5->Show(false);
        button_sap_by_internal->Show(true);
        button_sap_by_wbs->Show(false);
        mi_folder->Enable(false);
        Button_Pre_Production->Show(false);
        Button_cancel_production->Show(false);
        mi_pre_production->Enable(false);

        button_cancel_restart->Show(false);
        Button_Cancel_project->Show(false);
        Button_Restore_project->Show(false);
        Button_DEL_project->Show(false);

        mi_generate_contract->Enable(false);
        mi_search_contract->Enable(false);
        mi_unit_in_contract->Enable(false);
        mi_add_contract_id->Enable(false);
        mi_special_info->Enable(false);


        MenuItem3->Enable(false);
        MenuItem4->Enable(false);
        MenuItem5->Enable(false);
        //MenuItem6->Enable(false);
        MenuItem7->Enable(false);
        MenuItem8->Enable(false);
        MenuItem19->Enable(false);
       MenuItem20->Enable(false);
        Button_Cal_Basic_Info->Show(false);

        button_sap_by_internal->Show(false);
        button_sap_by_wbs->Show(false);
        Button_syc_to_din->Show(false);
        mi_syc_din->Enable(false);
        mi_print_label->Enable(false);
    }

    if(gr_para.login_user=="10260454"||gr_para.login_user=="10260435"||gr_para.login_user=="10350040")
    {
        mi_urgent->Enable(true);
    }else
    {
        mi_urgent->Enable(false);
    }
}

void instance_unit_info::OnButton5Click(wxCommandEvent& event)
{
    if(!gr_para.login_status)
        return;

    if(gr_para.login_user != wxT("10260435") && gr_para.login_user != wxT("10417121")&&gr_para.login_user!=wxT("10395142"))
    {
        wxMessageBox(_("阁下无此权限!"),_("提示"));
        return;
    }

    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

    if(wxMessageBox(_("确认所选项目已经release？"),_("release确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxString str_wbs_no;
    int i_status;

    for(int i=0;i<i_count;i++)
    {
        str_wbs_no = gd_unit_info->GetCellValue(array_sel_line.Item(i),1);
        i_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i),6));

        if(i_status!=5)
            continue;

        wxString str_sql = wxT("UPDATE s_unit_info SET status ='6', wf_status ='项目release完成', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' where wbs_no ='")+str_wbs_no+wxT("';");
        if(wxGetApp().app_sql_update(str_sql))
        {
            wxGetApp().change_log(wxT("s_unit_info"),str_wbs_no, wxT("status"), wxT("5"), wxT("6"),wxT("hand") );
            i_status = 6;

            gd_unit_info->SetCellValue(array_sel_line.Item(i),6, prj_status_to_str(i_status));
        }

    }
}


void instance_unit_info::OnButton4Click(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    bool b_log_pass = false;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    v_wf_action * t_template = get_template_action(wf_str_configure);
    v_wf_action * t_new_template = get_template_action(wf_str_new_config);

    /*    wxString *array_sel_str = new wxString[t_template[0].i_total_flow];
       wxString str_temp;

       for(int i=0; i<t_template[0].i_total_flow; i++)
       {
           str_temp = t_template[i].s_action_id + wxT("-")+ t_template[i].s_action_name;
           array_sel_str[i] = str_temp;
       }

       wxSingleChoiceDialog cdlg(this, _("请从如下配置步骤中选择重排产启动步骤："),_("重排产启动选择"),t_template[0].i_total_flow, array_sel_str);

       delete [] array_sel_str;

       if (cdlg.ShowModal() == wxID_CANCEL)
           return;

       str_temp = cdlg.GetStringSelection();
       int i_pos = str_temp.Find('-');
       str_temp = str_temp.Left(i_pos);*/
    wxTextEntryDialog tdlg(this, _("重排产提示输入"), _("备注"), wxT(""), wxOK | wxCANCEL | wxTE_MULTILINE, wxDefaultPosition);
    wxString str_desc;
    if (tdlg.ShowModal() == wxID_OK)
    {
        b_log_pass = false;
        str_desc = tdlg.GetValue();
    }
    else
    {
        b_log_pass = true;
    }
    wf_operator * wf_configure;
    wf_operator_ex * wf_new_conf;
    wxString s_case;
    bool b_new_config=false;

    wxString str_instance;
    wxLongLong mils_used, start_mils;
    int i_status;
    wxString s_project, s_lift_no, s_lift_type;
    wxArrayString array_wbs, array_group, array_flag;
    int i_ways;
    for (int i = 0; i < i_count; i++)
    {
        str_instance = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        i_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6));
        s_project = gd_unit_info->GetCellValue(array_sel_line.Item(i),0).Trim();
        s_lift_no = gd_unit_info->GetCellValue(array_sel_line.Item(i),5).Trim();
        s_lift_type = gd_unit_info->GetCellValue(array_sel_line.Item(i),2).Trim();

        check_same_lift_no(s_project,s_lift_no);
        if (b_log_pass)
        {
            str_desc = gd_unit_info->GetCellValue(array_sel_line.Item(i), 15);
        }
        if (i_status != 5 && i_status !=6)
        {
            wxLogMessage(str_instance + _("-配置未完成过，无法启动重排产流程!"));
            continue;
        }

        if (i_status  == 8)
        {
            wxLogMessage(str_instance + _("-已经发运，无法启动重排产!"));
            continue;
        }


        start_mils = wxGetLocalTimeMillis();

        int i_times = update_restart_status(str_instance, true);

        if(!wxGetApp().check_new_config(array_group, array_flag, i_ways, s_lift_type, s_case))
            b_new_config=false;
        else
        {
            if(!s_case.IsEmpty())
            {
              if(!wxGetApp().check_is_highspeed(str_instance))
                   b_new_config=false;
              else
                  b_new_config=true;
            }else
                b_new_config=true;
        }

        if(!b_new_config)//新的配置工作流，由非标负责
        {
            update_basic_finish_status(str_instance);
            wf_configure = new wf_operator(str_instance, wf_str_configure, t_template);
            wf_configure->restart_instance(i_times);
            wf_configure->update_instance(3);
            delete wf_configure;
            wf_configure = NULL;
        }else
        {
            for(int k=0; k<i_ways; k++)
            {

                wf_new_conf = new wf_operator_ex(str_instance, wf_str_new_config, t_new_template, array_flag.Item(k));
                wf_new_conf->restart_instance(i_times);
                wf_new_conf->update_instance(3);
                if (wf_new_conf)
                    delete wf_new_conf;

            }
        }

        mils_used = wxGetLocalTimeMillis() - start_mils;
        wxLogMessage(str_instance + _("重排产流程创建成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));
    }
    if (t_template)
        delete [] t_template;

    if(t_new_template )
        delete [] t_new_template;

    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

int instance_unit_info::update_restart_status(wxString str_wbs, bool b_up)
{
    wxString str_sql = wxT("SELECT * FROM s_unit_info where wbs_no='") + str_wbs + wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        return -1;
    }
    int i_times = _res->GetInt(wxT("restart_times"));
    _res->Clear();
    if (b_up)
        i_times++;
    else
        i_times--;
    str_sql = wxT("UPDATE s_unit_info SET restart_times='") + NumToStr(i_times) + wxT("' where wbs_no = '") + str_wbs + wxT("';");
    if (wxGetApp().app_sql_update(str_sql))
        return i_times;
    return -1;
}

int instance_unit_info::update_cancel_status(wxString str_wbs)
{
    wxString str_sql = wxT("SELECT * FROM s_unit_info where wbs_no='") + str_wbs + wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        return -1;
    }
    int i_times = _res->GetInt(wxT("cancel_times"));
    _res->Clear();
    i_times++;

    str_sql = wxT("UPDATE s_unit_info SET cancel_times='") + NumToStr(i_times) + wxT("' where wbs_no = '") + str_wbs + wxT("';");
    if (wxGetApp().app_sql_update(str_sql))
        return i_times;
    return -1;
}

void instance_unit_info::Onbutton_cancel_restartClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    bool b_log_pass = false;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    v_wf_action * t_template = get_template_action(wf_str_configure);
    v_wf_action * t_new_template = get_template_action(wf_str_new_config);
    wf_operator * wf_configure=NULL;
    wf_operator_ex * wf_new_conf=NULL;

    wxString str_instance, s_lift_type,s_case;
    bool b_new_config=false;

    wxArrayString array_wbs, array_group, array_flag;

    wxLongLong mils_used, start_mils;
    if (wxMessageBox(_("是否确认取消重排产?"), _("确认"), wxYES_NO) != wxYES)
        return;
    for (int i = 0; i < i_count; i++)
    {
        str_instance = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        s_lift_type = gd_unit_info->GetCellValue(array_sel_line.Item(i),2).Trim();
        if (prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6)) != 3)
        {
            wxLogMessage(str_instance + _("非重排产项目，无法取消重排产！"));
            continue;
        }
        start_mils = wxGetLocalTimeMillis();
        int i_times = update_restart_status(str_instance, false);

        int i_ways;

        if(!wxGetApp().check_new_config(array_group, array_flag, i_ways, s_lift_type, s_case))
            b_new_config=false;
        else
        {
            if(!s_case.IsEmpty())
            {
              if(!wxGetApp().check_is_highspeed(str_instance))
                   b_new_config=false;
              else
                  b_new_config=true;
            }else
                b_new_config=true;
        }

        if(!b_new_config)//新的配置工作流，由非标负责
        {
            update_basic_finish_status(str_instance, true);
            wf_configure = new wf_operator(str_instance, wf_str_configure, t_template);

            wf_configure->cancel_restart(i_times);
            wf_configure->update_cancel_instance();
            delete wf_configure;
            wf_configure = NULL;
        }else
        {
            for(int k=0; k<i_ways; k++)
            {

                wf_new_conf = new wf_operator_ex(str_instance, wf_str_new_config, t_new_template, array_flag.Item(k));
                wf_new_conf->cancel_restart(i_times);
                wf_new_conf->update_cancel_instance();
                if (wf_new_conf)
                    delete wf_new_conf;

            }
        }

        mils_used = wxGetLocalTimeMillis() - start_mils;
        wxLogMessage(str_instance + _("取消重排产成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));
    }
    if (t_template)
        delete [] t_template;
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem21Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    wxArrayString array_sel_ins;
    wxString str_wbs, str;
    wxPostgreSQLresult * _res;
    for (int i = 0; i < i_count; i++)
    {
        str_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        wxString str_sql = wxT("select index_id from l_nonstd_app_item where link_list like '%") + str_wbs + wxT("%';");
        _res = wxGetApp().app_sql_select(str_sql);
        if (_res->Status() != PGRES_TUPLES_OK)
        {
            _res->Clear();
            continue;
        }
        Compress_array(_res, array_sel_ins);
        _res->Clear();
    }
    array_sel_line.Clear();
    ins_nonstd_proc_log ipl_dlg;
    ipl_dlg.Refresh_list_view(array_sel_ins, wf_str_nonstd);
    ipl_dlg.ShowModal();
}

void instance_unit_info::OnMenuItem22Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    wxArrayString array_sel_ins;
    wxString str_wbs, str;
    wxPostgreSQLresult * _res;
    for (int i = 0; i < i_count; i++)
    {
        str_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        wxString str_sql = wxT("select index_mat_id from v_nonstd_app_item_instance where link_list like '%") + str_wbs + wxT("%';");
        _res = wxGetApp().app_sql_select(str_sql);
        if (_res->Status() != PGRES_TUPLES_OK)
        {
            _res->Clear();
            continue;
        }
        Compress_array(_res, array_sel_ins);
        _res->Clear();
    }
    array_sel_line.Clear();
    ins_nonstd_proc_log ipl_dlg;
    ipl_dlg.Refresh_list_view(array_sel_ins, wf_str_materials);
    ipl_dlg.ShowModal();
}

void instance_unit_info::OnMenuItem23Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    wxArrayString array_sel_ins;
    wxString str_wbs, str;
    wxPostgreSQLresult * _res;
    for (int i = 0; i < i_count; i++)
    {
        str_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        wxString str_sql = wxT("select index_mat_id from v_nonstd_app_item_instance where link_list like '%") + str_wbs + wxT("%';");
        _res = wxGetApp().app_sql_select(str_sql);
        if (_res->Status() != PGRES_TUPLES_OK)
        {
            _res->Clear();
            continue;
        }
        Compress_array(_res, array_sel_ins);
        _res->Clear();
    }
    array_sel_line.Clear();
    ins_nonstd_proc_log ipl_dlg;
    ipl_dlg.Refresh_list_view(array_sel_ins, wf_str_design);
    ipl_dlg.ShowModal();
}

void instance_unit_info::Compress_array(wxPostgreSQLresult * res, wxArrayString & array_sel)
{
    int i_rows = res->GetRowsNumber();
    int i_count = array_sel.GetCount();
    res->MoveFirst();
    wxString str;
    for (int i = 0; i < i_rows; i++)
    {
        str = res->GetVal(0);
        for (int j = 0; j < i_count; j++)
        {
            if (array_sel.Item(j) != str)
            {
                if (j < i_count - 1)
                    continue;
                else if (j == i_count - 1)
                {
                    array_sel.Add(str);
                    i_count++;
                }
            }
            else
                break;
        }
        if (i_count == 0)
        {
            array_sel.Add(str);
            i_count++;
        }
        res->MoveNext();
    }
    res = 0;
}

void instance_unit_info::OnMenuItem24Selected(wxCommandEvent& event)
{
    wxArrayInt array_sel = gd_unit_info->GetSelectedRows();
    int i_sel = array_sel.GetCount();
    if (i_sel == 0)
    {
        return;
    }
    wxString str_clause;
    for (int i = 0; i < i_sel; i++)
    {
        if (i == i_sel - 1)
        {
            str_clause = str_clause + wxT(" link_list like'%") + gd_unit_info->GetCellValue(array_sel.Item(i), 1) + wxT("%' ");
        }
        else
        {
            str_clause = str_clause + wxT(" link_list like'%") + gd_unit_info->GetCellValue(array_sel.Item(i), 1) + wxT("%' or ");
        }
    }
    wxString str_sql;
    nstd_mat_task_list dlg;
    dlg.init_nstd_mat_instance_header();
    str_sql = wxT("SELECT index_mat_id, concat(contract_id,' ', project_name,'-',project_id) as project_name, mat_req_date, drawing_req_date, \
                          nonstd_catalog, nonstd_desc, nonstd_value, (select name from s_employee where employee_id = res_person) as res_person,\
                          instance_nstd_desc, (select name from s_employee where employee_id = res_engineer) as res_engineer, status, link_list from v_nonstd_app_item_instance where  ") + str_clause + wxT(" order by index_id ASC;");
    dlg.Set_Query(str_sql);
    dlg.refresh_list(0);
    dlg.ShowModal();
}

void instance_unit_info::OnButton_Cancel_projectClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    bool b_log_pass = false;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();

    v_wf_action * t_template = get_template_action(wf_str_configure);

    v_wf_action * t_new_template = get_template_action(wf_str_new_config);
    wf_operator * wf_configure;
    wf_operator_ex * wf_new_conf;

    wxString str_instance, s_lift_type,s_case;
    bool b_new_config=false;

    wxArrayString array_wbs, array_group, array_flag;
    wxLongLong mils_used, start_mils;
    if (wxMessageBox(_("是否确认取消排产?"), _("确认"), wxYES_NO) != wxYES)
        return;
    for (int i = 0; i < i_count; i++)
    {
        str_instance = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        s_lift_type = gd_unit_info->GetCellValue(array_sel_line.Item(i),2).Trim();
        if (prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6)) != 1)
        {
            wxLogMessage(str_instance + _("非活动项目，无法取消排产！"));
            continue;
        }
        start_mils = wxGetLocalTimeMillis();
        int i_times = update_cancel_status(str_instance);

        int i_ways;

        if(!wxGetApp().check_new_config(array_group, array_flag, i_ways, s_lift_type, s_case))
            b_new_config=false;
        else
        {
            if(!s_case.IsEmpty())
            {
              if(!wxGetApp().check_is_highspeed(str_instance))
                   b_new_config=false;
              else
                  b_new_config=true;
            }else
                b_new_config=true;
        }

        if(!b_new_config)//新的配置工作流，由非标负责
        {
            wf_configure = new wf_operator(str_instance, wf_str_configure, t_template);

            wf_configure->cancel_task(i_times);

            wf_configure->update_cancel_instance();

            if(wf_configure)
               delete wf_configure;
            wf_configure = NULL;
        }else
        {
            for(int k=0; k<i_ways; k++)
            {
                wf_new_conf = new wf_operator_ex(str_instance, wf_str_new_config, t_new_template, array_flag.Item(k));
                wf_new_conf->cancel_restart(i_times);
                wf_new_conf->update_cancel_instance();
                if (wf_new_conf)
                    delete wf_new_conf;
                wf_new_conf = NULL;

            }
        }

        mils_used = wxGetLocalTimeMillis() - start_mils;
        wxLogMessage(str_instance + _("取消排产成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));
    }

    if (t_template)
        delete [] t_template;

    if( t_new_template)
        delete [] t_new_template;
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnButton_Restore_projectClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    bool b_log_pass = false;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    v_wf_action * t_template = get_template_action(wf_str_configure);
    v_wf_action * t_new_template = get_template_action(wf_str_new_config);
    wf_operator * wf_configure;
    wf_operator_ex * wf_new_conf;
    wxString str_instance, s_lift_type, s_case;
    bool b_new_config;

    wxArrayString array_wbs, array_group, array_flag;
    wxLongLong mils_used, start_mils;
    if (wxMessageBox(_("是否确认恢复排产?"), _("确认"), wxYES_NO) != wxYES)
        return;
    for (int i = 0; i < i_count; i++)
    {
        str_instance = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        s_lift_type = gd_unit_info->GetCellValue(array_sel_line.Item(i),2).Trim();
        if (prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6)) != -1)
        {
            wxLogMessage(str_instance + _("此项目非取消状态，无法恢复！"));
            continue;
        }
        start_mils = wxGetLocalTimeMillis();

        int i_ways;

        if(!wxGetApp().check_new_config(array_group, array_flag, i_ways, s_lift_type, s_case))
            b_new_config=false;
        else
        {
            if(!s_case.IsEmpty())
            {
              if(!wxGetApp().check_is_highspeed(str_instance))
                   b_new_config=false;
              else
                  b_new_config=true;
            }else
                b_new_config=true;
        }

        if(!b_new_config)//新的配置工作流，由非标负责
        {
            wf_configure = new wf_operator(str_instance, wf_str_configure, t_template);
            wf_configure->restore_task();
            wf_configure->update_instance(1);
            delete wf_configure;
            wf_configure = NULL;
        }else
        {
            for(int k=0; k<i_ways; k++)
            {
                wf_new_conf = new wf_operator_ex(str_instance, wf_str_new_config, t_new_template, array_flag.Item(k));
                wf_new_conf->restore_task();
                wf_new_conf->update_instance(1);
                if (wf_new_conf)
                    delete wf_new_conf;
                wf_new_conf = NULL;

            }
        }
        mils_used = wxGetLocalTimeMillis() - start_mils;
        wxLogMessage(str_instance + _("恢复排产成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));
    }

    if (t_template)
        delete [] t_template;
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnButton_DEL_projectClick(wxCommandEvent& event)
{
   wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    bool b_log_pass = false;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    v_wf_action * t_template = get_template_action(wxT("WF0002"));
    wf_operator * wf_configure;
    wxString str_instance;
    wxLongLong mils_used, start_mils;
    if (wxMessageBox(_("项目删除后将无法恢复，是否确认永久删除?"), _("确认"), wxYES_NO) != wxYES)
        return;

    for (int i = 0; i < i_count; i++)
    {
        str_instance = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        int i_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6));
        if (i_status >=5)
        {
            wxLogMessage(str_instance + _("配置完成的项目，无法删除！"));
            continue;
        }
        start_mils = wxGetLocalTimeMillis();
        wf_configure = new wf_operator(str_instance, wf_str_configure, t_template);
        wf_configure->cancel_task();

        wf_configure->update_instance(-2,0);
        delete wf_configure;
        wf_configure = NULL;
        mils_used = wxGetLocalTimeMillis() - start_mils;
        wxLogMessage(str_instance + _("项目删除成功!  耗时:") + NumToStr(mils_used) + _("毫秒"));
    }

    if (t_template)
        delete [] t_template;
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem25Selected(wxCommandEvent& event)
{
    Set_Where_clause(wxT(" WHERE status='-1' "));
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnMenuItem_ReviewSelected(wxCommandEvent& event)
{

    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    wxArrayString array_sel_wbs;
    wxString str_temp;
    for (int i = 0; i < i_count; i++)
    {
        str_temp = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1).Upper().Trim();
        array_sel_wbs.Add(str_temp);
    }
    ins_proc_log ipl_dlg;
    ipl_dlg.init_review_list_header();
    ipl_dlg.Refresh_review_list(array_sel_wbs);
    ipl_dlg.ShowModal();
    //  event.Skip();
}


bool instance_unit_info::update_nstd_level(wxString s_wbs, int old_status, int new_status)
{
    wxString str_sql = wxT("select count(*) as count from s_unit_nstd_level where wbs_no = '")+s_wbs+wxT("';");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return false;
    }

    int i_count = _res->GetInt(wxT("count"));


    _res->Clear();

    if(i_count == 0)
    {
        str_sql = wxT("INSERT INTO s_unit_nstd_level(wbs_no, nonstd_level_pre, is_sap_update, modify_date, modify_emp_id, create_date, create_emp_id) VALUES (\
                      '")+s_wbs+wxT("', '")+NumToStr(old_status)+wxT("',false,'")+DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("','")+
                      DateToAnsiStr(wxDateTime::Now())+wxT("','")+gr_para.login_user+wxT("');");

    }else
    {
        str_sql = wxT("UPDATE s_unit_nstd_level SET nonstd_level_pre='")+NumToStr(old_status)+wxT("', is_sap_update=false, modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                  wxT("',modify_emp_id='")+gr_para.login_user+wxT("' where wbs_no = '")+s_wbs+wxT("';");
    }

    if(!wxGetApp().app_sql_update(str_sql))
        return false;

    str_sql = wxT("UPDATE s_unit_info SET nonstd_level='")+NumToStr(new_status)+wxT("', modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                  wxT("',modify_emp_id='")+gr_para.login_user+wxT("' where wbs_no = '")+s_wbs+wxT("';");

    if(wxGetApp().app_sql_update(str_sql))
    {
        wxGetApp().change_log(wxT("s_unit_info"),s_wbs,wxT("nonstd_level"),NumToStr(old_status),NumToStr(new_status));
        return true;
    }

    return false;

}

void instance_unit_info::OnButton_NSTD_SAP_UPDATEClick(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }
    int i_count = array_sel_line.GetCount();
    wxString str_temp;
    for (int i = 0; i < i_count; i++)
    {
        str_temp = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
        refresh_nstd_level(str_temp);
    }

    wxString str_sql = wxT("select * from s_unit_nstd_level where is_sap_update = false;");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    i_count = _res->GetRowsNumber();

    if(i_count ==0)
        return;


    str_sql.Clear();
    for(int i=0;i<i_count;i++)
    {
        wxString str = _res->GetVal(wxT("wbs_no"));

        if(i==0)
        {
            if(i_count == 1)
               str_sql = wxT(" wbs_no = '")+str+wxT("' ");
            else
               str_sql = wxT(" (wbs_no = '")+str+wxT("' ");
        }else
        {
            if(i== i_count-1)
               str_sql = str_sql + wxT(" or wbs_no = '")+str+wxT("') ");
            else
                str_sql = str_sql + wxT(" or wbs_no = '")+str+wxT("' ");
        }
        _res->MoveNext();
    }
    _res->Clear();

    str_sql = wxT(" where ")+str_sql+wxT(" and status !='-1'  ");

    Set_Where_clause(str_sql);

    b_refresh = true;
    refresh_list();
    b_refresh = false;

}

void instance_unit_info::OnMenuItem26Selected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString str_sql = wxT("select * from s_unit_nstd_level where is_sap_update = false;");
    wxPostgreSQLresult * _res = wxGetApp().app_sql_select(str_sql);

    if(_res->Status()!= PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }

    int i_count = _res->GetRowsNumber();

    if(i_count ==0)
    {
        b_refresh = true;
        refresh_list();
        b_refresh = false;
        _res->Clear();
        return;
    }


    str_sql.Clear();
    for(int i=0;i<i_count;i++)
    {
        wxString str = _res->GetVal(wxT("wbs_no"));

        if(i==0)
        {
            if(i_count == 1)
               str_sql = wxT(" wbs_no = '")+str+wxT("' ");
            else
               str_sql = wxT(" (wbs_no = '")+str+wxT("' ");
        }else
        {
            if(i== i_count-1)
               str_sql = str_sql + wxT(" or wbs_no = '")+str+wxT("') ");
            else
                str_sql = str_sql + wxT(" or wbs_no = '")+str+wxT("' ");
        }
        _res->MoveNext();
    }
    _res->Clear();

    str_sql = wxT(" where ")+str_sql+wxT(" and status !='-1'  ");

    Set_Where_clause(str_sql);

    b_refresh = true;
    refresh_list();
    b_refresh = false;

}

bool instance_unit_info::refresh_nstd_level(wxString s_wbs, bool b_sap_update)
{
    wxString str_sql = wxT("UPDATE s_unit_nstd_level SET is_sap_update=")+BoolToStr(b_sap_update)+wxT(", modify_date='")+DateToAnsiStr(wxDateTime::Now())+
                  wxT("',modify_emp_id='")+gr_para.login_user+wxT("' where wbs_no = '")+s_wbs+wxT("';");

    if(wxGetApp().app_sql_update(str_sql))
    {
        wxGetApp().change_log(wxT("s_unit_nstd_level"),s_wbs,wxT("is_sap_update"),BoolToStr(!b_sap_update),BoolToStr(b_sap_update));
        return true;
    }

    return false;
}

void instance_unit_info::Onbutton_sap_by_wbsClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    search_case tdlg;
    tdlg.set_wbs_check(true);
    wxArrayString array_wbs;

    if(tdlg.ShowModal()==wxID_OK)
    {
        array_wbs = tdlg.GetValue();

    }else
       return;

    if(array_wbs.IsEmpty())
        return;
/*
    int i_connect_times = 0;
    while(!sap_rfc_conn->rfc_check_connect())
    {

        if(i_connect_times <3)
        {
            sap_rfc_conn->rfc_connect();
            i_connect_times++;
        }
        else
        {
            wxLogMessage(_("已经尝试")+NumToStr(i_connect_times+1)+_("次连接SAP,均无法登陆,线程未启动!"));
            return;
        }
    }*/

    MyThread* prj_thread = new MyThread((wfFrame*)GetParent(),array_wbs, 0);

    if ( prj_thread->Create() != wxTHREAD_NO_ERROR )
    {
        wxLogError(wxT("无法创建从SAP读取项目信息线程"));
        return;
    }

    wxCriticalSectionLocker enter(wxGetApp().AppCritSection);
    wxGetApp().AppThreads.Add(prj_thread);


    if ( prj_thread->Run() != wxTHREAD_NO_ERROR )
    {
         wxLogMessage(_("从SAP读取项目信息线程启动失败!"));
         return;
    }
    wxString s_id = wxString::Format("0x%lx",prj_thread->GetId());
    wxLogMessage(_("从SAP读取项目信息线程已经启动,请耐心等待,线程ID:")+s_id);
}

void instance_unit_info::Onbutton_sap_by_internalClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayString array_date;

    wxString str;

    datepickerdlg dlg;

    if(dlg.ShowModal()==wxID_CANCEL)
    {
        return;
    }

    bool b_from = dlg.b_from;
    bool b_to = dlg.b_to;


    if(b_from&&b_to)
    {
        str = DateToStrFormat(dlg.dt_from);
        str.Replace(wxT("-"),wxT(""));
        array_date.Add(str);

        str = DateToStrFormat(dlg.dt_to);
        str.Replace(wxT("-"),wxT(""));
        array_date.Add(str);

    }

    if(b_to && !b_from)
    {
        str = DateToStrFormat(wxDateTime::Today());
        str.Replace(wxT("-"),wxT(""));
        array_date.Add(str);
        str = DateToStrFormat(dlg.dt_to);
        str.Replace(wxT("-"),wxT(""));
        array_date.Add(str);
    }

    if(!b_to &&b_from)
    {
        str = DateToStrFormat(dlg.dt_from);
        str.Replace(wxT("-"),wxT(""));
        array_date.Add(str);

        str = DateToStrFormat(wxDateTime::Today());
        str.Replace(wxT("-"),wxT(""));
        array_date.Add(str);
    }


    if(!b_to &&!b_from)
    {
        str = DateToStrFormat(wxDateTime::Today());
        str.Replace(wxT("-"),wxT(""));
        array_date.Add(str);
        array_date.Add(str);
    }



    MyThread* prj_thread = new MyThread((wfFrame*)GetParent(),array_date, 2);

    if ( prj_thread->Create() != wxTHREAD_NO_ERROR )
    {
        wxLogError(wxT("无法创建从SAP读取项目信息线程"));
        return;
    }

    wxCriticalSectionLocker enter(wxGetApp().AppCritSection);
    wxGetApp().AppThreads.Add(prj_thread);


    if ( prj_thread->Run() != wxTHREAD_NO_ERROR )
    {
         wxLogMessage(_("从SAP读取项目信息线程启动失败!"));
         return;
    }

    wxString s_id = wxString::Format("0x%lx",prj_thread->GetId());
    wxLogMessage(_("从SAP读取项目信息线程已经启动,请耐心等待,线程ID:")+s_id);
}

void instance_unit_info::OnMenuItem_WeightSelected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();


    wxArrayString array_sel_wbs;
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    int i_count = array_sel_line.GetCount();
    wxString s_wbs;

    for(int i=0;i<i_count;i++)
    {
        s_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i),1);

        array_sel_wbs.Add(s_wbs);

    }

        unit_info_attach_dlg dlg;
        dlg.Set_Editable(false);
        dlg.refresh_control();
        dlg.array_wbs = array_sel_wbs;

        dlg.refresh_list();

        dlg.ShowModal();
}

void instance_unit_info::OnMenuItem_Basic_InfoSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString s_clause=wxT(" where is_basic_full_finish=false and status>=5 and status <8 ");
    Set_Where_clause(s_clause);
    b_refresh = true;
    refresh_list(true);
    b_refresh = false;

}

void instance_unit_info::OnButton_Cal_Basic_InfoClick(wxCommandEvent& event)
{

    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    if (wxMessageBox(_("是否确认同步计算所选项目基本信息?"), _("确认"), wxYES_NO) != wxYES)
        return;

    int i_count = array_sel_line.GetCount();

    wxArrayString array_wbs;
    wxString str_wbs;

    int i_status;

    for(int i=0;i<i_count;i++)
    {
        str_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1).Trim();

        i_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6));

        if(i_status <5)
        {
            wxLogMessage(str_wbs+_("配置流程尚未结束，信息无法同步!"));
            continue;
        }

        if(i_status>=8)
        {
            wxLogMessage(str_wbs+_("项目已经发运， 信息无需同步!"));
            continue;
        }

        array_wbs.Add(str_wbs);
    }

    if(array_wbs.IsEmpty())
        return;


    MyThread* prj_thread = new MyThread((wfFrame*)GetParent(),array_wbs, 1);

    if ( prj_thread->Create() != wxTHREAD_NO_ERROR )
    {
        wxLogError(wxT("无法创建从SAP同步项目信息线程"));
        return;
    }

    wxCriticalSectionLocker enter(wxGetApp().AppCritSection);
    wxGetApp().AppThreads.Add(prj_thread);


    if ( prj_thread->Run() != wxTHREAD_NO_ERROR )
    {
         wxLogMessage(_("从SAP同步项目信息线程启动失败!"));
         return;
    }

    wxString s_id = wxString::Format("0x%lx",prj_thread->GetId());
    wxLogMessage(_("从SAP同步项目基本信息线程已经启动,请耐心等待,线程ID:")+s_id);
}

void instance_unit_info::Onmi_contractSelected(wxCommandEvent& event)
{
        if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    search_case tdlg;
    wxString s_sql;
    wxArrayString array_contract_id;
    if (tdlg.ShowModal() == wxID_OK)
    {
        array_contract_id = tdlg.GetValue();
    }
    else return;
    int i_count  = array_contract_id.GetCount();
    for (int i = 0; i < i_count; i++)
    {
        if (i == 0)
            s_sql = wxT(" WHERE  (contract_id LIKE '%") + array_contract_id.Item(i) + wxT("%' ");
        else
            s_sql = s_sql + wxT(" OR contract_id LIKE '%") + array_contract_id.Item(i) + wxT("%' ");
    }
    s_sql  = s_sql + wxT(") and status >=0 ");
    Set_Where_clause(s_sql);
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::Onmi_unit_in_contractSelected(wxCommandEvent& event)
{
}

void instance_unit_info::Onmi_generate_contractSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }



    wxString s_project_id, s_contract_id, s_project_name;
    wxArrayString array_project_id, array_contract_id;

    long item = -1;
    bool b_valid = true;
    for(;;)
    {
         item = lc_project->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

         if(item==-1)
            break;

        if(b_valid)
        {
            if(wxMessageBox(_("确认为选中的项目生成合同文档"), _("确认"), wxYES_NO)==wxNO)
                return;
        }

        s_project_id = lc_project->GetItemText(item, 0).Trim();
        s_contract_id = lc_project->GetItemText(item, 1).Trim();

        s_project_name = lc_project->GetItemText(item, 2);

        b_valid = false;



        if(s_contract_id.IsEmpty())
        {
            wxTextEntryDialog tdlg(this, s_project_name+_(":对应合同号"), s_project_id,wxEmptyString, wxOK|wxCANCEL);
            tdlg.SetTextValidator(wxFILTER_DIGITS );

            if(tdlg.ShowModal() == wxID_OK)
            {
                s_contract_id = tdlg.GetValue();
                lc_project->SetItem(item, 1, s_contract_id);
                wxGetApp().add_contract_id(s_project_id, s_contract_id);
            }else
               continue;
        }

        array_project_id.Add(s_project_id);

        array_contract_id.Add(s_contract_id);
    }

    contract_label_print dlg(0);

    dlg.generate_doc(array_project_id, array_contract_id);

    dlg.ShowModal();

}

void instance_unit_info::Onmi_search_contractSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    contract_label_print dlg(0);

    dlg.ShowModal();
}

void instance_unit_info::Onmi_add_contract_idSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString s_contract_id,s_project_id,s_project_name;

    long item = -1;
    for(;;)
    {
         item = lc_project->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

         if(item==-1)
            break;

        s_project_id = lc_project->GetItemText(item, 0).Trim();
        s_contract_id = lc_project->GetItemText(item, 1).Trim();

        s_project_name = lc_project->GetItemText(item, 2);

       // if(s_contract_id.IsEmpty())
      //  {
            wxTextEntryDialog tdlg(this, s_project_name+_(":对应合同号"), s_project_id,wxEmptyString, wxOK|wxCANCEL);
            tdlg.SetTextValidator(wxFILTER_DIGITS );

            if(tdlg.ShowModal() == wxID_OK)
            {
                s_contract_id = tdlg.GetValue();
                lc_project->SetItem(item, 1, s_contract_id);
                wxGetApp().add_contract_id(s_project_id, s_contract_id);

                wxLogMessage(s_project_id+wxT(":")+s_project_name+_("补全合同号:")+s_contract_id+_("成功!"));
            }else
               continue;
    //    }
    }
}


void instance_unit_info::Onmi_hexSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    if (wxMessageBox(_("是否确认从SAP获取随行电缆|曳引钢丝绳|补偿链单重HEX值?"), _("确认"), wxYES_NO) != wxYES)
        return;

    int i_count = array_sel_line.GetCount();

    wxArrayString array_wbs;
    wxString str_wbs;

    int i_status;

    for(int i=0;i<i_count;i++)
    {
        str_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1).Trim();

        i_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i), 6));

        if(i_status <5)
        {
            wxLogMessage(str_wbs+_("配置流程尚未结束，信息无法获取!"));
            continue;
        }

        array_wbs.Add(str_wbs);
    }

    if(array_wbs.IsEmpty())
        return;


    MyThread* prj_thread = new MyThread((wfFrame*)GetParent(),array_wbs, 3);

    if ( prj_thread->Create() != wxTHREAD_NO_ERROR )
    {
        wxLogError(wxT("无法创建从SAP获取HEX值线程"));
        return;
    }

    wxCriticalSectionLocker enter(wxGetApp().AppCritSection);
    wxGetApp().AppThreads.Add(prj_thread);


    if ( prj_thread->Run() != wxTHREAD_NO_ERROR )
    {
         wxLogMessage(_("从SAP获取HEX值线程失败!"));
         return;
    }

    wxString s_id = wxString::Format("0x%lx",prj_thread->GetId());
    wxLogMessage(_("从SAP获取HEX值线程已经启动,请耐心等待,线程ID:")+s_id);
}

void instance_unit_info::Onmi_delivery_dateSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

       datepickerdlg dlg;

    if(dlg.ShowModal()==wxID_CANCEL)
    {
        return;
    }

    bool b_from = dlg.b_from;
    bool b_to = dlg.b_to;

    wxString str_from,str_to, s_sql;


    if(b_from&&b_to)
    {
        str_from = DateToStrFormat(dlg.dt_from);

        str_to = DateToStrFormat(dlg.dt_to);

        s_sql = s_sql + wxT(" where req_delivery_date>='")+str_from+wxT(" 00:00:00' and req_delivery_date<='")+str_to+wxT(" 23:59:59' and status>=0 ");
    }

    if(b_to && !b_from)
    {
        str_to = DateToStrFormat(dlg.dt_to);
        s_sql = s_sql + wxT(" where req_delivery_date<='")+str_to+wxT(" 23:59:59' and status>=0 ");

    }

    if(!b_to &&b_from)
    {
        str_from = DateToStrFormat(dlg.dt_from);
        s_sql = s_sql + wxT(" where req_delivery_date>='")+str_from+wxT(" 00:00:00' and status>=0 ");
    }


    if(!b_to &&!b_from)
    {
        str_from = str_to = DateToStrFormat(wxDateTime::Today());
        s_sql = s_sql + wxT(" where req_delivery_date>='")+str_from+wxT(" 00:00:00' and req_delivery_date<='")+str_to+wxT(" 23:59:59' and status>=0 ");

    }


    Set_Where_clause(s_sql);
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::Onmi_Excel_exportSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

     int i_count =gd_unit_info->GetNumberRows();

    if(i_count==0)
    {
        wxLogMessage(_("表格内无任何内容，无法输出!"));
        return;
    }

    wxFileDialog     saveFileDialog(this, _("Save xls file"), "", "",
                                       "xls files (*.xls)|*.xls", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    wxString str_file = saveFileDialog.GetPath();

    save_file(str_file);

}

void instance_unit_info::save_file(wxString s_file)
{
    int i_count = gd_unit_info->GetNumberRows();
    int i_col = gd_unit_info->GetNumberCols();

    int i_width=0;


    wxString str;
    workbook wb1;
    worksheet* ws = wb1.sheet("Sheet1");
    int i,j;

    wxArrayInt array_col;

    int i_show_col=0;

    for(i=0;i<i_col;i++)
    {
        i_width = gd_unit_info->GetColSize(i);
        if(i_width>0)
        {
            array_col.Add(i);
            str = gd_unit_info->GetColLabelValue(i);
            ws->label(0,i_show_col,str.ToStdWstring());
            i_show_col++;
        }

    }

    for(i=0;i<i_count;i++)
    {
        for(j=0;j<i_show_col;j++)
        {
            str = gd_unit_info->GetCellValue(i,array_col.Item(j));

            ws->label(i+1,j,str.ToStdWstring());
        }
    }

    std::string filename = s_file.ToStdString();
    int error_msg = wb1.Dump(filename);

    if(error_msg == NO_ERRORS)
    {
           wxMessageBox(_("导出完成!"),_("提示"));
    }
}

void instance_unit_info::OnButton_syc_to_dinClick(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    if (wxMessageBox(_("是否确认向DIN系统传递项目信息?"), _("确认"), wxYES_NO) != wxYES)
        return;

    int i_count = array_sel_line.GetCount();

    wxArrayString array_wbs;
    wxString str_wbs;

    int i_status,i,j;

    for(i=0;i<i_count;i++)
    {
        str_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1).Trim();

        array_wbs.Add(str_wbs);
    }

    if(array_wbs.IsEmpty())
    {
        wxLogMessage(_("未选中任何项目。"));
        return;
    }


    wxArrayToDin a_din;
    s_json_data_to_din st_json;

    wxString s_sql = wxT(" select * from v_unit_info_attach2 where ( ");

    for(j=0;j<i_count;j++)
    {
         s_sql=s_sql+wxT(" wbs_no='")+array_wbs.Item(j)+wxT("' ");

         if(j!=i_count-1)
             s_sql=s_sql +wxT(" or ");
    }

    s_sql = s_sql+wxT(" ) and is_basic_full_finish=true  order by wbs_no asc;");
    wxPostgreSQLresult* _res = wxGetApp().app_sql_select(s_sql);
    if (_res->Status() != PGRES_TUPLES_OK)
    {
        _res->Clear();
        return;
    }
 //   wxLogMessage(s_sql);

    int i_row=_res->GetRowsNumber();
    if(i_row==0)
    {
        wxLogMessage("所选项目基本数据未准备完成，无法传输!");
        return;
    }


    wxLogMessage(_("正在读取选中项目的基本信息..."));
    for(i=0;i<i_row;i++)
    {
        st_json.s_wbs_no = _res->GetVal(wxT("wbs_no"));

        st_json.s_project_name = _res->GetVal(wxT("project_name"));
        st_json.s_lift_no = _res->GetVal(wxT("lift_no"));
        st_json.i_car_weight = _res->GetInt(wxT("car_weight"));
        st_json.i_cwt_frame_weight=_res->GetInt(wxT("cwt_frame_weight"));
        st_json.i_reservedocoration_weight = _res->GetInt(wxT("reserve_decoration_weight"));
        st_json.d_balance_rate = _res->GetDouble(wxT("balance_rate"));
        st_json.i_conf_balance_block_qty = _res->GetInt(wxT("conf_balance_block_qty"));
        st_json.i_cwt_blockqty_before_dc = _res->GetInt(wxT("cwt_block_qty_before_dc"));
        st_json.i_cwt_blockqty_after_dc = _res->GetInt(wxT("cwt_block_qty_after_dc"));
        st_json.i_cwt_blockqty_mat1 = _res->GetInt(wxT("cwt_block_qty_mat1"));
        st_json.i_cwt_blockqty_mat2 = _res->GetInt(wxT("cwt_block_qty_mat2"));
        st_json.i_cwt_blockqty = _res->GetInt(wxT("conf_balance_block0_qty"));
        st_json.b_has_governor = _res->GetBool(wxT("has_governor"));
        st_json.b_has_spring = _res->GetBool(wxT("has_spring"));
        st_json.is_success = false;
        a_din.Add(st_json);
        _res->MoveNext();
    }

    curl_thread*  thread_curl = new curl_thread((wfFrame*)GetParent(),a_din);

    if ( thread_curl->Create() != wxTHREAD_NO_ERROR )
    {
        wxLogError(wxT("无法创建向DIN系统写入项目信息线程"));
        return;
    }

    wxCriticalSectionLocker enter(wxGetApp().AppCritSection);
    wxGetApp().AppThreads.Add(thread_curl);


    if ( thread_curl->Run() != wxTHREAD_NO_ERROR )
    {
         wxLogMessage(_("创建向DIN系统写入项目信息线程失败!"));
         return;
    }

    wxString s_id = wxString::Format("0x%lx",thread_curl->GetId());
    wxLogMessage(_("向DIN系统写入项目信息线程已经启动,请耐心等待,线程ID:")+s_id);
}

void instance_unit_info::Onmi_syc_dinSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxString s_clause=wxT(" where is_basic_full_finish=true and is_sync_din_latest=false and status>=5 and status <8 ");
    Set_Where_clause(s_clause);
    b_refresh = true;
    refresh_list(true);
    b_refresh = false;

}

void instance_unit_info::draw_label(wxDC &dc, int _page)
{

    wxString  s_wbs=print_array.Item(_page-1).Upper();
    dc.StartPage();

    dc.SetFont(wxFont(20, wxSWISS, wxNORMAL, wxBOLD, false,wxT("TkTypeRegular")));

    dc.DrawText(s_wbs.Left(10),mmtoppix*10,mmtoppiy*8);
    dc.DrawText(s_wbs.Right(3),mmtoppix*25, mmtoppiy*16);

    dc.EndPage();

}

void instance_unit_info::Onmi_print_labelSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    int i_count;

    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (array_sel_line.IsEmpty())
    {
     //   wxLogMessage(_("尚未选择项目，无法后续操作!"));

        search_case tdlg;
        if (tdlg.ShowModal() == wxID_OK)
        {
            print_array.Clear();
            print_array = tdlg.GetValue();
        }
        else return;

        i_count = print_array.GetCount();

        int j=0;

        while(j<i_count)
        {
            if(print_array.Item(j).Trim().Length()!=14)
            {
                print_array.RemoveAt(j);
                i_count--;
                continue;

            }

            if(print_array.Item(j).Mid(10,1)!=wxT("."))
            {

                 print_array.RemoveAt(j);
                 i_count--;
                 continue;
            }
            j++;

        }

    }else
    {

        i_count = array_sel_line.GetCount();

        print_array.Clear();
        wxString str_wbs;

        int i_status,i;

        for(i=0; i<i_count; i++)
        {
            str_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1).Trim();
            i_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i),6));

            if(i_status<5)
                continue;

            print_array.Add(str_wbs);
        }

        if(print_array.IsEmpty())
        {
            wxLogMessage(_("所选项目均未完成配置，无法打印标签!"));
            return;
        }
    }


    int pages =print_array.GetCount();

    if(pages==0)
    {
        wxLogMessage(_("没有满足要求的WBS NO可以打印!"));
        return;
    }
   //wxMessageBox(_("test"),_("test"));

   wxPrintDialogData printDialogData(* g_printData);

    wxPrintPreview *preview = new wxPrintPreview(new LabelPrintout(_("打印预览"),this,pages ),new LabelPrintout(_("打印预览"),this, pages), &printDialogData);
    if (!preview->Ok())
    {
        delete preview;

        wxMessageBox(_T("There was a problem previewing.\nPerhaps your current printer is not set correctly?"), _T("Previewing"), wxOK);
        return;
    }

    wxPreviewFrame *frame = new wxPreviewFrame(preview, this, _T("标签打印预览"), wxPoint(100, 100), wxSize(600, 650));
    frame->Centre(wxBOTH);
    frame->Initialize();
    frame->Show();
}


LabelPrintout::LabelPrintout(const wxString& name, instance_unit_info *_panel, int pages)
{
    m_Name = name;
    m_panel=_panel;
    m_NumPages = pages;
}

LabelPrintout::~LabelPrintout()
{
    m_panel=NULL;
}

bool LabelPrintout::OnPrintPage(int page)
{
    wxDC *dc = GetDC();
    if (dc)
    {
        if(page<=m_NumPages)
        {
            drawpage(*dc, page);
       //     MapScreenSizeToPage();

        }

        return true;
    }
    else
        return false;
}

bool LabelPrintout::HasPage(int page)
{
    return (page>0 && page<=m_NumPages);
}

bool LabelPrintout::OnBeginDocument(int startPage, int endPage)
{
    if (!wxPrintout::OnBeginDocument(startPage, endPage))
        return false;

    return true;
}

void LabelPrintout::GetPageInfo(int *minPage, int *maxPage, int *selPageFrom, int *selPageTo)
{
    *minPage = 1;
    *maxPage = m_NumPages;
    *selPageFrom = 1;
    *selPageTo = m_NumPages;
}

void LabelPrintout::drawpage(wxDC&dc, int page)
{
   // wxCoord maxX;
    //wxCoord maxY;

   // GetPageSizeMM(&maxX, &maxY);
    wxCoord maxX = 60*mmtoppix;
    wxCoord maxY = 30*mmtoppiy;

 //   wxSize page_size = g_pageSetupData->GetPaperSize();
  //  wxLogMessage(NumToStr(page_size.GetWidth())+wxT("*")+NumToStr(page_size.GetHeight()));

  //  dc.SetUserScale(x_scale, y_scale);

    FitThisSizeToPageMargins(wxSize(maxX, maxY), *g_pageSetupData);
    wxRect fitRect = GetLogicalPageMarginsRect(*g_pageSetupData);
 //   FitThisSizeToPage(wxSize(maxX, maxY));
  //  wxRect fitRect = GetLogicalPageRect();

    wxCoord xoff = (fitRect.width - maxX) / 2;
    wxCoord yoff = (fitRect.height - maxY) / 2;
    OffsetLogicalOrigin(xoff, yoff);

    m_panel->draw_label(dc, page);
}



void instance_unit_info::Onmi_contractbook_searchSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        if (b_refresh)
            wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }
    if (!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    long i_index=-1;
    i_index = lc_project->GetNextItem(i_index,  wxLIST_NEXT_ALL,  wxLIST_STATE_SELECTED);

    if(i_index==-1)
        return;
    wxString s_project = lc_project->GetItemText(i_index,0);

    contractbook_br_dlg dlg;
    dlg.set_mode(0);
    dlg.refresh_list(s_project, 0);
    dlg.ShowModal();

}

void instance_unit_info::Onmi_change_lenderSelected(wxCommandEvent& event)
{
   if (!gr_para.login_status)
    {
        if (b_refresh)
            wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }
    if (!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }

    contractbook_br_dlg dlg;
    dlg.set_mode(1);
    dlg.refresh_list(gr_para.login_user, 2);
    dlg.ShowModal();
}

void instance_unit_info::Onmi_contract_br_searchSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        if (b_refresh)
            wxLogMessage(_("尚未登陆,无法做任何操作!"));
        return;
    }
    if (!wxGetApp().conn->IsAlive())
    {
        wxLogMessage(_("系统连接已断开,请重新连接!"));
        wxGetApp().clear_login();
        return;
    }
    wxTextEntryDialog tdlg(this, _("请输入合同号或WBS NO"), _("项目合同借阅查询"),wxT(""), wxTextEntryDialogStyle, wxDefaultPosition);
    tdlg.SetTextValidator(wxFILTER_EMPTY);

    if (tdlg.ShowModal() == wxID_CANCEL)
        return;

    wxString s_case = tdlg.GetValue();

    contractbook_br_dlg dlg;
    dlg.set_mode(0);
    dlg.refresh_list(s_case, 1);
    dlg.ShowModal();
}

void instance_unit_info::Onmi_proj_nameSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    wxString s_sql;


    wxTextEntryDialog tdlg(this, _("请输入项目名称(支持模糊查询)"), _("按项目名称查询"), wxT(""), wxTextEntryDialogStyle, wxDefaultPosition);
    tdlg.SetTextValidator(wxFILTER_EMPTY);
    if (tdlg.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    wxString s_case = tdlg.GetValue();

//   event.Skip();
    s_sql = wxT(" WHERE  project_name ILIKE '%") + s_case + wxT("%' and status >=0 ");

    Set_Where_clause(s_sql);
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::Onmi_special_infoSelected(wxCommandEvent& event)
{
    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();

    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxString s_info=wxEmptyString;

    bool b_msg=false;

    for (int i=0;i<i_count;i++)
    {
        if(i>0&&s_info != gd_unit_info->GetCellValue(array_sel_line.Item(i), 13))
        {
            b_msg=true;
            break;
        }

        if(i==0)
            s_info = gd_unit_info->GetCellValue(array_sel_line.Item(i), 13);
    }


    if(b_msg&& wxMessageBox(_T("所选项目特殊标识不一致,是否强制修改为其他的内容?"),"特殊标识修改",wxOK|wxCANCEL)==wxCANCEL)
    {
         return;
    }

    wxTextEntryDialog tdlg(this, _("配置提示输入"), _("备注"), s_info, wxOK | wxCANCEL | wxTE_MULTILINE, wxDefaultPosition);

	if (tdlg.ShowModal()== wxID_OK)
	{
		s_info= tdlg.GetValue();
	}
	else return;

	wxString s_sql, s_wbs;

    for(int i=0;i<i_count;i++)
    {
         s_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1);
         s_sql = wxT("UPDATE s_unit_info SET special_info='")+s_info+wxT("' WHERE wbs_no='")+s_wbs+wxT("';");
         if(wxGetApp().app_sql_select(s_sql))
         {
             wxGetApp().change_log("s_unit_info",s_wbs, "special_info",gd_unit_info->GetCellValue(array_sel_line.Item(i), 13),s_info,"by hand");
             gd_unit_info->SetCellValue(array_sel_line.Item(i), 13, s_info);
         }
    }

}

void instance_unit_info::Onmi_mc2_hSelected(wxCommandEvent& event)
{

    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

     int i_count =gd_unit_info->GetNumberRows();

    if(i_count==0)
    {
        wxLogMessage(_("表格内无任何内容，无法输出!"));
        return;
    }

    wxFileDialog     saveFileDialog(this, _("Save xls file"), "", "",
                                       "xls files (*.xls)|*.xls", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    wxString s_file = saveFileDialog.GetPath();

    int i_col = gd_unit_info->GetNumberCols();

    int i_width=0;


    wxString str;
    workbook wb1;
    worksheet* ws = wb1.sheet("Sheet1");
    int i,j;

    wxArrayInt array_col;

    int i_show_col=0;

    for(i=0;i<i_col;i++)
    {
        i_width = gd_unit_info->GetColSize(i);
        if(i_width>0)
        {
            array_col.Add(i);
            str = gd_unit_info->GetColLabelValue(i);
            ws->label(0,i_show_col,str.ToStdWstring());
            i_show_col++;
        }

    }

    wxString s_special,s_project;
    s_project= wxEmptyString;
    int i_mc2_h=0;

    for(i=0;i<i_count;i++)
    {
        s_special = gd_unit_info->GetCellValue(i,13 );
        if(!s_special.Upper().Contains("MC2-H"))
            continue;

        if(s_project == gd_unit_info->GetCellValue(i, 0))
            continue;

        s_project=gd_unit_info->GetCellValue(i, 0);
        i_mc2_h++;

        for(j=0;j<i_show_col;j++)
        {
            str = gd_unit_info->GetCellValue(i,array_col.Item(j));

            ws->label(i_mc2_h,j,str.ToStdWstring());
        }
    }

    if(i_mc2_h==0)
        return;

    std::string filename = s_file.ToStdString();
    int error_msg = wb1.Dump(filename);

    if(error_msg == NO_ERRORS)
    {
           wxMessageBox(_("导出")+NumToStr(i_mc2_h)+_("台完成！"),_("提示"));
    }

}

void instance_unit_info::Onmi_delv_mc2_hSelected(wxCommandEvent& event)
{
      if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

       datepickerdlg dlg;

    if(dlg.ShowModal()==wxID_CANCEL)
    {
        return;
    }

    bool b_from = dlg.b_from;
    bool b_to = dlg.b_to;

    wxString str_from,str_to, s_sql;


    if(b_from&&b_to)
    {
        str_from = DateToStrFormat(dlg.dt_from);

        str_to = DateToStrFormat(dlg.dt_to);

        s_sql = s_sql + wxT(" where req_delivery_date>='")+str_from+wxT(" 00:00:00' and req_delivery_date<='")+str_to+wxT(" 23:59:59' and status>=0 ");
    }

    if(b_to && !b_from)
    {
        str_to = DateToStrFormat(dlg.dt_to);
        s_sql = s_sql + wxT(" where req_delivery_date<='")+str_to+wxT(" 23:59:59' and status>=0 ");

    }

    if(!b_to &&b_from)
    {
        str_from = DateToStrFormat(dlg.dt_from);
        s_sql = s_sql + wxT(" where req_delivery_date>='")+str_from+wxT(" 00:00:00' and status>=0 ");
    }


    if(!b_to &&!b_from)
    {
        str_from = str_to = DateToStrFormat(wxDateTime::Today());
        s_sql = s_sql + wxT(" where req_delivery_date>='")+str_from+wxT(" 00:00:00' and req_delivery_date<='")+str_to+wxT(" 23:59:59' and status>=0 ");

    }

    s_sql = s_sql + wxT(" and special_info ilike '%MC2-H%%' ");
    Set_Where_clause(s_sql);
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::Onmi_folderSelected(wxCommandEvent& event)
{
    if (!gr_para.login_status)
    {
        wxLogMessage(_("尚未登陆,不能进行任何操作!"));
        return;
    }

    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();
    if (array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项目，无法后续操作!"));
        return;
    }

    if (wxMessageBox(_("是否确认创建文件夹?"), _("确认"), wxYES_NO) != wxYES)
        return;

    int i_count = array_sel_line.GetCount();

    wxArrayString array_wbs;
    wxString str_wbs;

    int i_status,i,j;

    for(i=0;i<i_count;i++)
    {
        str_wbs = gd_unit_info->GetCellValue(array_sel_line.Item(i), 1).Trim();

        array_wbs.Add(str_wbs);
    }

    if(array_wbs.IsEmpty())
    {
        wxLogMessage(_("未选中任何项目。"));
        return;
    }

    //Create_Folder(array_wbs);
    Create_proj_Folder(array_wbs);
}

void instance_unit_info::OnButton_Pre_ProductionClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
        return;


    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

    if(wxMessageBox(_("确认所选项目启动排产？"),_("排产确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxString str_wbs_no;
    int i_status,i_can_status;
    bool b_can_psn;

    for(int i=0;i<i_count;i++)
    {
        str_wbs_no = gd_unit_info->GetCellValue(array_sel_line.Item(i),1);
        i_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i),6));
        b_can_psn = StrToBool(gd_unit_info->GetCellValue(array_sel_line.Item(i), 16));


        if (b_can_psn && (i_status==0 || i_status==1))
           i_can_status=2;
        else
           i_can_status = i_status;


        if(i_can_status!=2 && i_can_status!=5 && i_can_status !=6)
            continue;


        wxString str_sql = wxT("UPDATE s_unit_info SET old_status = '")+NumToStr(i_status)+wxT("', old_wf_status=wf_status, status ='9', wf_status ='项目启动排产', modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' where wbs_no ='")+str_wbs_no+wxT("';");
        if(wxGetApp().app_sql_update(str_sql))
        {
            wxGetApp().change_log(wxT("s_unit_info"),str_wbs_no, wxT("status"), NumToStr(i_status), wxT("9"),wxT("hand") );
            i_status =9;

            gd_unit_info->SetCellValue(array_sel_line.Item(i),6, prj_status_to_str(i_status));
            gd_unit_info->SetCellValue(array_sel_line.Item(i),7, wxT("项目启动排产"));
            wxLogMessage(str_wbs_no+wxT("启动排产成功!"));

        }

    }
}

void instance_unit_info::Onmi_pre_productionSelected(wxCommandEvent& event)
{
    Set_Where_clause(wxT(" WHERE  status='9' "));
    b_refresh = true;
    refresh_list();
    b_refresh = false;
}

void instance_unit_info::OnButton_cancel_productionClick(wxCommandEvent& event)
{
    if(!gr_para.login_status)
        return;


    wxArrayInt array_sel_line = gd_unit_info->GetSelectedRows();

    if(array_sel_line.IsEmpty())
    {
        wxLogMessage(_("尚未选择项次，无法后续操作!"));
        return;
    }

    if(wxMessageBox(_("确认所选项目取消排产？"),_("取消排产确认："),wxOK|wxCANCEL,this)==wxCANCEL)
    {
        return;
    }

    int i_count = array_sel_line.GetCount();

    wxString str_wbs_no;
    int i_status;

    for(int i=0;i<i_count;i++)
    {
        str_wbs_no = gd_unit_info->GetCellValue(array_sel_line.Item(i),1);
        i_status = prj_str_to_status(gd_unit_info->GetCellValue(array_sel_line.Item(i),6));

        if(i_status!=9)
            continue;

        wxString str_sql = wxT("UPDATE s_unit_info SET status=old_status, wf_status=old_wf_status, modify_date = '")+DateToAnsiStr(wxDateTime::Now())+wxT("', modify_emp_id = '")+gr_para.login_user+wxT("' where wbs_no ='")+str_wbs_no+wxT("';");
        if(wxGetApp().app_sql_update(str_sql))
        {
            wxLogMessage(str_wbs_no+wxT("取消排产成功!"));
        }

    }
    b_refresh = true;
    refresh_list();
    b_refresh = false;

}
