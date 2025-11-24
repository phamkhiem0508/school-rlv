// Modified version for Arduino Pro Micro (no USB Host Shield required)
// This version removes USB Host Shield dependencies and uses native HID mouse support

#include <Mouse.h>

void setup() {
  Serial.begin(115200);  // Changed from 1000000 to 115200 for better compatibility
  Serial.setTimeout(1);
  Mouse.begin(); // Init mouse emulation
  delay(1000); // Short delay to let mouse initialization settle
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read the serial input until newline character
    input.trim(); // Remove leading and trailing spaces
    
    // Handle button clicks
    if (input == "left") {
      Mouse.click(MOUSE_LEFT);
      return;
    }
    if (input == "right") {
      Mouse.click(MOUSE_RIGHT);
      return;
    }
    
    // Handle mouse movement commands
    // Format: [(x1:y1), (x2:y2), ...]
    if (input.startsWith("[") && input.endsWith("]")) {
      input.remove(0, 1); // Remove the leading '['
      input.remove(input.length() - 1); // Remove the trailing ']'
      
      char charArray[input.length() + 1];
      input.toCharArray(charArray, sizeof(charArray));
      
      char* pair = strtok(charArray, ", ");
      
      while (pair != NULL) {
        String pairStr = pair;
        pairStr.remove(0, 1); // Remove the leading '('
        pairStr.remove(pairStr.length() - 1); // Remove the trailing ')'

        int commaIndex = pairStr.indexOf(":");
        if (commaIndex != -1) {
          String xStr = pairStr.substring(0, commaIndex);
          String yStr = pairStr.substring(commaIndex + 1);

          int x = xStr.toInt();
          int y = yStr.toInt();
          
          // Adjust for Arduino's 127 limitation (same as original code)
          float lim = (float)1 + ((float)100/(float)254);
          int finx = round((float)x * (float)lim);
          int finy = round((float)y * (float)lim);
          
          // Move the mouse
          Mouse.move(finx, finy, 0);
        }

        pair = strtok(NULL, ", ");
      }
    }
  }
  Serial.flush();
}

