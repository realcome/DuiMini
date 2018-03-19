/**
 * Copyright (c) 2018-2050
 * All rights reserved.
 *
 * @Author:MXWXZ
 * @Date:2018/01/24
 *
 * @Description:
 */
#pragma once

namespace DuiMini {
struct DUIMINI_API UIFont {
    UStr name_;
    UStr lang_;
    UStr font_;
    USHORT size_ = 0;
    bool bold_ = false;
    bool italic_ = false;
    bool underline_ = false;
    bool strikeout_ = false;
};

////////////////////////////////////////

#define UIGetStrPath(x) UIConfig::GetStrPath(x)
#define UITranslateStr(x) UIConfig::TranslateStr(x)

class DUIMINI_API UIConfig {
public:
    /**
    * Load global config
    * @param    LPCTSTR v_relativepath:resource relative path
    * (default:uires.xml)
    */
    static void LoadConfig(LPCTSTR v_relativepath = DEFAULT_RESFILE);

    // Get shown config id
    static LANGID GetShownLangID();
    static FONTID GetShownFontID();
    static SKINID GetShownSkinID();

    // Get shown config
    static UIAttr* GetShownLang();
    static UIAttr* GetShownFont();
    static UIAttr* GetShownSkin();

    /**
    * Set Shown Config
    * @param    v_id:config id
    */
    static void SetShownLang(LANGID v_id);
    static void SetShownFont(FONTID v_id);
    static void SetShownSkin(SKINID v_id);
    static void AddSystemSkin(SKINID v_id);

    /**
    * Find dlg config
    * @param    LPCTSTR v_name:dlgname
    * @return   dlg attr structure, nullptr for not find
    */
    static UIAttr* FindDlg(LPCTSTR v_name);
    static CUStr FindDlgFile(LPCTSTR v_name);       // return file directly

    /**
    * Find resid
    * @param    LPCTSTR v_name:resid name
    * @return   resid attr structure, nullptr for not find
    */
    static UIAttr* FindResid(LPCTSTR v_name);
    static CUStr FindResidFile(LPCTSTR v_name);     // return file directly

    /**
     * Get real file path from str(resid or path)
     * @param    LPCTSTR v_str:str need to get path
     * @return   relative path, empty for not find
     * This function will check '[' at the beginning and ']' at the end
     * to distinguish resid and path, please use "[resid]" to represent
     * you want to use resid.
     */
    static CUStr GetStrPath(LPCTSTR v_str);

    /**
     * Find language string map
     * @param    LPCTSTR v_name:str name
     * @return   langstr attr structure, nullptr for not find
     */
    static UIAttr* FindLangMap(LPCTSTR v_name);
    static CUStr FindLangMapValue(LPCTSTR v_name);    // return value directly

    /**
     * Get current font style
     * @return   font style
     */
    static UIFont GetFontStyle();
    /**
     * Find font
     * @param    LPCTSTR v_name:font name
     * @return   font attr structure, nullptr for not find
     */
    static UIAttr* FindFont(LPCTSTR v_name);
    static UIFont FindFontValue(LPCTSTR v_name);    // return value directly

    /**
    * Translate string from string(langstr or plain string)
    * @param    LPCTSTR v_str:str need to translate
    * @return   translated string, if langstr not find, return v_str.
    * This function will check '[' at the beginning and ']' at the end
    * to distinguish langstr and plain str, please use "[langstr]"
    * to represent you want to use langstr.
    *
    * If your string is like "[string]"(started with '[' and ends in ']')
    * and you dont want to parse it as langstr, you must change the beginning
    * '[' to "\[". 
    * e.g. if you want to use "[[abc[def]" as a string other than langstr,
    * you must write it like "\[[abc[def]"
    */
    static CUStr TranslateStr(LPCTSTR v_str);

private:
    static UICFGItem dlg_;            // dlg config

    static LANGID shownlang_;         // shown lang
    static SKINID shownskin_;         // shown skin
    static FONTID shownfont_;         // shown font
    static UICFGItem lang_;           // language config
    static UICFGItem skin_;           // skin config
    static UICFGItem font_;           // font config

    static UICFGItem res_id_;         // shown skin resid
    static UICFGItem sys_res_id_;     // system skin id
    static UICFGItem lang_str_;       // shown language str
    static UIFont font_style_;        // shown font style
};
}   // namespace DuiMini
