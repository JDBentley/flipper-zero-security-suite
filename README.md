# Flipper Zero Physical Security Suite

A long term open source physical security assessment toolkit built
from scratch on the Flipper Zero platform. No pre-built firmware with
every feature written, documented, and explained line by line.

**Status:** Phase 1 complete — Active development
**Blog:** [jessebentley.com/series/flipper-zero-build](https://jessebentley.com/series/flipper-zero-build/)

---

## What This Is

Most Flipper Zero projects flash existing firmware and call it done.
This project builds everything from scratch with every line of C, every
ESP32 firmware file, every Python script written and explained
publicly on the blog.

The goal is a field ready physical security assessment toolkit that
a penetration tester can carry into an engagement and use to detect
hidden cameras, rogue access points, suspicious wireless devices,
and physical security vulnerabilities then generate a professional
PDF report from the findings.

---

## Hardware

**v1.0 (current)**
- Flipper Zero (main device)
- ESP32 WiFi Dev Board
- ESP32-CAM with 940nm IR LED array
- NRF24L01+PA+LNA 2.4GHz module
- NEO-6M GPS module
- Elecrow CrowPanel 3.5" LVGL touchscreen
- SentinelBoard — custom open source expansion PCB
- Custom 3D printed PETG enclosure

**v2.0 (planned)**
- Integrated ESP32-S3 (WiFi + Bluetooth 5 LE)
- CC1352R dual band radio (Sub-GHz + 2.4GHz)
- Single unified board replaces all modules
- JLCPCB manufactured
- CERN Open Hardware License

---

## Detection Capabilities

**WiFi**
- Device scanner with three tier MAC classification
- Pre-loaded camera manufacturer OUI database
- Evil twin access point detector
- Deauth attack detector
- Captive portal detector
- Probe request logger (passive)

**Bluetooth**
- BLE device scanning (v2.0)
- AirTag and tracker detection
- BLE camera detection

**RF**
- Sub-GHz spectrum analyzer
- 2.4GHz device scanning (NRF24L01)
- Baseline and delta scanning

**Physical**
- IR lens detector (940nm illumination)
- NFC/RFID vulnerability assessment
- GPS stamped scan logging

---

## Intelligence Layer

- Three tier MAC classification (whitelist, blacklist, greylist)
- Live editable lists via Flipper, CrowPanel, or companion app
- Temporal analysis engine (delta scanning)
- Risk scoring system (0-100 per scan)
- Device fingerprinting beyond OUI lookup
- Automated PDF report generation
- Shodan and CVE database integration

---

## Interfaces

- Flipper Zero screen and buttons (field use)
- CrowPanel 3.5" LVGL touch dashboard (companion display)
- Raspberry Pi base station with 5" display (desk unit)
- Python companion app (map visualization, reporting)

---

## Project Structure

<pre>
flipper-zero-security-suite/
├── apps/
│   └── hello_world/          ← Phase 1 complete
│       ├── hello_world.c
│       └── application.fam
├── esp32/                    ← Phase 2+ (coming)
├── companion/                ← Phase 13+ (coming)
├── sentinelboard/            ← PCB design (coming)
└── docs/                     ← Wiring diagrams, notes
</pre>

---

## Roadmap

See [ROADMAP.md](ROADMAP.md) for the complete 24 phase plan.

| Phase | Description | Status |
|---|---|---|
| Phase 1 | SDK setup and Hello World | ✅ Complete |
| Phase 2 | WiFi device scanner | 🔄 In progress |
| Phase 3 | Sub-GHz RF analyzer | ⬜ Planned |
| Phase 4 | IR scanner | ⬜ Planned |
| Phase 5 | NFC/RFID reader | ⬜ Planned |
| Phase 6 | CrowPanel LVGL UI | ⬜ Planned |
| Phase 7 | ESP32-CAM IR lens detector | ⬜ Planned |
| Phase 8 | MAC whitelist/blacklist system | ⬜ Planned |
| Phase 9 | Baseline and delta scanning | ⬜ Planned |
| Phase 10 | Risk scoring system | ⬜ Planned |
| Phase 11 | Deauth and evil twin detection | ⬜ Planned |
| Phase 12 | Device fingerprinting | ⬜ Planned |
| Phase 13 | Python companion app | ⬜ Planned |
| Phase 14 | GPS location logging | ⬜ Planned |
| Phase 15 | RF spectrum analyzer | ⬜ Planned |
| Phase 16 | Probe request logger | ⬜ Planned |
| Phase 17 | Captive portal detector | ⬜ Planned |
| Phase 18 | Stealth mode and auto scan | ⬜ Planned |
| Phase 19 | PDF report generator | ⬜ Planned |
| Phase 20 | Shodan and CVE integration | ⬜ Planned |
| Phase 21 | SentinelBoard PCB v1.0 | ⬜ Planned |
| Phase 22 | Temporal analysis engine | ⬜ Planned |
| Phase 23 | Machine learning layer | ⬜ Planned |
| Phase 24 | SentinelBoard v2.0 ESP32-S3 | ⬜ Planned |

---

## Building From Source

### Prerequisites

- Ubuntu 24.04 LTS (recommended)
- Python 3.12+
- ufbt (Flipper build tool)

### Install ufbt

```bash
python3 -m pip install ufbt --break-system-packages
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
ufbt update
```

### Build and deploy

```bash
cd apps/hello_world
ufbt launch
```

### USB permissions (Linux)

```bash
sudo usermod -a -G dialout $USER
# Log out and back in
```

---

## Blog

Every phase is documented in real time at:
[jessebentley.com/series/flipper-zero-build](https://jessebentley.com/series/flipper-zero-build/)

The blog documents what worked, what broke, and what was learned
at every step. Written to be useful to someone attempting the same
build — not a polished retrospective.

---

## Hardware Design

The SentinelBoard expansion PCB design files will be released
under the CERN Open Hardware License when complete. The goal is
for anyone in the security community to be able to order and
assemble their own board from JLCPCB.

---

## License

Software: [GPL-3.0](LICENSE)
Hardware (when released): CERN Open Hardware License v2

---

## Author

**Jesse Bentley** (Cerd)
- Blog: [jessebentley.com](https://jessebentley.com)
- GitHub: [@JDBentley](https://github.com/JDBentley)
- Email: jesse@jessebentley.com
