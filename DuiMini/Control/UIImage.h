/**
 * Copyright (c) 2018-2050
 * All rights reserved.
 *
 * @Author:MXWXZ
 * @Date:2018/01/28
 *
 * @Description:
 */
#pragma once

namespace DuiMini {
class UIWindow;
class DUIMINI_API UIImage :public UIControl {
public:
    UIImage();
    virtual ~UIImage();

public:
    bool SetFile(LPCTSTR v_path);

public:
    void BeforeSetAttribute() override;

    void LoadResAttr() override;

    LPVOID GetInterface(LPCTSTR v_name) override;
    void Paint() override;

public:
    // virtual void Event(TEventUI& event);

private:
    UIRenderImage *img_ = nullptr;
};
}   // namespace DuiMini
