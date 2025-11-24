# How to Run This Project

This is a color-based aimbot project that uses Python for color detection and Arduino with USB Host Shield for mouse control.

## Prerequisites

1. **Hardware Required:**
   
   **Option A: Arduino with USB Host Shield (Original Setup)**
   - Arduino board (Uno, Mega, Leonardo, etc. - compatible with USB Host Shield)
   - USB Host Shield
   - Compatible mouse (Razer, Logitech, or other USB mouse)
   
   **Option B: Arduino Pro Micro (Simplified Setup - No USB Host Shield)**
   - Arduino Pro Micro (or Leonardo)
   - Your regular mouse connected directly to your computer
   - ⚠️ Note: With Pro Micro, you cannot pass through physical mouse input via the shield

2. **Software Required:**
   - Python 3.x
   - Arduino IDE
   - USB Host Shield library (only needed for Option A)

## Setup Instructions

### Step 1: Install Python Dependencies

1. Open a terminal/command prompt in the project directory
2. Install the required Python packages:

```bash
pip install -r requirements.txt
```

Or install individually:
```bash
pip install numpy opencv-python keyboard pyserial pywin32 Pillow scipy mss
```

### Step 2: Setup Arduino

**For Arduino with USB Host Shield (Original):**

1. **Install USB Host Shield Library:**
   - Open Arduino IDE
   - Go to `Sketch` → `Include Library` → `Manage Libraries`
   - Search for "USB Host Shield Library 2.0" and install it

2. **Upload Arduino Code:**
   - Open `aimlabs_aimbot.ino` in Arduino IDE
   - Select your Arduino board and COM port
   - Upload the code to your Arduino
   - Note the COM port number (e.g., COM5, COM12)

**For Arduino Pro Micro (Simplified - No USB Host Shield):**

1. **No additional libraries needed** - Pro Micro uses native HID support

2. **Upload Arduino Code:**
   - Open `aimlabs_aimbot_pro_micro.ino` in Arduino IDE
   - Select **Tools** → **Board** → **Arduino Leonardo** (Pro Micro uses Leonardo bootloader)
   - Or if available: **Tools** → **Board** → **SparkFun Pro Micro** (if you have SparkFun boards installed)
   - Select the correct COM port
   - Upload the code to your Pro Micro
   - Note the COM port number (e.g., COM3, COM7)
   
3. **Important:** With Pro Micro, connect your mouse directly to your computer's USB port (not through the Arduino). The Pro Micro will only control mouse movement, not pass through physical mouse input.

### Step 3: Configure Python Script

1. **Open `color_aimbot_v1.py`** and update these settings:

   - **COM Port** (line 29 and 150):
     ```python
     port = 'COM12'  # Change to your Arduino's COM port
     ```

   - **Color Detection** (line 30):
     ```python
     color_to_use = 'red'  # Options: 'red', 'purple', or 'yellow'
     ```

   - **Monitor Settings** (line 45):
     ```python
     monitor = {"top": 0, "left": 0, "width": 1920, "height": 1080}
     # Adjust to your screen resolution
     ```

   - **Crosshair Position** (line 50):
     ```python
     pt = (960, 538)  # Screen center/crosshair position
     ```

2. **Open `PyArduinoBot_v2.py`** and update:

   - **COM Port** (line 221):
     ```python
     port = 'COM5'  # Change to match your Arduino's COM port
     ```

   - **FOV Settings** (lines 14, 22):
     ```python
     num_steps = 10  # Number of steps for mouse movement
     FOV = 1.0       # Field of view multiplier
     ```

### Step 4: Run the Project

1. **Connect Hardware:**
   
   **For USB Host Shield setup:**
   - Connect your Arduino to your computer via USB
   - Connect your mouse to the USB Host Shield
   - Make sure the Arduino is powered and the code is uploaded
   
   **For Pro Micro setup:**
   - Connect your Pro Micro to your computer via USB
   - Connect your mouse directly to your computer (not through Pro Micro)
   - Make sure the Pro Micro is powered and the code is uploaded

2. **Run the Python Script:**
   ```bash
   python color_aimbot_v1.py
   ```

3. **Controls:**
   - **Shift**: Hold to activate aimbot and shoot
   - **Caps Lock**: Press to exit the script
   - **Comma (,)**: Increase FOV adjuster
   - **Period (.)**: Decrease FOV adjuster

## Troubleshooting

### Common Issues:

1. **Serial Port Error:**
   - Make sure the COM port in the Python script matches your Arduino's port
   - Check Device Manager (Windows) to find the correct COM port
   - Ensure no other program is using the serial port

2. **Arduino Not Responding:**
   - Verify the Arduino code is uploaded successfully
   - For USB Host Shield: Check USB Host Shield connections and ensure mouse is connected to shield
   - For Pro Micro: Make sure you selected the correct board (Arduino Leonardo) in Arduino IDE
   - Try a different USB cable or USB port
   - Check if the Pro Micro appears as a COM port in Device Manager

3. **Color Detection Not Working:**
   - Adjust `lpoint` and `upoint` HSV values in `color_aimbot_v1.py`
   - Use the `hsv_color_spectrum.png` image as reference
   - Test with different colors (red, purple, yellow)

4. **Import Errors:**
   - Make sure all dependencies are installed: `pip install -r requirements.txt`
   - On Windows, you may need to install Visual C++ Redistributable for `pywin32`

5. **Permission Errors:**
   - Run Python script as Administrator (Windows)
   - Some antivirus software may block the script

## Important Notes

⚠️ **Warning:** This project is for educational purposes only. Using aimbots in online games may violate terms of service and result in account bans.

- The script captures screen content and controls mouse movement
- Make sure you have proper permissions to run automation scripts
- Test in a safe environment before using in any game

## Additional Resources

- Full tutorial: https://www.slyautomation.com/blog/valorant-aimbot-with-color-detection-with-python/
- Arduino setup guide: https://www.slyautomation.com/blog/setting-up-valorant-aimbot-arduino-with-usb-host-shield-to-mouse/

