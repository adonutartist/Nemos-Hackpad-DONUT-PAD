# DONUT PAD :O

<img width="612" height="511" alt="cad model assembled view" src="https://github.com/user-attachments/assets/ad3508e2-c4bf-4b14-9ec9-6a4476d5c22b" />

*Donut Pad is a 12 key macropad with a rotary encoder and an OLED Display. It uses QMK firmware. It was made to function as a gamepad/gamecontroller.*

* Keyboard Maintainer: [Nemo Donut](https://github.com/adonutartist)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make nemos_hackpad:default

Flashing example for this keyboard:

    make nemos_hackpad:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
