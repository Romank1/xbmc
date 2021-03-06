#pragma once
/*
 *      Copyright (C) 2005-2010 Team XBMC
 *      http://www.xbmc.org
 *
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#ifndef HAS_DS_PLAYER
#error DSPlayer's header file included without HAS_DS_PLAYER defined
#endif

#include "DSUtil/DSUtil.h"
#include "DSUtil/SmartPtr.h"
#include "IPaintCallback.h"
#include "streams.h"
#include "utils/CharsetConverter.h"
#include "system.h"

class IPaintCallbackMadvr
{
public:
  virtual ~IPaintCallbackMadvr() {};

  virtual LPDIRECT3DDEVICE9 GetDevice() { return NULL; };
  virtual bool IsDeviceSet(){ return false; }
  virtual bool IsEnteringExclusive(){ return false; }
  virtual void OsdRedrawFrame() {};
  virtual void SetMadvrPixelShader(){};
  virtual void RestoreMadvrSettings(){};
  virtual void SetStartMadvr(){};
  virtual bool IsCurrentThreadId() { return false; }
  virtual bool ParentWindowProc(HWND hWnd, UINT uMsg, WPARAM *wParam, LPARAM *lParam, LRESULT *ret) { return false; }
  virtual void SwapDevice(){};
  virtual void SetResolution(){};
  virtual void SetMadvrPosition(CRect wndRect, CRect videoRect) {};
  virtual void SettingSetScaling(CStdStringW path, int scaling) {};
  virtual void SettingSetDoubling(CStdStringW path, int iValue) {};
  virtual void SettingSetDoublingCondition(CStdStringW path, int condition) {};
  virtual void SettingSetQuadrupleCondition(CStdStringW path, int condition) {};
  virtual void SettingSetDeintActive(CStdStringW path, int iValue) {};
  virtual void SettingSetDeintForce(CStdStringW path, int iValue) {};
  virtual void SettingSetSmoothmotion(CStdStringW path, int iValue) {};
  virtual void SettingSetDithering(CStdStringW path, int iValue) {};
  virtual void SettingSetBool(CStdStringW path, BOOL bValue) {};
  virtual void SettingSetInt(CStdStringW path, int iValue) {};
  virtual CStdString GetDXVADecoderDescription() { return ""; };
};

class CMadvrCallback
{
public:
  /// Retrieve singleton instance
  static CMadvrCallback* Get();
  /// Destroy singleton instance
  static void Destroy()
  {
    delete m_pSingleton;
    m_pSingleton = NULL;
  }

  IPaintCallbackMadvr* GetCallback() { return m_pMadvr; }
  void SetCallback(IPaintCallbackMadvr* pMadvr) { m_pMadvr = pMadvr; }
  bool UsingMadvr();
  bool ReadyMadvr();
  bool IsEnteringExclusiveMadvr();
  void SetDsWndVisible(bool bVisible);
  bool IsInitMadvr() { return m_isInitMadvr; };
  void SetInitMadvr(bool b) { m_isInitMadvr = b; }
  HWND GetHwnd(){ return m_hWnd; }
  void SetHwnd(HWND hWnd){ m_hWnd = hWnd; }
  bool GetRenderOnMadvr() { return m_renderOnMadvr; }
  void SetRenderOnMadvr(bool b) { m_renderOnMadvr = b; }

private:
  CMadvrCallback();
  ~CMadvrCallback();

  static CMadvrCallback* m_pSingleton;
  IPaintCallbackMadvr* m_pMadvr;
  HWND m_hWnd;
  bool m_isInitMadvr;
  bool m_renderOnMadvr;
};
