#include "includes.h"
#include "More.h"

void menuIsPause(void)
{
  u16 key_num = IDLE_TOUCH;	

  popupDrawPage(bottomDoubleBtn, textSelect(LABEL_WARNING), textSelect(LABEL_IS_PAUSE), textSelect(LABEL_CONFIRM), textSelect(LABEL_CANNEL));
 
  while(infoMenu.menu[infoMenu.cur] == menuIsPause)
  {
    key_num = KEY_GetValue(2, doubleBtnRect);
    switch(key_num)
    {
      case KEY_POPUP_CONFIRM:
				if(setPrintPause(true))
			    infoMenu.menu[infoMenu.cur]=menuExtrude;
			  break;

      case KEY_POPUP_CANCEL:	
        infoMenu.cur--;
        break;		
    }
    loopProcess();
  }
}

MENUITEMS moreItems = {
//  title
LABEL_MORE,
// icon                       label
 {{ICON_FAN,                  LABEL_FAN},
  {ICON_RGB_SETTINGS,         LABEL_RGB_SETTINGS},
  {ICON_EXTRUDE,              LABEL_EXTRUDE},
  {ICON_FEATURE_SETTINGS,     LABEL_FEATURE_SETTINGS},
  {ICON_BACKGROUND,           LABEL_BACKGROUND},
  {ICON_BACKGROUND,           LABEL_BACKGROUND},
  {ICON_BACKGROUND,           LABEL_BACKGROUND},
  {ICON_BACK,                 LABEL_BACK},}
};

void menuMore(void)
{
  KEY_VALUES  key_num = KEY_IDLE;

  menuDrawPage(&moreItems,false);
  while(infoMenu.menu[infoMenu.cur] == menuMore)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      case KEY_ICON_0:
        infoMenu.menu[++infoMenu.cur] = menuFan;
        break;
      
      case KEY_ICON_1:
        infoMenu.menu[++infoMenu.cur] = menuRGBSettings;
        break;
      
      case KEY_ICON_2:
				if (isPrinting() && !isPause()) // need paused before extrude
				  infoMenu.menu[++infoMenu.cur] = menuIsPause;
				else
				  infoMenu.menu[++infoMenu.cur] = menuExtrude; 
        break;
      
      case KEY_ICON_3:
        infoMenu.menu[++infoMenu.cur] = menuFeatureSettings;
        break;
      
      case KEY_ICON_7:
        infoMenu.cur--;
        break;
      
      default:
        break;            
    }
    loopProcess();
  }
}
