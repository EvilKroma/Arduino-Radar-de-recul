# Radar de Recul avec Capteur à Ultrasons et LEDs

Ce projet Arduino utilise un capteur à ultrasons (HC-SR04) pour mesurer la distance entre un objet et le capteur, et allume différentes LEDs en fonction de cette distance. Le projet simule un radar de recul avec des LEDs indiquant si l'objet est proche ou loin.

## Composants nécessaires

- Arduino Uno (ou toute autre carte Arduino compatible)
- Capteur à ultrasons HC-SR04
- 3 LEDs (rouge, orange, verte)
- 3 résistances de 220Ω pour les LEDs
- Câbles de connexion

## Connexions

Voici comment connecter les composants à l'Arduino :

### Capteur à ultrasons HC-SR04

- **VCC** → 5V de l'Arduino
- **GND** → GND de l'Arduino
- **Trig** → Pin 9 de l'Arduino
- **Echo** → Pin 10 de l'Arduino

### LEDs

- **LED verte**
  - Anode (patte longue) → Pin 2 de l'Arduino
  - Cathode (patte courte) → Résistance 220Ω → GND
- **LED orange**
  - Anode (patte longue) → Pin 3 de l'Arduino
  - Cathode (patte courte) → Résistance 220Ω → GND
- **LED rouge**
  - Anode (patte longue) → Pin 4 de l'Arduino
  - Cathode (patte courte) → Résistance 220Ω → GND
