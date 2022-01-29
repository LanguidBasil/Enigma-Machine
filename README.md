# Enigma-Machine

## What it is
![Enigma_(crittografia)_-_Museo_scienza_e_tecnologia_Milano](https://user-images.githubusercontent.com/72715882/151639686-38997ef5-48a1-47a3-ad2f-2bf407bbcc95.jpg)

The [Enigma machine](https://en.wikipedia.org/wiki/Enigma_machine) is a cipher device developed in 1923 and used in the early- to mid-20th century to protect commercial, diplomatic, and military communication. It was employed extensively by Nazi Germany during World War II, in all branches of the German military. The Enigma machine was considered so secure that it was used to encipher the most top-secret messages.

## How it works
![LSie41jlw4-449px-enigmamachinelabeled](https://user-images.githubusercontent.com/72715882/151639733-da4ff2fc-ebc9-4a6c-bc99-2dac3cc91165.jpg)

Crucial parts of Enigma are rotors and reflector. When a key is pressed signal goes through first rotor, becoming any other letter, then second and third, reflecting of the reflector and going through all 3 rotors again. When signal has reached destination one ot many rotors rotate, and next character will be processed by different path. Adding to complexity, army version of Enigma had a plugboard. On that plugboard you could wire together two letters, when a signal goes to one, it goes through wire and outputs as the other. In total Enigma machine has 158,962,555,217,826,360,000 different settings which, at the time, seemed impossible to break.

## Is it unbreakable?
No, it is breakable. [Bomba](https://en.wikipedia.org/wiki/Bomba_(cryptography)) is a Polish decipher machine that was invented in January 1933 by Marian Rejewski and later enhanced by Alan Turing against newer versions of Enigma.

## This program
I've created a 3 rotor military Enigma machine with up to 10 plugs. For three rotor positions there are 8 rotors to choose from, any of 26 letters can be set as starting and ring changing. For reflector there are 5 configurations. You can set your enigma manually to decrypt a message, or randomly for a quick start.
![D__Projects_Enigma-Machine_bin_Win32_Release_EnigmaMachine exe 29_01_2022 10_54_18 (3)](https://user-images.githubusercontent.com/72715882/151640317-9845b4d9-a083-477c-bf1e-da58b906bbd6.png)

Want to play? Here is a crypted message and configuration, go ahead and break it ;)
```
Message: HUFRC GXOIZ EHEKJ DSRUV CCKTJ CCAQW XBPFA FQICK OR

Rotor 1: conf - ESOVPZJAYQUIRHXLNFTGKDCMWB current letter - C ring letter - J
Rotor 2: conf - EKMFLGDQVZNTOWYHXUSPAIBRCJ current letter - Q ring letter - N
Rotor 3: conf - JPGVOUMFYQBENHZRDKASXLICTW current letter - U ring letter - Z
Reflector configuration: ENKQAUYWJICOPBLMDXZVFTHRGS
Plugboard configuration: GW XK HY OF TQ JI ZN LU SE MR
```

## Sources to learn more
Articles on [wikipedia](https://en.wikipedia.org/wiki/Enigma_machine) and [brilliant](https://brilliant.org/wiki/enigma-machine/).

Videos from [Jared Owen](https://www.youtube.com/watch?v=ybkkiGtJmkM), [Code Bullet](https://www.youtube.com/watch?v=2D2bJWHvqJo&t=647s) and [Numberphile](https://www.youtube.com/watch?v=G2_Q9FoD-oQ&t=346s).
