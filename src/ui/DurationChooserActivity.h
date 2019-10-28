/**
 *  Copyright (c) 2017-2019 Julian Schroden. All rights reserved.
 *  Licensed under the MIT License. See LICENSE file in the project root for
 *  full license information.
 */

#ifndef _DURATION_CHOOSER_ACTIVITY_h
#define _DURATION_CHOOSER_ACTIVITY_h

#include "Activity.h"

namespace ActivityGUI
{
class DurationChooserActivity : public Activity
{
public:
   //!
   //! Create DurationChooserActivity instance.
   //! The \a duration parameter is used to specify the default duration.
   //!
   DurationChooserActivity(std::string title,
                           uint32_t duration,
                           bool showTitleBar = false,
                           int titleFontScale = 2,
                           bool showArrowHome = false);

   void onScroll(int distance) override;
   void onClick() override;

   void setResult(ByteStack &bytes) override;

protected:
   void drawLayout() override;

private:
   int8_t hours = 0;
   int8_t minutes = 0;
   int8_t seconds = 0;

   uint32_t duration;  // in seconds

   uint8_t activeView = 0;  // index of the selected view
};
}  // namespace ActivityGUI

#endif