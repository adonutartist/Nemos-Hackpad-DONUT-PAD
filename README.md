<div align="center">

# Donut Pad :O

*A 12-key macropad with a rotary encoder and OLED display, built for Hack Club's Stardance YSWS.*

<img width="1414" height="2000" alt="Copy of White Creative Project Cover Page" src="https://github.com/user-attachments/assets/1781746b-e17b-464b-bd36-734843ff5888" />

</div>

---

## About

Donut Pad is a 12 key macropad with a rotary encoder and an OLED display, built to function as a gamepad/game controller. It runs using a custom KiCad-designed PCB, and sits inside a integrated plate mounted case topped with a Kintsugi inspired plate with gold/silver cut accents.

## Features

- 12 Mechanical Keys:
  - 4 keys for D-Pad (Up, Down, Left, Right)
  - 4 keys for Action buttons (J, K, U, I)
  - Start and Esc buttons
  - Left and Right shoulder buttons
- EC11 Rotary Encoder for volume (rotation only press is not wired/functional)
- 128x32 OLED display (not functional)
- Seeed XIAO RP2040
- Clean custom PCB
- Sandwich mounting style case

---

## Exploded View

Everything fits together using 4 M3 screws and heatset inserts, integrated plate mount style, with 2 separate printed pieces:

- **Case Shell** where the PCB sits. Designed to be transparent so the PCB remains visible; clear resin printing (or transparent FDA) recommended for the best result. (I did it all black cuz resin is costly)
- **Case Top Plate** holds all keyholes, the OLED cutout, and the rotary encoder cutout. Features a black body with gold cut accents inspired by Kintsugi, the Japanese art of repairing broken pottery with gold.

Assembled view of Donut Pad:

<img width="612" height="511" alt="cad model assembled view" src="https://github.com/user-attachments/assets/1e639360-954a-4115-be22-222ac86149ec" />

Exploded view of Donut Pad:

<img width="724" height="545" alt="cad model exploded view" src="https://github.com/user-attachments/assets/941c54f7-7e13-4e4e-bf5f-0d5f86ff5bcd" />

Made in Fusion 360.

---

## BOM (Bill of Materials)

| Component | Qty | Purpose |
|-----------|-----|---------|
| Seeed XIAO RP2040 | 1 | Main controller |
| MX-Style switches | 12 | Key matrix |
| DSA keycaps | 12 | Keycaps |
| EC11 Rotary encoder | 1 | Scroll/volume input |
| 0.91" 128x32 OLED display | 1 | Status display |
| 1N4148 Diodes (THT) | 12 | Matrix ghosting protection |
| M3x16mm screws | 4 | Case assembly |
| M3x5x4mm heatset inserts | 4 | Case assembly |
| Custom PCB | 1 | — |
| 3D printed transparent case shell | 1 | Clear resin / transparent FDA |
| 3D printed Kintsugi-inspired case plate | 1 | Top plate with gold accents |

---

## Circuit Diagram

Designed in KiCad. The silkscreen art includes a custom dooOOnut mascot and the Hack Club logo.

PCB Schematic:

<img width="1478" height="701" alt="schematic kicad" src="https://github.com/user-attachments/assets/8a87f554-ff66-4fcd-be7c-e971abddb7fc" />

PCB Board:

<img width="794" height="803" alt="PCB kicad" src="https://github.com/user-attachments/assets/84d03b2e-c2c4-48b2-a8e7-04bad1cf93a4" />

---

## Known Issues

- **OLED display is not functional.** The PCB footprint was laid out assuming the module's pin header runs top-to-bottom (GND, 3V3, SCL, SDA), but the physical module's actual pin order runs bottom-to-top — so the connections ended up reversed on the board. Attempted a rework with a desoldering pump and solder wick to lift the header and rewire it with jumpers, but the pads wouldn't fully clear, so the fix was abandoned for now. Keys and the rotary encoder work fully; the OLED does not currently display anything.
- RGB underglow LEDs were dropped from the design due to DRC errors during PCB routing.

---

## Firmware

Built in the Arduino IDE using:

- Keyboard (built into the Raspberry Pi Pico/RP2040 board core)
- Adafruit GFX
- Adafruit SSD1306

Flash **`Macropad.ino`** to the board. The firmware:

- Scans the 4x3 matrix with debouncing and sends the mapped key on each press.
- Decodes the rotary encoder via interrupt-driven quadrature detection, sending Up/Down arrow keys.
- Drives the OLED status display — currently has no visible effect due to the wiring issue above, but the code is left in place for whenever the display gets rewired.

---

## OLED animation:

- Animated GIF on the OLED.

WIP preview of the OLED animation:

<img width="640" height="160" alt="1000240318" src="https://github.com/user-attachments/assets/ded0655c-8cc6-48af-a0f1-f3dd0a463a3c" />

I might add more stuff in the future! That's it for now.

---

## Gallery

<table>
<tr>
<td width="50%">
<img width="3264" height="1840" alt="IMG_20260905_141733" src="https://github.com/user-attachments/assets/01f73528-bd16-4f6b-bd68-53d85b8e939c" />
</td>
<td width="50%">
<img width="3264" height="1840" alt="IMG_20260905_141751" src="https://github.com/user-attachments/assets/f522d139-001d-4d8d-ac51-e1ac52a54699" />
</td>
</tr>

<tr>
<td width="50%">
<img width="3264" height="1840" alt="IMG_20260905_141802" src="https://github.com/user-attachments/assets/6508a93b-6058-492a-ac41-65a706adbdad" />
</td>
<td width="50%">
<img width="3264" height="1840" alt="IMG_20260905_141846" src="https://github.com/user-attachments/assets/8316ef60-64c3-4809-a8b0-74d0b74fd22b" />
</td>
</tr>

<tr>
<td width="50%">
<img width="1080" height="1920" alt="Snapchat-1131476981" src="https://github.com/user-attachments/assets/da655dbf-ac90-474a-b77d-5d0c6fdac3e8" />
</td>
<td width="50%">
<img width="1080" height="1920" alt="Snapchat-2125285501" src="https://github.com/user-attachments/assets/96cbfe74-6b1d-4e10-b2ac-51132587c2bb" />
</td>
</tr>
</table>

---

<div align="center">
<img width="300" alt="nemo" src="https://github.com/user-attachments/assets/aef52676-54b0-465c-9f61-d0daaa9ad6f4" />
</div>
