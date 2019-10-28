/**
 *  Copyright (c) 2017-2019 Julian Schroden. All rights reserved.
 *  Licensed under the MIT License. See LICENSE file in the project root for
 *  full license information.
 */

#ifndef _TEXTUTILS_h
#define _TEXTUTILS_h

#include <string>

namespace ActivityGUI
{
class Dimension
{
public:
   Dimension(int width, int height)
   {
      this->width = width;
      this->height = height;
   }
   int getWidth() const
   {
      return width;
   }
   int getHeight() const
   {
      return height;
   }
private:
   int width, height;
};

class TextUtils
{
public:
   /**
    *  calculates the required dimensions to draw the provided text
    *  @param text   the text whose dimensions should be calculed
    *  @param scale  the font scale
    *  @return a Dimension object
    */
   static Dimension getTextBounds(std::string text, int scale)
   {
      return Dimension(text.length() * 6 * scale, 8 * scale);
   }
};
}  // namespace ActivityGUI

#endif
