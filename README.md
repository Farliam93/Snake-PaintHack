# PaintHack

Anleitung:
1. Paint öffnen (kein Bild öffnen)(Wir brauchen den Fenster Titel Unbenannt).
2. Die Größe des Zeichenbereiches auf 400x400 Pixel anpassen.
3. Programm starten
4. Das Programm wartet bis Paint das erste mal den Focus besitzt.

Wenn der Basepointer und die Offsets in Zukunft nicht stimmen sollten:
Über Cheatengine wie bei allen anderen Spielen die Adresse des ersten Pixel suchen.
Doch der erste Pixel ist nicht der oberste linke. 

Paint legt die Daten der Pixel (3 Bytes) wie folgt ab:
![Screenshot_3](https://github.com/Farliam93/Snake-PaintHack/assets/116157943/ada270c2-6295-43f5-92c0-96d97ed500d5)

Suchen wir uns die Adresse dieses Pixel, sparen wir uns viel Arbeit, 
weil wir den gesamten Speicher in einem Stück ablegen können.

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/SLF0-G_G68k/0.jpg)](https://www.youtube.com/watch?v=SLF0-G_G68k)
