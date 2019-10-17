/**
 *  Copyright (c) 2017-2018 Julian Schroden. All rights reserved.
 *  Licensed under the MIT License. See LICENSE file in the project root for
 * full license information.
 */

#ifndef _ACTIVITY_h
#define _ACTIVITY_h

#include <Adafruit_SSD1306.h>
#include <Arduino.h>

#include <string>

#include "../utils/ByteStack.h"


namespace ActivityGUI
{
class Activity
{
public:
   /**
    *  Activity constructor
    *  @param title            a string containing the activity-title which can
    * be displayed in the titleBar
    *  @param showTitleBar     boolean value to choose, if the titleBar should
    * be displayed
    *  @param titleFontScale   an integer value > 0 to modify the size of the
    * titleBar text; tested with the values 1 and 2
    *  @param showArrowHome    boolean value to choose if an arrow should
    * indicate, that there is an upper activity
    */
   Activity(std::string title,
            bool showTitleBar = false,
            int titleFontScale = 2,
            bool showArrowHome = false);

   /**
    *  Activity destructor
    */
   virtual ~Activity();

   /**
    *  Callback which is called by the ActivityRuntime, when the user scrolls
    *  @param distance   an integer value which states, how far the user has
    * scrolled
    */
   virtual void onScroll(int distance);

   /**
    *  ActivityRuntime callback which is called, when the user performs a click
    * action
    */
   virtual void onClick();

   /**
    *  ActivityRuntime callback which is called, when the user performs a
    * longClick action ( > 1s)
    */
   virtual void onLongClick();

   /**
    *  ActivityRuntime callback which is called, when the user navigates to the
    * upper activity and a result is expected
    *  @param bytes   a reference to a bytestack which allows passing multiple
    * primitive data types easily
    *  @see   startActivityForResult
    */
   virtual void setResult(ByteStack &bytes);

   /**
    *  ActivityRuntime callback which is called, when the user has navigated to
    * the upper activity and a result is expected
    *  @param result   a reference to a bytestack which allows receiving
    * multiple primitive data types easily
    *  @param key      an integer value between -128 and 127 to associate the
    * returned data
    *  @see   startActivityForResult
    */
   virtual void onActivityResult(ByteStack &result, int8_t key);

   /**
    *  ActivityRuntime callback which is called on the newly created activity
    */
   virtual void onStart();

   /**
    *  ActivityRuntime callback which is called on an activity, after it has
    * started a new activity
    */
   virtual void onPause();

   /**
    *  ActivityRuntime callback which is called on the previous activity, when
    * the user has navigated back to it
    */
   virtual void onResume();

   /**
    *  ActivityRuntime callback which is called on an activity, when the user
    * navigates to the previous activity
    */
   virtual void onDestroy();

protected:
   /**
    *  Starts a new activity by calling corresponding ActivityRuntime method
    *  @param activity   a pointer to an activity instance
    */
   void startActivity(Activity *const activity);

   /**
    *  Starts a new activity by calling corresponding ActivityRuntime method
    *  A flag is set to allow data to be transferred to the calling activity
    *  @param activity   a pointer to an activity instance
    *  @param key        an integer value between -128 and 127 to associate the
    * returned data
    */
   void startActivityForResult(Activity *const activity, int8_t key);

   /**
    *  Stops current activity by calling corresponding ActivityRuntime method
    *  Frees allocated memory
    */
   void stopActivity();

   /**
    *  Virtual method to draw the layout of an activity
    *  Needs to be implemented by all child classes to draw the layout onStart
    * and onResume
    */
   virtual void drawLayout();

   /**
    *  Draws the titlebar to the top of the display
    *  @param title         a string which should be displayed as the title
    *  @param fontScale     integer value > 0 to modify the size of the titleBar
    * text; tested with the values 1 and 2
    *  @param showArrowHome boolean value to choose if an arrow should indicate,
    * that there is an upper activity
    *  @param draw          boolean value to choose if display buffer should be
    * transferred to display
    */
   void drawTitleBar(std::string title,
                     int fontScale,
                     bool showArrowHome,
                     bool draw = false);

   /**
    *  Clears the screen of the current activity
    *  @param color the fill color (BLACK|WHITE)
    *  @param draw  boolean value to choose if display buffer should be
    * transferred to display
    */
   void clearActivity(const int color = BLACK, const boolean draw = true);

protected:
   Adafruit_SSD1306 &display;
   std::string title;
   bool showTitleBar;
   int titleFontScale;
   bool showArrowHome;

   int titleBarHeight = 0;
   bool areInterruptsEnbabled = true;
};
}  // namespace ActivityGUI

#endif
