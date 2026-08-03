# LFR – Nuevo V2

<p align="center">
  <a href="https://linktr.ee/">Linktree</a> | <a href="https://github.com/lpps-1">GitHub</a> | <b>Category: Line Follower</b>
</p>

---

## Team LPPS Overview

> Team LPPS-1 is an elite, youth-led competitive robotics and engineering collective based in Pakistan. Completely self funded and operating independently with zero corporate or institutional backing, our core members peak at just 15 years old, yet we consistently dominate university level national arenas, securing over 9 major championship titles.
>
> We are renowned for pushing the boundaries of indigenous hardware innovation, having pioneered Pakistan's first locally manufactured high-grip silicone wheels for competitive robotics. We are also currently working on Pakistan's first custom high-amp motor drivers and 16-channel sensors capable of a 1MHz sample rate, alongside advanced autonomous firmware architectures, custom onboard OLED control systems, and high-performance line-following robots.

## Project Documentation

> GitHub's inline viewer can occasionally fail to render PDFs correctly. Use the links below to open the documents directly in your browser instead:

- 📄 [Components List](https://github.com/lpps-1/LFR---NuevoV2/blob/main/1%20-%20Project%20Details%20%26%20Specs/Project%20Nuevo%20V2%20-%20Components.pdf)
- 📄 [Technical Report](https://github.com/lpps-1/LFR---NuevoV2/blob/main/1%20-%20Project%20Details%20%26%20Specs/Project%20Nuevo%20V2%20-%20Technical%20Report.pdf)
- 📄 [Wiring Diagrams](https://github.com/lpps-1/LFR---NuevoV2/blob/main/1%20-%20Project%20Details%20%26%20Specs/Project%20Nuevo%20V2%20-%20Wiring.pdf)

---

## Competition Results — Nuevo V2

Nuevo V2 has been competition tested at the university level, taking on fields of some of the country's strongest robotics teams:

| Competition | Result | Field Size |
|---|---|---|
| **LUMS Psifi 17** | 3rd Place | 550+ teams |
| **UMT TechFiesta** | 1st Place | 60 teams |
| **PUCON** | 1st Place | 30 teams |
| **COMSATS Islamabad** | Runner-Up | 45 teams |

## About Nuevo V2

Nuevo V2 is a next gen, high speed autonomous Line Following Robot (LFR) engineered for maximum efficiency, track stability, and adaptability. Built on the competitive foundation of its predecessor, Nuevo V2 moves to an upgraded dual board architecture, combining a lightweight 25 cm × 15 cm single layer aluminum chassis with an expanded multi sensor array for track accuracy.

Rather than relying on standard PID control alone, Nuevo V2 runs an optimized, state driven logic algorithm paired with a dedicated sub routine for high speed intersection detection. Powered by a high torque 4 wheel drive TT motor layout and driven by the TB6612FNG dual motor module, the robot eliminates power loss oscillations to achieve rapid acceleration, tight cornering, and consistent execution on university level competition tracks.

### 1 - Wireless Connectivity

Nuevo V2 includes an onboard HC-05 Bluetooth module for wireless communication during both testing and competition. This removes the need for a USB tether during practice runs, making it easy to monitor live sensor values, check serial diagnostics, and tune PID values on the fly while the robot is on the track. The Bluetooth also lets Nuevo V2 switch into manual Remote Control (RC) mode via a smartphone app, giving it the flexibility to enter RC based driving events alongside standard line following categories.

## 2 - Robot Design

| Spec | Detail |
|---|---|
| Base Material | Aluminum |
| Length | 26 cm |
| Width | 15 cm |
| Height | 8 cm |
| Weight | 600 g (1.3 lb) |

- Pre-drilled mounting holes for precise placement of motors, sensors, and electronics
- Even weight distribution to prevent unnecessary skidding
- Compact, low center-of-gravity form factor for stable high-speed cornering

## Components

| Component | Quantity | Description |
|---|---|---|
| TB6612FNG Motor Driver | 1x | Motor driver |
| Arduino Nano | 1x | Microcontroller |
| 2200mAh 30C 11.7V LiPo | 1x | Power source |
| Push Button | 4x | Start/calibrate the LFR algorithm & navigate the custom OS on OLED |
| 4 Pin JST Male Header Pins | 10x | Inter-board communication |
| 4 Pin JST Male Connectors | 10x | Circuit connections |
| Vero Board 6×8cm | 2x | Base & soldering connections |
| Aluminum RC Car Sheet | 1x | Project base |
| TT Motor | 4x | DC motors |
| TCRT5000 5-Channel Array | 1x | IR sensors |
| HC-05 | 1x | Bluetooth communication module |
| LM2596 DC-DC Buck | 1x | Voltage regulator |
| Mini Buck Converter | 1x | Voltage regulation |
| Vero Board 3×5cm | 1x | Power board |
| Slide Switches 3mm | 4x | Motor control |
| 470µF Electrolytic Capacitor | 2x | Voltage stabilization |
| 10µF Electrolytic Capacitor | 3x | Signal filtration |
| Female Header Pins | 40x | Component placement |
| Male Header Pins | 40x | Component placement |
| 2 Pin JST Female Connectors | 6x | Motor/power connections |
| 2 Pin JST Male Pins | 6x | Motor/power connections |

*Full breakdown available in the [Components List PDF](https://raw.githubusercontent.com/lpps-1/LFR---NuevoV2/main/1%20-%20Project%20Details%20%26%20Specs/Project%20Nuevo%20V2%20-%20Components.pdf).*

## Wiring

### Arduino Nano → TB6612FNG

| Arduino Nano Pin | TB6612FNG Pin |
|---|---|
| D5 | PWMA |
| D8 | AIN1 |
| D7 | AIN2 |
| D12 | STBY |
| D9 | BIN1 |
| D10 | BIN2 |
| D11 | PWMB |
| 5V | VCC |
| GND | GND |

### TB6612FNG → TT Motors

| TB6612FNG Pin | Motor |
|---|---|
| A01 | Left Motor 1 |
| A02 | Left Motor 2 |
| B01 | Right Motor 1 |
| B02 | Right Motor 2 |
| VM | 12V Power Board Output |

### Arduino Nano → Navigation Buttons

| Arduino Nano Pin | Button |
|---|---|
| D2 | OKAY |
| D3 | CANCEL |
| D4 | UP |
| D6 | DOWN |
| GND | Common Ground |

### Arduino Nano → TCRT5000 5-Sensor Array

| Arduino Nano Pin | TCRT5000 Pin |
|---|---|
| A0 | Sensor 1 (L2) |
| A1 | Sensor 2 (L1) |
| A2 | Sensor 3 (C) |
| A3 | Sensor 4 (R1) |
| A6 | Sensor 5 (R2) |
| 5V | VCC |
| GND | GND |

### Arduino Nano → 1.3" OLED

| Arduino Nano Pin | OLED |
|---|---|
| A4 | SDA |
| A5 | SCL |
| 5V | 5V |
| GND | GND |

*Full wiring diagrams available in the [Wiring PDF](https://raw.githubusercontent.com/lpps-1/LFR---NuevoV2/main/1%20-%20Project%20Details%20%26%20Specs/Project%20Nuevo%20V2%20-%20Wiring.pdf).*

## Line-Following Algorithm & Control System

Instead of relying on basic logic switching or pure PID control alone, Nuevo V2 combines conditional if/else branching with a PID algorithm for smooth, responsive line tracking.

The microcontroller continuously polls the front five channel infrared array and calculates a weighted mean (average position) from the analog sensor readings. This weighted mean pinpoints the line's exact offset relative to the robot's center line. That error value feeds into a PID calculation loop, which adjusts motor PWM signals on the fly to handle smooth cornering and prevent jerky oscillations.

Alongside the continuous PID loop, conditional if/else statements handle state logic and track edge cases:

- **Line Centered** — PID output stays minimal, keeping drive motors at maximum forward speed.
- **Line Drifted** — PID applies differential power to the drive wheels to pull the robot back on track without overshooting.
- **Intersection Detection** — Independent if/else checks on the outer side sensors (A5 & A6) flag 90° turns or grid intersections, temporarily overriding standard steering to execute sharp maneuvers.
- **Line Lost** — An else condition triggers an active recovery sequence, rotating the robot back toward its last known position until the array regains track alignment.

## Custom UI

To remove any reliance on external laptops or serial monitors during competition, Nuevo V2 features an integrated, standalone visual interface powered by a 1.3" I2C OLED display and driven by a 4-button tactile keypad (UP, DOWN, OKAY, CANCEL). The UI is built with custom menu-rendering routines featuring smooth transition animations, high-contrast visual indicators, and real-time screen updates.

- **Main Dashboard & Startup Screen** — Splash animation, current robot model, run timer, active mode indicator, and quick-access navigation.
- **Live Sensor Monitor & Diagnostics** — Real-time bar graphs of raw IR sensor values with flashing indicators on intersection triggers — no laptop or serial plotter needed.
- **Automated Surface Calibration Mode** — Sweeps the sensor array across black/white track sections and auto-calculates optimal detection thresholds.
- **Real-Time PID Parameter Tuning** — Live adjustment of Kp, Ki, and Kd values at the track edge, no re-flashing required.
- **Drive Mode Selector** — Instant switch between Autonomous LFR Mode and Bluetooth RC Mode.

This self-contained setup drastically cuts setup time between runs, enabling instant troubleshooting and consistent high-speed performance on the track.

## Future Upgrades & Applications

**High-Precision Motion Control & IMU Sensor Fusion**
- 9-DOF IMU integration (accelerometer, gyroscope, magnetometer) for real-time angular velocity, tilt, and heading
- Closed-loop heading and inertial correction to compensate for wheel slip and drift
- Magnetic angle tracking for long distance directional orientation on complex, multi-path tracks
- Predictive deceleration algorithms based on measured track curvature and angular acceleration

**Advanced AI Navigation & Path Prediction**
- Embedded lightweight ML models to predict upcoming track profiles from lap telemetry
- Computer vision integration for complex path geometry, obstacles, and multi-lane intersections
- Sensor fusion engine merging vision, IR array, and IMU data via a central Kalman filter

## Repository Structure

```
├── 1 - Project Details & Specs/   # Components list, technical report, wiring diagrams
├── ...
```

---

<p align="center"><i>Built by Team LPPS-1 — Pakistan</i></p>
