# Table of Contents

- [Purchase List](#purchase-list)
- [3D Files](#3d-files)
- [Lids](#lids)
- [16x2](#16x2-lids)
- [Box](#box)
- [Mounting Options](#mounting-options)


## Purchase List
- [USB-C Pro Micro](https://a.co/d/40r7Z8c)
- [Toggle Switch with Aircraft Guard](https://a.co/d/8zprb8W)
- [Toggle Switches](https://a.co/d/gb6Z9sF)
- [Engine Start/Stop](https://a.co/d/4iWm9b6)
- [Diodes](https://a.co/d/17q5yrM)
- [Vinyl Wrap](https://a.co/d/8dlAxQy)
- [EC11 Rotary Encoders](https://a.co/d/904myFO)
- [12mm Momentary Switches](https://a.co/d/8DzCP9i)
- [7mm Momentary Switches](https://a.co/d/gAq71AI)
- [M6 assorted](https://a.co/d/cKX1Adg)
- [m6x60mm Bolts](https://a.co/d/dvMr3f9)

### 16x2 Option
- [Winstar OLED](https://www.aliexpress.us/item/2251832696798206.html)
- [I2C Adapter](https://a.co/d/55hU6gz)
- [Arduino Nano](https://a.co/d/cgAba1g): You can buy knockoffs... but make sure they at very least have a genuine CH340 chip. 

# 3D Files

## Lids

After some experimenting I have found that having most of the toggle switches along the bottom is the most ergonomic, but you can populate it how you best see fit.

- [lid_7mm_switches](./3d%20files/lid_7mm_switches.stl): Lid that houses 7mm switches. Most holes are 6.3mm or 7mm here. Big brake bias knob works great here.

- [lid_12mm_switches](./3d%20files/lid_12mm_switches.stl): Lid that houses 12mm switches. Other holes are 6.3mm or 7mm here. Big brake bias knob works great here.

### 16x2 Lids
Allows for a 16x2 display. I used the OLED one linked in the purchase list. I haven't tried any others; so double check measurements if you decide to use an LCD instead.

Use an Arduino Nano to run the 16x2 display as the Pro Micro doesn't have any more space. However, you can add the two additional buttons to the Pro Micro matrix.

- [lid_16x2_7mm_switches](./3d%20files/lid_16x2_7mm_switches.stl): This is the same as the 7mm switches, but has a cutout for an 16x2 display. It also moves one rotary from the top row back to the middle row.

- [lid_16x2_ctrls](./3d%20files/lid_16x2_ctrls.stl): Same as above, but this includes two additional button holes so you can use them to control the 16x2 screen (next/previous screens in SimHub).

### Knobs
The knobs are all the same size except for [BBKnob_large](./3d%20files/Knobs/BBKnob_large.stl). That knob is best used with lid_7mm_switches and lid_12mm_switches.

 You don't have to use these, but I have found them to be quite nice. The original design is by [RCHeliGuy](https://www.thingiverse.com/thing:4673851). 

## Box
The box has plenty of space for the items I have included in the purchase list. You'll notice it is akin to swiss cheese. I have given a lot of options for mounting for maximum flexibility. 

The majority of the holes in the box are **6mm holes**. 

There are also a few select **12mm holes** for running wire into the box if you do not want to panel mount or if you wish to run other wires into the box.

There are also holes for panel mounting your arduino pro micro / nano boards. You can find panel mounts here:

### Arduino Panel Mounts
- [Nano_PanelMount](./3d%20files/Nano_PanelMount.stl): Used to panel mount an Arduino Nano (USB Mini)
- [ProMicro_PanelMount-USBC](./3d%20files/ProMicro_PanelMount_USBC.stl): Used to panel mount most USBC pro micro boards
- [Arduino Pro-Micro Panel Mount](https://www.thingiverse.com/thing:4077845): Used for USB Micro Pro Micro Boards

## Mounting Options
Inside the [Mounting Folder](./3d%20files/Mounting/) there are multiple options for mounting; including simply attaching the box with 6mm bolts from inside the box (I have provided multiple holes to provide many options). It should also fit onto this [Button Box Mount by Advanced Sim Racing](https://www.advancedsimracing.com/products/button-box-mount)

If you want to use the hinge system: I recommend using little to no extensions, as the longer the extension, the more elasticity you'll have and it's not as sturdy. The best option is to mount it directly to a 4040/1515 profile. You'll also need the M6 x 60mm bolts linked in the purchase list.

- [4040-side-hinge](./3d%20files/Mounting/4040-side-hinge.stl): Used to connect any of the extensions to your 4040/1515 profile. This can be mounted horizontally or vertically along the profile.
- [box-side-hinge](./3d%20files/Mounting/box-side-hinge.stl): This attaches to the button box. Could be on the back or the sides. On the back, there are holes to attach this horizontally or vertically.
- [4040-to-box-connection](./3d%20files/Mounting/4040-to-box-connection.stl): This piece can be bolted to your 4040/1515 profile and then directly attached to the box-side-hinge.
- [Extensions](./3d%20files/Mounting/Extensions/): Varying lengths for extending the box from the 4040/1515 profiles.