# DONUT PAD :O
DonutPad is a 12 key macropad with a rotary encoder and an OLED Display. It uses QMK firmware.
It was made to function as a gamepad/gamecontroller.

## Features:
- 12 Mechanical Keys
  - 4 keys for D-Pad (Up, Down, Left, Right)
  - 4 keys for Action buttons (A, B, X, Y)
  - Start and Select buttons
  - Left and RIght Shoulder buttons

- EC11 Rotary Encoder
  - Only rotation works

- 128 x 32 OLED Display
 
- Seeed XIAO RP2040
 
- Clean Custom PCB
 
- Sandwich Mounting Style Case

- QMK Firmware

## CAD Model:
Everything fits together using 4 M3 Screws and heatset inserts. It uses sandwich mounting style.
It has 2 separate printed pieces. The Case Shell where the PCB sits, and the Case Top Plate. 

The Case Shell is designed to be transparent, allowing the internal PCB to remain visible. Make sure to use Clear resin printing (recommended)/ Transparent acrylic/ Transparent FDA for the best original results.

The Case Top Plate holds all keyholes, hole for OLED display and hole for the rotary encoder. It features a black body with gold cut accents inspired by Kintsugi, the japanese art of repairing broken pottery with gold. 

Assembled view of DONUT PAD: 

<img width="612" height="511" alt="cad model assembled view" src="https://github.com/user-attachments/assets/1e639360-954a-4115-be22-222ac86149ec" />

Exploded view of DONUT PAD: 

<img width="724" height="545" alt="cad model exploded view" src="https://github.com/user-attachments/assets/941c54f7-7e13-4e4e-bf5f-0d5f86ff5bcd" />

Made in Fusion 360

## PCB:
Here's my PCB board and schematic! It was made in KiCad. The silkscreen art includes the dooOOnut guy made by me and the HackCLub logo by HackClub.

PCB Schematic: 

<img width="1478" height="701" alt="schematic kicad" src="https://github.com/user-attachments/assets/8a87f554-ff66-4fcd-be7c-e971abddb7fc" />

PCB Board: 

<img width="794" height="803" alt="PCB kicad" src="https://github.com/user-attachments/assets/84d03b2e-c2c4-48b2-a8e7-04bad1cf93a4" />

## Firmware Overview:
This macropad uses QMK firmware for everything.

- The rotary encoder changes volume. Press funtion doesn't work.
- 4 keys on the mid left fuction as the D-Pad, 4 keys on the mid right function as the action buttons, 2 keys on the bottom function as start and select and 2 keys on the top right and top left corner work as the left and right shoulder buttons.
his hackpad uses QMK firmware for everything.
- The OLED is supposed to play a gif but I am still working on ideas for the gif so for now it displays a custom text.

WIP of the gif I am making for the OLED display:

<img width="640" height="160" alt="1000240318" src="https://github.com/user-attachments/assets/ded0655c-8cc6-48af-a0f1-f3dd0a463a3c" />

I might add more stuff in the future! That's it for now.

## BOM:
- 1x Seeed XIAO RP2040
- 12x MX-Style switches
- 12x DSA keycaps
- 1x EC11 Rotary encoder
- 1x 0.91 inch 128x32 OLED display
- 12x through-hole 1N4148 Diodes
- 4x M3x16mm screws
- 4x M3x5mx4mm heatset inserts
- PCB
- 1x 3D printed Transparent case shell (Resin/Acrylic/Transparent FDA)
- 1x 3D printed Kintsugi inspired case plate
